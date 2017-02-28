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
#include "tigl_internal.h"
#include <CCPACSMaterial.h>
#include "CPACSInterConnectionStrutAttachment.h"
#include "CPACSInterConnectionStrutAttachment.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSZCouplings
        
        // generated from /xsd:schema/xsd:complexType[938]
        class CPACSZCoupling
        {
        public:
            TIGL_EXPORT CPACSZCoupling();
            TIGL_EXPORT virtual ~CPACSZCoupling();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const std::string& GetUID() const;
            TIGL_EXPORT void SetUID(const std::string& value);
            
            TIGL_EXPORT const std::string& GetToControlSurfaceUID() const;
            TIGL_EXPORT void SetToControlSurfaceUID(const std::string& value);
            
            TIGL_EXPORT const CCPACSMaterial& GetMaterial() const;
            TIGL_EXPORT CCPACSMaterial& GetMaterial();
            
            TIGL_EXPORT const CPACSInterConnectionStrutAttachment& GetFromAttachment() const;
            TIGL_EXPORT CPACSInterConnectionStrutAttachment& GetFromAttachment();
            
            TIGL_EXPORT const CPACSInterConnectionStrutAttachment& GetToAttachment() const;
            TIGL_EXPORT CPACSInterConnectionStrutAttachment& GetToAttachment();
            
        protected:
            std::string                         m_uID;
            std::string                         m_toControlSurfaceUID;
            CCPACSMaterial                      m_material;
            CPACSInterConnectionStrutAttachment m_fromAttachment;
            CPACSInterConnectionStrutAttachment m_toAttachment;
            
        private:
            #ifdef HAVE_CPP11
            CPACSZCoupling(const CPACSZCoupling&) = delete;
            CPACSZCoupling& operator=(const CPACSZCoupling&) = delete;
            
            CPACSZCoupling(CPACSZCoupling&&) = delete;
            CPACSZCoupling& operator=(CPACSZCoupling&&) = delete;
            #else
            CPACSZCoupling(const CPACSZCoupling&);
            CPACSZCoupling& operator=(const CPACSZCoupling&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSZCoupling = generated::CPACSZCoupling;
    #else
    typedef generated::CPACSZCoupling CCPACSZCoupling;
    #endif
}
