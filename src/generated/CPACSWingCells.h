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
    class CCPACSWingCell;
    class CCPACSWingShell;
    
    namespace generated
    {
        // This class is used in:
        // CPACSWingShell
        
        // generated from /xsd:schema/xsd:complexType[893]
        class CPACSWingCells
        {
        public:
            TIGL_EXPORT CPACSWingCells(CCPACSWingShell* parent, CTiglUIDManager* uidMgr);
            
            TIGL_EXPORT virtual ~CPACSWingCells();
            
            TIGL_EXPORT CCPACSWingShell* GetParent() const;
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT virtual const std::vector<unique_ptr<CCPACSWingCell> >& GetCells() const;
            TIGL_EXPORT virtual std::vector<unique_ptr<CCPACSWingCell> >& GetCells();
            
        protected:
            CCPACSWingShell* m_parent;
            
            CTiglUIDManager* m_uidMgr;
            
            std::vector<unique_ptr<CCPACSWingCell> > m_cells;
            
        private:
            #ifdef HAVE_CPP11
            CPACSWingCells(const CPACSWingCells&) = delete;
            CPACSWingCells& operator=(const CPACSWingCells&) = delete;
            
            CPACSWingCells(CPACSWingCells&&) = delete;
            CPACSWingCells& operator=(CPACSWingCells&&) = delete;
            #else
            CPACSWingCells(const CPACSWingCells&);
            CPACSWingCells& operator=(const CPACSWingCells&);
            #endif
        };
    }
    
    // CPACSWingCells is customized, use type CCPACSWingCells directly
}
