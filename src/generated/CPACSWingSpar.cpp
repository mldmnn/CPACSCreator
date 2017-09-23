// Copyright (c) 2016 RISC Software GmbH
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
#include "CCPACSWingCSStructure.h"
#include "CPACSWingSpar.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSWingSpar::CPACSWingSpar(CCPACSWingCSStructure* parent, CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr), 
            m_sparPositions(reinterpret_cast<CCPACSWingSpars*>(this), m_uidMgr), 
            m_sparSegments(reinterpret_cast<CCPACSWingSpars*>(this), m_uidMgr)
        {
            //assert(parent != NULL);
            m_parent = parent;
        }
        
        CPACSWingSpar::~CPACSWingSpar() {}
        
        CCPACSWingCSStructure* CPACSWingSpar::GetParent() const
        {
            return m_parent;
        }
        
        CTiglUIDManager& CPACSWingSpar::GetUIDManager()
        {
            return *m_uidMgr;
        }
        
        const CTiglUIDManager& CPACSWingSpar::GetUIDManager() const
        {
            return *m_uidMgr;
        }
        
        void CPACSWingSpar::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element sparPositions
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/sparPositions")) {
                m_sparPositions.ReadCPACS(tixiHandle, xpath + "/sparPositions");
            }
            else {
                LOG(ERROR) << "Required element sparPositions is missing at xpath " << xpath;
            }
            
            // read element sparSegments
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/sparSegments")) {
                m_sparSegments.ReadCPACS(tixiHandle, xpath + "/sparSegments");
            }
            else {
                LOG(ERROR) << "Required element sparSegments is missing at xpath " << xpath;
            }
            
        }
        
        void CPACSWingSpar::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element sparPositions
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/sparPositions");
            m_sparPositions.WriteCPACS(tixiHandle, xpath + "/sparPositions");
            
            // write element sparSegments
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/sparSegments");
            m_sparSegments.WriteCPACS(tixiHandle, xpath + "/sparSegments");
            
        }
        
        const CCPACSWingSparPositions& CPACSWingSpar::GetSparPositions() const
        {
            return m_sparPositions;
        }
        
        CCPACSWingSparPositions& CPACSWingSpar::GetSparPositions()
        {
            return m_sparPositions;
        }
        
        const CCPACSWingSparSegments& CPACSWingSpar::GetSparSegments() const
        {
            return m_sparSegments;
        }
        
        CCPACSWingSparSegments& CPACSWingSpar::GetSparSegments()
        {
            return m_sparSegments;
        }
        
    }
}
