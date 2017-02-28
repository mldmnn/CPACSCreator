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
#include "CPACSTrackActuator.h"

namespace tigl
{
    namespace generated
    {
        CPACSTrackActuator::CPACSTrackActuator(){}
        CPACSTrackActuator::~CPACSTrackActuator() {}
        
        void CPACSTrackActuator::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            else {
                LOG(ERROR) << "Required attribute uID is missing";
            }
            
            // read element actuatorUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/actuatorUID")) {
                m_actuatorUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/actuatorUID");
            }
            else {
                LOG(ERROR) << "Required element actuatorUID is missing";
            }
            
            // read element material
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/material")) {
                m_material.ReadCPACS(tixiHandle, xpath + "/material");
            }
            else {
                LOG(ERROR) << "Required element material is missing";
            }
            
        }
        
        void CPACSTrackActuator::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uID");
            tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);
            
            // write element actuatorUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/actuatorUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/actuatorUID", m_actuatorUID);
            
            // write element material
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/material");
            m_material.WriteCPACS(tixiHandle, xpath + "/material");
            
        }
        
        const std::string& CPACSTrackActuator::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSTrackActuator::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        const std::string& CPACSTrackActuator::GetActuatorUID() const
        {
            return m_actuatorUID;
        }
        
        void CPACSTrackActuator::SetActuatorUID(const std::string& value)
        {
            m_actuatorUID = value;
        }
        
        const CCPACSMaterial& CPACSTrackActuator::GetMaterial() const
        {
            return m_material;
        }
        
        CCPACSMaterial& CPACSTrackActuator::GetMaterial()
        {
            return m_material;
        }
        
    }
}
