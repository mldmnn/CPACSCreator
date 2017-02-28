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
#include "CPACSSBotPlusTool.h"

namespace tigl
{
    namespace generated
    {
        CPACSSBotPlusTool::CPACSSBotPlusTool(){}
        CPACSSBotPlusTool::~CPACSSBotPlusTool() {}
        
        void CPACSSBotPlusTool::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element tool
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/tool")) {
                m_tool.ReadCPACS(tixiHandle, xpath + "/tool");
            }
            else {
                LOG(ERROR) << "Required element tool is missing";
            }
            
            // read element calcCsPropsFuselage
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/calcCsPropsFuselage")) {
                m_calcCsPropsFuselage = tixihelper::TixiGetElement<bool>(tixiHandle, xpath + "/calcCsPropsFuselage");
            }
            else {
                LOG(ERROR) << "Required element calcCsPropsFuselage is missing";
            }
            
            // read element createEtables
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/createEtables")) {
                m_createEtables = tixihelper::TixiGetElement<bool>(tixiHandle, xpath + "/createEtables");
            }
            else {
                LOG(ERROR) << "Required element createEtables is missing";
            }
            
            // read element optimizationControl
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/optimizationControl")) {
                m_optimizationControl.ReadCPACS(tixiHandle, xpath + "/optimizationControl");
            }
            else {
                LOG(ERROR) << "Required element optimizationControl is missing";
            }
            
            // read element sizingCriterionParameters
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/sizingCriterionParameters")) {
                m_sizingCriterionParameters = boost::in_place();
                try {
                    m_sizingCriterionParameters->ReadCPACS(tixiHandle, xpath + "/sizingCriterionParameters");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read sizingCriterionParameters at xpath << " << xpath << ": " << e.what();
                    m_sizingCriterionParameters = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read sizingCriterionParameters at xpath << " << xpath << ": " << e.getError();
                    m_sizingCriterionParameters = boost::none;
                }
            }
            
        }
        
        void CPACSSBotPlusTool::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element tool
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/tool");
            m_tool.WriteCPACS(tixiHandle, xpath + "/tool");
            
            // write element calcCsPropsFuselage
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/calcCsPropsFuselage");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/calcCsPropsFuselage", m_calcCsPropsFuselage);
            
            // write element createEtables
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/createEtables");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/createEtables", m_createEtables);
            
            // write element optimizationControl
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/optimizationControl");
            m_optimizationControl.WriteCPACS(tixiHandle, xpath + "/optimizationControl");
            
            // write element sizingCriterionParameters
            if (m_sizingCriterionParameters) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/sizingCriterionParameters");
                m_sizingCriterionParameters->WriteCPACS(tixiHandle, xpath + "/sizingCriterionParameters");
            }
            
        }
        
        const CPACSTool& CPACSSBotPlusTool::GetTool() const
        {
            return m_tool;
        }
        
        CPACSTool& CPACSSBotPlusTool::GetTool()
        {
            return m_tool;
        }
        
        const bool& CPACSSBotPlusTool::GetCalcCsPropsFuselage() const
        {
            return m_calcCsPropsFuselage;
        }
        
        void CPACSSBotPlusTool::SetCalcCsPropsFuselage(const bool& value)
        {
            m_calcCsPropsFuselage = value;
        }
        
        const bool& CPACSSBotPlusTool::GetCreateEtables() const
        {
            return m_createEtables;
        }
        
        void CPACSSBotPlusTool::SetCreateEtables(const bool& value)
        {
            m_createEtables = value;
        }
        
        const CPACSSBotOptimizationControl& CPACSSBotPlusTool::GetOptimizationControl() const
        {
            return m_optimizationControl;
        }
        
        CPACSSBotOptimizationControl& CPACSSBotPlusTool::GetOptimizationControl()
        {
            return m_optimizationControl;
        }
        
        bool CPACSSBotPlusTool::HasSizingCriterionParameters() const
        {
            return static_cast<bool>(m_sizingCriterionParameters);
        }
        
        const CPACSSBotSizingCriteriaParameter& CPACSSBotPlusTool::GetSizingCriterionParameters() const
        {
            return *m_sizingCriterionParameters;
        }
        
        CPACSSBotSizingCriteriaParameter& CPACSSBotPlusTool::GetSizingCriterionParameters()
        {
            return *m_sizingCriterionParameters;
        }
        
    }
}
