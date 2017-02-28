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
#include <boost/optional.hpp>
#include "tigl_internal.h"
#include "CPACSCoefficients.h"

namespace tigl
{
    namespace generated
    {
        class CPACSFuselageSegmentCoefficients;
        
        // This class is used in:
        // CPACSFuselageCoefficients
        
        // generated from /xsd:schema/xsd:complexType[371]
        class CPACSFuselageSegmentsCoefficients
        {
        public:
            TIGL_EXPORT CPACSFuselageSegmentsCoefficients();
            TIGL_EXPORT virtual ~CPACSFuselageSegmentsCoefficients();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const std::vector<unique_ptr<CPACSFuselageSegmentCoefficients>>& GetSegment() const;
            TIGL_EXPORT std::vector<unique_ptr<CPACSFuselageSegmentCoefficients>>& GetSegment();
            
            TIGL_EXPORT bool HasCalibration() const;
            TIGL_EXPORT const CPACSCoefficients& GetCalibration() const;
            TIGL_EXPORT CPACSCoefficients& GetCalibration();
            
        protected:
            std::vector<unique_ptr<CPACSFuselageSegmentCoefficients>> m_segment;
            boost::optional<CPACSCoefficients>                        m_calibration;
            
        private:
            #ifdef HAVE_CPP11
            CPACSFuselageSegmentsCoefficients(const CPACSFuselageSegmentsCoefficients&) = delete;
            CPACSFuselageSegmentsCoefficients& operator=(const CPACSFuselageSegmentsCoefficients&) = delete;
            
            CPACSFuselageSegmentsCoefficients(CPACSFuselageSegmentsCoefficients&&) = delete;
            CPACSFuselageSegmentsCoefficients& operator=(CPACSFuselageSegmentsCoefficients&&) = delete;
            #else
            CPACSFuselageSegmentsCoefficients(const CPACSFuselageSegmentsCoefficients&);
            CPACSFuselageSegmentsCoefficients& operator=(const CPACSFuselageSegmentsCoefficients&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSFuselageSegmentsCoefficients = generated::CPACSFuselageSegmentsCoefficients;
    #else
    typedef generated::CPACSFuselageSegmentsCoefficients CCPACSFuselageSegmentsCoefficients;
    #endif
    
    using generated::CPACSFuselageSegmentCoefficients;
}
