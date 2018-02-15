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
#include "CCPACSRotors.h"
#include "CPACSRotor.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSRotor::CPACSRotor(CCPACSRotors* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_transformation(m_uidMgr)
        , m_rotorHub(reinterpret_cast<CCPACSRotor*>(this), m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSRotor::~CPACSRotor()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
    }

    CCPACSRotors* CPACSRotor::GetParent() const
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSRotor::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSRotor::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSRotor::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read attribute uID
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
            m_uID = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            if (m_uID.empty()) {
                LOG(WARNING) << "Required attribute uID is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
        }

        // read attribute symmetry
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "symmetry")) {
            m_symmetry = stringToTiglSymmetryAxis(tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "symmetry"));
        }

        // read element name
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/name")) {
            m_name = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
            if (m_name.empty()) {
                LOG(WARNING) << "Required element name is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element name is missing at xpath " << xpath;
        }

        // read element description
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
            m_description = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            if (m_description->empty()) {
                LOG(WARNING) << "Optional element description is present but empty at xpath " << xpath;
            }
        }

        // read element parentUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/parentUID")) {
            m_parentUID = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/parentUID");
            if (m_parentUID->empty()) {
                LOG(WARNING) << "Optional element parentUID is present but empty at xpath " << xpath;
            }
        }

        // read element type
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/type")) {
            m_type = stringToCPACSRotor_type(tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/type"));
        }

        // read element nominalRotationsPerMinute
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/nominalRotationsPerMinute")) {
            m_nominalRotationsPerMinute = tixi::TixiGetElement<double>(tixiHandle, xpath + "/nominalRotationsPerMinute");
        }

        // read element transformation
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/transformation")) {
            m_transformation.ReadCPACS(tixiHandle, xpath + "/transformation");
        }
        else {
            LOG(ERROR) << "Required element transformation is missing at xpath " << xpath;
        }

        // read element rotorHub
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/rotorHub")) {
            m_rotorHub.ReadCPACS(tixiHandle, xpath + "/rotorHub");
        }
        else {
            LOG(ERROR) << "Required element rotorHub is missing at xpath " << xpath;
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSRotor::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write attribute symmetry
        if (m_symmetry) {
            tixi::TixiSaveAttribute(tixiHandle, xpath, "symmetry", TiglSymmetryAxisToString(*m_symmetry));
        }
        else {
            if (tixi::TixiCheckAttribute(tixiHandle, xpath, "symmetry")) {
                tixi::TixiRemoveAttribute(tixiHandle, xpath, "symmetry");
            }
        }

        // write element name
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
        tixi::TixiSaveElement(tixiHandle, xpath + "/name", m_name);

        // write element description
        if (m_description) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
            tixi::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/description");
            }
        }

        // write element parentUID
        if (m_parentUID) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/parentUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/parentUID", *m_parentUID);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/parentUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/parentUID");
            }
        }

        // write element type
        if (m_type) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/type");
            tixi::TixiSaveElement(tixiHandle, xpath + "/type", CPACSRotor_typeToString(*m_type));
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/type")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/type");
            }
        }

        // write element nominalRotationsPerMinute
        if (m_nominalRotationsPerMinute) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/nominalRotationsPerMinute");
            tixi::TixiSaveElement(tixiHandle, xpath + "/nominalRotationsPerMinute", *m_nominalRotationsPerMinute);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/nominalRotationsPerMinute")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/nominalRotationsPerMinute");
            }
        }

        // write element transformation
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/transformation");
        m_transformation.WriteCPACS(tixiHandle, xpath + "/transformation");

        // write element rotorHub
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rotorHub");
        m_rotorHub.WriteCPACS(tixiHandle, xpath + "/rotorHub");

    }

    const std::string& CPACSRotor::GetUID() const
    {
        return m_uID;
    }

    void CPACSRotor::SetUID(const std::string& value)
    {
        if (m_uidMgr) {
            m_uidMgr->TryUnregisterObject(m_uID);
            m_uidMgr->RegisterObject(value, *this);
        }
        m_uID = value;
    }

    const boost::optional<TiglSymmetryAxis>& CPACSRotor::GetSymmetry() const
    {
        return m_symmetry;
    }

    void CPACSRotor::SetSymmetry(const boost::optional<TiglSymmetryAxis>& value)
    {
        m_symmetry = value;
    }

    const std::string& CPACSRotor::GetName() const
    {
        return m_name;
    }

    void CPACSRotor::SetName(const std::string& value)
    {
        m_name = value;
    }

    const boost::optional<std::string>& CPACSRotor::GetDescription() const
    {
        return m_description;
    }

    void CPACSRotor::SetDescription(const boost::optional<std::string>& value)
    {
        m_description = value;
    }

    const boost::optional<std::string>& CPACSRotor::GetParentUID() const
    {
        return m_parentUID;
    }

    void CPACSRotor::SetParentUID(const boost::optional<std::string>& value)
    {
        m_parentUID = value;
    }

    const boost::optional<CPACSRotor_type>& CPACSRotor::GetType() const
    {
        return m_type;
    }

    void CPACSRotor::SetType(const boost::optional<CPACSRotor_type>& value)
    {
        m_type = value;
    }

    const boost::optional<double>& CPACSRotor::GetNominalRotationsPerMinute() const
    {
        return m_nominalRotationsPerMinute;
    }

    void CPACSRotor::SetNominalRotationsPerMinute(const boost::optional<double>& value)
    {
        m_nominalRotationsPerMinute = value;
    }

    const CCPACSTransformation& CPACSRotor::GetTransformation() const
    {
        return m_transformation;
    }

    CCPACSTransformation& CPACSRotor::GetTransformation()
    {
        return m_transformation;
    }

    const CCPACSRotorHub& CPACSRotor::GetRotorHub() const
    {
        return m_rotorHub;
    }

    CCPACSRotorHub& CPACSRotor::GetRotorHub()
    {
        return m_rotorHub;
    }

} // namespace generated
} // namespace tigl
