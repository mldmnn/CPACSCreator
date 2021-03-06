/*
* Copyright (C) 2018 CFS Engineering
*
* Created: 2018 Malo Drougard <malo.drougard@protonmail.com>
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
//
// Created by makem on 29/05/18.
//

#ifndef TIGL_MODIFICATORMANAGER_H
#define TIGL_MODIFICATORMANAGER_H


#include <CPACSCreatorLib/CPACSTreeItem.h>
#include <QPushButton>
#include "TIGLViewerTransformationWidget.h"
#include "CPACSCreatorAdapter.h"
#include "TIGLViewerWingWidget.h"
#include "ModificatorWidget.h"
#include "ProfilesDBManager.h"
#include "TIGLViewerPositioningsWidget.h"
#include "TIGLViewerFuselageWidget.h"

class ModificatorManager: public QObject {
    Q_OBJECT


public slots:
    void dispatch(cpcr::CPACSTreeItem * item ) ;
    void applyCurrentModifications();
    // simply reset the values displayed by the current modificator from the file
    void applyCurrentCancellation();

public:
    ModificatorManager(
                       CPACSCreatorAdapter* adapter,
                       QWidget* applyInterface,
                       TIGLViewerTransformationWidget* transformationModificator,
                       TIGLViewerWingWidget* wingModificator,
                       ProfilesDBManager* profilesDB,
                       TIGLViewerPositioningsWidget* positioningsModificator,
                       TIGLViewerFuselageWidget * fuselageModificator
                       );


    void setTransformationModificator(cpcr::CPACSTreeItem * item );
    void setWingModificator(cpcr::CPACSTreeItem * item);
    void setPositioningsModificator(cpcr::CPACSTreeItem * item);
    void setFuselageModificator(cpcr::CPACSTreeItem *pItem);
    void hideAll();

    void standardizeCurrentFile();
    bool isStandardized();
    void setUseCPACSStandard(bool value);
    inline bool useCPACSStandard() {return useCpacsStandard; };

    // copy the pointer (the pointer is contain in a new address but point to the same object) -> the user can not change the container of adapterS
    inline CPACSCreatorAdapter* getAdapter() {return  adapter; }
    void resetAdapter(CPACSCreatorAdapter* newAdapter );

    inline ProfilesDBManager* getProfilesDB() {return profilesDB; }

private:

    CPACSCreatorAdapter* adapter;
    ProfilesDBManager* profilesDB;


    TIGLViewerTransformationWidget* transformationModificator;
    TIGLViewerWingWidget* wingModificator;
    TIGLViewerPositioningsWidget* positioningsModificator;
    TIGLViewerFuselageWidget * fuselageModificator;

    ModificatorWidget* currentModificator;
    QWidget* widgetApply;
    QPushButton* commitButton;
    QPushButton* cancelButton;

    bool useCpacsStandard;


};


#endif //TIGL_MODIFICATORMANAGER_H
