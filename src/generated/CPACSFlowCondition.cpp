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
#include "CPACSFlowCondition.h"

namespace tigl
{
    namespace generated
    {
        CPACSFlowCondition::CPACSFlowCondition(){}
        CPACSFlowCondition::~CPACSFlowCondition() {}
        
        void CPACSFlowCondition::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element angleOfYaw
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/angleOfYaw")) {
                m_angleOfYaw = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/angleOfYaw");
            }
            else {
                LOG(ERROR) << "Required element angleOfYaw is missing";
            }
            
            // read element quasiSteadyRotation
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/quasiSteadyRotation")) {
                m_quasiSteadyRotation = boost::in_place();
                try {
                    m_quasiSteadyRotation->ReadCPACS(tixiHandle, xpath + "/quasiSteadyRotation");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read quasiSteadyRotation at xpath << " << xpath << ": " << e.what();
                    m_quasiSteadyRotation = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read quasiSteadyRotation at xpath << " << xpath << ": " << e.getError();
                    m_quasiSteadyRotation = boost::none;
                }
            }
            
            // read element controlSurfaces
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/controlSurfaces")) {
                m_controlSurfaces = boost::in_place();
                try {
                    m_controlSurfaces->ReadCPACS(tixiHandle, xpath + "/controlSurfaces");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read controlSurfaces at xpath << " << xpath << ": " << e.what();
                    m_controlSurfaces = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read controlSurfaces at xpath << " << xpath << ": " << e.getError();
                    m_controlSurfaces = boost::none;
                }
            }
            
            // read element machNumber
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/machNumber")) {
                m_machNumber_choice1 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/machNumber");
            }
            
            // read element reynoldsNumber
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/reynoldsNumber")) {
                m_reynoldsNumber_choice1 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/reynoldsNumber");
            }
            
            // read element standardAltitude
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/standardAltitude")) {
                m_standardAltitude_choice1 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/standardAltitude");
            }
            
            // read element deltaTemperature
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/deltaTemperature")) {
                m_deltaTemperature_choice1 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/deltaTemperature");
            }
            
            // read element kinematicViscosity
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/kinematicViscosity")) {
                m_kinematicViscosity_choice1 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/kinematicViscosity");
            }
            
            // read element airspeed
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/airspeed")) {
                m_airspeed_choice1 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/airspeed");
            }
            
            // read element speedOfSound
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/speedOfSound")) {
                m_speedOfSound_choice1 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/speedOfSound");
            }
            
            // read element reynoldsNumber
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/reynoldsNumber")) {
                m_reynoldsNumber_choice2 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/reynoldsNumber");
            }
            
            // read element standardAltitude
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/standardAltitude")) {
                m_standardAltitude_choice2 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/standardAltitude");
            }
            
            // read element deltaTemperature
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/deltaTemperature")) {
                m_deltaTemperature_choice2 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/deltaTemperature");
            }
            
            // read element speedOfSound
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/speedOfSound")) {
                m_speedOfSound_choice2 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/speedOfSound");
            }
            
            // read element airspeed
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/airspeed")) {
                m_airspeed_choice2 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/airspeed");
            }
            
            // read element kinematicViscosity
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/kinematicViscosity")) {
                m_kinematicViscosity_choice2 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/kinematicViscosity");
            }
            
            // read element airspeed
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/airspeed")) {
                m_airspeed_choice3 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/airspeed");
            }
            
            // read element standardAltitude
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/standardAltitude")) {
                m_standardAltitude_choice3 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/standardAltitude");
            }
            
            // read element deltaTemperature
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/deltaTemperature")) {
                m_deltaTemperature_choice3 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/deltaTemperature");
            }
            
            // read element kinematicViscosity
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/kinematicViscosity")) {
                m_kinematicViscosity_choice3 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/kinematicViscosity");
            }
            
            // read element speedOfSound
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/speedOfSound")) {
                m_speedOfSound_choice3 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/speedOfSound");
            }
            
            // read element angleOfAttack
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/angleOfAttack")) {
                m_angleOfAttack_choice1 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/angleOfAttack");
            }
            
            // read element targetLiftCoefficient
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/targetLiftCoefficient")) {
                m_targetLiftCoefficient_choice2 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/targetLiftCoefficient");
            }
            
        }
        
        void CPACSFlowCondition::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element angleOfYaw
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/angleOfYaw");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/angleOfYaw", m_angleOfYaw);
            
            // write element quasiSteadyRotation
            if (m_quasiSteadyRotation) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/quasiSteadyRotation");
                m_quasiSteadyRotation->WriteCPACS(tixiHandle, xpath + "/quasiSteadyRotation");
            }
            
            // write element controlSurfaces
            if (m_controlSurfaces) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/controlSurfaces");
                m_controlSurfaces->WriteCPACS(tixiHandle, xpath + "/controlSurfaces");
            }
            
            // write element machNumber
            if (m_machNumber_choice1) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/machNumber");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/machNumber", *m_machNumber_choice1);
            }
            
            // write element reynoldsNumber
            if (m_reynoldsNumber_choice1) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/reynoldsNumber");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/reynoldsNumber", *m_reynoldsNumber_choice1);
            }
            
            // write element standardAltitude
            if (m_standardAltitude_choice1) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/standardAltitude");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/standardAltitude", *m_standardAltitude_choice1);
            }
            
            // write element deltaTemperature
            if (m_deltaTemperature_choice1) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/deltaTemperature");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/deltaTemperature", *m_deltaTemperature_choice1);
            }
            
            // write element kinematicViscosity
            if (m_kinematicViscosity_choice1) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/kinematicViscosity");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/kinematicViscosity", *m_kinematicViscosity_choice1);
            }
            
            // write element airspeed
            if (m_airspeed_choice1) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/airspeed");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/airspeed", *m_airspeed_choice1);
            }
            
            // write element speedOfSound
            if (m_speedOfSound_choice1) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/speedOfSound");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/speedOfSound", *m_speedOfSound_choice1);
            }
            
            // write element reynoldsNumber
            if (m_reynoldsNumber_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/reynoldsNumber");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/reynoldsNumber", *m_reynoldsNumber_choice2);
            }
            
            // write element standardAltitude
            if (m_standardAltitude_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/standardAltitude");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/standardAltitude", *m_standardAltitude_choice2);
            }
            
            // write element deltaTemperature
            if (m_deltaTemperature_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/deltaTemperature");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/deltaTemperature", *m_deltaTemperature_choice2);
            }
            
            // write element speedOfSound
            if (m_speedOfSound_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/speedOfSound");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/speedOfSound", *m_speedOfSound_choice2);
            }
            
            // write element airspeed
            if (m_airspeed_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/airspeed");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/airspeed", *m_airspeed_choice2);
            }
            
            // write element kinematicViscosity
            if (m_kinematicViscosity_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/kinematicViscosity");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/kinematicViscosity", *m_kinematicViscosity_choice2);
            }
            
            // write element airspeed
            if (m_airspeed_choice3) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/airspeed");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/airspeed", *m_airspeed_choice3);
            }
            
            // write element standardAltitude
            if (m_standardAltitude_choice3) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/standardAltitude");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/standardAltitude", *m_standardAltitude_choice3);
            }
            
            // write element deltaTemperature
            if (m_deltaTemperature_choice3) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/deltaTemperature");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/deltaTemperature", *m_deltaTemperature_choice3);
            }
            
            // write element kinematicViscosity
            if (m_kinematicViscosity_choice3) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/kinematicViscosity");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/kinematicViscosity", *m_kinematicViscosity_choice3);
            }
            
            // write element speedOfSound
            if (m_speedOfSound_choice3) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/speedOfSound");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/speedOfSound", *m_speedOfSound_choice3);
            }
            
            // write element angleOfAttack
            if (m_angleOfAttack_choice1) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/angleOfAttack");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/angleOfAttack", *m_angleOfAttack_choice1);
            }
            
            // write element targetLiftCoefficient
            if (m_targetLiftCoefficient_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/targetLiftCoefficient");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/targetLiftCoefficient", *m_targetLiftCoefficient_choice2);
            }
            
        }
        
        const double& CPACSFlowCondition::GetAngleOfYaw() const
        {
            return m_angleOfYaw;
        }
        
        void CPACSFlowCondition::SetAngleOfYaw(const double& value)
        {
            m_angleOfYaw = value;
        }
        
        bool CPACSFlowCondition::HasQuasiSteadyRotation() const
        {
            return static_cast<bool>(m_quasiSteadyRotation);
        }
        
        const CPACSQuasiSteadyRotation& CPACSFlowCondition::GetQuasiSteadyRotation() const
        {
            return *m_quasiSteadyRotation;
        }
        
        CPACSQuasiSteadyRotation& CPACSFlowCondition::GetQuasiSteadyRotation()
        {
            return *m_quasiSteadyRotation;
        }
        
        bool CPACSFlowCondition::HasControlSurfaces() const
        {
            return static_cast<bool>(m_controlSurfaces);
        }
        
        const CPACSControlSurfaceDeflections& CPACSFlowCondition::GetControlSurfaces() const
        {
            return *m_controlSurfaces;
        }
        
        CPACSControlSurfaceDeflections& CPACSFlowCondition::GetControlSurfaces()
        {
            return *m_controlSurfaces;
        }
        
        bool CPACSFlowCondition::HasMachNumber_choice1() const
        {
            return static_cast<bool>(m_machNumber_choice1);
        }
        
        const double& CPACSFlowCondition::GetMachNumber_choice1() const
        {
            return *m_machNumber_choice1;
        }
        
        void CPACSFlowCondition::SetMachNumber_choice1(const double& value)
        {
            m_machNumber_choice1 = value;
        }
        
        bool CPACSFlowCondition::HasReynoldsNumber_choice1() const
        {
            return static_cast<bool>(m_reynoldsNumber_choice1);
        }
        
        const double& CPACSFlowCondition::GetReynoldsNumber_choice1() const
        {
            return *m_reynoldsNumber_choice1;
        }
        
        void CPACSFlowCondition::SetReynoldsNumber_choice1(const double& value)
        {
            m_reynoldsNumber_choice1 = value;
        }
        
        bool CPACSFlowCondition::HasStandardAltitude_choice1() const
        {
            return static_cast<bool>(m_standardAltitude_choice1);
        }
        
        const double& CPACSFlowCondition::GetStandardAltitude_choice1() const
        {
            return *m_standardAltitude_choice1;
        }
        
        void CPACSFlowCondition::SetStandardAltitude_choice1(const double& value)
        {
            m_standardAltitude_choice1 = value;
        }
        
        bool CPACSFlowCondition::HasDeltaTemperature_choice1() const
        {
            return static_cast<bool>(m_deltaTemperature_choice1);
        }
        
        const double& CPACSFlowCondition::GetDeltaTemperature_choice1() const
        {
            return *m_deltaTemperature_choice1;
        }
        
        void CPACSFlowCondition::SetDeltaTemperature_choice1(const double& value)
        {
            m_deltaTemperature_choice1 = value;
        }
        
        bool CPACSFlowCondition::HasKinematicViscosity_choice1() const
        {
            return static_cast<bool>(m_kinematicViscosity_choice1);
        }
        
        const double& CPACSFlowCondition::GetKinematicViscosity_choice1() const
        {
            return *m_kinematicViscosity_choice1;
        }
        
        void CPACSFlowCondition::SetKinematicViscosity_choice1(const double& value)
        {
            m_kinematicViscosity_choice1 = value;
        }
        
        bool CPACSFlowCondition::HasAirspeed_choice1() const
        {
            return static_cast<bool>(m_airspeed_choice1);
        }
        
        const double& CPACSFlowCondition::GetAirspeed_choice1() const
        {
            return *m_airspeed_choice1;
        }
        
        void CPACSFlowCondition::SetAirspeed_choice1(const double& value)
        {
            m_airspeed_choice1 = value;
        }
        
        bool CPACSFlowCondition::HasSpeedOfSound_choice1() const
        {
            return static_cast<bool>(m_speedOfSound_choice1);
        }
        
        const double& CPACSFlowCondition::GetSpeedOfSound_choice1() const
        {
            return *m_speedOfSound_choice1;
        }
        
        void CPACSFlowCondition::SetSpeedOfSound_choice1(const double& value)
        {
            m_speedOfSound_choice1 = value;
        }
        
        bool CPACSFlowCondition::HasReynoldsNumber_choice2() const
        {
            return static_cast<bool>(m_reynoldsNumber_choice2);
        }
        
        const double& CPACSFlowCondition::GetReynoldsNumber_choice2() const
        {
            return *m_reynoldsNumber_choice2;
        }
        
        void CPACSFlowCondition::SetReynoldsNumber_choice2(const double& value)
        {
            m_reynoldsNumber_choice2 = value;
        }
        
        bool CPACSFlowCondition::HasStandardAltitude_choice2() const
        {
            return static_cast<bool>(m_standardAltitude_choice2);
        }
        
        const double& CPACSFlowCondition::GetStandardAltitude_choice2() const
        {
            return *m_standardAltitude_choice2;
        }
        
        void CPACSFlowCondition::SetStandardAltitude_choice2(const double& value)
        {
            m_standardAltitude_choice2 = value;
        }
        
        bool CPACSFlowCondition::HasDeltaTemperature_choice2() const
        {
            return static_cast<bool>(m_deltaTemperature_choice2);
        }
        
        const double& CPACSFlowCondition::GetDeltaTemperature_choice2() const
        {
            return *m_deltaTemperature_choice2;
        }
        
        void CPACSFlowCondition::SetDeltaTemperature_choice2(const double& value)
        {
            m_deltaTemperature_choice2 = value;
        }
        
        bool CPACSFlowCondition::HasSpeedOfSound_choice2() const
        {
            return static_cast<bool>(m_speedOfSound_choice2);
        }
        
        const double& CPACSFlowCondition::GetSpeedOfSound_choice2() const
        {
            return *m_speedOfSound_choice2;
        }
        
        void CPACSFlowCondition::SetSpeedOfSound_choice2(const double& value)
        {
            m_speedOfSound_choice2 = value;
        }
        
        bool CPACSFlowCondition::HasAirspeed_choice2() const
        {
            return static_cast<bool>(m_airspeed_choice2);
        }
        
        const double& CPACSFlowCondition::GetAirspeed_choice2() const
        {
            return *m_airspeed_choice2;
        }
        
        void CPACSFlowCondition::SetAirspeed_choice2(const double& value)
        {
            m_airspeed_choice2 = value;
        }
        
        bool CPACSFlowCondition::HasKinematicViscosity_choice2() const
        {
            return static_cast<bool>(m_kinematicViscosity_choice2);
        }
        
        const double& CPACSFlowCondition::GetKinematicViscosity_choice2() const
        {
            return *m_kinematicViscosity_choice2;
        }
        
        void CPACSFlowCondition::SetKinematicViscosity_choice2(const double& value)
        {
            m_kinematicViscosity_choice2 = value;
        }
        
        bool CPACSFlowCondition::HasAirspeed_choice3() const
        {
            return static_cast<bool>(m_airspeed_choice3);
        }
        
        const double& CPACSFlowCondition::GetAirspeed_choice3() const
        {
            return *m_airspeed_choice3;
        }
        
        void CPACSFlowCondition::SetAirspeed_choice3(const double& value)
        {
            m_airspeed_choice3 = value;
        }
        
        bool CPACSFlowCondition::HasStandardAltitude_choice3() const
        {
            return static_cast<bool>(m_standardAltitude_choice3);
        }
        
        const double& CPACSFlowCondition::GetStandardAltitude_choice3() const
        {
            return *m_standardAltitude_choice3;
        }
        
        void CPACSFlowCondition::SetStandardAltitude_choice3(const double& value)
        {
            m_standardAltitude_choice3 = value;
        }
        
        bool CPACSFlowCondition::HasDeltaTemperature_choice3() const
        {
            return static_cast<bool>(m_deltaTemperature_choice3);
        }
        
        const double& CPACSFlowCondition::GetDeltaTemperature_choice3() const
        {
            return *m_deltaTemperature_choice3;
        }
        
        void CPACSFlowCondition::SetDeltaTemperature_choice3(const double& value)
        {
            m_deltaTemperature_choice3 = value;
        }
        
        bool CPACSFlowCondition::HasKinematicViscosity_choice3() const
        {
            return static_cast<bool>(m_kinematicViscosity_choice3);
        }
        
        const double& CPACSFlowCondition::GetKinematicViscosity_choice3() const
        {
            return *m_kinematicViscosity_choice3;
        }
        
        void CPACSFlowCondition::SetKinematicViscosity_choice3(const double& value)
        {
            m_kinematicViscosity_choice3 = value;
        }
        
        bool CPACSFlowCondition::HasSpeedOfSound_choice3() const
        {
            return static_cast<bool>(m_speedOfSound_choice3);
        }
        
        const double& CPACSFlowCondition::GetSpeedOfSound_choice3() const
        {
            return *m_speedOfSound_choice3;
        }
        
        void CPACSFlowCondition::SetSpeedOfSound_choice3(const double& value)
        {
            m_speedOfSound_choice3 = value;
        }
        
        bool CPACSFlowCondition::HasAngleOfAttack_choice1() const
        {
            return static_cast<bool>(m_angleOfAttack_choice1);
        }
        
        const double& CPACSFlowCondition::GetAngleOfAttack_choice1() const
        {
            return *m_angleOfAttack_choice1;
        }
        
        void CPACSFlowCondition::SetAngleOfAttack_choice1(const double& value)
        {
            m_angleOfAttack_choice1 = value;
        }
        
        bool CPACSFlowCondition::HasTargetLiftCoefficient_choice2() const
        {
            return static_cast<bool>(m_targetLiftCoefficient_choice2);
        }
        
        const double& CPACSFlowCondition::GetTargetLiftCoefficient_choice2() const
        {
            return *m_targetLiftCoefficient_choice2;
        }
        
        void CPACSFlowCondition::SetTargetLiftCoefficient_choice2(const double& value)
        {
            m_targetLiftCoefficient_choice2 = value;
        }
        
    }
}
