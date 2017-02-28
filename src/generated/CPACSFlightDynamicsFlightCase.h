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

#pragma once

#include <tixi.h>
#include <string>
#include <boost/optional.hpp>
#include "tigl_internal.h"
#include "CPACSFlightDynamicsLinearModel.h"
#include "CPACSFlightDynamicsTrimResult.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSFlightDynamicsFlightCases
        
        // generated from /xsd:schema/xsd:complexType[322]
        class CPACSFlightDynamicsFlightCase
        {
        public:
            TIGL_EXPORT CPACSFlightDynamicsFlightCase();
            TIGL_EXPORT virtual ~CPACSFlightDynamicsFlightCase();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const std::string& GetUID() const;
            TIGL_EXPORT void SetUID(const std::string& value);
            
            TIGL_EXPORT bool HasName() const;
            TIGL_EXPORT const std::string& GetName() const;
            TIGL_EXPORT void SetName(const std::string& value);
            
            TIGL_EXPORT bool HasDescription() const;
            TIGL_EXPORT const std::string& GetDescription() const;
            TIGL_EXPORT void SetDescription(const std::string& value);
            
            TIGL_EXPORT const std::string& GetWeightAndBalanceUID() const;
            TIGL_EXPORT void SetWeightAndBalanceUID(const std::string& value);
            
            TIGL_EXPORT const double& GetStandardAltitude() const;
            TIGL_EXPORT void SetStandardAltitude(const double& value);
            
            TIGL_EXPORT const double& GetVCAS() const;
            TIGL_EXPORT void SetVCAS(const double& value);
            
            TIGL_EXPORT const int& GetConfiguration() const;
            TIGL_EXPORT void SetConfiguration(const int& value);
            
            TIGL_EXPORT const int& GetGear() const;
            TIGL_EXPORT void SetGear(const int& value);
            
            TIGL_EXPORT bool HasLinearModel() const;
            TIGL_EXPORT const CPACSFlightDynamicsLinearModel& GetLinearModel() const;
            TIGL_EXPORT CPACSFlightDynamicsLinearModel& GetLinearModel();
            
            TIGL_EXPORT bool HasTrimResult() const;
            TIGL_EXPORT const CPACSFlightDynamicsTrimResult& GetTrimResult() const;
            TIGL_EXPORT CPACSFlightDynamicsTrimResult& GetTrimResult();
            
        protected:
            std::string                                     m_uID;
            boost::optional<std::string>                    m_name;
            boost::optional<std::string>                    m_description;
            std::string                                     m_weightAndBalanceUID;
            double                                          m_standardAltitude;
            double                                          m_vCAS;
            int                                             m_configuration;
            int                                             m_gear;
            boost::optional<CPACSFlightDynamicsLinearModel> m_linearModel;
            boost::optional<CPACSFlightDynamicsTrimResult>  m_trimResult;
            
        private:
            #ifdef HAVE_CPP11
            CPACSFlightDynamicsFlightCase(const CPACSFlightDynamicsFlightCase&) = delete;
            CPACSFlightDynamicsFlightCase& operator=(const CPACSFlightDynamicsFlightCase&) = delete;
            
            CPACSFlightDynamicsFlightCase(CPACSFlightDynamicsFlightCase&&) = delete;
            CPACSFlightDynamicsFlightCase& operator=(CPACSFlightDynamicsFlightCase&&) = delete;
            #else
            CPACSFlightDynamicsFlightCase(const CPACSFlightDynamicsFlightCase&);
            CPACSFlightDynamicsFlightCase& operator=(const CPACSFlightDynamicsFlightCase&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSFlightDynamicsFlightCase = generated::CPACSFlightDynamicsFlightCase;
    #else
    typedef generated::CPACSFlightDynamicsFlightCase CCPACSFlightDynamicsFlightCase;
    #endif
}
