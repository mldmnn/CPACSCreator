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

#include "CPACSPositioning.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSPositioning::CPACSPositioning(CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_length(0)
        , m_sweepAngle(0)
        , m_dihedralAngle(0)
    {
    }
    
    CPACSPositioning::~CPACSPositioning()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
    }
    
    CTiglUIDManager& CPACSPositioning::GetUIDManager()
    {
        return *m_uidMgr;
    }
    
    const CTiglUIDManager& CPACSPositioning::GetUIDManager() const
    {
        return *m_uidMgr;
    }
    
    void CPACSPositioning::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read attribute uID
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
            m_uID = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            if (m_uID.empty()) {
                LOG(WARNING) << "Required attribute uID is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
        }
        
        // read element name
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/name")) {
            m_name = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
            if (m_name.empty()) {
                LOG(WARNING) << "Required element name is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element name is missing at xpath " << xpath;
        }
        
        // read element description
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
            m_description = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            if (m_description->empty()) {
                LOG(WARNING) << "Optional element description is present but empty at xpath " << xpath;
            }
        }
        
        // read element length
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/length")) {
            m_length = tixi::TixiGetElement<double>(tixiHandle, xpath + "/length");
        }
        else {
            LOG(ERROR) << "Required element length is missing at xpath " << xpath;
        }
        
        // read element sweepAngle
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/sweepAngle")) {
            m_sweepAngle = tixi::TixiGetElement<double>(tixiHandle, xpath + "/sweepAngle");
        }
        else {
            LOG(ERROR) << "Required element sweepAngle is missing at xpath " << xpath;
        }
        
        // read element dihedralAngle
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/dihedralAngle")) {
            m_dihedralAngle = tixi::TixiGetElement<double>(tixiHandle, xpath + "/dihedralAngle");
        }
        else {
            LOG(ERROR) << "Required element dihedralAngle is missing at xpath " << xpath;
        }
        
        // read element fromSectionUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/fromSectionUID")) {
            m_fromSectionUID = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/fromSectionUID");
            if (m_fromSectionUID->empty()) {
                LOG(WARNING) << "Optional element fromSectionUID is present but empty at xpath " << xpath;
            }
        }
        
        // read element toSectionUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/toSectionUID")) {
            m_toSectionUID = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/toSectionUID");
            if (m_toSectionUID.empty()) {
                LOG(WARNING) << "Required element toSectionUID is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element toSectionUID is missing at xpath " << xpath;
        }
        
        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }
    
    void CPACSPositioning::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);
        
        // write element name
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
        tixi::TixiSaveElement(tixiHandle, xpath + "/name", m_name);
        
        // write element description
        if (m_description) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
            tixi::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/description");
            }
        }
        
        // write element length
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/length");
        tixi::TixiSaveElement(tixiHandle, xpath + "/length", m_length);
        
        // write element sweepAngle
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/sweepAngle");
        tixi::TixiSaveElement(tixiHandle, xpath + "/sweepAngle", m_sweepAngle);
        
        // write element dihedralAngle
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/dihedralAngle");
        tixi::TixiSaveElement(tixiHandle, xpath + "/dihedralAngle", m_dihedralAngle);
        
        // write element fromSectionUID
        if (m_fromSectionUID) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/fromSectionUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/fromSectionUID", *m_fromSectionUID);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/fromSectionUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/fromSectionUID");
            }
        }
        
        // write element toSectionUID
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/toSectionUID");
        tixi::TixiSaveElement(tixiHandle, xpath + "/toSectionUID", m_toSectionUID);
        
    }
    
    const std::string& CPACSPositioning::GetUID() const
    {
        return m_uID;
    }
    
    void CPACSPositioning::SetUID(const std::string& value)
    {
        if (m_uidMgr) {
            m_uidMgr->TryUnregisterObject(m_uID);
            m_uidMgr->RegisterObject(value, *this);
        }
        m_uID = value;
    }
    
    const std::string& CPACSPositioning::GetName() const
    {
        return m_name;
    }
    
    void CPACSPositioning::SetName(const std::string& value)
    {
        m_name = value;
    }
    
    const boost::optional<std::string>& CPACSPositioning::GetDescription() const
    {
        return m_description;
    }
    
    void CPACSPositioning::SetDescription(const boost::optional<std::string>& value)
    {
        m_description = value;
    }
    
    const double& CPACSPositioning::GetLength() const
    {
        return m_length;
    }
    
    void CPACSPositioning::SetLength(const double& value)
    {
        m_length = value;
    }
    
    const double& CPACSPositioning::GetSweepAngle() const
    {
        return m_sweepAngle;
    }
    
    void CPACSPositioning::SetSweepAngle(const double& value)
    {
        m_sweepAngle = value;
    }
    
    const double& CPACSPositioning::GetDihedralAngle() const
    {
        return m_dihedralAngle;
    }
    
    void CPACSPositioning::SetDihedralAngle(const double& value)
    {
        m_dihedralAngle = value;
    }
    
    const boost::optional<std::string>& CPACSPositioning::GetFromSectionUID() const
    {
        return m_fromSectionUID;
    }
    
    void CPACSPositioning::SetFromSectionUID(const boost::optional<std::string>& value)
    {
        m_fromSectionUID = value;
    }
    
    const std::string& CPACSPositioning::GetToSectionUID() const
    {
        return m_toSectionUID;
    }
    
    void CPACSPositioning::SetToSectionUID(const std::string& value)
    {
        m_toSectionUID = value;
    }
    
} // namespace generated
} // namespace tigl
