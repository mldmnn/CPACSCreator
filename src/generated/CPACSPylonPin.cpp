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
#include "CPACSPylonPin.h"

namespace tigl
{
    namespace generated
    {
        CPACSPylonPin::CPACSPylonPin(){}
        CPACSPylonPin::~CPACSPylonPin() {}
        
        void CPACSPylonPin::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            else {
                LOG(ERROR) << "Required attribute uID is missing";
            }
            
            // read element firstAttachmentUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/firstAttachmentUID")) {
                m_firstAttachmentUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/firstAttachmentUID");
            }
            else {
                LOG(ERROR) << "Required element firstAttachmentUID is missing";
            }
            
            // read element secondAttachmentUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/secondAttachmentUID")) {
                m_secondAttachmentUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/secondAttachmentUID");
            }
            else {
                LOG(ERROR) << "Required element secondAttachmentUID is missing";
            }
            
            // read element relPosition
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/relPosition")) {
                m_relPosition.ReadCPACS(tixiHandle, xpath + "/relPosition");
            }
            else {
                LOG(ERROR) << "Required element relPosition is missing";
            }
            
            // read element orientation
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/orientation")) {
                m_orientation = boost::in_place();
                try {
                    m_orientation->ReadCPACS(tixiHandle, xpath + "/orientation");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read orientation at xpath << " << xpath << ": " << e.what();
                    m_orientation = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read orientation at xpath << " << xpath << ": " << e.getError();
                    m_orientation = boost::none;
                }
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
            
            // read element bolt
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/bolt")) {
                m_bolt = boost::in_place();
                try {
                    m_bolt->ReadCPACS(tixiHandle, xpath + "/bolt");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read bolt at xpath << " << xpath << ": " << e.what();
                    m_bolt = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read bolt at xpath << " << xpath << ": " << e.getError();
                    m_bolt = boost::none;
                }
            }
            
        }
        
        void CPACSPylonPin::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uID");
            tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);
            
            // write element firstAttachmentUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/firstAttachmentUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/firstAttachmentUID", m_firstAttachmentUID);
            
            // write element secondAttachmentUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/secondAttachmentUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/secondAttachmentUID", m_secondAttachmentUID);
            
            // write element relPosition
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/relPosition");
            m_relPosition.WriteCPACS(tixiHandle, xpath + "/relPosition");
            
            // write element orientation
            if (m_orientation) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/orientation");
                m_orientation->WriteCPACS(tixiHandle, xpath + "/orientation");
            }
            
            // write element blockedDOF
            if (m_blockedDOF) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/blockedDOF");
                m_blockedDOF->WriteCPACS(tixiHandle, xpath + "/blockedDOF");
            }
            
            // write element bolt
            if (m_bolt) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/bolt");
                m_bolt->WriteCPACS(tixiHandle, xpath + "/bolt");
            }
            
        }
        
        const std::string& CPACSPylonPin::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSPylonPin::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        const std::string& CPACSPylonPin::GetFirstAttachmentUID() const
        {
            return m_firstAttachmentUID;
        }
        
        void CPACSPylonPin::SetFirstAttachmentUID(const std::string& value)
        {
            m_firstAttachmentUID = value;
        }
        
        const std::string& CPACSPylonPin::GetSecondAttachmentUID() const
        {
            return m_secondAttachmentUID;
        }
        
        void CPACSPylonPin::SetSecondAttachmentUID(const std::string& value)
        {
            m_secondAttachmentUID = value;
        }
        
        const CPACSPointXYZ& CPACSPylonPin::GetRelPosition() const
        {
            return m_relPosition;
        }
        
        CPACSPointXYZ& CPACSPylonPin::GetRelPosition()
        {
            return m_relPosition;
        }
        
        bool CPACSPylonPin::HasOrientation() const
        {
            return static_cast<bool>(m_orientation);
        }
        
        const CPACSPointYZ& CPACSPylonPin::GetOrientation() const
        {
            return *m_orientation;
        }
        
        CPACSPointYZ& CPACSPylonPin::GetOrientation()
        {
            return *m_orientation;
        }
        
        bool CPACSPylonPin::HasBlockedDOF() const
        {
            return static_cast<bool>(m_blockedDOF);
        }
        
        const CPACSPointXYZ& CPACSPylonPin::GetBlockedDOF() const
        {
            return *m_blockedDOF;
        }
        
        CPACSPointXYZ& CPACSPylonPin::GetBlockedDOF()
        {
            return *m_blockedDOF;
        }
        
        bool CPACSPylonPin::HasBolt() const
        {
            return static_cast<bool>(m_bolt);
        }
        
        const CPACSStrut& CPACSPylonPin::GetBolt() const
        {
            return *m_bolt;
        }
        
        CPACSStrut& CPACSPylonPin::GetBolt()
        {
            return *m_bolt;
        }
        
    }
}
