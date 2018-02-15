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

#include <cassert>
#include "CCPACSWingCells.h"
#include "CPACSWingCell.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSWingCell::CPACSWingCell(CCPACSWingCells* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_positioningLeadingEdge(reinterpret_cast<CCPACSWingCell*>(this))
        , m_positioningTrailingEdge(reinterpret_cast<CCPACSWingCell*>(this))
        , m_positioningInnerBorder(reinterpret_cast<CCPACSWingCell*>(this))
        , m_positioningOuterBorder(reinterpret_cast<CCPACSWingCell*>(this))
    {
        //assert(parent != NULL);
        m_parent = parent;
    }
    
    CPACSWingCell::~CPACSWingCell()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
    }
    
    CCPACSWingCells* CPACSWingCell::GetParent() const
    {
        return m_parent;
    }
    
    CTiglUIDManager& CPACSWingCell::GetUIDManager()
    {
        return *m_uidMgr;
    }
    
    const CTiglUIDManager& CPACSWingCell::GetUIDManager() const
    {
        return *m_uidMgr;
    }
    
    void CPACSWingCell::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
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
        
        // read element skin
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/skin")) {
            m_skin.ReadCPACS(tixiHandle, xpath + "/skin");
        }
        else {
            LOG(ERROR) << "Required element skin is missing at xpath " << xpath;
        }
        
        // read element positioningLeadingEdge
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/positioningLeadingEdge")) {
            m_positioningLeadingEdge.ReadCPACS(tixiHandle, xpath + "/positioningLeadingEdge");
        }
        else {
            LOG(ERROR) << "Required element positioningLeadingEdge is missing at xpath " << xpath;
        }
        
        // read element positioningTrailingEdge
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/positioningTrailingEdge")) {
            m_positioningTrailingEdge.ReadCPACS(tixiHandle, xpath + "/positioningTrailingEdge");
        }
        else {
            LOG(ERROR) << "Required element positioningTrailingEdge is missing at xpath " << xpath;
        }
        
        // read element positioningInnerBorder
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/positioningInnerBorder")) {
            m_positioningInnerBorder.ReadCPACS(tixiHandle, xpath + "/positioningInnerBorder");
        }
        else {
            LOG(ERROR) << "Required element positioningInnerBorder is missing at xpath " << xpath;
        }
        
        // read element positioningOuterBorder
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/positioningOuterBorder")) {
            m_positioningOuterBorder.ReadCPACS(tixiHandle, xpath + "/positioningOuterBorder");
        }
        else {
            LOG(ERROR) << "Required element positioningOuterBorder is missing at xpath " << xpath;
        }
        
        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }
    
    void CPACSWingCell::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);
        
        // write element skin
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/skin");
        m_skin.WriteCPACS(tixiHandle, xpath + "/skin");
        
        // write element positioningLeadingEdge
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/positioningLeadingEdge");
        m_positioningLeadingEdge.WriteCPACS(tixiHandle, xpath + "/positioningLeadingEdge");
        
        // write element positioningTrailingEdge
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/positioningTrailingEdge");
        m_positioningTrailingEdge.WriteCPACS(tixiHandle, xpath + "/positioningTrailingEdge");
        
        // write element positioningInnerBorder
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/positioningInnerBorder");
        m_positioningInnerBorder.WriteCPACS(tixiHandle, xpath + "/positioningInnerBorder");
        
        // write element positioningOuterBorder
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/positioningOuterBorder");
        m_positioningOuterBorder.WriteCPACS(tixiHandle, xpath + "/positioningOuterBorder");
        
    }
    
    const std::string& CPACSWingCell::GetUID() const
    {
        return m_uID;
    }
    
    void CPACSWingCell::SetUID(const std::string& value)
    {
        if (m_uidMgr) {
            m_uidMgr->TryUnregisterObject(m_uID);
            m_uidMgr->RegisterObject(value, *this);
        }
        m_uID = value;
    }
    
    const CPACSWingSkin& CPACSWingCell::GetSkin() const
    {
        return m_skin;
    }
    
    CPACSWingSkin& CPACSWingCell::GetSkin()
    {
        return m_skin;
    }
    
    const CCPACSWingCellPositionChordwise& CPACSWingCell::GetPositioningLeadingEdge() const
    {
        return m_positioningLeadingEdge;
    }
    
    CCPACSWingCellPositionChordwise& CPACSWingCell::GetPositioningLeadingEdge()
    {
        return m_positioningLeadingEdge;
    }
    
    const CCPACSWingCellPositionChordwise& CPACSWingCell::GetPositioningTrailingEdge() const
    {
        return m_positioningTrailingEdge;
    }
    
    CCPACSWingCellPositionChordwise& CPACSWingCell::GetPositioningTrailingEdge()
    {
        return m_positioningTrailingEdge;
    }
    
    const CCPACSWingCellPositionSpanwise& CPACSWingCell::GetPositioningInnerBorder() const
    {
        return m_positioningInnerBorder;
    }
    
    CCPACSWingCellPositionSpanwise& CPACSWingCell::GetPositioningInnerBorder()
    {
        return m_positioningInnerBorder;
    }
    
    const CCPACSWingCellPositionSpanwise& CPACSWingCell::GetPositioningOuterBorder() const
    {
        return m_positioningOuterBorder;
    }
    
    CCPACSWingCellPositionSpanwise& CPACSWingCell::GetPositioningOuterBorder()
    {
        return m_positioningOuterBorder;
    }
    
} // namespace generated
} // namespace tigl
