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
#include "CCPACSWingCell.h"
#include "CPACSCellPositioningChordwise.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSCellPositioningChordwise::CPACSCellPositioningChordwise(CCPACSWingCell* parent)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSCellPositioningChordwise::~CPACSCellPositioningChordwise()
    {
    }

    const CCPACSWingCell* CPACSCellPositioningChordwise::GetParent() const
    {
        return m_parent;
    }

    CCPACSWingCell* CPACSCellPositioningChordwise::GetParent()
    {
        return m_parent;
    }

    void CPACSCellPositioningChordwise::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element sparUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/sparUID")) {
            m_sparUID_choice1 = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/sparUID");
            if (m_sparUID_choice1->empty()) {
                LOG(WARNING) << "Optional element sparUID is present but empty at xpath " << xpath;
            }
        }

        // read element xsi1
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/xsi1")) {
            m_xsi1_choice2 = tixi::TixiGetElement<double>(tixiHandle, xpath + "/xsi1");
        }

        // read element xsi2
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/xsi2")) {
            m_xsi2_choice2 = tixi::TixiGetElement<double>(tixiHandle, xpath + "/xsi2");
        }

        if (!ValidateChoices()) {
            LOG(ERROR) << "Invalid choice configuration at xpath " << xpath;
        }
    }

    void CPACSCellPositioningChordwise::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element sparUID
        if (m_sparUID_choice1) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/sparUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/sparUID", *m_sparUID_choice1);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/sparUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/sparUID");
            }
        }

        // write element xsi1
        if (m_xsi1_choice2) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/xsi1");
            tixi::TixiSaveElement(tixiHandle, xpath + "/xsi1", *m_xsi1_choice2);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/xsi1")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/xsi1");
            }
        }

        // write element xsi2
        if (m_xsi2_choice2) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/xsi2");
            tixi::TixiSaveElement(tixiHandle, xpath + "/xsi2", *m_xsi2_choice2);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/xsi2")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/xsi2");
            }
        }

    }

    bool CPACSCellPositioningChordwise::ValidateChoices() const
    {
        return
        (
            (
                (
                    // mandatory elements of this choice must be there
                    m_sparUID_choice1.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_xsi1_choice2.is_initialized()
                        ||
                        m_xsi2_choice2.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_xsi1_choice2.is_initialized()
                    &&
                    m_xsi2_choice2.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_sparUID_choice1.is_initialized()
                    )
                )
                == 1
            )
        )
        ;
    }

    const boost::optional<std::string>& CPACSCellPositioningChordwise::GetSparUID_choice1() const
    {
        return m_sparUID_choice1;
    }

    void CPACSCellPositioningChordwise::SetSparUID_choice1(const boost::optional<std::string>& value)
    {
        m_sparUID_choice1 = value;
    }

    const boost::optional<double>& CPACSCellPositioningChordwise::GetXsi1_choice2() const
    {
        return m_xsi1_choice2;
    }

    void CPACSCellPositioningChordwise::SetXsi1_choice2(const boost::optional<double>& value)
    {
        m_xsi1_choice2 = value;
    }

    const boost::optional<double>& CPACSCellPositioningChordwise::GetXsi2_choice2() const
    {
        return m_xsi2_choice2;
    }

    void CPACSCellPositioningChordwise::SetXsi2_choice2(const boost::optional<double>& value)
    {
        m_xsi2_choice2 = value;
    }

} // namespace generated
} // namespace tigl
