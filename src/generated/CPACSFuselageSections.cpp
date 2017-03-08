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

#include <CCPACSFuselageSection.h>
#include "TixiHelper.h"
#include "CTiglLogging.h"
#include "CTiglError.h"
#include "CPACSFuselageSections.h"

namespace tigl
{
    namespace generated
    {
        CPACSFuselageSections::CPACSFuselageSections(){}
        CPACSFuselageSections::~CPACSFuselageSections() {}
        
        void CPACSFuselageSections::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element section
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/section")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/section", m_section);
            }
            
        }
        
        void CPACSFuselageSections::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element section
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/section", m_section);
            
        }
        
        const std::vector<unique_ptr<CCPACSFuselageSection> >& CPACSFuselageSections::GetSection() const
        {
            return m_section;
        }
        
        std::vector<unique_ptr<CCPACSFuselageSection> >& CPACSFuselageSections::GetSection()
        {
            return m_section;
        }
        
    }
}
