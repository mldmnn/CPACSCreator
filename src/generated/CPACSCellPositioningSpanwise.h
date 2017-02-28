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
#include "tigl_internal.h"

namespace tigl
{
    class CCPACSWingCell;
    
    namespace generated
    {
        class CPACSWingIntermediateStructureCell;
        
        // This class is used in:
        // CPACSWingCell
        // CPACSWingIntermediateStructureCell
        
        // generated from /xsd:schema/xsd:complexType[118]
        class CPACSCellPositioningSpanwise
        {
        public:
            TIGL_EXPORT CPACSCellPositioningSpanwise(CCPACSWingCell* parent);
            TIGL_EXPORT CPACSCellPositioningSpanwise(CPACSWingIntermediateStructureCell* parent);
            
            TIGL_EXPORT virtual ~CPACSCellPositioningSpanwise();
            
            template<typename P>
            TIGL_EXPORT bool IsParent() const
            {
                return m_parentType != nullptr && *m_parentType == typeid(P);
            }
            
            template<typename P>
            TIGL_EXPORT P* GetParent() const
            {
                #ifdef HAVE_CPP11
                static_assert(std::is_same<P, CCPACSWingCell>::value || std::is_same<P, CPACSWingIntermediateStructureCell>::value, "template argument for P is not a parent class of CPACSCellPositioningSpanwise");
                #endif
                if (!IsParent<P>()) {
                    throw CTiglError("bad parent");
                }
                return static_cast<P*>(m_parent);
            }
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT bool HasEta1_choice1() const;
            TIGL_EXPORT const double& GetEta1_choice1() const;
            TIGL_EXPORT void SetEta1_choice1(const double& value);
            
            TIGL_EXPORT bool HasEta2_choice1() const;
            TIGL_EXPORT const double& GetEta2_choice1() const;
            TIGL_EXPORT void SetEta2_choice1(const double& value);
            
            TIGL_EXPORT bool HasRibNumber_choice2() const;
            TIGL_EXPORT const int& GetRibNumber_choice2() const;
            TIGL_EXPORT void SetRibNumber_choice2(const int& value);
            
            TIGL_EXPORT bool HasRibDefinitionUID_choice2() const;
            TIGL_EXPORT const std::string& GetRibDefinitionUID_choice2() const;
            TIGL_EXPORT void SetRibDefinitionUID_choice2(const std::string& value);
            
        protected:
            void* m_parent;
            const std::type_info* m_parentType;
            
            boost::optional<double>      m_eta1_choice1;
            boost::optional<double>      m_eta2_choice1;
            boost::optional<int>         m_ribNumber_choice2;
            boost::optional<std::string> m_ribDefinitionUID_choice2;
            
        private:
            #ifdef HAVE_CPP11
            CPACSCellPositioningSpanwise(const CPACSCellPositioningSpanwise&) = delete;
            CPACSCellPositioningSpanwise& operator=(const CPACSCellPositioningSpanwise&) = delete;
            
            CPACSCellPositioningSpanwise(CPACSCellPositioningSpanwise&&) = delete;
            CPACSCellPositioningSpanwise& operator=(CPACSCellPositioningSpanwise&&) = delete;
            #else
            CPACSCellPositioningSpanwise(const CPACSCellPositioningSpanwise&);
            CPACSCellPositioningSpanwise& operator=(const CPACSCellPositioningSpanwise&);
            #endif
        };
    }
    
    // This type is customized, use type CCPACSWingCellPositionSpanwise
    
    using generated::CPACSWingIntermediateStructureCell;
}
