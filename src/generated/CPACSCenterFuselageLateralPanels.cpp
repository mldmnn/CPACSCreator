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

#include "TixiHelper.h"
#include "CTiglLogging.h"
#include "CTiglError.h"
#include "CPACSCenterFuselageLateralPanels.h"

namespace tigl
{
    namespace generated
    {
        CPACSCenterFuselageLateralPanels::CPACSCenterFuselageLateralPanels(){}
        CPACSCenterFuselageLateralPanels::~CPACSCenterFuselageLateralPanels() {}
        
        void CPACSCenterFuselageLateralPanels::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            
            // read element transitionFrameUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/transitionFrameUID")) {
                m_transitionFrameUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/transitionFrameUID");
            }
            else {
                LOG(ERROR) << "Required element transitionFrameUID is missing";
            }
            
            // read element fwdLatPanelLowY
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/fwdLatPanelLowY")) {
                m_fwdLatPanelLowY = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/fwdLatPanelLowY");
            }
            else {
                LOG(ERROR) << "Required element fwdLatPanelLowY is missing";
            }
            
            // read element fwdLatPanelSheetUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/fwdLatPanelSheetUID")) {
                m_fwdLatPanelSheetUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/fwdLatPanelSheetUID");
            }
            else {
                LOG(ERROR) << "Required element fwdLatPanelSheetUID is missing";
            }
            
            // read element fwdLatPanelReinforcementUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/fwdLatPanelReinforcementUID")) {
                m_fwdLatPanelReinforcementUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/fwdLatPanelReinforcementUID");
            }
            else {
                LOG(ERROR) << "Required element fwdLatPanelReinforcementUID is missing";
            }
            
            // read element rearLatPanelHeightStringerUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/rearLatPanelHeightStringerUID")) {
                m_rearLatPanelHeightStringerUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/rearLatPanelHeightStringerUID");
            }
            else {
                LOG(ERROR) << "Required element rearLatPanelHeightStringerUID is missing";
            }
            
            // read element rearLatPanelSheetUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/rearLatPanelSheetUID")) {
                m_rearLatPanelSheetUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/rearLatPanelSheetUID");
            }
            else {
                LOG(ERROR) << "Required element rearLatPanelSheetUID is missing";
            }
            
            // read element rearLatPanelReinforcementUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/rearLatPanelReinforcementUID")) {
                m_rearLatPanelReinforcementUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/rearLatPanelReinforcementUID");
            }
            else {
                LOG(ERROR) << "Required element rearLatPanelReinforcementUID is missing";
            }
            
        }
        
        void CPACSCenterFuselageLateralPanels::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            if (m_uID) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uID");
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", *m_uID);
            }
            
            // write element transitionFrameUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/transitionFrameUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/transitionFrameUID", m_transitionFrameUID);
            
            // write element fwdLatPanelLowY
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/fwdLatPanelLowY");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/fwdLatPanelLowY", m_fwdLatPanelLowY);
            
            // write element fwdLatPanelSheetUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/fwdLatPanelSheetUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/fwdLatPanelSheetUID", m_fwdLatPanelSheetUID);
            
            // write element fwdLatPanelReinforcementUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/fwdLatPanelReinforcementUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/fwdLatPanelReinforcementUID", m_fwdLatPanelReinforcementUID);
            
            // write element rearLatPanelHeightStringerUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rearLatPanelHeightStringerUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/rearLatPanelHeightStringerUID", m_rearLatPanelHeightStringerUID);
            
            // write element rearLatPanelSheetUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rearLatPanelSheetUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/rearLatPanelSheetUID", m_rearLatPanelSheetUID);
            
            // write element rearLatPanelReinforcementUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rearLatPanelReinforcementUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/rearLatPanelReinforcementUID", m_rearLatPanelReinforcementUID);
            
        }
        
        bool CPACSCenterFuselageLateralPanels::HasUID() const
        {
            return static_cast<bool>(m_uID);
        }
        
        const std::string& CPACSCenterFuselageLateralPanels::GetUID() const
        {
            return *m_uID;
        }
        
        void CPACSCenterFuselageLateralPanels::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        const std::string& CPACSCenterFuselageLateralPanels::GetTransitionFrameUID() const
        {
            return m_transitionFrameUID;
        }
        
        void CPACSCenterFuselageLateralPanels::SetTransitionFrameUID(const std::string& value)
        {
            m_transitionFrameUID = value;
        }
        
        const double& CPACSCenterFuselageLateralPanels::GetFwdLatPanelLowY() const
        {
            return m_fwdLatPanelLowY;
        }
        
        void CPACSCenterFuselageLateralPanels::SetFwdLatPanelLowY(const double& value)
        {
            m_fwdLatPanelLowY = value;
        }
        
        const std::string& CPACSCenterFuselageLateralPanels::GetFwdLatPanelSheetUID() const
        {
            return m_fwdLatPanelSheetUID;
        }
        
        void CPACSCenterFuselageLateralPanels::SetFwdLatPanelSheetUID(const std::string& value)
        {
            m_fwdLatPanelSheetUID = value;
        }
        
        const std::string& CPACSCenterFuselageLateralPanels::GetFwdLatPanelReinforcementUID() const
        {
            return m_fwdLatPanelReinforcementUID;
        }
        
        void CPACSCenterFuselageLateralPanels::SetFwdLatPanelReinforcementUID(const std::string& value)
        {
            m_fwdLatPanelReinforcementUID = value;
        }
        
        const std::string& CPACSCenterFuselageLateralPanels::GetRearLatPanelHeightStringerUID() const
        {
            return m_rearLatPanelHeightStringerUID;
        }
        
        void CPACSCenterFuselageLateralPanels::SetRearLatPanelHeightStringerUID(const std::string& value)
        {
            m_rearLatPanelHeightStringerUID = value;
        }
        
        const std::string& CPACSCenterFuselageLateralPanels::GetRearLatPanelSheetUID() const
        {
            return m_rearLatPanelSheetUID;
        }
        
        void CPACSCenterFuselageLateralPanels::SetRearLatPanelSheetUID(const std::string& value)
        {
            m_rearLatPanelSheetUID = value;
        }
        
        const std::string& CPACSCenterFuselageLateralPanels::GetRearLatPanelReinforcementUID() const
        {
            return m_rearLatPanelReinforcementUID;
        }
        
        void CPACSCenterFuselageLateralPanels::SetRearLatPanelReinforcementUID(const std::string& value)
        {
            m_rearLatPanelReinforcementUID = value;
        }
        
    }
}
