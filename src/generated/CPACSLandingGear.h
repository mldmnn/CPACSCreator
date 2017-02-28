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
#include "CPACSNoseGears.h"
#include "CPACSMainGears.h"
#include "CPACSSkidGears.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSAircraftModel
        // CPACSRotorcraftModel
        
        // generated from /xsd:schema/xsd:complexType[469]
        class CPACSLandingGear
        {
        public:
            TIGL_EXPORT CPACSLandingGear();
            TIGL_EXPORT virtual ~CPACSLandingGear();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT bool HasNoseGears() const;
            TIGL_EXPORT const CPACSNoseGears& GetNoseGears() const;
            TIGL_EXPORT CPACSNoseGears& GetNoseGears();
            
            TIGL_EXPORT bool HasMainGears() const;
            TIGL_EXPORT const CPACSMainGears& GetMainGears() const;
            TIGL_EXPORT CPACSMainGears& GetMainGears();
            
            TIGL_EXPORT bool HasSkidGears() const;
            TIGL_EXPORT const CPACSSkidGears& GetSkidGears() const;
            TIGL_EXPORT CPACSSkidGears& GetSkidGears();
            
        protected:
            boost::optional<CPACSNoseGears> m_noseGears;
            boost::optional<CPACSMainGears> m_mainGears;
            boost::optional<CPACSSkidGears> m_skidGears;
            
        private:
            #ifdef HAVE_CPP11
            CPACSLandingGear(const CPACSLandingGear&) = delete;
            CPACSLandingGear& operator=(const CPACSLandingGear&) = delete;
            
            CPACSLandingGear(CPACSLandingGear&&) = delete;
            CPACSLandingGear& operator=(CPACSLandingGear&&) = delete;
            #else
            CPACSLandingGear(const CPACSLandingGear&);
            CPACSLandingGear& operator=(const CPACSLandingGear&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSLandingGear = generated::CPACSLandingGear;
    #else
    typedef generated::CPACSLandingGear CCPACSLandingGear;
    #endif
}
