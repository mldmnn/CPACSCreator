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

#include "CPACSSingleGenericMass.h"
#include "TixiHelper.h"
#include "CTiglLogging.h"
#include "CTiglError.h"
#include "CPACSMIFESystems.h"

namespace tigl
{
    namespace generated
    {
        CPACSMIFESystems::CPACSMIFESystems(){}
        CPACSMIFESystems::~CPACSMIFESystems() {}
        
        void CPACSMIFESystems::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element massDescription
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/massDescription")) {
                m_massDescription.ReadCPACS(tixiHandle, xpath + "/massDescription");
            }
            else {
                LOG(ERROR) << "Required element massDescription is missing";
            }
            
            // read element mIFE
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mIFE")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/mIFE", m_mIFE);
            }
            
        }
        
        void CPACSMIFESystems::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element massDescription
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/massDescription");
            m_massDescription.WriteCPACS(tixiHandle, xpath + "/massDescription");
            
            // write element mIFE
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/mIFE", m_mIFE);
            
        }
        
        const CPACSGenericMass& CPACSMIFESystems::GetMassDescription() const
        {
            return m_massDescription;
        }
        
        CPACSGenericMass& CPACSMIFESystems::GetMassDescription()
        {
            return m_massDescription;
        }
        
        const std::vector<unique_ptr<CPACSSingleGenericMass>>& CPACSMIFESystems::GetMIFE() const
        {
            return m_mIFE;
        }
        
        std::vector<unique_ptr<CPACSSingleGenericMass>>& CPACSMIFESystems::GetMIFE()
        {
            return m_mIFE;
        }
        
    }
}
