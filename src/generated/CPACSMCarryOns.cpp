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

#include "CPACSMCarryOn.h"
#include "TixiHelper.h"
#include "CTiglLogging.h"
#include "CTiglError.h"
#include "CPACSMCarryOns.h"

namespace tigl
{
    namespace generated
    {
        CPACSMCarryOns::CPACSMCarryOns(){}
        CPACSMCarryOns::~CPACSMCarryOns() {}
        
        void CPACSMCarryOns::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element massDescription
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/massDescription")) {
                m_massDescription.ReadCPACS(tixiHandle, xpath + "/massDescription");
            }
            else {
                LOG(ERROR) << "Required element massDescription is missing";
            }
            
            // read element mCarryOn
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mCarryOn")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/mCarryOn", m_mCarryOn);
            }
            
        }
        
        void CPACSMCarryOns::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element massDescription
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/massDescription");
            m_massDescription.WriteCPACS(tixiHandle, xpath + "/massDescription");
            
            // write element mCarryOn
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/mCarryOn", m_mCarryOn);
            
        }
        
        const CPACSGenericMass& CPACSMCarryOns::GetMassDescription() const
        {
            return m_massDescription;
        }
        
        CPACSGenericMass& CPACSMCarryOns::GetMassDescription()
        {
            return m_massDescription;
        }
        
        const std::vector<unique_ptr<CPACSMCarryOn>>& CPACSMCarryOns::GetMCarryOn() const
        {
            return m_mCarryOn;
        }
        
        std::vector<unique_ptr<CPACSMCarryOn>>& CPACSMCarryOns::GetMCarryOn()
        {
            return m_mCarryOn;
        }
        
    }
}
