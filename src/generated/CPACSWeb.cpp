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

#include "CPACSWeb.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSWeb::CPACSWeb()
        : m_relPos(0)
    {
    }
    
    CPACSWeb::~CPACSWeb()
    {
    }
    
    void CPACSWeb::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element material
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/material")) {
            m_material.ReadCPACS(tixiHandle, xpath + "/material");
        }
        else {
            LOG(ERROR) << "Required element material is missing at xpath " << xpath;
        }
        
        // read element relPos
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/relPos")) {
            m_relPos = tixi::TixiGetElement<double>(tixiHandle, xpath + "/relPos");
        }
        else {
            LOG(ERROR) << "Required element relPos is missing at xpath " << xpath;
        }
        
    }
    
    void CPACSWeb::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element material
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/material");
        m_material.WriteCPACS(tixiHandle, xpath + "/material");
        
        // write element relPos
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/relPos");
        tixi::TixiSaveElement(tixiHandle, xpath + "/relPos", m_relPos);
        
    }
    
    const CCPACSMaterialDefinition& CPACSWeb::GetMaterial() const
    {
        return m_material;
    }
    
    CCPACSMaterialDefinition& CPACSWeb::GetMaterial()
    {
        return m_material;
    }
    
    const double& CPACSWeb::GetRelPos() const
    {
        return m_relPos;
    }
    
    void CPACSWeb::SetRelPos(const double& value)
    {
        m_relPos = value;
    }
    
} // namespace generated
} // namespace tigl
