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

#include "CPACSProfileGeometry.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSProfileGeometry::CPACSProfileGeometry(){}
        CPACSProfileGeometry::~CPACSProfileGeometry() {}
        
        void CPACSProfileGeometry::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute symmetry
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "symmetry")) {
                m_symmetry = stringToTiglSymmetryAxis(tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "symmetry"));
            }
            
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            else {
                LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
            }
            
            // read element name
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/name")) {
                m_name = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
            }
            else {
                LOG(ERROR) << "Required element name is missing at xpath " << xpath;
            }
            
            // read element description
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/description")) {
                m_description = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            }
            
            // read element pointList
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/pointList")) {
                m_pointList_choice1 = boost::in_place();
                try {
                    m_pointList_choice1->ReadCPACS(tixiHandle, xpath + "/pointList");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read pointList at xpath << " << xpath << ": " << e.what();
                    m_pointList_choice1 = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read pointList at xpath << " << xpath << ": " << e.getError();
                    m_pointList_choice1 = boost::none;
                }
            }
            
            // read element cst2D
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/cst2D")) {
                m_cst2D_choice2 = boost::in_place();
                try {
                    m_cst2D_choice2->ReadCPACS(tixiHandle, xpath + "/cst2D");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read cst2D at xpath << " << xpath << ": " << e.what();
                    m_cst2D_choice2 = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read cst2D at xpath << " << xpath << ": " << e.getError();
                    m_cst2D_choice2 = boost::none;
                }
            }
            
        }
        
        void CPACSProfileGeometry::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute symmetry
            if (m_symmetry) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/symmetry");
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "symmetry", TiglSymmetryAxisToString(*m_symmetry));
            }
            
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
            if (m_pointList_choice1) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/pointList");
                m_pointList_choice1->WriteCPACS(tixiHandle, xpath + "/pointList");
            }
            
            // write element cst2D
            if (m_cst2D_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/cst2D");
                m_cst2D_choice2->WriteCPACS(tixiHandle, xpath + "/cst2D");
            }
            
        }
        
        const boost::optional<TiglSymmetryAxis>& CPACSProfileGeometry::GetSymmetry() const
        {
            return m_symmetry;
        }
        
        void CPACSProfileGeometry::SetSymmetry(const TiglSymmetryAxis& value)
        {
            m_symmetry = value;
        }
        
        void CPACSProfileGeometry::SetSymmetry(const boost::optional<TiglSymmetryAxis>& value)
        {
            m_symmetry = value;
        }
        
        const std::string& CPACSProfileGeometry::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSProfileGeometry::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        const std::string& CPACSProfileGeometry::GetName() const
        {
            return m_name;
        }
        
        void CPACSProfileGeometry::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        const boost::optional<std::string>& CPACSProfileGeometry::GetDescription() const
        {
            return m_description;
        }
        
        void CPACSProfileGeometry::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        void CPACSProfileGeometry::SetDescription(const boost::optional<std::string>& value)
        {
            m_description = value;
        }
        
        const boost::optional<CCPACSPointListXYZ>& CPACSProfileGeometry::GetPointList_choice1() const
        {
            return m_pointList_choice1;
        }
        
        boost::optional<CCPACSPointListXYZ>& CPACSProfileGeometry::GetPointList_choice1()
        {
            return m_pointList_choice1;
        }
        
        const boost::optional<CCPACSWingProfileCST>& CPACSProfileGeometry::GetCst2D_choice2() const
        {
            return m_cst2D_choice2;
        }
        
        boost::optional<CCPACSWingProfileCST>& CPACSProfileGeometry::GetCst2D_choice2()
        {
            return m_cst2D_choice2;
        }
        
    }
}
