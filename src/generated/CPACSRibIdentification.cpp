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

#include "TixiHelper.h"
#include "CTiglLogging.h"
#include "CTiglError.h"
#include "CPACSRibIdentification.h"

namespace tigl
{
    namespace generated
    {
        CPACSRibIdentification::CPACSRibIdentification(){}
        CPACSRibIdentification::~CPACSRibIdentification() {}
        
        void CPACSRibIdentification::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element ribDefinitionUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/ribDefinitionUID")) {
                m_ribDefinitionUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/ribDefinitionUID");
            }
            else {
                LOG(ERROR) << "Required element ribDefinitionUID is missing";
            }
            
            // read element ribNumber
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/ribNumber")) {
                m_ribNumber = tixihelper::TixiGetElement<int>(tixiHandle, xpath + "/ribNumber");
            }
            else {
                LOG(ERROR) << "Required element ribNumber is missing";
            }
            
        }
        
        void CPACSRibIdentification::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element ribDefinitionUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribDefinitionUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/ribDefinitionUID", m_ribDefinitionUID);
            
            // write element ribNumber
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribNumber");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/ribNumber", m_ribNumber);
            
        }
        
        const std::string& CPACSRibIdentification::GetRibDefinitionUID() const
        {
            return m_ribDefinitionUID;
        }
        
        void CPACSRibIdentification::SetRibDefinitionUID(const std::string& value)
        {
            m_ribDefinitionUID = value;
        }
        
        const int& CPACSRibIdentification::GetRibNumber() const
        {
            return m_ribNumber;
        }
        
        void CPACSRibIdentification::SetRibNumber(const int& value)
        {
            m_ribNumber = value;
        }
        
    }
}
