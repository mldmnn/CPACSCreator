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

#include "CPACSPoint.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSPoint::CPACSPoint(CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr) {}
        
        CPACSPoint::~CPACSPoint()
        {
            if (m_uidMgr && m_uID) m_uidMgr->UnregisterObject(*m_uID);
        }
        
        void CPACSPoint::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            
            // read element x
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/x")) {
                m_x = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/x");
            }
            
            // read element y
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/y")) {
                m_y = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/y");
            }
            
            // read element z
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/z")) {
                m_z = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/z");
            }
            
            if (m_uidMgr && m_uID) m_uidMgr->RegisterObject(*m_uID, *this);
        }
        
        void CPACSPoint::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            if (m_uID) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uID");
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", *m_uID);
            }
            
            // write element x
            if (m_x) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/x");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/x", *m_x);
            }
            
            // write element y
            if (m_y) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/y");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/y", *m_y);
            }
            
            // write element z
            if (m_z) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/z");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/z", *m_z);
            }
            
        }
        
        const boost::optional<std::string>& CPACSPoint::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSPoint::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        void CPACSPoint::SetUID(const boost::optional<std::string>& value)
        {
            m_uID = value;
        }
        
        const boost::optional<double>& CPACSPoint::GetX() const
        {
            return m_x;
        }
        
        void CPACSPoint::SetX(const double& value)
        {
            m_x = value;
        }
        
        void CPACSPoint::SetX(const boost::optional<double>& value)
        {
            m_x = value;
        }
        
        const boost::optional<double>& CPACSPoint::GetY() const
        {
            return m_y;
        }
        
        void CPACSPoint::SetY(const double& value)
        {
            m_y = value;
        }
        
        void CPACSPoint::SetY(const boost::optional<double>& value)
        {
            m_y = value;
        }
        
        const boost::optional<double>& CPACSPoint::GetZ() const
        {
            return m_z;
        }
        
        void CPACSPoint::SetZ(const double& value)
        {
            m_z = value;
        }
        
        void CPACSPoint::SetZ(const boost::optional<double>& value)
        {
            m_z = value;
        }
        
    }
}
