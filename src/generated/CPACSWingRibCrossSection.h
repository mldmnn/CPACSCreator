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
#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include "tigl_internal.h"
#include <CCPACSMaterial.h>
#include "CPACSPointX.h"
#include "CPACSWingRibCell.h"
#include "CPACSCap.h"
#include "CPACSCap.h"

namespace tigl
{
    class CCPACSWingRibsDefinition;
    
    namespace generated
    {
        // This class is used in:
        // CPACSWingRibsDefinition
        
        // generated from /xsd:schema/xsd:complexType[912]
        class CPACSWingRibCrossSection
        {
        public:
            TIGL_EXPORT CPACSWingRibCrossSection(CCPACSWingRibsDefinition* parent);
            
            TIGL_EXPORT virtual ~CPACSWingRibCrossSection();
            
            TIGL_EXPORT CCPACSWingRibsDefinition* GetParent() const;
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const CCPACSMaterial& GetMaterial() const;
            TIGL_EXPORT CCPACSMaterial& GetMaterial();
            
            TIGL_EXPORT const boost::optional<CPACSPointX>& GetRibRotation() const;
            TIGL_EXPORT boost::optional<CPACSPointX>& GetRibRotation();
            
            TIGL_EXPORT const boost::optional<CPACSWingRibCell>& GetRibCell() const;
            TIGL_EXPORT boost::optional<CPACSWingRibCell>& GetRibCell();
            
            TIGL_EXPORT const boost::optional<CPACSCap>& GetUpperCap() const;
            TIGL_EXPORT boost::optional<CPACSCap>& GetUpperCap();
            
            TIGL_EXPORT const boost::optional<CPACSCap>& GetLowerCap() const;
            TIGL_EXPORT boost::optional<CPACSCap>& GetLowerCap();
            
        protected:
            CCPACSWingRibsDefinition* m_parent;
            
            CCPACSMaterial                    m_material;
            boost::optional<CPACSPointX>      m_ribRotation;
            boost::optional<CPACSWingRibCell> m_ribCell;
            boost::optional<CPACSCap>         m_upperCap;
            boost::optional<CPACSCap>         m_lowerCap;
            
        private:
            #ifdef HAVE_CPP11
            CPACSWingRibCrossSection(const CPACSWingRibCrossSection&) = delete;
            CPACSWingRibCrossSection& operator=(const CPACSWingRibCrossSection&) = delete;
            
            CPACSWingRibCrossSection(CPACSWingRibCrossSection&&) = delete;
            CPACSWingRibCrossSection& operator=(CPACSWingRibCrossSection&&) = delete;
            #else
            CPACSWingRibCrossSection(const CPACSWingRibCrossSection&);
            CPACSWingRibCrossSection& operator=(const CPACSWingRibCrossSection&);
            #endif
        };
    }
    
    // Aliases in tigl namespace
    // CPACSWingRibCrossSection is customized, use type CCPACSWingRibCrossSection directly
}
