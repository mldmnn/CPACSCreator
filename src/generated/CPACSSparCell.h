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
#include "CPACSCap.h"
#include "CPACSCap.h"
#include "CPACSWeb.h"
#include "CPACSWeb.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSSparCells
        
        // generated from /xsd:schema/xsd:complexType[783]
        class CPACSSparCell
        {
        public:
            TIGL_EXPORT CPACSSparCell();
            TIGL_EXPORT virtual ~CPACSSparCell();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const std::string& GetUID() const;
            TIGL_EXPORT void SetUID(const std::string& value);
            
            TIGL_EXPORT const double& GetFromEta() const;
            TIGL_EXPORT void SetFromEta(const double& value);
            
            TIGL_EXPORT const double& GetToEta() const;
            TIGL_EXPORT void SetToEta(const double& value);
            
            TIGL_EXPORT const CPACSCap& GetUpperCap() const;
            TIGL_EXPORT CPACSCap& GetUpperCap();
            
            TIGL_EXPORT const CPACSCap& GetLowerCap() const;
            TIGL_EXPORT CPACSCap& GetLowerCap();
            
            TIGL_EXPORT const CPACSWeb& GetWeb1() const;
            TIGL_EXPORT CPACSWeb& GetWeb1();
            
            TIGL_EXPORT const boost::optional<CPACSWeb>& GetWeb2() const;
            TIGL_EXPORT boost::optional<CPACSWeb>& GetWeb2();
            
            TIGL_EXPORT const double& GetRotation() const;
            TIGL_EXPORT void SetRotation(const double& value);
            
        protected:
            std::string               m_uID;
            double                    m_fromEta;
            double                    m_toEta;
            CPACSCap                  m_upperCap;
            CPACSCap                  m_lowerCap;
            CPACSWeb                  m_web1;
            boost::optional<CPACSWeb> m_web2;
            double                    m_rotation;
            
        private:
            #ifdef HAVE_CPP11
            CPACSSparCell(const CPACSSparCell&) = delete;
            CPACSSparCell& operator=(const CPACSSparCell&) = delete;
            
            CPACSSparCell(CPACSSparCell&&) = delete;
            CPACSSparCell& operator=(CPACSSparCell&&) = delete;
            #else
            CPACSSparCell(const CPACSSparCell&);
            CPACSSparCell& operator=(const CPACSSparCell&);
            #endif
        };
    }
    
    // Aliases in tigl namespace
    #ifdef HAVE_CPP11
    using CCPACSSparCell = generated::CPACSSparCell;
    #else
    typedef generated::CPACSSparCell CCPACSSparCell;
    #endif
}
