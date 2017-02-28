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

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSSteffsOutputParameters
        
        // generated from /xsd:schema/xsd:complexType[796]/xsd:complexContent/xsd:extension/xsd:sequence/xsd:element[15]/xsd:complexType
        class CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold
        {
        public:
            TIGL_EXPORT CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold();
            TIGL_EXPORT virtual ~CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
        protected:
        private:
            #ifdef HAVE_CPP11
            CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold(const CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold&) = delete;
            CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold& operator=(const CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold&) = delete;
            
            CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold(CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold&&) = delete;
            CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold& operator=(CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold&&) = delete;
            #else
            CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold(const CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold&);
            CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold& operator=(const CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold = generated::CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold;
    #else
    typedef generated::CPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold CCPACSSteffsOutputParameters_consideredLoadCasesRelativeThreshold;
    #endif
}
