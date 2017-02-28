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
        // CPACSControlSurfaceBorderLeadingEdge
        // CPACSControlSurfaceBorderSpoiler
        // CPACSControlSurfaceBorderTrailingEdge
        
        // generated from /xsd:schema/xsd:complexType[154]
        class CPACSContourReference
        {
        public:
            TIGL_EXPORT CPACSContourReference();
            TIGL_EXPORT virtual ~CPACSContourReference();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const std::string& GetAirfoilUID() const;
            TIGL_EXPORT void SetAirfoilUID(const std::string& value);
            
            TIGL_EXPORT const double& GetRotX() const;
            TIGL_EXPORT void SetRotX(const double& value);
            
            TIGL_EXPORT const double& GetScalY() const;
            TIGL_EXPORT void SetScalY(const double& value);
            
            TIGL_EXPORT const double& GetScalZ() const;
            TIGL_EXPORT void SetScalZ(const double& value);
            
        protected:
            std::string m_airfoilUID;
            double      m_rotX;
            double      m_scalY;
            double      m_scalZ;
            
        private:
            #ifdef HAVE_CPP11
            CPACSContourReference(const CPACSContourReference&) = delete;
            CPACSContourReference& operator=(const CPACSContourReference&) = delete;
            
            CPACSContourReference(CPACSContourReference&&) = delete;
            CPACSContourReference& operator=(CPACSContourReference&&) = delete;
            #else
            CPACSContourReference(const CPACSContourReference&);
            CPACSContourReference& operator=(const CPACSContourReference&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSContourReference = generated::CPACSContourReference;
    #else
    typedef generated::CPACSContourReference CCPACSContourReference;
    #endif
}
