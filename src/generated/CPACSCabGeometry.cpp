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
#include "CPACSCabGeometry.h"

namespace tigl
{
    namespace generated
    {
        CPACSCabGeometry::CPACSCabGeometry(){}
        CPACSCabGeometry::~CPACSCabGeometry() {}
        
        void CPACSCabGeometry::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            else {
                LOG(ERROR) << "Required attribute uID is missing";
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
            
            // read element x
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/x")) {
                m_x.ReadCPACS(tixiHandle, xpath + "/x");
            }
            else {
                LOG(ERROR) << "Required element x is missing";
            }
            
            // read element z
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/z")) {
                m_z.ReadCPACS(tixiHandle, xpath + "/z");
            }
            else {
                LOG(ERROR) << "Required element z is missing";
            }
            
            // read element y
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/y")) {
                m_y.ReadCPACS(tixiHandle, xpath + "/y");
            }
            else {
                LOG(ERROR) << "Required element y is missing";
            }
            
        }
        
        void CPACSCabGeometry::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uID");
            tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);
            
            // write element name
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/name", m_name);
            
            // write element description
            if (m_description) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
            }
            
            // write element x
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/x");
            m_x.WriteCPACS(tixiHandle, xpath + "/x");
            
            // write element z
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/z");
            m_z.WriteCPACS(tixiHandle, xpath + "/z");
            
            // write element y
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/y");
            m_y.WriteCPACS(tixiHandle, xpath + "/y");
            
        }
        
        const std::string& CPACSCabGeometry::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSCabGeometry::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        const std::string& CPACSCabGeometry::GetName() const
        {
            return m_name;
        }
        
        void CPACSCabGeometry::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        bool CPACSCabGeometry::HasDescription() const
        {
            return static_cast<bool>(m_description);
        }
        
        const std::string& CPACSCabGeometry::GetDescription() const
        {
            return *m_description;
        }
        
        void CPACSCabGeometry::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        const CCPACSStringVector& CPACSCabGeometry::GetX() const
        {
            return m_x;
        }
        
        CCPACSStringVector& CPACSCabGeometry::GetX()
        {
            return m_x;
        }
        
        const CCPACSStringVector& CPACSCabGeometry::GetZ() const
        {
            return m_z;
        }
        
        CCPACSStringVector& CPACSCabGeometry::GetZ()
        {
            return m_z;
        }
        
        const CPACSStringArrayBase& CPACSCabGeometry::GetY() const
        {
            return m_y;
        }
        
        CPACSStringArrayBase& CPACSCabGeometry::GetY()
        {
            return m_y;
        }
        
    }
}
