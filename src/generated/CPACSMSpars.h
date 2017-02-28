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
#include "CPACSGenericMass.h"

namespace tigl
{
    namespace generated
    {
        class CPACSSingleGenericMass;
        
        // This class is used in:
        // CPACSMWingBox
        
        // generated from /xsd:schema/xsd:complexType[596]
        class CPACSMSpars
        {
        public:
            TIGL_EXPORT CPACSMSpars();
            TIGL_EXPORT virtual ~CPACSMSpars();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const CPACSGenericMass& GetMassDescription() const;
            TIGL_EXPORT CPACSGenericMass& GetMassDescription();
            
            TIGL_EXPORT const std::vector<unique_ptr<CPACSSingleGenericMass>>& GetMSpar() const;
            TIGL_EXPORT std::vector<unique_ptr<CPACSSingleGenericMass>>& GetMSpar();
            
        protected:
            CPACSGenericMass                                m_massDescription;
            std::vector<unique_ptr<CPACSSingleGenericMass>> m_mSpar;
            
        private:
            #ifdef HAVE_CPP11
            CPACSMSpars(const CPACSMSpars&) = delete;
            CPACSMSpars& operator=(const CPACSMSpars&) = delete;
            
            CPACSMSpars(CPACSMSpars&&) = delete;
            CPACSMSpars& operator=(CPACSMSpars&&) = delete;
            #else
            CPACSMSpars(const CPACSMSpars&);
            CPACSMSpars& operator=(const CPACSMSpars&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSMSpars = generated::CPACSMSpars;
    #else
    typedef generated::CPACSMSpars CCPACSMSpars;
    #endif
    
    using generated::CPACSSingleGenericMass;
}
