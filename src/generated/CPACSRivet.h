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
    namespace generated
    {
        // This class is used in:
        // CPACSRivets
        
        // generated from /xsd:schema/xsd:complexType[733]
        class CPACSRivet
        {
        public:
            TIGL_EXPORT CPACSRivet();
            TIGL_EXPORT virtual ~CPACSRivet();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const std::string& GetUID() const;
            TIGL_EXPORT void SetUID(const std::string& value);
            
            TIGL_EXPORT bool HasName() const;
            TIGL_EXPORT const std::string& GetName() const;
            TIGL_EXPORT void SetName(const std::string& value);
            
            TIGL_EXPORT bool HasDescription() const;
            TIGL_EXPORT const std::string& GetDescription() const;
            TIGL_EXPORT void SetDescription(const std::string& value);
            
            TIGL_EXPORT const double& GetTensileStrength() const;
            TIGL_EXPORT void SetTensileStrength(const double& value);
            
            TIGL_EXPORT const double& GetShearStrength() const;
            TIGL_EXPORT void SetShearStrength(const double& value);
            
        protected:
            std::string                  m_uID;
            boost::optional<std::string> m_name;
            boost::optional<std::string> m_description;
            double                       m_tensileStrength;
            double                       m_shearStrength;
            
        private:
            #ifdef HAVE_CPP11
            CPACSRivet(const CPACSRivet&) = delete;
            CPACSRivet& operator=(const CPACSRivet&) = delete;
            
            CPACSRivet(CPACSRivet&&) = delete;
            CPACSRivet& operator=(CPACSRivet&&) = delete;
            #else
            CPACSRivet(const CPACSRivet&);
            CPACSRivet& operator=(const CPACSRivet&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSRivet = generated::CPACSRivet;
    #else
    typedef generated::CPACSRivet CCPACSRivet;
    #endif
}
