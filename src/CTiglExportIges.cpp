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
* @brief  Export routines for CPACS configurations.
*/

#include "CTiglExportIges.h"
#include "CCPACSImportExport.h"
#include "CCPACSConfiguration.h"

#include "TopoDS_Shape.hxx"
#include "Standard_CString.hxx"
#include "IGESControl_Controller.hxx"
#include "IGESControl_Writer.hxx"
#include "IGESData_IGESModel.hxx"
#include "IGESCAFControl_Writer.hxx"
#include "Interface_Static.hxx"



namespace tigl {

    // Constructor
    CTiglExportIges::CTiglExportIges(CCPACSConfiguration& config)
    :myConfig(config)
    {
        Interface_Static::SetCVal("xstep.cascade.unit", "M");
        Interface_Static::SetCVal("write.iges.unit", "M");
        Interface_Static::SetIVal("write.iges.brep.mode", 0);
        Interface_Static::SetCVal("write.iges.header.author", "TIGL");
        Interface_Static::SetCVal("write.iges.header.company", "German Aerospace Center (DLR), SC");
    }

    // Destructor
    CTiglExportIges::~CTiglExportIges(void)
    {
    }
    
    
    // Exports the whole configuration as IGES file
    // All wing- and fuselage segments are exported as single bodys
    void CTiglExportIges::ExportIGES(const std::string& filename) const
    {
        IGESControl_Controller::Init();

        IGESControl_Writer igesWriter;
        igesWriter.Model()->ApplyStatic(); // apply set parameters

        if( filename.empty()) {
           LOG(ERROR) << "Error: Empty filename in ExportFusedIGES.";
           return;
        }

        // Export all wings of the configuration
        for (int w = 1; w <= myConfig.GetWingCount(); w++)
        {
            CCPACSWing& wing = myConfig.GetWing(w);

            for (int i = 1; i <= wing.GetSegmentCount(); i++)
            {
                CCPACSWingSegment& segment = (tigl::CCPACSWingSegment &) wing.GetSegment(i);
                TopoDS_Shape loft = segment.GetLoft();

                igesWriter.AddShape(loft);
            }
        }

        // Export all fuselages of the configuration
        for (int f = 1; f <= myConfig.GetFuselageCount(); f++)
        {
            CCPACSFuselage& fuselage = myConfig.GetFuselage(f);

            for (int i = 1; i <= fuselage.GetSegmentCount(); i++)
            {
                CCPACSFuselageSegment& segment = (tigl::CCPACSFuselageSegment &) fuselage.GetSegment(i);
                TopoDS_Shape loft = segment.GetLoft();

                // Transform loft by fuselage transformation => absolute world coordinates
                loft = fuselage.GetFuselageTransformation().Transform(loft);

                igesWriter.AddShape(loft);
            }
        }

        // Write IGES file
        igesWriter.ComputeModel();
        if (igesWriter.Write(const_cast<char*>(filename.c_str())) != Standard_True)
            throw CTiglError("Error: Export to IGES file failed in CTiglExportIges::ExportIGES", TIGL_ERROR);
    }


    // Exports the whole configuration as one fused part to an IGES file
    void CTiglExportIges::ExportFusedIGES(const std::string& filename)
    {
        TopoDS_Shape fusedAirplane = myConfig.GetFusedAirplane();

        IGESControl_Controller::Init();

        if( filename.empty()) {
           LOG(ERROR) << "Error: Empty filename in ExportFusedIGES.";
           return;
        }

        IGESControl_Writer igesWriter;
        igesWriter.Model()->ApplyStatic(); // apply set parameters

        igesWriter.AddShape(fusedAirplane);

        // Write IGES file
        igesWriter.ComputeModel();
        if (igesWriter.Write(const_cast<char*>(filename.c_str())) != Standard_True)
            throw CTiglError("Error: Export fused shapes to IGES file failed in CTiglExportIges::ExportFusedIGES", TIGL_ERROR);
    }




    // Save a sequence of shapes in IGES Format
    void CTiglExportIges::ExportShapes(const Handle(TopTools_HSequenceOfShape)& aHSequenceOfShape, const std::string& filename)
    {
        IGESControl_Controller::Init();
        IGESControl_Writer igesWriter;

        if( filename.empty()) {
           LOG(ERROR) << "Error: Empty filename in ExportShapes.";
           return;
        }

        for (Standard_Integer i=1;i<=aHSequenceOfShape->Length();i++)
        {
            igesWriter.AddShape (aHSequenceOfShape->Value(i));
        }

        igesWriter.ComputeModel();
        if (igesWriter.Write(const_cast<char*>(filename.c_str())) != Standard_True)
            throw CTiglError("Error: Export of shapes to IGES file failed in CCPACSImportExport::SaveIGES", TIGL_ERROR);
    }


    // Saves as iges, with cpacs metadata information in it
    void CTiglExportIges::ExportIgesWithCPACSMetadata(const std::string& filename)
       {
           if( filename.empty()) {
               LOG(ERROR) << "Error: Empty filename in ExportIgesWithCPACSMetadata.";
               return;
           }

           CCPACSImportExport generator(myConfig);
           Handle(TDocStd_Document) hDoc = generator.buildXDEStructure();

           IGESControl_Controller::Init();
           IGESCAFControl_Writer writer;
           writer.Transfer(hDoc);
           writer.Write(filename.c_str());
       }

} // end namespace tigl
