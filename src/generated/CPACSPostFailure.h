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

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <string>
#include <tixi.h>
#include <vector>
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
    namespace generated
    {
        class CPACSPlasticityCurvePoint;
        
        // This class is used in:
        // CPACSMaterial
        
        // generated from /xsd:schema/xsd:complexType[727]
        class CPACSPostFailure
        {
        public:
            TIGL_EXPORT CPACSPostFailure();
            TIGL_EXPORT virtual ~CPACSPostFailure();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT bool ValidateChoices() const;
            
            TIGL_EXPORT virtual const boost::optional<std::string>& GetName() const;
            TIGL_EXPORT virtual void SetName(const boost::optional<std::string>& value);
            
            TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
            TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);
            
            TIGL_EXPORT virtual const boost::optional<std::string>& GetMaterialLaw() const;
            TIGL_EXPORT virtual void SetMaterialLaw(const boost::optional<std::string>& value);
            
            TIGL_EXPORT virtual const boost::optional<double>& GetPlasticEliminationStrain_choice1() const;
            TIGL_EXPORT virtual void SetPlasticEliminationStrain_choice1(const boost::optional<double>& value);
            
            TIGL_EXPORT virtual const std::vector<unique_ptr<CPACSPlasticityCurvePoint> >& GetPlasticityCurvePoints_choice1() const;
            TIGL_EXPORT virtual std::vector<unique_ptr<CPACSPlasticityCurvePoint> >& GetPlasticityCurvePoints_choice1();
            
            TIGL_EXPORT virtual const boost::optional<double>& GetInitialEquivalentShearStrain_choice2() const;
            TIGL_EXPORT virtual void SetInitialEquivalentShearStrain_choice2(const boost::optional<double>& value);
            
            TIGL_EXPORT virtual const boost::optional<double>& GetIntermediateEquivalentShearStrain_choice2() const;
            TIGL_EXPORT virtual void SetIntermediateEquivalentShearStrain_choice2(const boost::optional<double>& value);
            
            TIGL_EXPORT virtual const boost::optional<double>& GetUltimateEquivalentShearStrain_choice2() const;
            TIGL_EXPORT virtual void SetUltimateEquivalentShearStrain_choice2(const boost::optional<double>& value);
            
            TIGL_EXPORT virtual const boost::optional<double>& GetIntermediateDamage_choice2() const;
            TIGL_EXPORT virtual void SetIntermediateDamage_choice2(const boost::optional<double>& value);
            
            TIGL_EXPORT virtual const boost::optional<double>& GetUltimateDamage_choice2() const;
            TIGL_EXPORT virtual void SetUltimateDamage_choice2(const boost::optional<double>& value);
            
            TIGL_EXPORT virtual CPACSPlasticityCurvePoint& AddPlasticityCurvePoint_choice1();
            TIGL_EXPORT virtual void RemovePlasticityCurvePoint_choice1(CPACSPlasticityCurvePoint& ref);
            
        protected:
            boost::optional<std::string>                        m_name;
            boost::optional<std::string>                        m_description;
            boost::optional<std::string>                        m_materialLaw;
            boost::optional<double>                             m_plasticEliminationStrain_choice1;
            std::vector<unique_ptr<CPACSPlasticityCurvePoint> > m_plasticityCurvePoints_choice1;
            boost::optional<double>                             m_initialEquivalentShearStrain_choice2;
            boost::optional<double>                             m_intermediateEquivalentShearStrain_choice2;
            boost::optional<double>                             m_ultimateEquivalentShearStrain_choice2;
            boost::optional<double>                             m_intermediateDamage_choice2;
            boost::optional<double>                             m_ultimateDamage_choice2;
            
        private:
            #ifdef HAVE_CPP11
            CPACSPostFailure(const CPACSPostFailure&) = delete;
            CPACSPostFailure& operator=(const CPACSPostFailure&) = delete;
            
            CPACSPostFailure(CPACSPostFailure&&) = delete;
            CPACSPostFailure& operator=(CPACSPostFailure&&) = delete;
            #else
            CPACSPostFailure(const CPACSPostFailure&);
            CPACSPostFailure& operator=(const CPACSPostFailure&);
            #endif
        };
    }
    
    // Aliases in tigl namespace
    #ifdef HAVE_CPP11
    using CCPACSPostFailure = generated::CPACSPostFailure;
    using CCPACSPlasticityCurvePoint = generated::CPACSPlasticityCurvePoint;
    #else
    typedef generated::CPACSPostFailure CCPACSPostFailure;
    typedef generated::CPACSPlasticityCurvePoint CCPACSPlasticityCurvePoint;
    #endif
}
