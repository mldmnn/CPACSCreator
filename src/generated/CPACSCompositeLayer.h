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
        // CPACSComposite
        
        // generated from /xsd:schema/xsd:complexType[146]
        class CPACSCompositeLayer
        {
        public:
            TIGL_EXPORT CPACSCompositeLayer();
            TIGL_EXPORT virtual ~CPACSCompositeLayer();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT bool HasName() const;
            TIGL_EXPORT const std::string& GetName() const;
            TIGL_EXPORT void SetName(const std::string& value);
            
            TIGL_EXPORT bool HasDescription() const;
            TIGL_EXPORT const std::string& GetDescription() const;
            TIGL_EXPORT void SetDescription(const std::string& value);
            
            TIGL_EXPORT const double& GetThickness() const;
            TIGL_EXPORT void SetThickness(const double& value);
            
            TIGL_EXPORT const double& GetPhi() const;
            TIGL_EXPORT void SetPhi(const double& value);
            
            TIGL_EXPORT const std::string& GetMaterialUID() const;
            TIGL_EXPORT void SetMaterialUID(const std::string& value);
            
        protected:
            boost::optional<std::string> m_name;
            boost::optional<std::string> m_description;
            double                       m_thickness;
            double                       m_phi;
            std::string                  m_materialUID;
            
        private:
            #ifdef HAVE_CPP11
            CPACSCompositeLayer(const CPACSCompositeLayer&) = delete;
            CPACSCompositeLayer& operator=(const CPACSCompositeLayer&) = delete;
            
            CPACSCompositeLayer(CPACSCompositeLayer&&) = delete;
            CPACSCompositeLayer& operator=(CPACSCompositeLayer&&) = delete;
            #else
            CPACSCompositeLayer(const CPACSCompositeLayer&);
            CPACSCompositeLayer& operator=(const CPACSCompositeLayer&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef HAVE_CPP11
    using CCPACSCompositeLayer = generated::CPACSCompositeLayer;
    #else
    typedef generated::CPACSCompositeLayer CCPACSCompositeLayer;
    #endif
}
