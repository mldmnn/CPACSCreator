/*
* Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
* Changed: $Id$
*
* Version: $Revision$
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
/**
* @file
* @brief  Implementation of CPACS configuration handling routines.
*/

#include "CCPACSConfiguration.h"

#include "CCPACSFuselageSegment.h"
#include "CCPACSWingSegment.h"

#include "TopoDS_Shape.hxx"
#include "Standard_CString.hxx"
#include "BRepOffsetAPI_ThruSections.hxx"
#include "BRepAlgoAPI_Fuse.hxx"
#include "BRepAlgo_Fuse.hxx"
#include "ShapeFix_Shape.hxx"
#include "TopoDS_Compound.hxx"
#include "BRepFeat_Gluer.hxx"
#include "BRep_Builder.hxx"
#include "BRepMesh.hxx"
#include "IGESControl_Controller.hxx"
#include "IGESControl_Writer.hxx"
#include "StlAPI_Writer.hxx"
#include "Interface_Static.hxx"
#include "StlAPI.hxx"
#include "BRepTools.hxx"
#include <BRepBndLib.hxx>
#include <Bnd_Box.hxx>
#include "CTiglFusePlane.h"
#include "CNamedShape.h"
#include "TixiSaveExt.h"

#include <cfloat>

namespace tigl
{

// Constructor
CCPACSConfiguration::CCPACSConfiguration(TixiDocumentHandle tixiHandle)
    : tixiDocumentHandle(tixiHandle), cpacsModel(nullptr)
{
}

// Destructor
CCPACSConfiguration::~CCPACSConfiguration(void)
{
    if (cpacsModel) {
        delete cpacsModel;
    }
}

// Invalidates the internal state of the configuration and forces
// recalculation of wires, lofts etc.
void CCPACSConfiguration::Invalidate(void)
{
    cpacsModel->Invalidate();
    aircraftFuser.reset();
    shapeCache.Clear();
    configUID = "";
}

// Build up memory structure for whole CPACS file
void CCPACSConfiguration::ReadCPACS(const std::string& configurationUID)
{
    char* path;
    if (tixiUIDGetXPath(tixiDocumentHandle, configurationUID.c_str(), &path) != SUCCESS) {
        throw CTiglError("Error: XML error while reading in CCPACSConfiguration::ReadCPACS", TIGL_XML_ERROR);
    }
    const std::string xpath = path;

    // create new root component for CTiglUIDManager
    if (cpacsModel) {
        delete cpacsModel;
    }
    cpacsModel = new CCPACSModel(this);
    cpacsModel->SetUID(configurationUID);
    uidManager.SetRootComponent(cpacsModel);

    // TODO: why can't we just write "/cpacs/vehicles/aircraft/model[" + configurationUID + "]" ?
    cpacsModel->ReadCPACS(tixiDocumentHandle, xpath); // reads everything underneath /cpacs/vehicles/aircraft/model

    header.ReadCPACS(tixiDocumentHandle, "/cpacs/header");
    guideCurveProfiles.ReadCPACS(tixiDocumentHandle, "/cpacs/vehicles/profiles/guideCurveProfiles");
    farField.ReadCPACS(tixiDocumentHandle, "/cpacs/toolspecific/cFD/farField");

    configUID = configurationUID;
    // Now do parent <-> child transformations. Child should use the
    // parent coordinate system as root.
    try {
        transformAllComponents(uidManager.GetRootComponent());
    }
    catch (tigl::CTiglError& ex) {
        LOG(ERROR) << ex.getError() << std::endl;
    }
}

// Write CPACS structure to tixiHandle
void CCPACSConfiguration::WriteCPACS(const std::string& configurationUID)
{
    char* path;
    if (tixiUIDGetXPath(tixiDocumentHandle, configurationUID.c_str(), &path) != SUCCESS) {
        throw CTiglError("Error: XML error while reading in CCPACSConfiguration::ReadCPACS", TIGL_XML_ERROR);
    }
    const std::string xpath = path;

    header.WriteCPACS(tixiDocumentHandle, "/cpacs/header");
    cpacsModel->WriteCPACS(tixiDocumentHandle, xpath);
}

// transform all components relative to their parents
void CCPACSConfiguration::transformAllComponents(CTiglAbstractPhysicalComponent* parent)
{
    if (!parent) {
        return;
    }

    CTiglAbstractPhysicalComponent::ChildContainerType children = parent->GetChildren(false);
    CTiglAbstractPhysicalComponent::ChildContainerType::iterator pIter;
    CTiglPoint parentTranslation = parent->GetTranslation();
    for (pIter = children.begin(); pIter != children.end(); ++pIter) {
        CTiglAbstractPhysicalComponent* child = *pIter;
        if (child->GetTranslationType() == ABS_LOCAL) {
            child->Translate(parentTranslation);
        }
        transformAllComponents(child);

    }
}


// Returns the boolean fused airplane as TopoDS_Shape
PTiglFusePlane CCPACSConfiguration::AircraftFusingAlgo(void)
{
    if (! aircraftFuser) {
        aircraftFuser = PTiglFusePlane(new CTiglFusePlane(*this));
    }
    return aircraftFuser;
}


// Returns the underlying tixi document handle used by a CPACS configuration
TixiDocumentHandle CCPACSConfiguration::GetTixiDocumentHandle(void) const
{
    return tixiDocumentHandle;
}

bool CCPACSConfiguration::HasWingProfile(std::string uid) const
{
    return cpacsModel->GetWings().HasProfile(uid);
}

// Returns the total count of wing profiles in this configuration
int CCPACSConfiguration::GetWingProfileCount(void) const
{
    return cpacsModel->GetWings().GetProfileCount();
}

// Returns the class which holds all wing profiles
CCPACSWingProfiles& CCPACSConfiguration::GetWingProfiles(void)
{
    return cpacsModel->GetWings().GetProfiles();
}

// Returns the class which holds all fuselage profiles
CCPACSFuselageProfiles& CCPACSConfiguration::GetFuselageProfiles(void)
{
    return cpacsModel->GetFuselages().GetProfiles();
}

// Returns the wing profile for a given uid.
CCPACSWingProfile& CCPACSConfiguration::GetWingProfile(std::string uid) const
{
    return cpacsModel->GetWings().GetProfile(uid);
}

// Returns the wing profile for a given index - TODO: depricated function!
CCPACSWingProfile& CCPACSConfiguration::GetWingProfile(int index) const
{
    return cpacsModel->GetWings().GetProfile(index);
}

// Returns the total count of wings in a configuration
int CCPACSConfiguration::GetWingCount(void) const
{
    return cpacsModel->GetWings().GetWingCount();
}

// Returns the wing for a given index.
CCPACSWing& CCPACSConfiguration::GetWing(int index) const
{
    return cpacsModel->GetWings().GetWing(index);
}
// Returns the wing for a given UID.
CCPACSWing& CCPACSConfiguration::GetWing(const std::string& UID) const
{
    return cpacsModel->GetWings().GetWing(UID);
}

TopoDS_Shape CCPACSConfiguration::GetParentLoft(const std::string& UID)
{
    return uidManager.GetParentComponent(UID)->GetLoft()->Shape();
}

bool CCPACSConfiguration::HasFuselageProfile(std::string uid) const
{
    return cpacsModel->GetFuselages().HasProfile(uid);
}

// Returns the total count of fuselage profiles in this configuration
int CCPACSConfiguration::GetFuselageProfileCount(void) const
{
    return cpacsModel->GetFuselages().GetProfileCount();
}

// Returns the fuselage profile for a given index.
CCPACSFuselageProfile& CCPACSConfiguration::GetFuselageProfile(int index) const
{
    return cpacsModel->GetFuselages().GetProfile(index);
}

// Returns the fuselage profile for a given uid.
CCPACSFuselageProfile& CCPACSConfiguration::GetFuselageProfile(std::string uid) const
{
    return cpacsModel->GetFuselages().GetProfile(uid);
}

// Returns the total count of fuselages in a configuration
int CCPACSConfiguration::GetFuselageCount(void) const
{
    return cpacsModel->GetFuselages().GetFuselageCount();
}

// Returns the fuselage for a given index.
CCPACSFuselage& CCPACSConfiguration::GetFuselage(int index) const
{
    return cpacsModel->GetFuselages().GetFuselage(index);
}


CCPACSFuselages& CCPACSConfiguration::GetFuselages()
{
    return cpacsModel->GetFuselages();
}


CCPACSFarField& CCPACSConfiguration::GetFarField()
{
    return farField;
}

// Returns the fuselage for a given UID.
CCPACSFuselage& CCPACSConfiguration::GetFuselage(const std::string UID) const
{
    return cpacsModel->GetFuselages().GetFuselage(UID);
}

// Returns the guide curve profile for a given UID.
CCPACSGuideCurveProfile& CCPACSConfiguration::GetGuideCurveProfile(std::string UID) const
{
    return guideCurveProfiles.GetGuideCurveProfile(UID);
}

// Returns the uid manager
CTiglUIDManager& CCPACSConfiguration::GetUIDManager(void)
{
    return uidManager;
}

double CCPACSConfiguration::GetAirplaneLenth(void)
{
    Bnd_Box boundingBox;

    // Draw all wings
    for (int w = 1; w <= GetWingCount(); w++) {
        tigl::CCPACSWing& wing = GetWing(w);

        for (int i = 1; i <= wing.GetSegmentCount(); i++) {
            tigl::CCPACSWingSegment& segment = (tigl::CCPACSWingSegment&) wing.GetSegment(i);
            BRepBndLib::Add(segment.GetLoft()->Shape(), boundingBox);

        }

        if (wing.GetSymmetryAxis() == TIGL_NO_SYMMETRY) {
            continue;
        }

        for (int i = 1; i <= wing.GetSegmentCount(); i++) {
            tigl::CCPACSWingSegment& segment = (tigl::CCPACSWingSegment&) wing.GetSegment(i);
            BRepBndLib::Add(segment.GetLoft()->Shape(), boundingBox);
        }
    }

    for (int f = 1; f <= GetFuselageCount(); f++) {
        tigl::CCPACSFuselage& fuselage = GetFuselage(f);

        for (int i = 1; i <= fuselage.GetSegmentCount(); i++) {
            tigl::CCPACSFuselageSegment& segment = (tigl::CCPACSFuselageSegment&) fuselage.GetSegment(i);
            BRepBndLib::Add(segment.GetLoft()->Shape(), boundingBox);
        }
    }
    Standard_Real xmin, xmax, ymin, ymax, zmin, zmax;
    boundingBox.Get(xmin, ymin, zmin, xmax, ymax, zmax);

    return xmax-xmin;
}

// Returns the uid manager
const std::string& CCPACSConfiguration::GetUID(void) const
{
    return configUID;
}

CTiglShapeCache& CCPACSConfiguration::GetShapeCache()
{
    return shapeCache;
}

CTiglMemoryPool& CCPACSConfiguration::GetMemoryPool()
{
    return memoryPool;
}

std::string CCPACSConfiguration::GetName(void) const
{
    return cpacsModel->GetName();
}

std::string CCPACSConfiguration::GetDescription(void) const
{
    return cpacsModel->GetDescription();
}

CCPACSHeader* CCPACSConfiguration::GetHeader()
{
    return &header;
}

CCPACSWings* CCPACSConfiguration::GetWings()
{
    return &cpacsModel->GetWings();
}

} // end namespace tigl

