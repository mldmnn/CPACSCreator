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
#include "CPACSLoadCases.h"

namespace tigl
{
    namespace generated
    {
        CPACSLoadCases::CPACSLoadCases(){}
        CPACSLoadCases::~CPACSLoadCases() {}
        
        void CPACSLoadCases::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element crashLoadCases
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/crashLoadCases")) {
                m_crashLoadCases = boost::in_place();
                try {
                    m_crashLoadCases->ReadCPACS(tixiHandle, xpath + "/crashLoadCases");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read crashLoadCases at xpath << " << xpath << ": " << e.what();
                    m_crashLoadCases = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read crashLoadCases at xpath << " << xpath << ": " << e.getError();
                    m_crashLoadCases = boost::none;
                }
            }
            
            // read element flightLoadCases
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/flightLoadCases")) {
                m_flightLoadCases = boost::in_place();
                try {
                    m_flightLoadCases->ReadCPACS(tixiHandle, xpath + "/flightLoadCases");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read flightLoadCases at xpath << " << xpath << ": " << e.what();
                    m_flightLoadCases = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read flightLoadCases at xpath << " << xpath << ": " << e.getError();
                    m_flightLoadCases = boost::none;
                }
            }
            
            // read element groundLoadCases
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/groundLoadCases")) {
                m_groundLoadCases = boost::in_place();
                try {
                    m_groundLoadCases->ReadCPACS(tixiHandle, xpath + "/groundLoadCases");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read groundLoadCases at xpath << " << xpath << ": " << e.what();
                    m_groundLoadCases = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read groundLoadCases at xpath << " << xpath << ": " << e.getError();
                    m_groundLoadCases = boost::none;
                }
            }
            
            // read element aeroDataSetsForLoads
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/aeroDataSetsForLoads")) {
                m_aeroDataSetsForLoads = boost::in_place();
                try {
                    m_aeroDataSetsForLoads->ReadCPACS(tixiHandle, xpath + "/aeroDataSetsForLoads");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read aeroDataSetsForLoads at xpath << " << xpath << ": " << e.what();
                    m_aeroDataSetsForLoads = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read aeroDataSetsForLoads at xpath << " << xpath << ": " << e.getError();
                    m_aeroDataSetsForLoads = boost::none;
                }
            }
            
            // read element loadsEnvelope
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/loadsEnvelope")) {
                m_loadsEnvelope = boost::in_place();
                try {
                    m_loadsEnvelope->ReadCPACS(tixiHandle, xpath + "/loadsEnvelope");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read loadsEnvelope at xpath << " << xpath << ": " << e.what();
                    m_loadsEnvelope = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read loadsEnvelope at xpath << " << xpath << ": " << e.getError();
                    m_loadsEnvelope = boost::none;
                }
            }
            
        }
        
        void CPACSLoadCases::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element crashLoadCases
            if (m_crashLoadCases) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/crashLoadCases");
                m_crashLoadCases->WriteCPACS(tixiHandle, xpath + "/crashLoadCases");
            }
            
            // write element flightLoadCases
            if (m_flightLoadCases) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/flightLoadCases");
                m_flightLoadCases->WriteCPACS(tixiHandle, xpath + "/flightLoadCases");
            }
            
            // write element groundLoadCases
            if (m_groundLoadCases) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/groundLoadCases");
                m_groundLoadCases->WriteCPACS(tixiHandle, xpath + "/groundLoadCases");
            }
            
            // write element aeroDataSetsForLoads
            if (m_aeroDataSetsForLoads) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/aeroDataSetsForLoads");
                m_aeroDataSetsForLoads->WriteCPACS(tixiHandle, xpath + "/aeroDataSetsForLoads");
            }
            
            // write element loadsEnvelope
            if (m_loadsEnvelope) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/loadsEnvelope");
                m_loadsEnvelope->WriteCPACS(tixiHandle, xpath + "/loadsEnvelope");
            }
            
        }
        
        bool CPACSLoadCases::HasCrashLoadCases() const
        {
            return static_cast<bool>(m_crashLoadCases);
        }
        
        const CPACSCrashLoadCases& CPACSLoadCases::GetCrashLoadCases() const
        {
            return *m_crashLoadCases;
        }
        
        CPACSCrashLoadCases& CPACSLoadCases::GetCrashLoadCases()
        {
            return *m_crashLoadCases;
        }
        
        bool CPACSLoadCases::HasFlightLoadCases() const
        {
            return static_cast<bool>(m_flightLoadCases);
        }
        
        const CPACSFlightLoadCases& CPACSLoadCases::GetFlightLoadCases() const
        {
            return *m_flightLoadCases;
        }
        
        CPACSFlightLoadCases& CPACSLoadCases::GetFlightLoadCases()
        {
            return *m_flightLoadCases;
        }
        
        bool CPACSLoadCases::HasGroundLoadCases() const
        {
            return static_cast<bool>(m_groundLoadCases);
        }
        
        const CPACSGroundLoadCases& CPACSLoadCases::GetGroundLoadCases() const
        {
            return *m_groundLoadCases;
        }
        
        CPACSGroundLoadCases& CPACSLoadCases::GetGroundLoadCases()
        {
            return *m_groundLoadCases;
        }
        
        bool CPACSLoadCases::HasAeroDataSetsForLoads() const
        {
            return static_cast<bool>(m_aeroDataSetsForLoads);
        }
        
        const CPACSAeroDataSetsForLoads& CPACSLoadCases::GetAeroDataSetsForLoads() const
        {
            return *m_aeroDataSetsForLoads;
        }
        
        CPACSAeroDataSetsForLoads& CPACSLoadCases::GetAeroDataSetsForLoads()
        {
            return *m_aeroDataSetsForLoads;
        }
        
        bool CPACSLoadCases::HasLoadsEnvelope() const
        {
            return static_cast<bool>(m_loadsEnvelope);
        }
        
        const CPACSLoadsEnvelope& CPACSLoadCases::GetLoadsEnvelope() const
        {
            return *m_loadsEnvelope;
        }
        
        CPACSLoadsEnvelope& CPACSLoadCases::GetLoadsEnvelope()
        {
            return *m_loadsEnvelope;
        }
        
    }
}
