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

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
class CCPACSWingCell;

namespace generated
{
    // This class is used in:
    // CPACSWingCell
    
    // generated from /xsd:schema/xsd:complexType[116]
    class CPACSCellPositioningSpanwise
    {
    public:
        TIGL_EXPORT CPACSCellPositioningSpanwise(CCPACSWingCell* parent);
        
        TIGL_EXPORT virtual ~CPACSCellPositioningSpanwise();
        
        TIGL_EXPORT CCPACSWingCell* GetParent() const;
        
        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
        
        TIGL_EXPORT bool ValidateChoices() const;
        
        TIGL_EXPORT virtual const boost::optional<double>& GetEta1_choice1() const;
        TIGL_EXPORT virtual void SetEta1_choice1(const boost::optional<double>& value);
        
        TIGL_EXPORT virtual const boost::optional<double>& GetEta2_choice1() const;
        TIGL_EXPORT virtual void SetEta2_choice1(const boost::optional<double>& value);
        
        TIGL_EXPORT virtual const boost::optional<int>& GetRibNumber_choice2() const;
        TIGL_EXPORT virtual void SetRibNumber_choice2(const boost::optional<int>& value);
        
        TIGL_EXPORT virtual const boost::optional<std::string>& GetRibDefinitionUID_choice2() const;
        TIGL_EXPORT virtual void SetRibDefinitionUID_choice2(const boost::optional<std::string>& value);
        
    protected:
        CCPACSWingCell* m_parent;
        
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
} // namespace generated

// CPACSCellPositioningSpanwise is customized, use type CCPACSWingCellPositionSpanwise directly
} // namespace tigl
