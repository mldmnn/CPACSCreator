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
        // CPACSCenterFuselageLowWingConfiguration
        
        // generated from /xsd:schema/xsd:complexType[128]
        class CPACSCenterFuselageSidebox
        {
        public:
            TIGL_EXPORT CPACSCenterFuselageSidebox();
            TIGL_EXPORT virtual ~CPACSCenterFuselageSidebox();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT bool HasUID() const;
            TIGL_EXPORT const std::string& GetUID() const;
            TIGL_EXPORT void SetUID(const std::string& value);
            
            TIGL_EXPORT const double& GetSideboxWidthFactor() const;
            TIGL_EXPORT void SetSideboxWidthFactor(const double& value);
            
            TIGL_EXPORT const std::string& GetSheetElementUID() const;
            TIGL_EXPORT void SetSheetElementUID(const std::string& value);
            
        protected:
            boost::optional<std::string> m_uID;
            double                       m_sideboxWidthFactor;
            std::string                  m_sheetElementUID;
            
        private:
            #ifdef HAVE_CPP11
            CPACSCenterFuselageSidebox(const CPACSCenterFuselageSidebox&) = delete;
            CPACSCenterFuselageSidebox& operator=(const CPACSCenterFuselageSidebox&) = delete;
            
            CPACSCenterFuselageSidebox(CPACSCenterFuselageSidebox&&) = delete;
            CPACSCenterFuselageSidebox& operator=(CPACSCenterFuselageSidebox&&) = delete;
            #else
            CPACSCenterFuselageSidebox(const CPACSCenterFuselageSidebox&);
            CPACSCenterFuselageSidebox& operator=(const CPACSCenterFuselageSidebox&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSCenterFuselageSidebox = generated::CPACSCenterFuselageSidebox;
    #else
    typedef generated::CPACSCenterFuselageSidebox CCPACSCenterFuselageSidebox;
    #endif
}
