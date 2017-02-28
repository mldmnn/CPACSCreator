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
#include "CPACSInterpolation.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSGeneralStructuralMemberPosition
        
        // generated from /xsd:schema/xsd:complexType[381]/xsd:complexContent/xsd:extension/xsd:all/xsd:element[13]/xsd:complexType
        class CPACSGeneralStructuralMemberPosition_interpolation
        {
        public:
            TIGL_EXPORT CPACSGeneralStructuralMemberPosition_interpolation();
            TIGL_EXPORT virtual ~CPACSGeneralStructuralMemberPosition_interpolation();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const CPACSInterpolation& GetSimpleContent() const;
            TIGL_EXPORT void SetSimpleContent(const CPACSInterpolation& value);
            
        protected:
            CPACSInterpolation m_simpleContent;
            
        private:
            #ifdef HAVE_CPP11
            CPACSGeneralStructuralMemberPosition_interpolation(const CPACSGeneralStructuralMemberPosition_interpolation&) = delete;
            CPACSGeneralStructuralMemberPosition_interpolation& operator=(const CPACSGeneralStructuralMemberPosition_interpolation&) = delete;
            
            CPACSGeneralStructuralMemberPosition_interpolation(CPACSGeneralStructuralMemberPosition_interpolation&&) = delete;
            CPACSGeneralStructuralMemberPosition_interpolation& operator=(CPACSGeneralStructuralMemberPosition_interpolation&&) = delete;
            #else
            CPACSGeneralStructuralMemberPosition_interpolation(const CPACSGeneralStructuralMemberPosition_interpolation&);
            CPACSGeneralStructuralMemberPosition_interpolation& operator=(const CPACSGeneralStructuralMemberPosition_interpolation&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSGeneralStructuralMemberPosition_interpolation = generated::CPACSGeneralStructuralMemberPosition_interpolation;
    #else
    typedef generated::CPACSGeneralStructuralMemberPosition_interpolation CCPACSGeneralStructuralMemberPosition_interpolation;
    #endif
}
