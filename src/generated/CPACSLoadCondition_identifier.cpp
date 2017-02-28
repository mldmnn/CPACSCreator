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
#include "CPACSLoadCondition_identifier.h"

namespace tigl
{
    namespace generated
    {
        CPACSLoadCondition_identifier::CPACSLoadCondition_identifier(){}
        CPACSLoadCondition_identifier::~CPACSLoadCondition_identifier() {}
        
        void CPACSLoadCondition_identifier::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read simpleContent 
            if (tixihelper::TixiCheckElement(tixiHandle, xpath)) {
                m_simpleContent = stringToCPACSLoadCondition_identifier_SimpleContent(tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/"));
            }
            else {
                LOG(ERROR) << "Required simpleContent  is missing";
            }
            
        }
        
        void CPACSLoadCondition_identifier::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write simpleContent 
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/", CPACSLoadCondition_identifier_SimpleContentToString(m_simpleContent));
            
        }
        
        const CPACSLoadCondition_identifier_SimpleContent& CPACSLoadCondition_identifier::GetSimpleContent() const
        {
            return m_simpleContent;
        }
        
        void CPACSLoadCondition_identifier::SetSimpleContent(const CPACSLoadCondition_identifier_SimpleContent& value)
        {
            m_simpleContent = value;
        }
        
    }
}
