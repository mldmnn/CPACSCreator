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
#include <CCPACSTransformation.h>
#include "CPACSRotorHubHinge_type.h"

namespace tigl
{
    class CCPACSRotorHinges;
    
    namespace generated
    {
        // This class is used in:
        // CPACSRotorHubHinges
        
        // generated from /xsd:schema/xsd:complexType[740]
        class CPACSRotorHubHinge
        {
        public:
            TIGL_EXPORT CPACSRotorHubHinge(CCPACSRotorHinges* parent);
            
            TIGL_EXPORT virtual ~CPACSRotorHubHinge();
            
            TIGL_EXPORT CCPACSRotorHinges* GetParent() const;
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const boost::optional<std::string>& GetUID() const;
            TIGL_EXPORT void SetUID(const std::string& value);
            TIGL_EXPORT void SetUID(const boost::optional<std::string>& value);
            
            TIGL_EXPORT const boost::optional<std::string>& GetName() const;
            TIGL_EXPORT void SetName(const std::string& value);
            TIGL_EXPORT void SetName(const boost::optional<std::string>& value);
            
            TIGL_EXPORT const boost::optional<std::string>& GetDescription() const;
            TIGL_EXPORT void SetDescription(const std::string& value);
            TIGL_EXPORT void SetDescription(const boost::optional<std::string>& value);
            
            TIGL_EXPORT const CCPACSTransformation& GetTransformation() const;
            TIGL_EXPORT CCPACSTransformation& GetTransformation();
            
            TIGL_EXPORT const CPACSRotorHubHinge_type& GetType() const;
            TIGL_EXPORT void SetType(const CPACSRotorHubHinge_type& value);
            
            TIGL_EXPORT const boost::optional<double>& GetNeutralPosition() const;
            TIGL_EXPORT void SetNeutralPosition(const double& value);
            TIGL_EXPORT void SetNeutralPosition(const boost::optional<double>& value);
            
            TIGL_EXPORT const boost::optional<double>& GetStaticStiffness() const;
            TIGL_EXPORT void SetStaticStiffness(const double& value);
            TIGL_EXPORT void SetStaticStiffness(const boost::optional<double>& value);
            
            TIGL_EXPORT const boost::optional<double>& GetDynamicStiffness() const;
            TIGL_EXPORT void SetDynamicStiffness(const double& value);
            TIGL_EXPORT void SetDynamicStiffness(const boost::optional<double>& value);
            
            TIGL_EXPORT const boost::optional<double>& GetDamping() const;
            TIGL_EXPORT void SetDamping(const double& value);
            TIGL_EXPORT void SetDamping(const boost::optional<double>& value);
            
        protected:
            CCPACSRotorHinges* m_parent;
            
            boost::optional<std::string> m_uID;
            boost::optional<std::string> m_name;
            boost::optional<std::string> m_description;
            CCPACSTransformation         m_transformation;
            CPACSRotorHubHinge_type      m_type;
            boost::optional<double>      m_neutralPosition;
            boost::optional<double>      m_staticStiffness;
            boost::optional<double>      m_dynamicStiffness;
            boost::optional<double>      m_damping;
            
        private:
            #ifdef HAVE_CPP11
            CPACSRotorHubHinge(const CPACSRotorHubHinge&) = delete;
            CPACSRotorHubHinge& operator=(const CPACSRotorHubHinge&) = delete;
            
            CPACSRotorHubHinge(CPACSRotorHubHinge&&) = delete;
            CPACSRotorHubHinge& operator=(CPACSRotorHubHinge&&) = delete;
            #else
            CPACSRotorHubHinge(const CPACSRotorHubHinge&);
            CPACSRotorHubHinge& operator=(const CPACSRotorHubHinge&);
            #endif
        };
    }
    
    // CPACSRotorHubHinge is customized, use type CCPACSRotorHinge directly
}
