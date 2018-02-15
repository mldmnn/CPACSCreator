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

#include <CCPACSWingSparPositions.h>
#include <CCPACSWingSparSegments.h>
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSWingCSStructure;

namespace generated
{
    // This class is used in:
    // CPACSWingComponentSegmentStructure
    
    // generated from /xsd:schema/xsd:complexType[959]
    class CPACSWingSpar
    {
    public:
        TIGL_EXPORT CPACSWingSpar(CCPACSWingCSStructure* parent, CTiglUIDManager* uidMgr);
        
        TIGL_EXPORT virtual ~CPACSWingSpar();
        
        TIGL_EXPORT CCPACSWingCSStructure* GetParent() const;
        
        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;
        
        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
        
        TIGL_EXPORT virtual const CCPACSWingSparPositions& GetSparPositions() const;
        TIGL_EXPORT virtual CCPACSWingSparPositions& GetSparPositions();
        
        TIGL_EXPORT virtual const CCPACSWingSparSegments& GetSparSegments() const;
        TIGL_EXPORT virtual CCPACSWingSparSegments& GetSparSegments();
        
    protected:
        CCPACSWingCSStructure* m_parent;
        
        CTiglUIDManager* m_uidMgr;
        
        CCPACSWingSparPositions m_sparPositions;
        CCPACSWingSparSegments  m_sparSegments;
        
    private:
#ifdef HAVE_CPP11
        CPACSWingSpar(const CPACSWingSpar&) = delete;
        CPACSWingSpar& operator=(const CPACSWingSpar&) = delete;
        
        CPACSWingSpar(CPACSWingSpar&&) = delete;
        CPACSWingSpar& operator=(CPACSWingSpar&&) = delete;
#else
        CPACSWingSpar(const CPACSWingSpar&);
        CPACSWingSpar& operator=(const CPACSWingSpar&);
#endif
    };
} // namespace generated

// CPACSWingSpar is customized, use type CCPACSWingSpars directly
} // namespace tigl
