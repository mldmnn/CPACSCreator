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
#include "CPACSOuterCutOutProfile.h"

namespace tigl
{
    namespace generated
    {
        CPACSOuterCutOutProfile::CPACSOuterCutOutProfile(){}
        CPACSOuterCutOutProfile::~CPACSOuterCutOutProfile() {}
        
        void CPACSOuterCutOutProfile::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element profileUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/profileUID")) {
                m_profileUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/profileUID");
            }
            else {
                LOG(ERROR) << "Required element profileUID is missing";
            }
            
            // read element rotZ
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/rotZ")) {
                m_rotZ = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/rotZ");
            }
            else {
                LOG(ERROR) << "Required element rotZ is missing";
            }
            
        }
        
        void CPACSOuterCutOutProfile::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element profileUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/profileUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/profileUID", m_profileUID);
            
            // write element rotZ
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rotZ");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/rotZ", m_rotZ);
            
        }
        
        const std::string& CPACSOuterCutOutProfile::GetProfileUID() const
        {
            return m_profileUID;
        }
        
        void CPACSOuterCutOutProfile::SetProfileUID(const std::string& value)
        {
            m_profileUID = value;
        }
        
        const double& CPACSOuterCutOutProfile::GetRotZ() const
        {
            return m_rotZ;
        }
        
        void CPACSOuterCutOutProfile::SetRotZ(const double& value)
        {
            m_rotZ = value;
        }
        
    }
}
