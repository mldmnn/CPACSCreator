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
#include "CPACSDynamicAircraftModelPoints.h"

namespace tigl
{
    namespace generated
    {
        CPACSDynamicAircraftModelPoints::CPACSDynamicAircraftModelPoints(){}
        CPACSDynamicAircraftModelPoints::~CPACSDynamicAircraftModelPoints() {}
        
        void CPACSDynamicAircraftModelPoints::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element uID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/uID")) {
                m_uID.ReadCPACS(tixiHandle, xpath + "/uID");
            }
            else {
                LOG(ERROR) << "Required element uID is missing";
            }
            
            // read element x
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/x")) {
                m_x.ReadCPACS(tixiHandle, xpath + "/x");
            }
            else {
                LOG(ERROR) << "Required element x is missing";
            }
            
            // read element y
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/y")) {
                m_y.ReadCPACS(tixiHandle, xpath + "/y");
            }
            else {
                LOG(ERROR) << "Required element y is missing";
            }
            
            // read element z
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/z")) {
                m_z.ReadCPACS(tixiHandle, xpath + "/z");
            }
            else {
                LOG(ERROR) << "Required element z is missing";
            }
            
        }
        
        void CPACSDynamicAircraftModelPoints::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element uID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uID");
            m_uID.WriteCPACS(tixiHandle, xpath + "/uID");
            
            // write element x
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/x");
            m_x.WriteCPACS(tixiHandle, xpath + "/x");
            
            // write element y
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/y");
            m_y.WriteCPACS(tixiHandle, xpath + "/y");
            
            // write element z
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/z");
            m_z.WriteCPACS(tixiHandle, xpath + "/z");
            
        }
        
        const CCPACSStringVector& CPACSDynamicAircraftModelPoints::GetUID() const
        {
            return m_uID;
        }
        
        CCPACSStringVector& CPACSDynamicAircraftModelPoints::GetUID()
        {
            return m_uID;
        }
        
        const CCPACSStringVector& CPACSDynamicAircraftModelPoints::GetX() const
        {
            return m_x;
        }
        
        CCPACSStringVector& CPACSDynamicAircraftModelPoints::GetX()
        {
            return m_x;
        }
        
        const CCPACSStringVector& CPACSDynamicAircraftModelPoints::GetY() const
        {
            return m_y;
        }
        
        CCPACSStringVector& CPACSDynamicAircraftModelPoints::GetY()
        {
            return m_y;
        }
        
        const CCPACSStringVector& CPACSDynamicAircraftModelPoints::GetZ() const
        {
            return m_z;
        }
        
        CCPACSStringVector& CPACSDynamicAircraftModelPoints::GetZ()
        {
            return m_z;
        }
        
    }
}
