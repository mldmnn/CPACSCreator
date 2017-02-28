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
#include "CPACSInterConnectionStrutAttachment.h"

namespace tigl
{
    namespace generated
    {
        CPACSInterConnectionStrutAttachment::CPACSInterConnectionStrutAttachment(){}
        CPACSInterConnectionStrutAttachment::~CPACSInterConnectionStrutAttachment() {}
        
        void CPACSInterConnectionStrutAttachment::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element position
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/position")) {
                m_position.ReadCPACS(tixiHandle, xpath + "/position");
            }
            else {
                LOG(ERROR) << "Required element position is missing";
            }
            
            // read element material
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/material")) {
                m_material.ReadCPACS(tixiHandle, xpath + "/material");
            }
            else {
                LOG(ERROR) << "Required element material is missing";
            }
            
        }
        
        void CPACSInterConnectionStrutAttachment::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element position
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/position");
            m_position.WriteCPACS(tixiHandle, xpath + "/position");
            
            // write element material
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/material");
            m_material.WriteCPACS(tixiHandle, xpath + "/material");
            
        }
        
        const CPACSCruiseRollerPosition& CPACSInterConnectionStrutAttachment::GetPosition() const
        {
            return m_position;
        }
        
        CPACSCruiseRollerPosition& CPACSInterConnectionStrutAttachment::GetPosition()
        {
            return m_position;
        }
        
        const CCPACSMaterial& CPACSInterConnectionStrutAttachment::GetMaterial() const
        {
            return m_material;
        }
        
        CCPACSMaterial& CPACSInterConnectionStrutAttachment::GetMaterial()
        {
            return m_material;
        }
        
    }
}
