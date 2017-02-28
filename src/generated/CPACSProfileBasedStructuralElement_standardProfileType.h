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
#include "CPACSProfileBasedStructuralElement_standardProfileType_SimpleContent.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSProfileBasedStructuralElement
        
        // generated from /xsd:schema/xsd:complexType[704]/xsd:complexContent/xsd:extension/xsd:sequence/xsd:choice[1]/xsd:sequence[2]/xsd:element[1]/xsd:complexType
        class CPACSProfileBasedStructuralElement_standardProfileType
        {
        public:
            TIGL_EXPORT CPACSProfileBasedStructuralElement_standardProfileType();
            TIGL_EXPORT virtual ~CPACSProfileBasedStructuralElement_standardProfileType();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const CPACSProfileBasedStructuralElement_standardProfileType_SimpleContent& GetSimpleContent() const;
            TIGL_EXPORT void SetSimpleContent(const CPACSProfileBasedStructuralElement_standardProfileType_SimpleContent& value);
            
        protected:
            CPACSProfileBasedStructuralElement_standardProfileType_SimpleContent m_simpleContent;
            
        private:
            #ifdef HAVE_CPP11
            CPACSProfileBasedStructuralElement_standardProfileType(const CPACSProfileBasedStructuralElement_standardProfileType&) = delete;
            CPACSProfileBasedStructuralElement_standardProfileType& operator=(const CPACSProfileBasedStructuralElement_standardProfileType&) = delete;
            
            CPACSProfileBasedStructuralElement_standardProfileType(CPACSProfileBasedStructuralElement_standardProfileType&&) = delete;
            CPACSProfileBasedStructuralElement_standardProfileType& operator=(CPACSProfileBasedStructuralElement_standardProfileType&&) = delete;
            #else
            CPACSProfileBasedStructuralElement_standardProfileType(const CPACSProfileBasedStructuralElement_standardProfileType&);
            CPACSProfileBasedStructuralElement_standardProfileType& operator=(const CPACSProfileBasedStructuralElement_standardProfileType&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSProfileBasedStructuralElement_standardProfileType = generated::CPACSProfileBasedStructuralElement_standardProfileType;
    #else
    typedef generated::CPACSProfileBasedStructuralElement_standardProfileType CCPACSProfileBasedStructuralElement_standardProfileType;
    #endif
}
