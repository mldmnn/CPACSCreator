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
#include "CPACSStructuralProfile3D.h"

namespace tigl
{
    namespace generated
    {
        CPACSStructuralProfile3D::CPACSStructuralProfile3D(){}
        CPACSStructuralProfile3D::~CPACSStructuralProfile3D() {}
        
        void CPACSStructuralProfile3D::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
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
            
            // read element pointList
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/pointList")) {
                m_pointList.ReadCPACS(tixiHandle, xpath + "/pointList");
            }
            else {
                LOG(ERROR) << "Required element pointList is missing";
            }
            
            // read element sheetList3D
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/sheetList3D")) {
                m_sheetList3D.ReadCPACS(tixiHandle, xpath + "/sheetList3D");
            }
            else {
                LOG(ERROR) << "Required element sheetList3D is missing";
            }
            
        }
        
        void CPACSStructuralProfile3D::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
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
            
            // write element pointList
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/pointList");
            m_pointList.WriteCPACS(tixiHandle, xpath + "/pointList");
            
            // write element sheetList3D
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/sheetList3D");
            m_sheetList3D.WriteCPACS(tixiHandle, xpath + "/sheetList3D");
            
        }
        
        const std::string& CPACSStructuralProfile3D::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSStructuralProfile3D::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        const std::string& CPACSStructuralProfile3D::GetName() const
        {
            return m_name;
        }
        
        void CPACSStructuralProfile3D::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        bool CPACSStructuralProfile3D::HasDescription() const
        {
            return static_cast<bool>(m_description);
        }
        
        const std::string& CPACSStructuralProfile3D::GetDescription() const
        {
            return *m_description;
        }
        
        void CPACSStructuralProfile3D::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        const CPACSPointList& CPACSStructuralProfile3D::GetPointList() const
        {
            return m_pointList;
        }
        
        CPACSPointList& CPACSStructuralProfile3D::GetPointList()
        {
            return m_pointList;
        }
        
        const CPACSSheetList3D& CPACSStructuralProfile3D::GetSheetList3D() const
        {
            return m_sheetList3D;
        }
        
        CPACSSheetList3D& CPACSStructuralProfile3D::GetSheetList3D()
        {
            return m_sheetList3D;
        }
        
    }
}
