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
#include <vector>
#include "UniquePtr.h"
#include "tigl_internal.h"

namespace tigl
{
    namespace generated
    {
        class CPACSControlInput;
        
        // This class is used in:
        // CPACSLoadCaseSettings
        // CPACSMissionSegment
        
        // generated from /xsd:schema/xsd:complexType[162]
        class CPACSControlInputs
        {
        public:
            TIGL_EXPORT CPACSControlInputs();
            TIGL_EXPORT virtual ~CPACSControlInputs();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const std::vector<unique_ptr<CPACSControlInput>>& GetControlInput() const;
            TIGL_EXPORT std::vector<unique_ptr<CPACSControlInput>>& GetControlInput();
            
        protected:
            std::vector<unique_ptr<CPACSControlInput>> m_controlInput;
            
        private:
            #ifdef HAVE_CPP11
            CPACSControlInputs(const CPACSControlInputs&) = delete;
            CPACSControlInputs& operator=(const CPACSControlInputs&) = delete;
            
            CPACSControlInputs(CPACSControlInputs&&) = delete;
            CPACSControlInputs& operator=(CPACSControlInputs&&) = delete;
            #else
            CPACSControlInputs(const CPACSControlInputs&);
            CPACSControlInputs& operator=(const CPACSControlInputs&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSControlInputs = generated::CPACSControlInputs;
    #else
    typedef generated::CPACSControlInputs CCPACSControlInputs;
    #endif
    
    using generated::CPACSControlInput;
}
