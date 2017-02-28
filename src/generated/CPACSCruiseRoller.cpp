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
#include "CPACSCruiseRoller.h"

namespace tigl
{
    namespace generated
    {
        CPACSCruiseRoller::CPACSCruiseRoller(){}
        CPACSCruiseRoller::~CPACSCruiseRoller() {}
        
        void CPACSCruiseRoller::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            else {
                LOG(ERROR) << "Required attribute uID is missing";
            }
            
            // read element position
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/position")) {
                m_position.ReadCPACS(tixiHandle, xpath + "/position");
            }
            else {
                LOG(ERROR) << "Required element position is missing";
            }
            
            // read element parentAttachment
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/parentAttachment")) {
                m_parentAttachment.ReadCPACS(tixiHandle, xpath + "/parentAttachment");
            }
            else {
                LOG(ERROR) << "Required element parentAttachment is missing";
            }
            
            // read element controlSurfaceAttachment
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/controlSurfaceAttachment")) {
                m_controlSurfaceAttachment.ReadCPACS(tixiHandle, xpath + "/controlSurfaceAttachment");
            }
            else {
                LOG(ERROR) << "Required element controlSurfaceAttachment is missing";
            }
            
            // read element blockedDOF
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/blockedDOF")) {
                m_blockedDOF = boost::in_place();
                try {
                    m_blockedDOF->ReadCPACS(tixiHandle, xpath + "/blockedDOF");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read blockedDOF at xpath << " << xpath << ": " << e.what();
                    m_blockedDOF = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read blockedDOF at xpath << " << xpath << ": " << e.getError();
                    m_blockedDOF = boost::none;
                }
            }
            
        }
        
        void CPACSCruiseRoller::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uID");
            tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);
            
            // write element position
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/position");
            m_position.WriteCPACS(tixiHandle, xpath + "/position");
            
            // write element parentAttachment
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/parentAttachment");
            m_parentAttachment.WriteCPACS(tixiHandle, xpath + "/parentAttachment");
            
            // write element controlSurfaceAttachment
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/controlSurfaceAttachment");
            m_controlSurfaceAttachment.WriteCPACS(tixiHandle, xpath + "/controlSurfaceAttachment");
            
            // write element blockedDOF
            if (m_blockedDOF) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/blockedDOF");
                m_blockedDOF->WriteCPACS(tixiHandle, xpath + "/blockedDOF");
            }
            
        }
        
        const std::string& CPACSCruiseRoller::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSCruiseRoller::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        const CPACSCruiseRollerPosition& CPACSCruiseRoller::GetPosition() const
        {
            return m_position;
        }
        
        CPACSCruiseRollerPosition& CPACSCruiseRoller::GetPosition()
        {
            return m_position;
        }
        
        const CCPACSMaterial& CPACSCruiseRoller::GetParentAttachment() const
        {
            return m_parentAttachment;
        }
        
        CCPACSMaterial& CPACSCruiseRoller::GetParentAttachment()
        {
            return m_parentAttachment;
        }
        
        const CCPACSMaterial& CPACSCruiseRoller::GetControlSurfaceAttachment() const
        {
            return m_controlSurfaceAttachment;
        }
        
        CCPACSMaterial& CPACSCruiseRoller::GetControlSurfaceAttachment()
        {
            return m_controlSurfaceAttachment;
        }
        
        bool CPACSCruiseRoller::HasBlockedDOF() const
        {
            return static_cast<bool>(m_blockedDOF);
        }
        
        const CPACSBlockedDOF& CPACSCruiseRoller::GetBlockedDOF() const
        {
            return *m_blockedDOF;
        }
        
        CPACSBlockedDOF& CPACSCruiseRoller::GetBlockedDOF()
        {
            return *m_blockedDOF;
        }
        
    }
}
