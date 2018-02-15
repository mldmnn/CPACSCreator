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

#include <string>
#include <tixi.h>
#include <vector>
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSWingSection;
class CCPACSWing;

namespace generated
{
    // This class is used in:
    // CPACSWing
    
    // generated from /xsd:schema/xsd:complexType[951]
    class CPACSWingSections
    {
    public:
        TIGL_EXPORT CPACSWingSections(CCPACSWing* parent, CTiglUIDManager* uidMgr);
        
        TIGL_EXPORT virtual ~CPACSWingSections();
        
        TIGL_EXPORT CCPACSWing* GetParent() const;
        
        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;
        
        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
        
        TIGL_EXPORT virtual const std::vector<unique_ptr<CCPACSWingSection> >& GetSections() const;
        TIGL_EXPORT virtual std::vector<unique_ptr<CCPACSWingSection> >& GetSections();
        
        TIGL_EXPORT virtual CCPACSWingSection& AddSection();
        TIGL_EXPORT virtual void RemoveSection(CCPACSWingSection& ref);
        
    protected:
        CCPACSWing* m_parent;
        
        CTiglUIDManager* m_uidMgr;
        
        std::vector<unique_ptr<CCPACSWingSection> > m_sections;
        
    private:
#ifdef HAVE_CPP11
        CPACSWingSections(const CPACSWingSections&) = delete;
        CPACSWingSections& operator=(const CPACSWingSections&) = delete;
        
        CPACSWingSections(CPACSWingSections&&) = delete;
        CPACSWingSections& operator=(CPACSWingSections&&) = delete;
#else
        CPACSWingSections(const CPACSWingSections&);
        CPACSWingSections& operator=(const CPACSWingSections&);
#endif
    };
} // namespace generated

// CPACSWingSections is customized, use type CCPACSWingSections directly
} // namespace tigl
