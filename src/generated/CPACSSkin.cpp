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

#include "CPACSSkin.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSSkin::CPACSSkin(CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
    }

    CPACSSkin::~CPACSSkin()
    {
    }

    CTiglUIDManager& CPACSSkin::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSSkin::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSSkin::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element standardSheetElementUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/standardSheetElementUID")) {
            m_standardSheetElementUID = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/standardSheetElementUID");
            if (m_standardSheetElementUID->empty()) {
                LOG(WARNING) << "Optional element standardSheetElementUID is present but empty at xpath " << xpath;
            }
        }

        // read element skinSegments
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/skinSegments")) {
            m_skinSegments = boost::in_place(m_uidMgr);
            try {
                m_skinSegments->ReadCPACS(tixiHandle, xpath + "/skinSegments");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read skinSegments at xpath " << xpath << ": " << e.what();
                m_skinSegments = boost::none;
            }
        }

    }

    void CPACSSkin::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element standardSheetElementUID
        if (m_standardSheetElementUID) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/standardSheetElementUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/standardSheetElementUID", *m_standardSheetElementUID);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/standardSheetElementUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/standardSheetElementUID");
            }
        }

        // write element skinSegments
        if (m_skinSegments) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/skinSegments");
            m_skinSegments->WriteCPACS(tixiHandle, xpath + "/skinSegments");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/skinSegments")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/skinSegments");
            }
        }

    }

    const boost::optional<std::string>& CPACSSkin::GetStandardSheetElementUID() const
    {
        return m_standardSheetElementUID;
    }

    void CPACSSkin::SetStandardSheetElementUID(const boost::optional<std::string>& value)
    {
        m_standardSheetElementUID = value;
    }

    const boost::optional<CPACSSkinSegments>& CPACSSkin::GetSkinSegments() const
    {
        return m_skinSegments;
    }

    boost::optional<CPACSSkinSegments>& CPACSSkin::GetSkinSegments()
    {
        return m_skinSegments;
    }

    CPACSSkinSegments& CPACSSkin::GetSkinSegments(CreateIfNotExistsTag)
    {
        if (!m_skinSegments)
            m_skinSegments = boost::in_place(m_uidMgr);
        return *m_skinSegments;
    }

    void CPACSSkin::RemoveSkinSegments()
    {
        m_skinSegments = boost::none;
    }

} // namespace generated
} // namespace tigl
