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
#include "CPACSTransmissions.h"
#include "CPACSShafts.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSDriveSystems
        
        // generated from /xsd:schema/xsd:complexType[286]
        class CPACSDriveSystem
        {
        public:
            TIGL_EXPORT CPACSDriveSystem();
            TIGL_EXPORT virtual ~CPACSDriveSystem();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT bool HasTransmissions() const;
            TIGL_EXPORT const CPACSTransmissions& GetTransmissions() const;
            TIGL_EXPORT CPACSTransmissions& GetTransmissions();
            
            TIGL_EXPORT bool HasShafts() const;
            TIGL_EXPORT const CPACSShafts& GetShafts() const;
            TIGL_EXPORT CPACSShafts& GetShafts();
            
            TIGL_EXPORT bool HasStates() const;
            TIGL_EXPORT const std::string& GetStates() const;
            TIGL_EXPORT void SetStates(const std::string& value);
            
        protected:
            boost::optional<CPACSTransmissions> m_transmissions;
            boost::optional<CPACSShafts>        m_shafts;
            boost::optional<std::string>        m_states;
            
        private:
            #ifdef HAVE_CPP11
            CPACSDriveSystem(const CPACSDriveSystem&) = delete;
            CPACSDriveSystem& operator=(const CPACSDriveSystem&) = delete;
            
            CPACSDriveSystem(CPACSDriveSystem&&) = delete;
            CPACSDriveSystem& operator=(CPACSDriveSystem&&) = delete;
            #else
            CPACSDriveSystem(const CPACSDriveSystem&);
            CPACSDriveSystem& operator=(const CPACSDriveSystem&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSDriveSystem = generated::CPACSDriveSystem;
    #else
    typedef generated::CPACSDriveSystem CCPACSDriveSystem;
    #endif
}
