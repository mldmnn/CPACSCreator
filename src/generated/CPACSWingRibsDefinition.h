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
#include <CCPACSWingRibCrossSection.h>
#include <CCPACSWingRibsPositioning.h>
#include <string>
#include <tixi.h>
#include "CPACSWingRibExplicitPositioning.h"
#include "CreateIfNotExists.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSWingRibsDefinitions;

namespace generated
{
    // This class is used in:
    // CPACSWingRibsDefinitions
    
    // generated from /xsd:schema/xsd:complexType[947]
    class CPACSWingRibsDefinition
    {
    public:
        TIGL_EXPORT CPACSWingRibsDefinition(CCPACSWingRibsDefinitions* parent, CTiglUIDManager* uidMgr);
        
        TIGL_EXPORT virtual ~CPACSWingRibsDefinition();
        
        TIGL_EXPORT CCPACSWingRibsDefinitions* GetParent() const;
        
        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;
        
        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
        
        TIGL_EXPORT bool ValidateChoices() const;
        
        TIGL_EXPORT virtual const boost::optional<std::string>& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const boost::optional<std::string>& value);
        
        TIGL_EXPORT virtual const std::string& GetName() const;
        TIGL_EXPORT virtual void SetName(const std::string& value);
        
        TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);
        
        TIGL_EXPORT virtual const CCPACSWingRibCrossSection& GetRibCrossSection() const;
        TIGL_EXPORT virtual CCPACSWingRibCrossSection& GetRibCrossSection();
        
        TIGL_EXPORT virtual const boost::optional<CCPACSWingRibsPositioning>& GetRibsPositioning_choice1() const;
        TIGL_EXPORT virtual boost::optional<CCPACSWingRibsPositioning>& GetRibsPositioning_choice1();
        
        TIGL_EXPORT virtual const boost::optional<CPACSWingRibExplicitPositioning>& GetRibExplicitPositioning_choice2() const;
        TIGL_EXPORT virtual boost::optional<CPACSWingRibExplicitPositioning>& GetRibExplicitPositioning_choice2();
        
        TIGL_EXPORT virtual CCPACSWingRibsPositioning& GetRibsPositioning_choice1(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveRibsPositioning_choice1();
        
        TIGL_EXPORT virtual CPACSWingRibExplicitPositioning& GetRibExplicitPositioning_choice2(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveRibExplicitPositioning_choice2();
        
    protected:
        CCPACSWingRibsDefinitions* m_parent;
        
        CTiglUIDManager* m_uidMgr;
        
        boost::optional<std::string>                     m_uID;
        std::string                                      m_name;
        boost::optional<std::string>                     m_description;
        CCPACSWingRibCrossSection                        m_ribCrossSection;
        boost::optional<CCPACSWingRibsPositioning>       m_ribsPositioning_choice1;
        boost::optional<CPACSWingRibExplicitPositioning> m_ribExplicitPositioning_choice2;
        
    private:
#ifdef HAVE_CPP11
        CPACSWingRibsDefinition(const CPACSWingRibsDefinition&) = delete;
        CPACSWingRibsDefinition& operator=(const CPACSWingRibsDefinition&) = delete;
        
        CPACSWingRibsDefinition(CPACSWingRibsDefinition&&) = delete;
        CPACSWingRibsDefinition& operator=(CPACSWingRibsDefinition&&) = delete;
#else
        CPACSWingRibsDefinition(const CPACSWingRibsDefinition&);
        CPACSWingRibsDefinition& operator=(const CPACSWingRibsDefinition&);
#endif
    };
} // namespace generated

// CPACSWingRibsDefinition is customized, use type CCPACSWingRibsDefinition directly
} // namespace tigl
