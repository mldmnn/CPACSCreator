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

#include <CCPACSWing.h>
#include <cassert>
#include "CCPACSAircraftModel.h"
#include "CCPACSRotorcraftModel.h"
#include "TixiHelper.h"
#include "CTiglLogging.h"
#include "CTiglError.h"
#include "CPACSWings.h"

namespace tigl
{
    namespace generated
    {
        CPACSWings::CPACSWings(CCPACSAircraftModel* parent)
        {
            //assert(parent != nullptr);
            m_parent = parent;
            m_parentType = &typeid(CCPACSAircraftModel);
        }
        
        CPACSWings::CPACSWings(CCPACSRotorcraftModel* parent)
        {
            //assert(parent != nullptr);
            m_parent = parent;
            m_parentType = &typeid(CCPACSRotorcraftModel);
        }
        
        CPACSWings::~CPACSWings() {}
        
        void CPACSWings::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element wing
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/wing")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/wing", m_wing, reinterpret_cast<CCPACSWings*>(this));
            }
            
        }
        
        void CPACSWings::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element wing
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/wing", m_wing);
            
        }
        
        const std::vector<unique_ptr<CCPACSWing>>& CPACSWings::GetWing() const
        {
            return m_wing;
        }
        
        std::vector<unique_ptr<CCPACSWing>>& CPACSWings::GetWing()
        {
            return m_wing;
        }
        
    }
}
