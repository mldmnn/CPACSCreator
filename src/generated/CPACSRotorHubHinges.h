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

#pragma once

#include <string>
#include <tixi.h>
#include <vector>
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSRotorHinge;
class CCPACSRotorBladeAttachment;

namespace generated
{
    // This class is used in:
    // CPACSRotorBladeAttachment

    // generated from /xsd:schema/xsd:complexType[769]
    class CPACSRotorHubHinges
    {
    public:
        TIGL_EXPORT CPACSRotorHubHinges(CCPACSRotorBladeAttachment* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSRotorHubHinges();

        TIGL_EXPORT CCPACSRotorBladeAttachment* GetParent();

        TIGL_EXPORT const CCPACSRotorBladeAttachment* GetParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<unique_ptr<CCPACSRotorHinge> >& GetHinges() const;
        TIGL_EXPORT virtual std::vector<unique_ptr<CCPACSRotorHinge> >& GetHinges();

        TIGL_EXPORT virtual CCPACSRotorHinge& AddHinge();
        TIGL_EXPORT virtual void RemoveHinge(CCPACSRotorHinge& ref);

    protected:
        CCPACSRotorBladeAttachment* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::vector<unique_ptr<CCPACSRotorHinge> > m_hinges;

    private:
#ifdef HAVE_CPP11
        CPACSRotorHubHinges(const CPACSRotorHubHinges&) = delete;
        CPACSRotorHubHinges& operator=(const CPACSRotorHubHinges&) = delete;

        CPACSRotorHubHinges(CPACSRotorHubHinges&&) = delete;
        CPACSRotorHubHinges& operator=(CPACSRotorHubHinges&&) = delete;
#else
        CPACSRotorHubHinges(const CPACSRotorHubHinges&);
        CPACSRotorHubHinges& operator=(const CPACSRotorHubHinges&);
#endif
    };
} // namespace generated

// CPACSRotorHubHinges is customized, use type CCPACSRotorHinges directly
} // namespace tigl
