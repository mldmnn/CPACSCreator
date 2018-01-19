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
#include <CCPACSFrame.h>
#include "CCPACSFuselageStructure.h"
#include "CPACSFramesAssembly.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSFramesAssembly::CPACSFramesAssembly(CCPACSFuselageStructure* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSFramesAssembly::~CPACSFramesAssembly()
    {
    }

    CCPACSFuselageStructure* CPACSFramesAssembly::GetParent() const
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSFramesAssembly::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSFramesAssembly::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSFramesAssembly::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element frame
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/frame")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/frame", m_frames, reinterpret_cast<CCPACSFramesAssembly*>(this), m_uidMgr);
        }

    }

    void CPACSFramesAssembly::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element frame
        tixi::TixiSaveElements(tixiHandle, xpath + "/frame", m_frames);

    }

    const std::vector<unique_ptr<CCPACSFrame> >& CPACSFramesAssembly::GetFrames() const
    {
        return m_frames;
    }

    std::vector<unique_ptr<CCPACSFrame> >& CPACSFramesAssembly::GetFrames()
    {
        return m_frames;
    }

    CCPACSFrame& CPACSFramesAssembly::AddFrame()
    {
        m_frames.push_back(make_unique<CCPACSFrame>(reinterpret_cast<CCPACSFramesAssembly*>(this), m_uidMgr));
        return *m_frames.back();
    }

    void CPACSFramesAssembly::RemoveFrame(CCPACSFrame& ref)
    {
        for (std::size_t i = 0; i < m_frames.size(); i++) {
            if (m_frames[i].get() == &ref) {
                m_frames.erase(m_frames.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
