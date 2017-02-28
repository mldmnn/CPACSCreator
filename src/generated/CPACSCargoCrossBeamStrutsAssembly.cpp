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

#include "CPACSCrossBeamStrutAssemblyPosition.h"
#include "TixiHelper.h"
#include "CTiglLogging.h"
#include "CTiglError.h"
#include "CPACSCargoCrossBeamStrutsAssembly.h"

namespace tigl
{
    namespace generated
    {
        CPACSCargoCrossBeamStrutsAssembly::CPACSCargoCrossBeamStrutsAssembly(){}
        CPACSCargoCrossBeamStrutsAssembly::~CPACSCargoCrossBeamStrutsAssembly() {}
        
        void CPACSCargoCrossBeamStrutsAssembly::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element cargoCrossBeamStrut
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/cargoCrossBeamStrut")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/cargoCrossBeamStrut", m_cargoCrossBeamStrut);
            }
            
        }
        
        void CPACSCargoCrossBeamStrutsAssembly::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element cargoCrossBeamStrut
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/cargoCrossBeamStrut", m_cargoCrossBeamStrut);
            
        }
        
        const std::vector<unique_ptr<CPACSCrossBeamStrutAssemblyPosition>>& CPACSCargoCrossBeamStrutsAssembly::GetCargoCrossBeamStrut() const
        {
            return m_cargoCrossBeamStrut;
        }
        
        std::vector<unique_ptr<CPACSCrossBeamStrutAssemblyPosition>>& CPACSCargoCrossBeamStrutsAssembly::GetCargoCrossBeamStrut()
        {
            return m_cargoCrossBeamStrut;
        }
        
    }
}
