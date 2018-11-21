// Copyright (c) 2018 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <cassert>
#include "CCPACSTrailingEdgeDevice.h"
#include "CCPACSWingComponentSegment.h"
#include "CPACSWingComponentSegmentStructure.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSWingComponentSegmentStructure::CPACSWingComponentSegmentStructure(CCPACSWingComponentSegment* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_upperShell(reinterpret_cast<CCPACSWingCSStructure*>(this), m_uidMgr)
        , m_lowerShell(reinterpret_cast<CCPACSWingCSStructure*>(this), m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSWingComponentSegment);
    }

    CPACSWingComponentSegmentStructure::CPACSWingComponentSegmentStructure(CCPACSTrailingEdgeDevice* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_upperShell(reinterpret_cast<CCPACSWingCSStructure*>(this), m_uidMgr)
        , m_lowerShell(reinterpret_cast<CCPACSWingCSStructure*>(this), m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSTrailingEdgeDevice);
    }

    CPACSWingComponentSegmentStructure::~CPACSWingComponentSegmentStructure()
    {
    }

    CTiglUIDManager& CPACSWingComponentSegmentStructure::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSWingComponentSegmentStructure::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSWingComponentSegmentStructure::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element upperShell
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/upperShell")) {
            m_upperShell.ReadCPACS(tixiHandle, xpath + "/upperShell");
        }
        else {
            LOG(ERROR) << "Required element upperShell is missing at xpath " << xpath;
        }

        // read element lowerShell
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/lowerShell")) {
            m_lowerShell.ReadCPACS(tixiHandle, xpath + "/lowerShell");
        }
        else {
            LOG(ERROR) << "Required element lowerShell is missing at xpath " << xpath;
        }

        // read element ribsDefinitions
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribsDefinitions")) {
            m_ribsDefinitions = boost::in_place(reinterpret_cast<CCPACSWingCSStructure*>(this), m_uidMgr);
            try {
                m_ribsDefinitions->ReadCPACS(tixiHandle, xpath + "/ribsDefinitions");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read ribsDefinitions at xpath " << xpath << ": " << e.what();
                m_ribsDefinitions = boost::none;
            }
        }

        // read element spars
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/spars")) {
            m_spars = boost::in_place(reinterpret_cast<CCPACSWingCSStructure*>(this), m_uidMgr);
            try {
                m_spars->ReadCPACS(tixiHandle, xpath + "/spars");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read spars at xpath " << xpath << ": " << e.what();
                m_spars = boost::none;
            }
        }

    }

    void CPACSWingComponentSegmentStructure::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element upperShell
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/upperShell");
        m_upperShell.WriteCPACS(tixiHandle, xpath + "/upperShell");

        // write element lowerShell
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/lowerShell");
        m_lowerShell.WriteCPACS(tixiHandle, xpath + "/lowerShell");

        // write element ribsDefinitions
        if (m_ribsDefinitions) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribsDefinitions");
            m_ribsDefinitions->WriteCPACS(tixiHandle, xpath + "/ribsDefinitions");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribsDefinitions")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/ribsDefinitions");
            }
        }

        // write element spars
        if (m_spars) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/spars");
            m_spars->WriteCPACS(tixiHandle, xpath + "/spars");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/spars")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/spars");
            }
        }

    }

    const CCPACSWingShell& CPACSWingComponentSegmentStructure::GetUpperShell() const
    {
        return m_upperShell;
    }

    CCPACSWingShell& CPACSWingComponentSegmentStructure::GetUpperShell()
    {
        return m_upperShell;
    }

    const CCPACSWingShell& CPACSWingComponentSegmentStructure::GetLowerShell() const
    {
        return m_lowerShell;
    }

    CCPACSWingShell& CPACSWingComponentSegmentStructure::GetLowerShell()
    {
        return m_lowerShell;
    }

    const boost::optional<CCPACSWingRibsDefinitions>& CPACSWingComponentSegmentStructure::GetRibsDefinitions() const
    {
        return m_ribsDefinitions;
    }

    boost::optional<CCPACSWingRibsDefinitions>& CPACSWingComponentSegmentStructure::GetRibsDefinitions()
    {
        return m_ribsDefinitions;
    }

    const boost::optional<CCPACSWingSpars>& CPACSWingComponentSegmentStructure::GetSpars() const
    {
        return m_spars;
    }

    boost::optional<CCPACSWingSpars>& CPACSWingComponentSegmentStructure::GetSpars()
    {
        return m_spars;
    }

    CCPACSWingRibsDefinitions& CPACSWingComponentSegmentStructure::GetRibsDefinitions(CreateIfNotExistsTag)
    {
        if (!m_ribsDefinitions)
            m_ribsDefinitions = boost::in_place(reinterpret_cast<CCPACSWingCSStructure*>(this), m_uidMgr);
        return *m_ribsDefinitions;
    }

    void CPACSWingComponentSegmentStructure::RemoveRibsDefinitions()
    {
        m_ribsDefinitions = boost::none;
    }

    CCPACSWingSpars& CPACSWingComponentSegmentStructure::GetSpars(CreateIfNotExistsTag)
    {
        if (!m_spars)
            m_spars = boost::in_place(reinterpret_cast<CCPACSWingCSStructure*>(this), m_uidMgr);
        return *m_spars;
    }

    void CPACSWingComponentSegmentStructure::RemoveSpars()
    {
        m_spars = boost::none;
    }

} // namespace generated
} // namespace tigl
