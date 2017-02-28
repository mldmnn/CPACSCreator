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
#include <CCPACSStringVector.h>

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSControlInputs
        
        // generated from /xsd:schema/xsd:complexType[161]
        class CPACSControlInput
        {
        public:
            TIGL_EXPORT CPACSControlInput();
            TIGL_EXPORT virtual ~CPACSControlInput();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const std::string& GetCockpitControlUID() const;
            TIGL_EXPORT void SetCockpitControlUID(const std::string& value);
            
            TIGL_EXPORT const CCPACSStringVector& GetValue() const;
            TIGL_EXPORT CCPACSStringVector& GetValue();
            
        protected:
            std::string        m_cockpitControlUID;
            CCPACSStringVector m_value;
            
        private:
            #ifdef HAVE_CPP11
            CPACSControlInput(const CPACSControlInput&) = delete;
            CPACSControlInput& operator=(const CPACSControlInput&) = delete;
            
            CPACSControlInput(CPACSControlInput&&) = delete;
            CPACSControlInput& operator=(CPACSControlInput&&) = delete;
            #else
            CPACSControlInput(const CPACSControlInput&);
            CPACSControlInput& operator=(const CPACSControlInput&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSControlInput = generated::CPACSControlInput;
    #else
    typedef generated::CPACSControlInput CCPACSControlInput;
    #endif
}
