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
#include "tigl_internal.h"
#include "CPACSFqPhugoid.h"
#include "CPACSFqShortPeriod.h"
#include "CPACSFqRolosc.h"
#include "CPACSFqEiglat.h"
#include "CPACSFqTreff.h"
#include "CPACSFqRollPerf.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSFqCase
        
        // generated from /xsd:schema/xsd:complexType[341]
        class CPACSFqCharParameters
        {
        public:
            TIGL_EXPORT CPACSFqCharParameters();
            TIGL_EXPORT virtual ~CPACSFqCharParameters();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const std::string& GetStaticMargin() const;
            TIGL_EXPORT void SetStaticMargin(const std::string& value);
            
            TIGL_EXPORT const CPACSFqPhugoid& GetPhugoid() const;
            TIGL_EXPORT CPACSFqPhugoid& GetPhugoid();
            
            TIGL_EXPORT const CPACSFqShortPeriod& GetShortPeriod() const;
            TIGL_EXPORT CPACSFqShortPeriod& GetShortPeriod();
            
            TIGL_EXPORT const CPACSFqRolosc& GetRolosc() const;
            TIGL_EXPORT CPACSFqRolosc& GetRolosc();
            
            TIGL_EXPORT const std::string& GetRollSpiral() const;
            TIGL_EXPORT void SetRollSpiral(const std::string& value);
            
            TIGL_EXPORT const CPACSFqEiglat& GetEiglat() const;
            TIGL_EXPORT CPACSFqEiglat& GetEiglat();
            
            TIGL_EXPORT const CPACSFqTreff& GetTreff() const;
            TIGL_EXPORT CPACSFqTreff& GetTreff();
            
            TIGL_EXPORT const CPACSFqRollPerf& GetRollPerf() const;
            TIGL_EXPORT CPACSFqRollPerf& GetRollPerf();
            
        protected:
            std::string        m_staticMargin;
            CPACSFqPhugoid     m_phugoid;
            CPACSFqShortPeriod m_shortPeriod;
            CPACSFqRolosc      m_rolosc;
            std::string        m_rollSpiral;
            CPACSFqEiglat      m_eiglat;
            CPACSFqTreff       m_treff;
            CPACSFqRollPerf    m_rollPerf;
            
        private:
            #ifdef HAVE_CPP11
            CPACSFqCharParameters(const CPACSFqCharParameters&) = delete;
            CPACSFqCharParameters& operator=(const CPACSFqCharParameters&) = delete;
            
            CPACSFqCharParameters(CPACSFqCharParameters&&) = delete;
            CPACSFqCharParameters& operator=(CPACSFqCharParameters&&) = delete;
            #else
            CPACSFqCharParameters(const CPACSFqCharParameters&);
            CPACSFqCharParameters& operator=(const CPACSFqCharParameters&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSFqCharParameters = generated::CPACSFqCharParameters;
    #else
    typedef generated::CPACSFqCharParameters CCPACSFqCharParameters;
    #endif
}
