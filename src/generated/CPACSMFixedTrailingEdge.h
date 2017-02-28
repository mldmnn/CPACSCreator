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
#include "CPACSGenericMass.h"
#include "CPACSSingleGenericMass.h"
#include "CPACSMControlSurfaceSupports.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSMWingBox
        
        // generated from /xsd:schema/xsd:complexType[549]
        class CPACSMFixedTrailingEdge
        {
        public:
            TIGL_EXPORT CPACSMFixedTrailingEdge();
            TIGL_EXPORT virtual ~CPACSMFixedTrailingEdge();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const CPACSGenericMass& GetMassDescription() const;
            TIGL_EXPORT CPACSGenericMass& GetMassDescription();
            
            TIGL_EXPORT bool HasMPanelsAndFalsework() const;
            TIGL_EXPORT const CPACSSingleGenericMass& GetMPanelsAndFalsework() const;
            TIGL_EXPORT CPACSSingleGenericMass& GetMPanelsAndFalsework();
            
            TIGL_EXPORT bool HasMControlSurfaceSupports() const;
            TIGL_EXPORT const CPACSMControlSurfaceSupports& GetMControlSurfaceSupports() const;
            TIGL_EXPORT CPACSMControlSurfaceSupports& GetMControlSurfaceSupports();
            
        protected:
            CPACSGenericMass                              m_massDescription;
            boost::optional<CPACSSingleGenericMass>       m_mPanelsAndFalsework;
            boost::optional<CPACSMControlSurfaceSupports> m_mControlSurfaceSupports;
            
        private:
            #ifdef HAVE_CPP11
            CPACSMFixedTrailingEdge(const CPACSMFixedTrailingEdge&) = delete;
            CPACSMFixedTrailingEdge& operator=(const CPACSMFixedTrailingEdge&) = delete;
            
            CPACSMFixedTrailingEdge(CPACSMFixedTrailingEdge&&) = delete;
            CPACSMFixedTrailingEdge& operator=(CPACSMFixedTrailingEdge&&) = delete;
            #else
            CPACSMFixedTrailingEdge(const CPACSMFixedTrailingEdge&);
            CPACSMFixedTrailingEdge& operator=(const CPACSMFixedTrailingEdge&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSMFixedTrailingEdge = generated::CPACSMFixedTrailingEdge;
    #else
    typedef generated::CPACSMFixedTrailingEdge CCPACSMFixedTrailingEdge;
    #endif
}
