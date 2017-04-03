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
#include "CTiglError.h"
#include <typeinfo>
#include "tigl_internal.h"
#include <TiglSymmetryAxis.h>
#include <CCPACSTransformation.h>
#include <CCPACSWingSections.h>
#include <CCPACSPositionings.h>
#include <CCPACSWingSegments.h>
#include <CCPACSWingComponentSegments.h>

namespace tigl
{
    class CCPACSRotorBlades;
    class CCPACSWings;
    
    namespace generated
    {
        // This class is used in:
        // CPACSRotorBlades
        // CPACSWings
        
        // generated from /xsd:schema/xsd:complexType[929]
        class CPACSWing
        {
        public:
            TIGL_EXPORT CPACSWing(CCPACSRotorBlades* parent);
            TIGL_EXPORT CPACSWing(CCPACSWings* parent);
            
            TIGL_EXPORT virtual ~CPACSWing();
            
            template<typename P>
            TIGL_EXPORT bool IsParent() const
            {
                return m_parentType != NULL && *m_parentType == typeid(P);
            }
            
            template<typename P>
            TIGL_EXPORT P* GetParent() const
            {
                #ifdef HAVE_CPP11
                static_assert(std::is_same<P, CCPACSRotorBlades>::value || std::is_same<P, CCPACSWings>::value, "template argument for P is not a parent class of CPACSWing");
                #endif
                if (!IsParent<P>()) {
                    throw CTiglError("bad parent");
                }
                return static_cast<P*>(m_parent);
            }
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const std::string& GetUID() const;
            TIGL_EXPORT void SetUID(const std::string& value);
            
            TIGL_EXPORT const boost::optional<TiglSymmetryAxis>& GetSymmetry() const;
            TIGL_EXPORT void SetSymmetry(const TiglSymmetryAxis& value);
            TIGL_EXPORT void SetSymmetry(const boost::optional<TiglSymmetryAxis>& value);
            
            TIGL_EXPORT const std::string& GetName() const;
            TIGL_EXPORT void SetName(const std::string& value);
            
            TIGL_EXPORT const boost::optional<std::string>& GetDescription() const;
            TIGL_EXPORT void SetDescription(const std::string& value);
            TIGL_EXPORT void SetDescription(const boost::optional<std::string>& value);
            
            TIGL_EXPORT const boost::optional<std::string>& GetParentUID() const;
            TIGL_EXPORT void SetParentUID(const std::string& value);
            TIGL_EXPORT void SetParentUID(const boost::optional<std::string>& value);
            
            TIGL_EXPORT const CCPACSTransformation& GetTransformation() const;
            TIGL_EXPORT CCPACSTransformation& GetTransformation();
            
            TIGL_EXPORT const CCPACSWingSections& GetSections() const;
            TIGL_EXPORT CCPACSWingSections& GetSections();
            
            TIGL_EXPORT const boost::optional<CCPACSPositionings>& GetPositionings() const;
            TIGL_EXPORT boost::optional<CCPACSPositionings>& GetPositionings();
            
            TIGL_EXPORT const CCPACSWingSegments& GetSegments() const;
            TIGL_EXPORT CCPACSWingSegments& GetSegments();
            
            TIGL_EXPORT const boost::optional<CCPACSWingComponentSegments>& GetComponentSegments() const;
            TIGL_EXPORT boost::optional<CCPACSWingComponentSegments>& GetComponentSegments();
            
        protected:
            void* m_parent;
            const std::type_info* m_parentType;
            
            std::string                                  m_uID;
            boost::optional<TiglSymmetryAxis>            m_symmetry;
            std::string                                  m_name;
            boost::optional<std::string>                 m_description;
            boost::optional<std::string>                 m_parentUID;
            CCPACSTransformation                         m_transformation;
            CCPACSWingSections                           m_sections;
            boost::optional<CCPACSPositionings>          m_positionings;
            CCPACSWingSegments                           m_segments;
            boost::optional<CCPACSWingComponentSegments> m_componentSegments;
            
        private:
            #ifdef HAVE_CPP11
            CPACSWing(const CPACSWing&) = delete;
            CPACSWing& operator=(const CPACSWing&) = delete;
            
            CPACSWing(CPACSWing&&) = delete;
            CPACSWing& operator=(CPACSWing&&) = delete;
            #else
            CPACSWing(const CPACSWing&);
            CPACSWing& operator=(const CPACSWing&);
            #endif
        };
    }
    
    // Aliases in tigl namespace
    // CPACSWing is customized, use type CCPACSWing directly
}
