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
#include <CCPACSWingSparPositionUIDs.h>
#include "CPACSSparCrossSection.h"

namespace tigl
{
    class CCPACSWingSparSegments;
    
    namespace generated
    {
        // This class is used in:
        // CPACSSparSegments
        
        // generated from /xsd:schema/xsd:complexType[789]
        class CPACSSparSegment
        {
        public:
            TIGL_EXPORT CPACSSparSegment(CCPACSWingSparSegments* parent);
            
            TIGL_EXPORT virtual ~CPACSSparSegment();
            
            TIGL_EXPORT CCPACSWingSparSegments* GetParent() const;
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const std::string& GetUID() const;
            TIGL_EXPORT void SetUID(const std::string& value);
            
            TIGL_EXPORT const std::string& GetName() const;
            TIGL_EXPORT void SetName(const std::string& value);
            
            TIGL_EXPORT const std::string& GetDescription() const;
            TIGL_EXPORT void SetDescription(const std::string& value);
            
            TIGL_EXPORT const CCPACSWingSparPositionUIDs& GetSparPositionUIDs() const;
            TIGL_EXPORT CCPACSWingSparPositionUIDs& GetSparPositionUIDs();
            
            TIGL_EXPORT const CPACSSparCrossSection& GetSparCrossSection() const;
            TIGL_EXPORT CPACSSparCrossSection& GetSparCrossSection();
            
        protected:
            CCPACSWingSparSegments* m_parent;
            
            std::string                m_uID;
            std::string                m_name;
            std::string                m_description;
            CCPACSWingSparPositionUIDs m_sparPositionUIDs;
            CPACSSparCrossSection      m_sparCrossSection;
            
        private:
            #ifdef HAVE_CPP11
            CPACSSparSegment(const CPACSSparSegment&) = delete;
            CPACSSparSegment& operator=(const CPACSSparSegment&) = delete;
            
            CPACSSparSegment(CPACSSparSegment&&) = delete;
            CPACSSparSegment& operator=(CPACSSparSegment&&) = delete;
            #else
            CPACSSparSegment(const CPACSSparSegment&);
            CPACSSparSegment& operator=(const CPACSSparSegment&);
            #endif
        };
    }
    
    // CPACSSparSegment is customized, use type CCPACSWingSparSegment directly
}
