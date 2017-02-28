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
#include "CPACSMSystems.h"

namespace tigl
{
    namespace generated
    {
        CPACSMSystems::CPACSMSystems(){}
        CPACSMSystems::~CPACSMSystems() {}
        
        void CPACSMSystems::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element massDescription
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/massDescription")) {
                m_massDescription.ReadCPACS(tixiHandle, xpath + "/massDescription");
            }
            else {
                LOG(ERROR) << "Required element massDescription is missing";
            }
            
            // read element mAuxillaryPowerUnit
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mAuxillaryPowerUnit")) {
                m_mAuxillaryPowerUnit = boost::in_place();
                try {
                    m_mAuxillaryPowerUnit->ReadCPACS(tixiHandle, xpath + "/mAuxillaryPowerUnit");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mAuxillaryPowerUnit at xpath << " << xpath << ": " << e.what();
                    m_mAuxillaryPowerUnit = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mAuxillaryPowerUnit at xpath << " << xpath << ": " << e.getError();
                    m_mAuxillaryPowerUnit = boost::none;
                }
            }
            
            // read element mHydraulicGeneration
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mHydraulicGeneration")) {
                m_mHydraulicGeneration = boost::in_place();
                try {
                    m_mHydraulicGeneration->ReadCPACS(tixiHandle, xpath + "/mHydraulicGeneration");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mHydraulicGeneration at xpath << " << xpath << ": " << e.what();
                    m_mHydraulicGeneration = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mHydraulicGeneration at xpath << " << xpath << ": " << e.getError();
                    m_mHydraulicGeneration = boost::none;
                }
            }
            
            // read element mHydraulicDistribution
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mHydraulicDistribution")) {
                m_mHydraulicDistribution = boost::in_place();
                try {
                    m_mHydraulicDistribution->ReadCPACS(tixiHandle, xpath + "/mHydraulicDistribution");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mHydraulicDistribution at xpath << " << xpath << ": " << e.what();
                    m_mHydraulicDistribution = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mHydraulicDistribution at xpath << " << xpath << ": " << e.getError();
                    m_mHydraulicDistribution = boost::none;
                }
            }
            
            // read element mAirConditioning
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mAirConditioning")) {
                m_mAirConditioning = boost::in_place();
                try {
                    m_mAirConditioning->ReadCPACS(tixiHandle, xpath + "/mAirConditioning");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mAirConditioning at xpath << " << xpath << ": " << e.what();
                    m_mAirConditioning = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mAirConditioning at xpath << " << xpath << ": " << e.getError();
                    m_mAirConditioning = boost::none;
                }
            }
            
            // read element mDeIcing
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mDeIcing")) {
                m_mDeIcing = boost::in_place();
                try {
                    m_mDeIcing->ReadCPACS(tixiHandle, xpath + "/mDeIcing");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mDeIcing at xpath << " << xpath << ": " << e.what();
                    m_mDeIcing = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mDeIcing at xpath << " << xpath << ": " << e.getError();
                    m_mDeIcing = boost::none;
                }
            }
            
            // read element mFireProtection
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mFireProtection")) {
                m_mFireProtection = boost::in_place();
                try {
                    m_mFireProtection->ReadCPACS(tixiHandle, xpath + "/mFireProtection");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mFireProtection at xpath << " << xpath << ": " << e.what();
                    m_mFireProtection = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mFireProtection at xpath << " << xpath << ": " << e.getError();
                    m_mFireProtection = boost::none;
                }
            }
            
            // read element mFlightControls
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mFlightControls")) {
                m_mFlightControls = boost::in_place();
                try {
                    m_mFlightControls->ReadCPACS(tixiHandle, xpath + "/mFlightControls");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mFlightControls at xpath << " << xpath << ": " << e.what();
                    m_mFlightControls = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mFlightControls at xpath << " << xpath << ": " << e.getError();
                    m_mFlightControls = boost::none;
                }
            }
            
            // read element mInstrumentPanel
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mInstrumentPanel")) {
                m_mInstrumentPanel = boost::in_place();
                try {
                    m_mInstrumentPanel->ReadCPACS(tixiHandle, xpath + "/mInstrumentPanel");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mInstrumentPanel at xpath << " << xpath << ": " << e.what();
                    m_mInstrumentPanel = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mInstrumentPanel at xpath << " << xpath << ": " << e.getError();
                    m_mInstrumentPanel = boost::none;
                }
            }
            
            // read element mAutomaticFlightSystem
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mAutomaticFlightSystem")) {
                m_mAutomaticFlightSystem = boost::in_place();
                try {
                    m_mAutomaticFlightSystem->ReadCPACS(tixiHandle, xpath + "/mAutomaticFlightSystem");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mAutomaticFlightSystem at xpath << " << xpath << ": " << e.what();
                    m_mAutomaticFlightSystem = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mAutomaticFlightSystem at xpath << " << xpath << ": " << e.getError();
                    m_mAutomaticFlightSystem = boost::none;
                }
            }
            
            // read element mCommunication
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mCommunication")) {
                m_mCommunication = boost::in_place();
                try {
                    m_mCommunication->ReadCPACS(tixiHandle, xpath + "/mCommunication");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mCommunication at xpath << " << xpath << ": " << e.what();
                    m_mCommunication = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mCommunication at xpath << " << xpath << ": " << e.getError();
                    m_mCommunication = boost::none;
                }
            }
            
            // read element mElectricalGeneration
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mElectricalGeneration")) {
                m_mElectricalGeneration = boost::in_place();
                try {
                    m_mElectricalGeneration->ReadCPACS(tixiHandle, xpath + "/mElectricalGeneration");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mElectricalGeneration at xpath << " << xpath << ": " << e.what();
                    m_mElectricalGeneration = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mElectricalGeneration at xpath << " << xpath << ": " << e.getError();
                    m_mElectricalGeneration = boost::none;
                }
            }
            
            // read element mElectricalDistribution
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mElectricalDistribution")) {
                m_mElectricalDistribution = boost::in_place();
                try {
                    m_mElectricalDistribution->ReadCPACS(tixiHandle, xpath + "/mElectricalDistribution");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mElectricalDistribution at xpath << " << xpath << ": " << e.what();
                    m_mElectricalDistribution = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mElectricalDistribution at xpath << " << xpath << ": " << e.getError();
                    m_mElectricalDistribution = boost::none;
                }
            }
            
            // read element mIntegratedModularAvionics
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mIntegratedModularAvionics")) {
                m_mIntegratedModularAvionics = boost::in_place();
                try {
                    m_mIntegratedModularAvionics->ReadCPACS(tixiHandle, xpath + "/mIntegratedModularAvionics");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mIntegratedModularAvionics at xpath << " << xpath << ": " << e.what();
                    m_mIntegratedModularAvionics = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mIntegratedModularAvionics at xpath << " << xpath << ": " << e.getError();
                    m_mIntegratedModularAvionics = boost::none;
                }
            }
            
            // read element mMillitarySystems
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mMillitarySystems")) {
                m_mMillitarySystems = boost::in_place();
                try {
                    m_mMillitarySystems->ReadCPACS(tixiHandle, xpath + "/mMillitarySystems");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mMillitarySystems at xpath << " << xpath << ": " << e.what();
                    m_mMillitarySystems = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mMillitarySystems at xpath << " << xpath << ": " << e.getError();
                    m_mMillitarySystems = boost::none;
                }
            }
            
            // read element mNavigation
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/mNavigation")) {
                m_mNavigation = boost::in_place();
                try {
                    m_mNavigation->ReadCPACS(tixiHandle, xpath + "/mNavigation");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read mNavigation at xpath << " << xpath << ": " << e.what();
                    m_mNavigation = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read mNavigation at xpath << " << xpath << ": " << e.getError();
                    m_mNavigation = boost::none;
                }
            }
            
        }
        
        void CPACSMSystems::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element massDescription
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/massDescription");
            m_massDescription.WriteCPACS(tixiHandle, xpath + "/massDescription");
            
            // write element mAuxillaryPowerUnit
            if (m_mAuxillaryPowerUnit) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mAuxillaryPowerUnit");
                m_mAuxillaryPowerUnit->WriteCPACS(tixiHandle, xpath + "/mAuxillaryPowerUnit");
            }
            
            // write element mHydraulicGeneration
            if (m_mHydraulicGeneration) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mHydraulicGeneration");
                m_mHydraulicGeneration->WriteCPACS(tixiHandle, xpath + "/mHydraulicGeneration");
            }
            
            // write element mHydraulicDistribution
            if (m_mHydraulicDistribution) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mHydraulicDistribution");
                m_mHydraulicDistribution->WriteCPACS(tixiHandle, xpath + "/mHydraulicDistribution");
            }
            
            // write element mAirConditioning
            if (m_mAirConditioning) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mAirConditioning");
                m_mAirConditioning->WriteCPACS(tixiHandle, xpath + "/mAirConditioning");
            }
            
            // write element mDeIcing
            if (m_mDeIcing) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mDeIcing");
                m_mDeIcing->WriteCPACS(tixiHandle, xpath + "/mDeIcing");
            }
            
            // write element mFireProtection
            if (m_mFireProtection) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mFireProtection");
                m_mFireProtection->WriteCPACS(tixiHandle, xpath + "/mFireProtection");
            }
            
            // write element mFlightControls
            if (m_mFlightControls) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mFlightControls");
                m_mFlightControls->WriteCPACS(tixiHandle, xpath + "/mFlightControls");
            }
            
            // write element mInstrumentPanel
            if (m_mInstrumentPanel) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mInstrumentPanel");
                m_mInstrumentPanel->WriteCPACS(tixiHandle, xpath + "/mInstrumentPanel");
            }
            
            // write element mAutomaticFlightSystem
            if (m_mAutomaticFlightSystem) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mAutomaticFlightSystem");
                m_mAutomaticFlightSystem->WriteCPACS(tixiHandle, xpath + "/mAutomaticFlightSystem");
            }
            
            // write element mCommunication
            if (m_mCommunication) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mCommunication");
                m_mCommunication->WriteCPACS(tixiHandle, xpath + "/mCommunication");
            }
            
            // write element mElectricalGeneration
            if (m_mElectricalGeneration) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mElectricalGeneration");
                m_mElectricalGeneration->WriteCPACS(tixiHandle, xpath + "/mElectricalGeneration");
            }
            
            // write element mElectricalDistribution
            if (m_mElectricalDistribution) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mElectricalDistribution");
                m_mElectricalDistribution->WriteCPACS(tixiHandle, xpath + "/mElectricalDistribution");
            }
            
            // write element mIntegratedModularAvionics
            if (m_mIntegratedModularAvionics) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mIntegratedModularAvionics");
                m_mIntegratedModularAvionics->WriteCPACS(tixiHandle, xpath + "/mIntegratedModularAvionics");
            }
            
            // write element mMillitarySystems
            if (m_mMillitarySystems) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mMillitarySystems");
                m_mMillitarySystems->WriteCPACS(tixiHandle, xpath + "/mMillitarySystems");
            }
            
            // write element mNavigation
            if (m_mNavigation) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mNavigation");
                m_mNavigation->WriteCPACS(tixiHandle, xpath + "/mNavigation");
            }
            
        }
        
        const CPACSGenericMass& CPACSMSystems::GetMassDescription() const
        {
            return m_massDescription;
        }
        
        CPACSGenericMass& CPACSMSystems::GetMassDescription()
        {
            return m_massDescription;
        }
        
        bool CPACSMSystems::HasMAuxillaryPowerUnit() const
        {
            return static_cast<bool>(m_mAuxillaryPowerUnit);
        }
        
        const CPACSMAuxillaryPowerUnit& CPACSMSystems::GetMAuxillaryPowerUnit() const
        {
            return *m_mAuxillaryPowerUnit;
        }
        
        CPACSMAuxillaryPowerUnit& CPACSMSystems::GetMAuxillaryPowerUnit()
        {
            return *m_mAuxillaryPowerUnit;
        }
        
        bool CPACSMSystems::HasMHydraulicGeneration() const
        {
            return static_cast<bool>(m_mHydraulicGeneration);
        }
        
        const CPACSMHydraulicGeneration& CPACSMSystems::GetMHydraulicGeneration() const
        {
            return *m_mHydraulicGeneration;
        }
        
        CPACSMHydraulicGeneration& CPACSMSystems::GetMHydraulicGeneration()
        {
            return *m_mHydraulicGeneration;
        }
        
        bool CPACSMSystems::HasMHydraulicDistribution() const
        {
            return static_cast<bool>(m_mHydraulicDistribution);
        }
        
        const CPACSMHydraulicDistribution& CPACSMSystems::GetMHydraulicDistribution() const
        {
            return *m_mHydraulicDistribution;
        }
        
        CPACSMHydraulicDistribution& CPACSMSystems::GetMHydraulicDistribution()
        {
            return *m_mHydraulicDistribution;
        }
        
        bool CPACSMSystems::HasMAirConditioning() const
        {
            return static_cast<bool>(m_mAirConditioning);
        }
        
        const CPACSMAirConditioning& CPACSMSystems::GetMAirConditioning() const
        {
            return *m_mAirConditioning;
        }
        
        CPACSMAirConditioning& CPACSMSystems::GetMAirConditioning()
        {
            return *m_mAirConditioning;
        }
        
        bool CPACSMSystems::HasMDeIcing() const
        {
            return static_cast<bool>(m_mDeIcing);
        }
        
        const CPACSMDeIcing& CPACSMSystems::GetMDeIcing() const
        {
            return *m_mDeIcing;
        }
        
        CPACSMDeIcing& CPACSMSystems::GetMDeIcing()
        {
            return *m_mDeIcing;
        }
        
        bool CPACSMSystems::HasMFireProtection() const
        {
            return static_cast<bool>(m_mFireProtection);
        }
        
        const CPACSMFireProtection& CPACSMSystems::GetMFireProtection() const
        {
            return *m_mFireProtection;
        }
        
        CPACSMFireProtection& CPACSMSystems::GetMFireProtection()
        {
            return *m_mFireProtection;
        }
        
        bool CPACSMSystems::HasMFlightControls() const
        {
            return static_cast<bool>(m_mFlightControls);
        }
        
        const CPACSMFlightControls& CPACSMSystems::GetMFlightControls() const
        {
            return *m_mFlightControls;
        }
        
        CPACSMFlightControls& CPACSMSystems::GetMFlightControls()
        {
            return *m_mFlightControls;
        }
        
        bool CPACSMSystems::HasMInstrumentPanel() const
        {
            return static_cast<bool>(m_mInstrumentPanel);
        }
        
        const CPACSMInstrumentPanel& CPACSMSystems::GetMInstrumentPanel() const
        {
            return *m_mInstrumentPanel;
        }
        
        CPACSMInstrumentPanel& CPACSMSystems::GetMInstrumentPanel()
        {
            return *m_mInstrumentPanel;
        }
        
        bool CPACSMSystems::HasMAutomaticFlightSystem() const
        {
            return static_cast<bool>(m_mAutomaticFlightSystem);
        }
        
        const CPACSMAutomaticFlightSystem& CPACSMSystems::GetMAutomaticFlightSystem() const
        {
            return *m_mAutomaticFlightSystem;
        }
        
        CPACSMAutomaticFlightSystem& CPACSMSystems::GetMAutomaticFlightSystem()
        {
            return *m_mAutomaticFlightSystem;
        }
        
        bool CPACSMSystems::HasMCommunication() const
        {
            return static_cast<bool>(m_mCommunication);
        }
        
        const CPACSMCommunication& CPACSMSystems::GetMCommunication() const
        {
            return *m_mCommunication;
        }
        
        CPACSMCommunication& CPACSMSystems::GetMCommunication()
        {
            return *m_mCommunication;
        }
        
        bool CPACSMSystems::HasMElectricalGeneration() const
        {
            return static_cast<bool>(m_mElectricalGeneration);
        }
        
        const CPACSMElectricalGeneration& CPACSMSystems::GetMElectricalGeneration() const
        {
            return *m_mElectricalGeneration;
        }
        
        CPACSMElectricalGeneration& CPACSMSystems::GetMElectricalGeneration()
        {
            return *m_mElectricalGeneration;
        }
        
        bool CPACSMSystems::HasMElectricalDistribution() const
        {
            return static_cast<bool>(m_mElectricalDistribution);
        }
        
        const CPACSMElectricalDistribution& CPACSMSystems::GetMElectricalDistribution() const
        {
            return *m_mElectricalDistribution;
        }
        
        CPACSMElectricalDistribution& CPACSMSystems::GetMElectricalDistribution()
        {
            return *m_mElectricalDistribution;
        }
        
        bool CPACSMSystems::HasMIntegratedModularAvionics() const
        {
            return static_cast<bool>(m_mIntegratedModularAvionics);
        }
        
        const CPACSMIntegratedModularAvionics& CPACSMSystems::GetMIntegratedModularAvionics() const
        {
            return *m_mIntegratedModularAvionics;
        }
        
        CPACSMIntegratedModularAvionics& CPACSMSystems::GetMIntegratedModularAvionics()
        {
            return *m_mIntegratedModularAvionics;
        }
        
        bool CPACSMSystems::HasMMillitarySystems() const
        {
            return static_cast<bool>(m_mMillitarySystems);
        }
        
        const CPACSMMillitarySystems& CPACSMSystems::GetMMillitarySystems() const
        {
            return *m_mMillitarySystems;
        }
        
        CPACSMMillitarySystems& CPACSMSystems::GetMMillitarySystems()
        {
            return *m_mMillitarySystems;
        }
        
        bool CPACSMSystems::HasMNavigation() const
        {
            return static_cast<bool>(m_mNavigation);
        }
        
        const CPACSMNavigation& CPACSMSystems::GetMNavigation() const
        {
            return *m_mNavigation;
        }
        
        CPACSMNavigation& CPACSMSystems::GetMNavigation()
        {
            return *m_mNavigation;
        }
        
    }
}
