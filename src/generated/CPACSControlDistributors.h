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
#include "tigl_internal.h"

namespace tigl
{
    namespace generated
    {
        class CPACSControlDistributor;
        
        // This class is used in:
        // CPACSSystems
        
        // generated from /xsd:schema/xsd:complexType[156]
        class CPACSControlDistributors
        {
        public:
            TIGL_EXPORT CPACSControlDistributors();
            TIGL_EXPORT virtual ~CPACSControlDistributors();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const std::vector<unique_ptr<CPACSControlDistributor>>& GetControlDistributor() const;
            TIGL_EXPORT std::vector<unique_ptr<CPACSControlDistributor>>& GetControlDistributor();
            
        protected:
            std::vector<unique_ptr<CPACSControlDistributor>> m_controlDistributor;
            
        private:
            #ifdef HAVE_CPP11
            CPACSControlDistributors(const CPACSControlDistributors&) = delete;
            CPACSControlDistributors& operator=(const CPACSControlDistributors&) = delete;
            
            CPACSControlDistributors(CPACSControlDistributors&&) = delete;
            CPACSControlDistributors& operator=(CPACSControlDistributors&&) = delete;
            #else
            CPACSControlDistributors(const CPACSControlDistributors&);
            CPACSControlDistributors& operator=(const CPACSControlDistributors&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSControlDistributors = generated::CPACSControlDistributors;
    #else
    typedef generated::CPACSControlDistributors CCPACSControlDistributors;
    #endif
    
    using generated::CPACSControlDistributor;
}
