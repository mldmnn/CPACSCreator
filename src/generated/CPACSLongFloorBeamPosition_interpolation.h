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
        // CPACSLongFloorBeamPosition
        
        // generated from /xsd:schema/xsd:complexType[505]/xsd:complexContent/xsd:extension/xsd:all/xsd:element[6]/xsd:complexType
        class CPACSLongFloorBeamPosition_interpolation
        {
        public:
            TIGL_EXPORT CPACSLongFloorBeamPosition_interpolation();
            TIGL_EXPORT virtual ~CPACSLongFloorBeamPosition_interpolation();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const CPACSInterpolation& GetSimpleContent() const;
            TIGL_EXPORT void SetSimpleContent(const CPACSInterpolation& value);
            
        protected:
            CPACSInterpolation m_simpleContent;
            
        private:
            #ifdef HAVE_CPP11
            CPACSLongFloorBeamPosition_interpolation(const CPACSLongFloorBeamPosition_interpolation&) = delete;
            CPACSLongFloorBeamPosition_interpolation& operator=(const CPACSLongFloorBeamPosition_interpolation&) = delete;
            
            CPACSLongFloorBeamPosition_interpolation(CPACSLongFloorBeamPosition_interpolation&&) = delete;
            CPACSLongFloorBeamPosition_interpolation& operator=(CPACSLongFloorBeamPosition_interpolation&&) = delete;
            #else
            CPACSLongFloorBeamPosition_interpolation(const CPACSLongFloorBeamPosition_interpolation&);
            CPACSLongFloorBeamPosition_interpolation& operator=(const CPACSLongFloorBeamPosition_interpolation&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSLongFloorBeamPosition_interpolation = generated::CPACSLongFloorBeamPosition_interpolation;
    #else
    typedef generated::CPACSLongFloorBeamPosition_interpolation CCPACSLongFloorBeamPosition_interpolation;
    #endif
}
