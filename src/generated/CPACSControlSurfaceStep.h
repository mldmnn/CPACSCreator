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
#include <CCPACSPoint.h>
#include "CPACSPointXZ.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSControlSurfaceSteps
        
        // generated from /xsd:schema/xsd:complexType[188]
        class CPACSControlSurfaceStep
        {
        public:
            TIGL_EXPORT CPACSControlSurfaceStep();
            TIGL_EXPORT virtual ~CPACSControlSurfaceStep();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const double& GetRelDeflection() const;
            TIGL_EXPORT void SetRelDeflection(const double& value);
            
            TIGL_EXPORT bool HasInnerHingeTranslation() const;
            TIGL_EXPORT const CCPACSPoint& GetInnerHingeTranslation() const;
            TIGL_EXPORT CCPACSPoint& GetInnerHingeTranslation();
            
            TIGL_EXPORT bool HasOuterHingeTranslation() const;
            TIGL_EXPORT const CPACSPointXZ& GetOuterHingeTranslation() const;
            TIGL_EXPORT CPACSPointXZ& GetOuterHingeTranslation();
            
            TIGL_EXPORT bool HasHingeLineRotation() const;
            TIGL_EXPORT const double& GetHingeLineRotation() const;
            TIGL_EXPORT void SetHingeLineRotation(const double& value);
            
        protected:
            double                        m_relDeflection;
            boost::optional<CCPACSPoint>  m_innerHingeTranslation;
            boost::optional<CPACSPointXZ> m_outerHingeTranslation;
            boost::optional<double>       m_hingeLineRotation;
            
        private:
            #ifdef HAVE_CPP11
            CPACSControlSurfaceStep(const CPACSControlSurfaceStep&) = delete;
            CPACSControlSurfaceStep& operator=(const CPACSControlSurfaceStep&) = delete;
            
            CPACSControlSurfaceStep(CPACSControlSurfaceStep&&) = delete;
            CPACSControlSurfaceStep& operator=(CPACSControlSurfaceStep&&) = delete;
            #else
            CPACSControlSurfaceStep(const CPACSControlSurfaceStep&);
            CPACSControlSurfaceStep& operator=(const CPACSControlSurfaceStep&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef CPP11
    using CCPACSControlSurfaceStep = generated::CPACSControlSurfaceStep;
    #else
    typedef generated::CPACSControlSurfaceStep CCPACSControlSurfaceStep;
    #endif
}
