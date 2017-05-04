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

#include <string>
#include <TiglFarFieldType.h>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSCFDTool
        
        // generated from /xsd:schema/xsd:complexType[317]
        class CPACSFarField
        {
        public:
            TIGL_EXPORT CPACSFarField();
            TIGL_EXPORT virtual ~CPACSFarField();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT virtual const TiglFarFieldType& GetType() const;
            TIGL_EXPORT virtual void SetType(const TiglFarFieldType& value);
            
            TIGL_EXPORT virtual const double& GetReferenceLength() const;
            TIGL_EXPORT virtual void SetReferenceLength(const double& value);
            
            TIGL_EXPORT virtual const double& GetMultiplier() const;
            TIGL_EXPORT virtual void SetMultiplier(const double& value);
            
        protected:
            TiglFarFieldType m_type;
            double           m_referenceLength;
            double           m_multiplier;
            
        private:
            #ifdef HAVE_CPP11
            CPACSFarField(const CPACSFarField&) = delete;
            CPACSFarField& operator=(const CPACSFarField&) = delete;
            
            CPACSFarField(CPACSFarField&&) = delete;
            CPACSFarField& operator=(CPACSFarField&&) = delete;
            #else
            CPACSFarField(const CPACSFarField&);
            CPACSFarField& operator=(const CPACSFarField&);
            #endif
        };
    }
    
    // CPACSFarField is customized, use type CCPACSFarField directly
}
