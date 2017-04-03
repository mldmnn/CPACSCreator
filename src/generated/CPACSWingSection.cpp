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

#include "CPACSWingSection.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSWingSection::CPACSWingSection(){}
        CPACSWingSection::~CPACSWingSection() {}
        
        void CPACSWingSection::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
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
            
            // read element transformation
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/transformation")) {
                m_transformation.ReadCPACS(tixiHandle, xpath + "/transformation");
            }
            else {
                LOG(ERROR) << "Required element transformation is missing at xpath " << xpath;
            }
            
            // read element elements
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/elements")) {
                m_elements.ReadCPACS(tixiHandle, xpath + "/elements");
            }
            else {
                LOG(ERROR) << "Required element elements is missing at xpath " << xpath;
            }
            
        }
        
        void CPACSWingSection::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
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
            
            // write element transformation
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/transformation");
            m_transformation.WriteCPACS(tixiHandle, xpath + "/transformation");
            
            // write element elements
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/elements");
            m_elements.WriteCPACS(tixiHandle, xpath + "/elements");
            
        }
        
        const std::string& CPACSWingSection::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSWingSection::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        const std::string& CPACSWingSection::GetName() const
        {
            return m_name;
        }
        
        void CPACSWingSection::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        const boost::optional<std::string>& CPACSWingSection::GetDescription() const
        {
            return m_description;
        }
        
        void CPACSWingSection::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        void CPACSWingSection::SetDescription(const boost::optional<std::string>& value)
        {
            m_description = value;
        }
        
        const CCPACSTransformation& CPACSWingSection::GetTransformation() const
        {
            return m_transformation;
        }
        
        CCPACSTransformation& CPACSWingSection::GetTransformation()
        {
            return m_transformation;
        }
        
        const CCPACSWingSectionElements& CPACSWingSection::GetElements() const
        {
            return m_elements;
        }
        
        CCPACSWingSectionElements& CPACSWingSection::GetElements()
        {
            return m_elements;
        }
        
    }
}
