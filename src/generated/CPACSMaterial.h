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

namespace tigl
{
    namespace generated
    {
        class CPACSPostFailure;
        
        // This class is used in:
        // CPACSMaterials
        
        // generated from /xsd:schema/xsd:complexType[641]
        class CPACSMaterial
        {
        public:
            TIGL_EXPORT CPACSMaterial();
            TIGL_EXPORT virtual ~CPACSMaterial();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT bool HasUID() const;
            TIGL_EXPORT const std::string& GetUID() const;
            TIGL_EXPORT void SetUID(const std::string& value);
            
            TIGL_EXPORT const std::string& GetName() const;
            TIGL_EXPORT void SetName(const std::string& value);
            
            TIGL_EXPORT bool HasDescription() const;
            TIGL_EXPORT const std::string& GetDescription() const;
            TIGL_EXPORT void SetDescription(const std::string& value);
            
            TIGL_EXPORT const double& GetRho() const;
            TIGL_EXPORT void SetRho(const double& value);
            
            TIGL_EXPORT const double& GetK11() const;
            TIGL_EXPORT void SetK11(const double& value);
            
            TIGL_EXPORT const double& GetK12() const;
            TIGL_EXPORT void SetK12(const double& value);
            
            TIGL_EXPORT bool HasMaxStrain() const;
            TIGL_EXPORT const double& GetMaxStrain() const;
            TIGL_EXPORT void SetMaxStrain(const double& value);
            
            TIGL_EXPORT bool HasFatigueFactor() const;
            TIGL_EXPORT const double& GetFatigueFactor() const;
            TIGL_EXPORT void SetFatigueFactor(const double& value);
            
            TIGL_EXPORT const std::vector<unique_ptr<CPACSPostFailure> >& GetPostFailure() const;
            TIGL_EXPORT std::vector<unique_ptr<CPACSPostFailure> >& GetPostFailure();
            
            TIGL_EXPORT bool HasSig11_choice1() const;
            TIGL_EXPORT const double& GetSig11_choice1() const;
            TIGL_EXPORT void SetSig11_choice1(const double& value);
            
            TIGL_EXPORT bool HasTau12_choice1() const;
            TIGL_EXPORT const double& GetTau12_choice1() const;
            TIGL_EXPORT void SetTau12_choice1(const double& value);
            
            TIGL_EXPORT bool HasSig11yieldT_choice1() const;
            TIGL_EXPORT const double& GetSig11yieldT_choice1() const;
            TIGL_EXPORT void SetSig11yieldT_choice1(const double& value);
            
            TIGL_EXPORT bool HasSig11yieldC_choice1() const;
            TIGL_EXPORT const double& GetSig11yieldC_choice1() const;
            TIGL_EXPORT void SetSig11yieldC_choice1(const double& value);
            
            TIGL_EXPORT bool HasK22_choice2() const;
            TIGL_EXPORT const double& GetK22_choice2() const;
            TIGL_EXPORT void SetK22_choice2(const double& value);
            
            TIGL_EXPORT bool HasK23_choice2() const;
            TIGL_EXPORT const double& GetK23_choice2() const;
            TIGL_EXPORT void SetK23_choice2(const double& value);
            
            TIGL_EXPORT bool HasK66_choice2() const;
            TIGL_EXPORT const double& GetK66_choice2() const;
            TIGL_EXPORT void SetK66_choice2(const double& value);
            
            TIGL_EXPORT bool HasSig11t_choice2() const;
            TIGL_EXPORT const double& GetSig11t_choice2() const;
            TIGL_EXPORT void SetSig11t_choice2(const double& value);
            
            TIGL_EXPORT bool HasSig11c_choice2() const;
            TIGL_EXPORT const double& GetSig11c_choice2() const;
            TIGL_EXPORT void SetSig11c_choice2(const double& value);
            
            TIGL_EXPORT bool HasSig22t_choice2() const;
            TIGL_EXPORT const double& GetSig22t_choice2() const;
            TIGL_EXPORT void SetSig22t_choice2(const double& value);
            
            TIGL_EXPORT bool HasSig22c_choice2() const;
            TIGL_EXPORT const double& GetSig22c_choice2() const;
            TIGL_EXPORT void SetSig22c_choice2(const double& value);
            
            TIGL_EXPORT bool HasTau12_choice2() const;
            TIGL_EXPORT const double& GetTau12_choice2() const;
            TIGL_EXPORT void SetTau12_choice2(const double& value);
            
            TIGL_EXPORT bool HasTau23_choice2() const;
            TIGL_EXPORT const double& GetTau23_choice2() const;
            TIGL_EXPORT void SetTau23_choice2(const double& value);
            
            TIGL_EXPORT bool HasK13_choice3() const;
            TIGL_EXPORT const double& GetK13_choice3() const;
            TIGL_EXPORT void SetK13_choice3(const double& value);
            
            TIGL_EXPORT bool HasK22_choice3() const;
            TIGL_EXPORT const double& GetK22_choice3() const;
            TIGL_EXPORT void SetK22_choice3(const double& value);
            
            TIGL_EXPORT bool HasK23_choice3() const;
            TIGL_EXPORT const double& GetK23_choice3() const;
            TIGL_EXPORT void SetK23_choice3(const double& value);
            
            TIGL_EXPORT bool HasK33_choice3() const;
            TIGL_EXPORT const double& GetK33_choice3() const;
            TIGL_EXPORT void SetK33_choice3(const double& value);
            
