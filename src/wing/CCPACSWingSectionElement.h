/* 
* Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
* Changed: $Id$ 
*
* Version: $Revision$
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
/**
* @file
* @brief  Implementation of CPACS wing section element handling routines.
*/

#ifndef CCPACSWINGSECTIONELEMENT_H
#define CCPACSWINGSECTIONELEMENT_H

#include "generated/CPACSWingElement.h"
#include "CTiglTransformation.h"
#include "CTiglPoint.h"

namespace tigl
{

class CCPACSWingSectionElement : public generated::CPACSWingElement
{
public:
    // Returns the UID of the referenced wing profile
    TIGL_EXPORT std::string GetProfileIndex() const;

    // Returns the UID of the profile of this element
    TIGL_EXPORT std::string GetProfileUID() const;

    // Gets the section element transformation
    TIGL_EXPORT CTiglTransformation GetSectionElementTransformation() const;

    // Getter for translation
    DEPRECATED TIGL_EXPORT CTiglPoint GetTranslation() const;

    // Getter for rotation
    DEPRECATED TIGL_EXPORT CTiglPoint GetRotation() const;

    // Getter for scaling
    DEPRECATED TIGL_EXPORT CTiglPoint GetScaling() const;

    // Setter for translation
    TIGL_EXPORT void SetTranslation(const CTiglPoint& trans);

    // Setter for rotation
    TIGL_EXPORT void SetRotation(const CTiglPoint& rot);

    // Setter for scaling
    TIGL_EXPORT void SetScaling(const CTiglPoint& scaling);
};

} // end namespace tigl

#endif // CCPACSWINGSECTIONELEMENT_H
