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
#include "CPACSAttachmentPin.h"

namespace tigl
{
    namespace generated
    {
        CPACSAttachmentPin::CPACSAttachmentPin(){}
        CPACSAttachmentPin::~CPACSAttachmentPin() {}
        
        void CPACSAttachmentPin::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            else {
                LOG(ERROR) << "Required attribute uID is missing";
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
            
            // read element attachmentStructure
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/attachmentStructure")) {
                m_attachmentStructure = boost::in_place();
                try {
                    m_attachmentStructure->ReadCPACS(tixiHandle, xpath + "/attachmentStructure");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read attachmentStructure at xpath << " << xpath << ": " << e.what();
                    m_attachmentStructure = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read attachmentStructure at xpath << " << xpath << ": " << e.getError();
                    m_attachmentStructure = boost::none;
                }
            }
            
        }
        
        void CPACSAttachmentPin::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uID");
            tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);
            
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
            
            // write element attachmentStructure
            if (m_attachmentStructure) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/attachmentStructure");
                m_attachmentStructure->WriteCPACS(tixiHandle, xpath + "/attachmentStructure");
            }
            
        }
        
        const std::string& CPACSAttachmentPin::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSAttachmentPin::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        const CPACSAttachmentPinPosition& CPACSAttachmentPin::GetRelPosition() const
        {
            return m_relPosition;
        }
        
        CPACSAttachmentPinPosition& CPACSAttachmentPin::GetRelPosition()
        {
            return m_relPosition;
        }
        
        bool CPACSAttachmentPin::HasOrientation() const
        {
            return static_cast<bool>(m_orientation);
        }
        
        const CPACSPointYZ& CPACSAttachmentPin::GetOrientation() const
        {
            return *m_orientation;
        }
        
        CPACSPointYZ& CPACSAttachmentPin::GetOrientation()
        {
            return *m_orientation;
        }
        
        bool CPACSAttachmentPin::HasBlockedDOF() const
        {
            return static_cast<bool>(m_blockedDOF);
        }
        
        const CPACSPointXYZ& CPACSAttachmentPin::GetBlockedDOF() const
        {
            return *m_blockedDOF;
        }
        
        CPACSPointXYZ& CPACSAttachmentPin::GetBlockedDOF()
        {
            return *m_blockedDOF;
        }
        
        bool CPACSAttachmentPin::HasBolt() const
        {
            return static_cast<bool>(m_bolt);
        }
        
        const CPACSStrut& CPACSAttachmentPin::GetBolt() const
        {
            return *m_bolt;
        }
        
        CPACSStrut& CPACSAttachmentPin::GetBolt()
        {
            return *m_bolt;
        }
        
        bool CPACSAttachmentPin::HasAttachmentStructure() const
        {
            return static_cast<bool>(m_attachmentStructure);
        }
        
        const CCPACSMaterial& CPACSAttachmentPin::GetAttachmentStructure() const
        {
            return *m_attachmentStructure;
        }
        
        CCPACSMaterial& CPACSAttachmentPin::GetAttachmentStructure()
        {
            return *m_attachmentStructure;
        }
        
    }
}
