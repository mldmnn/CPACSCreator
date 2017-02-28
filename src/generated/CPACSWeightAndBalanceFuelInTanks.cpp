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

#include "CPACSWeightAndBalanceFuelInTank.h"
#include "TixiHelper.h"
#include "CTiglLogging.h"
#include "CTiglError.h"
#include "CPACSWeightAndBalanceFuelInTanks.h"

namespace tigl
{
    namespace generated
    {
        CPACSWeightAndBalanceFuelInTanks::CPACSWeightAndBalanceFuelInTanks(){}
        CPACSWeightAndBalanceFuelInTanks::~CPACSWeightAndBalanceFuelInTanks() {}
        
        void CPACSWeightAndBalanceFuelInTanks::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element fuelInTank
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/fuelInTank")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/fuelInTank", m_fuelInTank);
            }
            
        }
        
        void CPACSWeightAndBalanceFuelInTanks::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element fuelInTank
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/fuelInTank", m_fuelInTank);
            
        }
        
        const std::vector<unique_ptr<CPACSWeightAndBalanceFuelInTank>>& CPACSWeightAndBalanceFuelInTanks::GetFuelInTank() const
        {
            return m_fuelInTank;
        }
        
        std::vector<unique_ptr<CPACSWeightAndBalanceFuelInTank>>& CPACSWeightAndBalanceFuelInTanks::GetFuelInTank()
        {
            return m_fuelInTank;
        }
        
    }
}
