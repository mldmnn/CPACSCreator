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
#include "CPACSCockpitControl.h"
#include "CPACSCockpitControl.h"
#include "CPACSCockpitControl.h"

namespace tigl
{
    namespace generated
    {
        class CPACSCockpitControl;
        
        // This class is used in:
        // CPACSSystems
        
        // generated from /xsd:schema/xsd:complexType[133]
        class CPACSCockpitControls
        {
        public:
            TIGL_EXPORT CPACSCockpitControls();
            TIGL_EXPORT virtual ~CPACSCockpitControls();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const CPACSCockpitControl& GetStickPitch() const;
            TIGL_EXPORT CPACSCockpitControl& GetStickPitch();
            
            TIGL_EXPORT const CPACSCockpitControl& GetStickRoll() const;
            TIGL_EXPORT CPACSCockpitControl& GetStickRoll();
            
            TIGL_EXPORT const CPACSCockpitControl& GetPedals() const;
            TIGL_EXPORT CPACSCockpitControl& GetPedals();
            
            TIGL_EXPORT const std::vector<unique_ptr<CPACSCockpitControl>>& GetCockpitControl() const;
            TIGL_EXPORT std::vector<unique_ptr<CPACSCockpitControl>>& GetCockpitControl();
            
        protected:
            CPACSCockpitControl                          m_stickPitch;
            CPACSCockpitControl                          m_stickRoll;
            CPACSCockpitControl                          m_pedals;
            std::vector<unique_ptr<CPACSCockpitControl>> m_cockpitControl;
            
        private:
            #ifdef HAVE_CPP11
            CPACSCockpitControls(const CPACSCockpitControls&) = delete;
            CPACSCockpitControls& operator=(const CPACSCockpitControls&) = delete;
            
            CPACSCockpitControls(CPACSCockpitControls&&) = delete;
            CPACSCockpitControls& operator=(CPACSCockpitControls&&) = delete;
            #else
            CPACSCockpitControls(const CPACSCockpitControls&);
            CPACSCockpitControls& operator=(const CPACSCockpitControls&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSCockpitControls = generated::CPACSCockpitControls;
    #else
    typedef generated::CPACSCockpitControls CCPACSCockpitControls;
    #endif
    
    using generated::CPACSCockpitControl;
}
