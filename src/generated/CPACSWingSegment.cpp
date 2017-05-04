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
#include "CCPACSWingSegments.h"
#include "CPACSWingSegment.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSWingSegment::CPACSWingSegment(CCPACSWingSegments* parent, CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr)
        {
            //assert(parent != NULL);
            m_parent = parent;
        }
        
        CPACSWingSegment::~CPACSWingSegment()
        {
            if (m_uidMgr) m_uidMgr->UnregisterObject(m_uID);
        }
        
        CCPACSWingSegments* CPACSWingSegment::GetParent() const
        {
            return m_parent;
        }
        
        void CPACSWingSegment::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            else {
                LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
            }
            
            // read element name
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/name")) {
                m_name = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
            }
            else {
                LOG(ERROR) << "Required element name is missing at xpath " << xpath;
            }
            
            // read element description
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/description")) {
                m_description = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            }
            
            // read element fromElementUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/fromElementUID")) {
                m_fromElementUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/fromElementUID");
            }
            else {
                LOG(ERROR) << "Required element fromElementUID is missing at xpath " << xpath;
            }
            
            // read element toElementUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/toElementUID")) {
                m_toElementUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/toElementUID");
            }
            else {
                LOG(ERROR) << "Required element toElementUID is missing at xpath " << xpath;
            }
            
            // read element guideCurves
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/guideCurves")) {
                m_guideCurves = boost::in_place(m_uidMgr);
                try {
                    m_guideCurves->ReadCPACS(tixiHandle, xpath + "/guideCurves");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read guideCurves at xpath " << xpath << ": " << e.what();
                    m_guideCurves = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read guideCurves at xpath " << xpath << ": " << e.getError();
                    m_guideCurves = boost::none;
                }
            }
            
            if (m_uidMgr) m_uidMgr->RegisterObject(m_uID, *this);
        }
        
        void CPACSWingSegment::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uID");
            tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);
            
            // write element name
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/name", m_name);
            
            // write element description
            if (m_description) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
            }
            
            // write element fromElementUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/fromElementUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/fromElementUID", m_fromElementUID);
            
            // write element toElementUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/toElementUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/toElementUID", m_toElementUID);
            
            // write element guideCurves
            if (m_guideCurves) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/guideCurves");
                m_guideCurves->WriteCPACS(tixiHandle, xpath + "/guideCurves");
            }
            
        }
        
        const std::string& CPACSWingSegment::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSWingSegment::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        const std::string& CPACSWingSegment::GetName() const
        {
            return m_name;
        }
        
        void CPACSWingSegment::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        const boost::optional<std::string>& CPACSWingSegment::GetDescription() const
        {
            return m_description;
        }
        
        void CPACSWingSegment::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        void CPACSWingSegment::SetDescription(const boost::optional<std::string>& value)
        {
            m_description = value;
        }
        
        const std::string& CPACSWingSegment::GetFromElementUID() const
        {
            return m_fromElementUID;
        }
        
        void CPACSWingSegment::SetFromElementUID(const std::string& value)
        {
            m_fromElementUID = value;
        }
        
        const std::string& CPACSWingSegment::GetToElementUID() const
        {
            return m_toElementUID;
        }
        
        void CPACSWingSegment::SetToElementUID(const std::string& value)
        {
            m_toElementUID = value;
        }
        
        const boost::optional<CCPACSGuideCurves>& CPACSWingSegment::GetGuideCurves() const
        {
            return m_guideCurves;
        }
        
        boost::optional<CCPACSGuideCurves>& CPACSWingSegment::GetGuideCurves()
        {
            return m_guideCurves;
        }
        
    }
}
