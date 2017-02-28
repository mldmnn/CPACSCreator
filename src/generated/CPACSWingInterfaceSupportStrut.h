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
        // CPACSWingInterfaceSupportStrutsAssembly
        
        // generated from /xsd:schema/xsd:complexType[907]
        class CPACSWingInterfaceSupportStrut
        {
        public:
            TIGL_EXPORT CPACSWingInterfaceSupportStrut();
            TIGL_EXPORT virtual ~CPACSWingInterfaceSupportStrut();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT bool HasUID() const;
            TIGL_EXPORT const std::string& GetUID() const;
            TIGL_EXPORT void SetUID(const std::string& value);
            
            TIGL_EXPORT const std::string& GetName() const;
            TIGL_EXPORT void SetName(const std::string& value);
            
            TIGL_EXPORT bool HasDescription() const;
            TIGL_EXPORT const std::string& GetDescription() const;
            TIGL_EXPORT void SetDescription(const std::string& value);
            
            TIGL_EXPORT const std::string& GetStructuralElementUID() const;
            TIGL_EXPORT void SetStructuralElementUID(const std::string& value);
            
            TIGL_EXPORT const std::string& GetWingAttachmentPinUID() const;
            TIGL_EXPORT void SetWingAttachmentPinUID(const std::string& value);
            
            TIGL_EXPORT bool HasFuselageAttachmentFrameUID() const;
            TIGL_EXPORT const std::string& GetFuselageAttachmentFrameUID() const;
            TIGL_EXPORT void SetFuselageAttachmentFrameUID(const std::string& value);
            
            TIGL_EXPORT bool HasFuselageAttachmentStringerUID() const;
            TIGL_EXPORT const std::string& GetFuselageAttachmentStringerUID() const;
            TIGL_EXPORT void SetFuselageAttachmentStringerUID(const std::string& value);
            
        protected:
            boost::optional<std::string> m_uID;
            std::string                  m_name;
            boost::optional<std::string> m_description;
            std::string                  m_structuralElementUID;
            std::string                  m_wingAttachmentPinUID;
            boost::optional<std::string> m_fuselageAttachmentFrameUID;
            boost::optional<std::string> m_fuselageAttachmentStringerUID;
            
        private:
            #ifdef HAVE_CPP11
            CPACSWingInterfaceSupportStrut(const CPACSWingInterfaceSupportStrut&) = delete;
            CPACSWingInterfaceSupportStrut& operator=(const CPACSWingInterfaceSupportStrut&) = delete;
            
            CPACSWingInterfaceSupportStrut(CPACSWingInterfaceSupportStrut&&) = delete;
            CPACSWingInterfaceSupportStrut& operator=(CPACSWingInterfaceSupportStrut&&) = delete;
            #else
            CPACSWingInterfaceSupportStrut(const CPACSWingInterfaceSupportStrut&);
            CPACSWingInterfaceSupportStrut& operator=(const CPACSWingInterfaceSupportStrut&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSWingInterfaceSupportStrut = generated::CPACSWingInterfaceSupportStrut;
    #else
    typedef generated::CPACSWingInterfaceSupportStrut CCPACSWingInterfaceSupportStrut;
    #endif
}
