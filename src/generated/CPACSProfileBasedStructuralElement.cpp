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

#include "CPACSMaterialDefinitionForProfileBased.h"
#include "CPACSMaterialDefinitionForProfileBasedPoint.h"
#include "CPACSMaterialDefinitionForProfileBased.h"
#include "TixiHelper.h"
#include "CTiglLogging.h"
#include "CTiglError.h"
#include "CPACSProfileBasedStructuralElement.h"

namespace tigl
{
    namespace generated
    {
        CPACSProfileBasedStructuralElement::CPACSProfileBasedStructuralElement(){}
        CPACSProfileBasedStructuralElement::~CPACSProfileBasedStructuralElement() {}
        
        void CPACSProfileBasedStructuralElement::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
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
            
            // read element description
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/description")) {
                m_description = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            }
            
            // read element transformation
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/transformation")) {
                m_transformation = boost::in_place();
                try {
                    m_transformation->ReadCPACS(tixiHandle, xpath + "/transformation");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read transformation at xpath << " << xpath << ": " << e.what();
                    m_transformation = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read transformation at xpath << " << xpath << ": " << e.getError();
                    m_transformation = boost::none;
                }
            }
            
            // read element globalBeamProperties
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/globalBeamProperties")) {
                m_globalBeamProperties = boost::in_place();
                try {
                    m_globalBeamProperties->ReadCPACS(tixiHandle, xpath + "/globalBeamProperties");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read globalBeamProperties at xpath << " << xpath << ": " << e.what();
                    m_globalBeamProperties = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read globalBeamProperties at xpath << " << xpath << ": " << e.getError();
                    m_globalBeamProperties = boost::none;
                }
            }
            
            // read element structuralProfileUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/structuralProfileUID")) {
                m_structuralProfileUID_choice1 = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/structuralProfileUID");
            }
            
            // read element sheetProperties
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/sheetProperties")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/sheetProperties", m_sheetProperties_choice1);
            }
            
            // read element pointProperties
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/pointProperties")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/pointProperties", m_pointProperties_choice1);
            }
            
            // read element referencePointUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/referencePointUID")) {
                m_referencePointUID_choice1 = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/referencePointUID");
            }
            
            // read element standardProfileType
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/standardProfileType")) {
                m_standardProfileType_choice2 = boost::in_place();
                try {
                    m_standardProfileType_choice2->ReadCPACS(tixiHandle, xpath + "/standardProfileType");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read standardProfileType at xpath << " << xpath << ": " << e.what();
                    m_standardProfileType_choice2 = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read standardProfileType at xpath << " << xpath << ": " << e.getError();
                    m_standardProfileType_choice2 = boost::none;
                }
            }
            
            // read element sheetProperties
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/sheetProperties")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/sheetProperties", m_sheetProperties_choice2);
            }
            
        }
        
        void CPACSProfileBasedStructuralElement::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uID");
            tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);
            
            // write element name
            if (m_name) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/name", *m_name);
            }
            
            // write element description
            if (m_description) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
            }
            
            // write element transformation
            if (m_transformation) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/transformation");
                m_transformation->WriteCPACS(tixiHandle, xpath + "/transformation");
            }
            
            // write element globalBeamProperties
            if (m_globalBeamProperties) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/globalBeamProperties");
                m_globalBeamProperties->WriteCPACS(tixiHandle, xpath + "/globalBeamProperties");
            }
            
            // write element structuralProfileUID
            if (m_structuralProfileUID_choice1) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/structuralProfileUID");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/structuralProfileUID", *m_structuralProfileUID_choice1);
            }
            
            // write element sheetProperties
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/sheetProperties", m_sheetProperties_choice1);
            
            // write element pointProperties
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/pointProperties", m_pointProperties_choice1);
            
            // write element referencePointUID
            if (m_referencePointUID_choice1) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/referencePointUID");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/referencePointUID", *m_referencePointUID_choice1);
            }
            
            // write element standardProfileType
            if (m_standardProfileType_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/standardProfileType");
                m_standardProfileType_choice2->WriteCPACS(tixiHandle, xpath + "/standardProfileType");
            }
            
            // write element sheetProperties
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/sheetProperties", m_sheetProperties_choice2);
            
        }
        
        const std::string& CPACSProfileBasedStructuralElement::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSProfileBasedStructuralElement::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        bool CPACSProfileBasedStructuralElement::HasName() const
        {
            return static_cast<bool>(m_name);
        }
        
        const std::string& CPACSProfileBasedStructuralElement::GetName() const
        {
            return *m_name;
        }
        
        void CPACSProfileBasedStructuralElement::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        bool CPACSProfileBasedStructuralElement::HasDescription() const
        {
            return static_cast<bool>(m_description);
        }
        
        const std::string& CPACSProfileBasedStructuralElement::GetDescription() const
        {
            return *m_description;
        }
        
        void CPACSProfileBasedStructuralElement::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        bool CPACSProfileBasedStructuralElement::HasTransformation() const
        {
            return static_cast<bool>(m_transformation);
        }
        
        const CPACSTransformation2D& CPACSProfileBasedStructuralElement::GetTransformation() const
        {
            return *m_transformation;
        }
        
        CPACSTransformation2D& CPACSProfileBasedStructuralElement::GetTransformation()
        {
            return *m_transformation;
        }
        
        bool CPACSProfileBasedStructuralElement::HasGlobalBeamProperties() const
        {
            return static_cast<bool>(m_globalBeamProperties);
        }
        
        const CPACSGlobalBeamProperties& CPACSProfileBasedStructuralElement::GetGlobalBeamProperties() const
        {
            return *m_globalBeamProperties;
        }
        
        CPACSGlobalBeamProperties& CPACSProfileBasedStructuralElement::GetGlobalBeamProperties()
        {
            return *m_globalBeamProperties;
        }
        
        bool CPACSProfileBasedStructuralElement::HasStructuralProfileUID_choice1() const
        {
            return static_cast<bool>(m_structuralProfileUID_choice1);
        }
        
        const std::string& CPACSProfileBasedStructuralElement::GetStructuralProfileUID_choice1() const
        {
            return *m_structuralProfileUID_choice1;
        }
        
        void CPACSProfileBasedStructuralElement::SetStructuralProfileUID_choice1(const std::string& value)
        {
            m_structuralProfileUID_choice1 = value;
        }
        
        const std::vector<unique_ptr<CPACSMaterialDefinitionForProfileBased>>& CPACSProfileBasedStructuralElement::GetSheetProperties_choice1() const
        {
            return m_sheetProperties_choice1;
        }
        
        std::vector<unique_ptr<CPACSMaterialDefinitionForProfileBased>>& CPACSProfileBasedStructuralElement::GetSheetProperties_choice1()
        {
            return m_sheetProperties_choice1;
        }
        
        const std::vector<unique_ptr<CPACSMaterialDefinitionForProfileBasedPoint>>& CPACSProfileBasedStructuralElement::GetPointProperties_choice1() const
        {
            return m_pointProperties_choice1;
        }
        
        std::vector<unique_ptr<CPACSMaterialDefinitionForProfileBasedPoint>>& CPACSProfileBasedStructuralElement::GetPointProperties_choice1()
        {
            return m_pointProperties_choice1;
        }
        
        bool CPACSProfileBasedStructuralElement::HasReferencePointUID_choice1() const
        {
            return static_cast<bool>(m_referencePointUID_choice1);
        }
        
        const std::string& CPACSProfileBasedStructuralElement::GetReferencePointUID_choice1() const
        {
            return *m_referencePointUID_choice1;
        }
        
        void CPACSProfileBasedStructuralElement::SetReferencePointUID_choice1(const std::string& value)
        {
            m_referencePointUID_choice1 = value;
        }
        
        bool CPACSProfileBasedStructuralElement::HasStandardProfileType_choice2() const
        {
            return static_cast<bool>(m_standardProfileType_choice2);
        }
        
        const CPACSProfileBasedStructuralElement_standardProfileType& CPACSProfileBasedStructuralElement::GetStandardProfileType_choice2() const
        {
            return *m_standardProfileType_choice2;
        }
        
        CPACSProfileBasedStructuralElement_standardProfileType& CPACSProfileBasedStructuralElement::GetStandardProfileType_choice2()
        {
            return *m_standardProfileType_choice2;
        }
        
        const std::vector<unique_ptr<CPACSMaterialDefinitionForProfileBased>>& CPACSProfileBasedStructuralElement::GetSheetProperties_choice2() const
        {
            return m_sheetProperties_choice2;
        }
        
        std::vector<unique_ptr<CPACSMaterialDefinitionForProfileBased>>& CPACSProfileBasedStructuralElement::GetSheetProperties_choice2()
        {
            return m_sheetProperties_choice2;
        }
        
    }
}
