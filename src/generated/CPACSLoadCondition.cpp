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
#include "CPACSLoadCondition.h"

namespace tigl
{
    namespace generated
    {
        CPACSLoadCondition::CPACSLoadCondition(){}
        CPACSLoadCondition::~CPACSLoadCondition() {}
        
        void CPACSLoadCondition::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element identifier
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/identifier")) {
                m_identifier = boost::in_place();
                try {
                    m_identifier->ReadCPACS(tixiHandle, xpath + "/identifier");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read identifier at xpath << " << xpath << ": " << e.what();
                    m_identifier = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read identifier at xpath << " << xpath << ": " << e.getError();
                    m_identifier = boost::none;
                }
            }
            
            // read element sizingType
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/sizingType")) {
                m_sizingType = boost::in_place();
                try {
                    m_sizingType->ReadCPACS(tixiHandle, xpath + "/sizingType");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read sizingType at xpath << " << xpath << ": " << e.what();
                    m_sizingType = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read sizingType at xpath << " << xpath << ": " << e.getError();
                    m_sizingType = boost::none;
                }
            }
            
            // read element safetyFactor
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/safetyFactor")) {
                m_safetyFactor = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/safetyFactor");
            }
            
            // read element designSpeed
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/designSpeed")) {
                m_designSpeed = boost::in_place();
                try {
                    m_designSpeed->ReadCPACS(tixiHandle, xpath + "/designSpeed");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read designSpeed at xpath << " << xpath << ": " << e.what();
                    m_designSpeed = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read designSpeed at xpath << " << xpath << ": " << e.getError();
                    m_designSpeed = boost::none;
                }
            }
            
            // read element additionalParameters
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/additionalParameters")) {
                m_additionalParameters = boost::in_place();
                try {
                    m_additionalParameters->ReadCPACS(tixiHandle, xpath + "/additionalParameters");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read additionalParameters at xpath << " << xpath << ": " << e.what();
                    m_additionalParameters = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read additionalParameters at xpath << " << xpath << ": " << e.getError();
                    m_additionalParameters = boost::none;
                }
            }
            
        }
        
        void CPACSLoadCondition::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element identifier
            if (m_identifier) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/identifier");
                m_identifier->WriteCPACS(tixiHandle, xpath + "/identifier");
            }
            
            // write element sizingType
            if (m_sizingType) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/sizingType");
                m_sizingType->WriteCPACS(tixiHandle, xpath + "/sizingType");
            }
            
            // write element safetyFactor
            if (m_safetyFactor) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/safetyFactor");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/safetyFactor", *m_safetyFactor);
            }
            
            // write element designSpeed
            if (m_designSpeed) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/designSpeed");
                m_designSpeed->WriteCPACS(tixiHandle, xpath + "/designSpeed");
            }
            
            // write element additionalParameters
            if (m_additionalParameters) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/additionalParameters");
                m_additionalParameters->WriteCPACS(tixiHandle, xpath + "/additionalParameters");
            }
            
        }
        
        bool CPACSLoadCondition::HasIdentifier() const
        {
            return static_cast<bool>(m_identifier);
        }
        
        const CPACSLoadCondition_identifier& CPACSLoadCondition::GetIdentifier() const
        {
            return *m_identifier;
        }
        
        CPACSLoadCondition_identifier& CPACSLoadCondition::GetIdentifier()
        {
            return *m_identifier;
        }
        
        bool CPACSLoadCondition::HasSizingType() const
        {
            return static_cast<bool>(m_sizingType);
        }
        
        const CPACSLoadCondition_sizingType& CPACSLoadCondition::GetSizingType() const
        {
            return *m_sizingType;
        }
        
        CPACSLoadCondition_sizingType& CPACSLoadCondition::GetSizingType()
        {
            return *m_sizingType;
        }
        
        bool CPACSLoadCondition::HasSafetyFactor() const
        {
            return static_cast<bool>(m_safetyFactor);
        }
        
        const double& CPACSLoadCondition::GetSafetyFactor() const
        {
            return *m_safetyFactor;
        }
        
        void CPACSLoadCondition::SetSafetyFactor(const double& value)
        {
            m_safetyFactor = value;
        }
        
        bool CPACSLoadCondition::HasDesignSpeed() const
        {
            return static_cast<bool>(m_designSpeed);
        }
        
        const CPACSLoadCondition_designSpeed& CPACSLoadCondition::GetDesignSpeed() const
        {
            return *m_designSpeed;
        }
        
        CPACSLoadCondition_designSpeed& CPACSLoadCondition::GetDesignSpeed()
        {
            return *m_designSpeed;
        }
        
        bool CPACSLoadCondition::HasAdditionalParameters() const
        {
            return static_cast<bool>(m_additionalParameters);
        }
        
        const CPACSAdditionalParameters& CPACSLoadCondition::GetAdditionalParameters() const
        {
            return *m_additionalParameters;
        }
        
        CPACSAdditionalParameters& CPACSLoadCondition::GetAdditionalParameters()
        {
            return *m_additionalParameters;
        }
        
    }
}
