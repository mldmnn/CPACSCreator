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
#include "CPACSControlSurfaceTrackType_trackType_SimpleContent.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSControlSurfaceTrackType
        
        // generated from /xsd:schema/xsd:complexType[190]/xsd:complexContent/xsd:extension/xsd:sequence/xsd:element[2]/xsd:complexType
        class CPACSControlSurfaceTrackType_trackType
        {
        public:
            TIGL_EXPORT CPACSControlSurfaceTrackType_trackType();
            TIGL_EXPORT virtual ~CPACSControlSurfaceTrackType_trackType();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const CPACSControlSurfaceTrackType_trackType_SimpleContent& GetSimpleContent() const;
            TIGL_EXPORT void SetSimpleContent(const CPACSControlSurfaceTrackType_trackType_SimpleContent& value);
            
        protected:
            CPACSControlSurfaceTrackType_trackType_SimpleContent m_simpleContent;
            
        private:
            #ifdef HAVE_CPP11
            CPACSControlSurfaceTrackType_trackType(const CPACSControlSurfaceTrackType_trackType&) = delete;
            CPACSControlSurfaceTrackType_trackType& operator=(const CPACSControlSurfaceTrackType_trackType&) = delete;
            
            CPACSControlSurfaceTrackType_trackType(CPACSControlSurfaceTrackType_trackType&&) = delete;
            CPACSControlSurfaceTrackType_trackType& operator=(CPACSControlSurfaceTrackType_trackType&&) = delete;
            #else
            CPACSControlSurfaceTrackType_trackType(const CPACSControlSurfaceTrackType_trackType&);
            CPACSControlSurfaceTrackType_trackType& operator=(const CPACSControlSurfaceTrackType_trackType&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSControlSurfaceTrackType_trackType = generated::CPACSControlSurfaceTrackType_trackType;
    #else
    typedef generated::CPACSControlSurfaceTrackType_trackType CCPACSControlSurfaceTrackType_trackType;
    #endif
}
