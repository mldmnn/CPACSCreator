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

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSComponentSegmentPath
        
        // generated from /xsd:schema/xsd:complexType[445]
        class CPACSHingePointComponentSegmentPath
        {
        public:
            TIGL_EXPORT CPACSHingePointComponentSegmentPath();
            TIGL_EXPORT virtual ~CPACSHingePointComponentSegmentPath();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const double& GetEta() const;
            TIGL_EXPORT void SetEta(const double& value);
            
            TIGL_EXPORT const double& GetXsi() const;
            TIGL_EXPORT void SetXsi(const double& value);
            
            TIGL_EXPORT const double& GetRelHeight() const;
            TIGL_EXPORT void SetRelHeight(const double& value);
            
        protected:
            double m_eta;
            double m_xsi;
            double m_relHeight;
            
        private:
            #ifdef HAVE_CPP11
            CPACSHingePointComponentSegmentPath(const CPACSHingePointComponentSegmentPath&) = delete;
            CPACSHingePointComponentSegmentPath& operator=(const CPACSHingePointComponentSegmentPath&) = delete;
            
            CPACSHingePointComponentSegmentPath(CPACSHingePointComponentSegmentPath&&) = delete;
            CPACSHingePointComponentSegmentPath& operator=(CPACSHingePointComponentSegmentPath&&) = delete;
            #else
            CPACSHingePointComponentSegmentPath(const CPACSHingePointComponentSegmentPath&);
            CPACSHingePointComponentSegmentPath& operator=(const CPACSHingePointComponentSegmentPath&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSHingePointComponentSegmentPath = generated::CPACSHingePointComponentSegmentPath;
    #else
    typedef generated::CPACSHingePointComponentSegmentPath CCPACSHingePointComponentSegmentPath;
    #endif
}