            TIGL_EXPORT bool HasK44_choice3() const;
            TIGL_EXPORT const double& GetK44_choice3() const;
            TIGL_EXPORT void SetK44_choice3(const double& value);
            
            TIGL_EXPORT bool HasK55_choice3() const;
            TIGL_EXPORT const double& GetK55_choice3() const;
            TIGL_EXPORT void SetK55_choice3(const double& value);
            
            TIGL_EXPORT bool HasK66_choice3() const;
            TIGL_EXPORT const double& GetK66_choice3() const;
            TIGL_EXPORT void SetK66_choice3(const double& value);
            
            TIGL_EXPORT bool HasSig11t_choice3() const;
            TIGL_EXPORT const double& GetSig11t_choice3() const;
            TIGL_EXPORT void SetSig11t_choice3(const double& value);
            
            TIGL_EXPORT bool HasSig11c_choice3() const;
            TIGL_EXPORT const double& GetSig11c_choice3() const;
            TIGL_EXPORT void SetSig11c_choice3(const double& value);
            
            TIGL_EXPORT bool HasSig22t_choice3() const;
            TIGL_EXPORT const double& GetSig22t_choice3() const;
            TIGL_EXPORT void SetSig22t_choice3(const double& value);
            
            TIGL_EXPORT bool HasSig22c_choice3() const;
            TIGL_EXPORT const double& GetSig22c_choice3() const;
            TIGL_EXPORT void SetSig22c_choice3(const double& value);
            
            TIGL_EXPORT bool HasSig33t_choice3() const;
            TIGL_EXPORT const double& GetSig33t_choice3() const;
            TIGL_EXPORT void SetSig33t_choice3(const double& value);
            
            TIGL_EXPORT bool HasSig33c_choice3() const;
            TIGL_EXPORT const double& GetSig33c_choice3() const;
            TIGL_EXPORT void SetSig33c_choice3(const double& value);
            
            TIGL_EXPORT bool HasTau12_choice3() const;
            TIGL_EXPORT const double& GetTau12_choice3() const;
            TIGL_EXPORT void SetTau12_choice3(const double& value);
            
            TIGL_EXPORT bool HasTau13_choice3() const;
            TIGL_EXPORT const double& GetTau13_choice3() const;
            TIGL_EXPORT void SetTau13_choice3(const double& value);
            
            TIGL_EXPORT bool HasTau23_choice3() const;
            TIGL_EXPORT const double& GetTau23_choice3() const;
            TIGL_EXPORT void SetTau23_choice3(const double& value);
            
        protected:
            boost::optional<std::string>               m_uID;
            std::string                                m_name;
            boost::optional<std::string>               m_description;
            double                                     m_rho;
            double                                     m_k11;
            double                                     m_k12;
            boost::optional<double>                    m_maxStrain;
            boost::optional<double>                    m_fatigueFactor;
            std::vector<unique_ptr<CPACSPostFailure> > m_postFailure;
            boost::optional<double>                    m_sig11_choice1;
            boost::optional<double>                    m_tau12_choice1;
            boost::optional<double>                    m_sig11yieldT_choice1;
            boost::optional<double>                    m_sig11yieldC_choice1;
            boost::optional<double>                    m_k22_choice2;
            boost::optional<double>                    m_k23_choice2;
            boost::optional<double>                    m_k66_choice2;
            boost::optional<double>                    m_sig11t_choice2;
            boost::optional<double>                    m_sig11c_choice2;
            boost::optional<double>                    m_sig22t_choice2;
            boost::optional<double>                    m_sig22c_choice2;
            boost::optional<double>                    m_tau12_choice2;
            boost::optional<double>                    m_tau23_choice2;
            boost::optional<double>                    m_k13_choice3;
            boost::optional<double>                    m_k22_choice3;
            boost::optional<double>                    m_k23_choice3;
            boost::optional<double>                    m_k33_choice3;
            boost::optional<double>                    m_k44_choice3;
            boost::optional<double>                    m_k55_choice3;
            boost::optional<double>                    m_k66_choice3;
            boost::optional<double>                    m_sig11t_choice3;
            boost::optional<double>                    m_sig11c_choice3;
            boost::optional<double>                    m_sig22t_choice3;
            boost::optional<double>                    m_sig22c_choice3;
            boost::optional<double>                    m_sig33t_choice3;
            boost::optional<double>                    m_sig33c_choice3;
            boost::optional<double>                    m_tau12_choice3;
            boost::optional<double>                    m_tau13_choice3;
            boost::optional<double>                    m_tau23_choice3;
            
        private:
            #ifdef HAVE_CPP11
            CPACSMaterial(const CPACSMaterial&) = delete;
            CPACSMaterial& operator=(const CPACSMaterial&) = delete;
            
            CPACSMaterial(CPACSMaterial&&) = delete;
            CPACSMaterial& operator=(CPACSMaterial&&) = delete;
            #else
            CPACSMaterial(const CPACSMaterial&);
            CPACSMaterial& operator=(const CPACSMaterial&);
            #endif
        };
    }
    
    // This type is not customized, create alias in tigl namespace
    #ifdef HAVE_CPP11
    using CCPACSMaterial = generated::CPACSMaterial;
    #else
    typedef generated::CPACSMaterial CCPACSMaterial;
    #endif
    
    using generated::CPACSPostFailure;
}
