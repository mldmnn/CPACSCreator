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
#include <vector>
#include "UniquePtr.h"
#include <boost/optional.hpp>
#include "tigl_internal.h"

namespace tigl
{
    namespace generated
    {
        class CPACSVtpFrameDef;
        
        // This class is used in:
        // CPACSTailplaneAttachmentArea
        
        // generated from /xsd:schema/xsd:complexType[874]
        class CPACSVtpInterfaceDef
        {
        public:
            TIGL_EXPORT CPACSVtpInterfaceDef();
            TIGL_EXPORT virtual ~CPACSVtpInterfaceDef();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT bool HasUID() const;
            TIGL_EXPORT const std::string& GetUID() const;
            TIGL_EXPORT void SetUID(const std::string& value);
            
            TIGL_EXPORT const std::vector<unique_ptr<CPACSVtpFrameDef>>& GetVtpFrameDefinitions() const;
            TIGL_EXPORT std::vector<unique_ptr<CPACSVtpFrameDef>>& GetVtpFrameDefinitions();
            
            TIGL_EXPORT bool HasVtpAreaToleranceX() const;
            TIGL_EXPORT const double& GetVtpAreaToleranceX() const;
            TIGL_EXPORT void SetVtpAreaToleranceX(const double& value);
            
            TIGL_EXPORT bool HasVtpAreaToleranceZ() const;
            TIGL_EXPORT const double& GetVtpAreaToleranceZ() const;
            TIGL_EXPORT void SetVtpAreaToleranceZ(const double& value);
            
            TIGL_EXPORT const double& GetVtpReinfRelZ() const;
            TIGL_EXPORT void SetVtpReinfRelZ(const double& value);
            
            TIGL_EXPORT const double& GetVtpReinfRelWidth() const;
            TIGL_EXPORT void SetVtpReinfRelWidth(const double& value);
            
            TIGL_EXPORT const double& GetVtpIntersectionArc() const;
            TIGL_EXPORT void SetVtpIntersectionArc(const double& value);
            
            TIGL_EXPORT const std::string& GetVtpAttachmentStructElemUID() const;
            TIGL_EXPORT void SetVtpAttachmentStructElemUID(const std::string& value);
            
        protected:
            boost::optional<std::string>              m_uID;
            std::vector<unique_ptr<CPACSVtpFrameDef>> m_vtpFrameDefinitions;
            boost::optional<double>                   m_vtpAreaToleranceX;
            boost::optional<double>                   m_vtpAreaToleranceZ;
            double                                    m_vtpReinfRelZ;
            double                                    m_vtpReinfRelWidth;
            double                                    m_vtpIntersectionArc;
            std::string                               m_vtpAttachmentStructElemUID;
            
        private:
            #ifdef HAVE_CPP11
            CPACSVtpInterfaceDef(const CPACSVtpInterfaceDef&) = delete;
            CPACSVtpInterfaceDef& operator=(const CPACSVtpInterfaceDef&) = delete;
            
            CPACSVtpInterfaceDef(CPACSVtpInterfaceDef&&) = delete;
            CPACSVtpInterfaceDef& operator=(CPACSVtpInterfaceDef&&) = delete;
            #else
            CPACSVtpInterfaceDef(const CPACSVtpInterfaceDef&);
            CPACSVtpInterfaceDef& operator=(const CPACSVtpInterfaceDef&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSVtpInterfaceDef = generated::CPACSVtpInterfaceDef;
    #else
    typedef generated::CPACSVtpInterfaceDef CCPACSVtpInterfaceDef;
    #endif
    
    using generated::CPACSVtpFrameDef;
}
