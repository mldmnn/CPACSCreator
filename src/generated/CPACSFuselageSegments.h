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
    class CCPACSFuselageSegment;
    class CCPACSFuselage;
    
    namespace generated
    {
        // This class is used in:
        // CPACSFuselage
        
        // generated from /xsd:schema/xsd:complexType[372]
        class CPACSFuselageSegments
        {
        public:
            TIGL_EXPORT CPACSFuselageSegments(CCPACSFuselage* parent);
            
            TIGL_EXPORT virtual ~CPACSFuselageSegments();
            
            TIGL_EXPORT CCPACSFuselage* GetParent() const;
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const std::vector<unique_ptr<CCPACSFuselageSegment> >& GetSegments() const;
            TIGL_EXPORT std::vector<unique_ptr<CCPACSFuselageSegment> >& GetSegments();
            
        protected:
            CCPACSFuselage* m_parent;
            
            std::vector<unique_ptr<CCPACSFuselageSegment> > m_segments;
            
        private:
            #ifdef HAVE_CPP11
            CPACSFuselageSegments(const CPACSFuselageSegments&) = delete;
            CPACSFuselageSegments& operator=(const CPACSFuselageSegments&) = delete;
            
            CPACSFuselageSegments(CPACSFuselageSegments&&) = delete;
            CPACSFuselageSegments& operator=(CPACSFuselageSegments&&) = delete;
            #else
            CPACSFuselageSegments(const CPACSFuselageSegments&);
            CPACSFuselageSegments& operator=(const CPACSFuselageSegments&);
            #endif
        };
    }
    
    // CPACSFuselageSegments is customized, use type CCPACSFuselageSegments directly
}
