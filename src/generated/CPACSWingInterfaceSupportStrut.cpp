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
#include "CPACSWingInterfaceSupportStrut.h"

namespace tigl
{
    namespace generated
    {
        CPACSWingInterfaceSupportStrut::CPACSWingInterfaceSupportStrut(){}
        CPACSWingInterfaceSupportStrut::~CPACSWingInterfaceSupportStrut() {}
        
        void CPACSWingInterfaceSupportStrut::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            
            // read element name
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/name")) {
                m_name = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
            }
            else {
                LOG(ERROR) << "Required element name is missing";
            }
            
            // read element description
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/description")) {
                m_description = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            }
            
            // read element structuralElementUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/structuralElementUID")) {
                m_structuralElementUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/structuralElementUID");
            }
            else {
                LOG(ERROR) << "Required element structuralElementUID is missing";
            }
            
            // read element wingAttachmentPinUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/wingAttachmentPinUID")) {
                m_wingAttachmentPinUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/wingAttachmentPinUID");
            }
            else {
                LOG(ERROR) << "Required element wingAttachmentPinUID is missing";
            }
            
            // read element fuselageAttachmentFrameUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/fuselageAttachmentFrameUID")) {
                m_fuselageAttachmentFrameUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/fuselageAttachmentFrameUID");
            }
            
            // read element fuselageAttachmentStringerUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/fuselageAttachmentStringerUID")) {
                m_fuselageAttachmentStringerUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/fuselageAttachmentStringerUID");
            }
            
        }
        
        void CPACSWingInterfaceSupportStrut::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            if (m_uID) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uID");
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", *m_uID);
            }
            
            // write element name
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/name", m_name);
            
            // write element description
            if (m_description) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
            }
            
            // write element structuralElementUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/structuralElementUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/structuralElementUID", m_structuralElementUID);
            
            // write element wingAttachmentPinUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/wingAttachmentPinUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/wingAttachmentPinUID", m_wingAttachmentPinUID);
            
            // write element fuselageAttachmentFrameUID
            if (m_fuselageAttachmentFrameUID) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/fuselageAttachmentFrameUID");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/fuselageAttachmentFrameUID", *m_fuselageAttachmentFrameUID);
            }
            
            // write element fuselageAttachmentStringerUID
            if (m_fuselageAttachmentStringerUID) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/fuselageAttachmentStringerUID");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/fuselageAttachmentStringerUID", *m_fuselageAttachmentStringerUID);
            }
            
        }
        
        bool CPACSWingInterfaceSupportStrut::HasUID() const
        {
            return static_cast<bool>(m_uID);
        }
        
        const std::string& CPACSWingInterfaceSupportStrut::GetUID() const
        {
            return *m_uID;
        }
        
        void CPACSWingInterfaceSupportStrut::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        const std::string& CPACSWingInterfaceSupportStrut::GetName() const
        {
            return m_name;
        }
        
        void CPACSWingInterfaceSupportStrut::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        bool CPACSWingInterfaceSupportStrut::HasDescription() const
        {
            return static_cast<bool>(m_description);
        }
        
        const std::string& CPACSWingInterfaceSupportStrut::GetDescription() const
        {
            return *m_description;
        }
        
        void CPACSWingInterfaceSupportStrut::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        const std::string& CPACSWingInterfaceSupportStrut::GetStructuralElementUID() const
        {
            return m_structuralElementUID;
        }
        
        void CPACSWingInterfaceSupportStrut::SetStructuralElementUID(const std::string& value)
        {
            m_structuralElementUID = value;
        }
        
        const std::string& CPACSWingInterfaceSupportStrut::GetWingAttachmentPinUID() const
        {
            return m_wingAttachmentPinUID;
        }
        
        void CPACSWingInterfaceSupportStrut::SetWingAttachmentPinUID(const std::string& value)
        {
            m_wingAttachmentPinUID = value;
        }
        
        bool CPACSWingInterfaceSupportStrut::HasFuselageAttachmentFrameUID() const
        {
            return static_cast<bool>(m_fuselageAttachmentFrameUID);
        }
        
        const std::string& CPACSWingInterfaceSupportStrut::GetFuselageAttachmentFrameUID() const
        {
            return *m_fuselageAttachmentFrameUID;
        }
        
        void CPACSWingInterfaceSupportStrut::SetFuselageAttachmentFrameUID(const std::string& value)
        {
            m_fuselageAttachmentFrameUID = value;
        }
        
        bool CPACSWingInterfaceSupportStrut::HasFuselageAttachmentStringerUID() const
        {
            return static_cast<bool>(m_fuselageAttachmentStringerUID);
        }
        
        const std::string& CPACSWingInterfaceSupportStrut::GetFuselageAttachmentStringerUID() const
        {
            return *m_fuselageAttachmentStringerUID;
        }
        
        void CPACSWingInterfaceSupportStrut::SetFuselageAttachmentStringerUID(const std::string& value)
        {
            m_fuselageAttachmentStringerUID = value;
        }
        
    }
}
