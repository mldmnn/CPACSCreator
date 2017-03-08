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
#include "CPACSRibRotation_ribRotationReference_SimpleContent.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSRibRotation
        
        // generated from /xsd:schema/xsd:complexType[730]/xsd:complexContent/xsd:extension/xsd:sequence/xsd:element[1]/xsd:complexType
        class CPACSRibRotation_ribRotationReference
        {
        public:
            TIGL_EXPORT CPACSRibRotation_ribRotationReference();
            TIGL_EXPORT virtual ~CPACSRibRotation_ribRotationReference();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const CPACSRibRotation_ribRotationReference_SimpleContent& GetSimpleContent() const;
            TIGL_EXPORT void SetSimpleContent(const CPACSRibRotation_ribRotationReference_SimpleContent& value);
            
        protected:
            CPACSRibRotation_ribRotationReference_SimpleContent m_simpleContent;
            
        private:
            #ifdef HAVE_CPP11
            CPACSRibRotation_ribRotationReference(const CPACSRibRotation_ribRotationReference&) = delete;
            CPACSRibRotation_ribRotationReference& operator=(const CPACSRibRotation_ribRotationReference&) = delete;
            
            CPACSRibRotation_ribRotationReference(CPACSRibRotation_ribRotationReference&&) = delete;
            CPACSRibRotation_ribRotationReference& operator=(CPACSRibRotation_ribRotationReference&&) = delete;
            #else
            CPACSRibRotation_ribRotationReference(const CPACSRibRotation_ribRotationReference&);
            CPACSRibRotation_ribRotationReference& operator=(const CPACSRibRotation_ribRotationReference&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef HAVE_CPP11
    using CCPACSRibRotation_ribRotationReference = generated::CPACSRibRotation_ribRotationReference;
    #else
    typedef generated::CPACSRibRotation_ribRotationReference CCPACSRibRotation_ribRotationReference;
    #endif
}
