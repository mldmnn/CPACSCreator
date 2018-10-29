// Copyright (c) 2018 RISC Software GmbH
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

#include <cassert>
#include <CCPACSRotor.h>
#include "CCPACSRotorcraftModel.h"
#include "CPACSRotors.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSRotors::CPACSRotors(CCPACSRotorcraftModel* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSRotors::~CPACSRotors()
    {
    }

    const CCPACSRotorcraftModel* CPACSRotors::GetParent() const
    {
        return m_parent;
    }

    CCPACSRotorcraftModel* CPACSRotors::GetParent()
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSRotors::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSRotors::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSRotors::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element rotor
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/rotor")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/rotor", m_rotors, reinterpret_cast<CCPACSRotors*>(this), m_uidMgr);
        }

    }

    void CPACSRotors::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element rotor
        tixi::TixiSaveElements(tixiHandle, xpath + "/rotor", m_rotors);

    }

    const std::vector<unique_ptr<CCPACSRotor> >& CPACSRotors::GetRotors() const
    {
        return m_rotors;
    }

    std::vector<unique_ptr<CCPACSRotor> >& CPACSRotors::GetRotors()
    {
        return m_rotors;
    }

    CCPACSRotor& CPACSRotors::AddRotor()
    {
        m_rotors.push_back(make_unique<CCPACSRotor>(reinterpret_cast<CCPACSRotors*>(this), m_uidMgr));
        return *m_rotors.back();
    }

    void CPACSRotors::RemoveRotor(CCPACSRotor& ref)
    {
        for (std::size_t i = 0; i < m_rotors.size(); i++) {
            if (m_rotors[i].get() == &ref) {
                m_rotors.erase(m_rotors.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
