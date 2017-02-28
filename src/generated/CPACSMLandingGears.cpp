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
#include "CPACSMLandingGears.h"

namespace tigl
{
    namespace generated
    {
        CPACSMLandingGears::CPACSMLandingGears(){}
        CPACSMLandingGears::~CPACSMLandingGears() {}
        
        void CPACSMLandingGears::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element massDescription
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/massDescription")) {
                m_massDescription.ReadCPACS(tixiHandle, xpath + "/massDescription");
            }
            else {
                LOG(ERROR) << "Required element massDescription is missing";
            }
            
            // read element mNoseGears
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mNoseGears")) {
                m_mNoseGears = boost::in_place();
                try {
                    m_mNoseGears->ReadCPACS(tixiHandle, xpath + "/mNoseGears");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mNoseGears at xpath << " << xpath << ": " << e.what();
                    m_mNoseGears = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mNoseGears at xpath << " << xpath << ": " << e.getError();
                    m_mNoseGears = boost::none;
                }
            }
            
            // read element mMainGears
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mMainGears")) {
                m_mMainGears = boost::in_place();
                try {
                    m_mMainGears->ReadCPACS(tixiHandle, xpath + "/mMainGears");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mMainGears at xpath << " << xpath << ": " << e.what();
                    m_mMainGears = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mMainGears at xpath << " << xpath << ": " << e.getError();
                    m_mMainGears = boost::none;
                }
            }
            
        }
        
        void CPACSMLandingGears::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element massDescription
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/massDescription");
            m_massDescription.WriteCPACS(tixiHandle, xpath + "/massDescription");
            
            // write element mNoseGears
            if (m_mNoseGears) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mNoseGears");
                m_mNoseGears->WriteCPACS(tixiHandle, xpath + "/mNoseGears");
            }
            
            // write element mMainGears
            if (m_mMainGears) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mMainGears");
                m_mMainGears->WriteCPACS(tixiHandle, xpath + "/mMainGears");
            }
            
        }
        
        const CPACSGenericMass& CPACSMLandingGears::GetMassDescription() const
        {
            return m_massDescription;
        }
        
        CPACSGenericMass& CPACSMLandingGears::GetMassDescription()
        {
            return m_massDescription;
        }
        
        bool CPACSMLandingGears::HasMNoseGears() const
        {
            return static_cast<bool>(m_mNoseGears);
        }
        
        const CPACSMNoseGears& CPACSMLandingGears::GetMNoseGears() const
        {
            return *m_mNoseGears;
        }
        
        CPACSMNoseGears& CPACSMLandingGears::GetMNoseGears()
        {
            return *m_mNoseGears;
        }
        
        bool CPACSMLandingGears::HasMMainGears() const
        {
            return static_cast<bool>(m_mMainGears);
        }
        
        const CPACSMMainGears& CPACSMLandingGears::GetMMainGears() const
        {
            return *m_mMainGears;
        }
        
        CPACSMMainGears& CPACSMLandingGears::GetMMainGears()
        {
            return *m_mMainGears;
        }
        
    }
}
