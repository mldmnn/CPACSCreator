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
#include <boost/utility/in_place_factory.hpp>
#include "tigl_internal.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSTransformation
        
        // generated from /xsd:schema/xsd:complexType[689]
        class CPACSPoint
        {
        public:
            TIGL_EXPORT CPACSPoint();
            TIGL_EXPORT virtual ~CPACSPoint();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const boost::optional<std::string>& GetUID() const;
            TIGL_EXPORT void SetUID(const std::string& value);
            TIGL_EXPORT void SetUID(const boost::optional<std::string>& value);
            
            TIGL_EXPORT const boost::optional<double>& GetX() const;
            TIGL_EXPORT void SetX(const double& value);
            TIGL_EXPORT void SetX(const boost::optional<double>& value);
            
            TIGL_EXPORT const boost::optional<double>& GetY() const;
            TIGL_EXPORT void SetY(const double& value);
            TIGL_EXPORT void SetY(const boost::optional<double>& value);
            
            TIGL_EXPORT const boost::optional<double>& GetZ() const;
            TIGL_EXPORT void SetZ(const double& value);
            TIGL_EXPORT void SetZ(const boost::optional<double>& value);
            
        protected:
            boost::optional<std::string> m_uID;
            boost::optional<double>      m_x;
            boost::optional<double>      m_y;
            boost::optional<double>      m_z;
            
        private:
            #ifdef HAVE_CPP11
            CPACSPoint(const CPACSPoint&) = delete;
            CPACSPoint& operator=(const CPACSPoint&) = delete;
            
            CPACSPoint(CPACSPoint&&) = delete;
            CPACSPoint& operator=(CPACSPoint&&) = delete;
            #else
            CPACSPoint(const CPACSPoint&);
            CPACSPoint& operator=(const CPACSPoint&);
            #endif
        };
    }
    
    // CPACSPoint is customized, use type CCPACSPoint directly
}
