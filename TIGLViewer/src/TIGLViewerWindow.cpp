/*
*
* Modifications Copyright (C) 2018 CFS Engineering
*
* Changed: CPACSCreator Addition, 2018 Malo Drougard <malo.drougard@protonmail.com>
*
* Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
* Changed: $Id: TIGLViewerWindow.cpp 214 2012-10-16 09:20:45Z martinsiggel $
*
* Version: $Revision: 214 $
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
#define _USE_MATH_DEFINES

#include <QtGui>
#include <QFileDialog>
#include <QtCore/QTextStream>
#include <QtCore/QFileInfo>
#include <QtCore/QString>
#include <QShortcut>
#include <QTimer>
#include <QProcessEnvironment>
#include <QMessageBox>

#include "TIGLViewerWindow.h"
#include "TIGLViewerSettingsDialog.h"
#include "TIGLViewerDrawVectorDialog.h"
#include "TIGLViewerDocument.h"
#include "TIGLViewerInputoutput.h"
#include "TIGLDebugStream.h"
#include "TIGLScriptEngine.h"
#include "CommandLineParameters.h"
#include "TIGLViewerSettings.h"
#include "TiglViewerConsole.h"
#include "TIGLViewerControlFile.h"
#include "TIGLViewerErrorDialog.h"
#include "TIGLViewerLogHistory.h"
#include "TIGLViewerLogRedirection.h"
#include "CTiglLogSplitter.h"
#include "TIGLViewerLoggerHTMLDecorator.h"
#include "TIGLViewerScreenshotDialog.h"
#include "TIGLViewerScopedCommand.h"
#include "tigl_config.h"
#include "api/tigl_version.h"
#include "CCPACSConfigurationManager.h"

#include "CPACSAbstractModel.h"
#include "CPACSCreatorLib/CPACSTreeItem.h"

#include <cstdlib>

namespace
{
QString makeLink(const QString& linkText, const QString& address)
{
    return QString("<a style='color: #8eceff;' href='%1'>%2</a>").arg(address).arg(linkText);
}
}

TIGLViewerWindow::TIGLViewerWindow()
    : myLastFolder(tr(""))
    , cpacsConfiguration(NULL)
{
    setupUi(this);

    setTiglWindowTitle(QString("TiGL Viewer %1").arg(TIGL_MAJOR_VERSION));

    tiglViewerSettings = &TIGLViewerSettings::Instance();
    settingsDialog     = new TIGLViewerSettingsDialog(*tiglViewerSettings, this);

    myScene = new TIGLViewerContext();
    myOCC->setContext(myScene);

    watcher = nullptr;
    // we create a timer to workaround QFileSystemWatcher bug,
    // which emits multiple signals in a few milliseconds. This caused
    // TIGLViewer to also open a document many times.
    // Now, when we get a signal, we start the timer and only after the
    // timer times out, we reopen the cpacs config
    openTimer = new QTimer(this);
    openTimer->setSingleShot(true);
    // the timeout of 200ms is a bit arbitrary but should be conservative enough
    // to catch all events
    openTimer->setInterval(200);

    //redirect everything to TIGL console, let error messages be printed in red
    stdoutStream = new QDebugStream(std::cout, true);
    errorStream  = new QDebugStream(std::cerr, true);
    errorStream->setMarkup("<b><font color=\"red\">", "</font></b>");

    // insert two loggers, one for the log history and one for the console
    CSharedPtr<tigl::CTiglLogSplitter> splitter(new tigl::CTiglLogSplitter);
    logHistory = CSharedPtr<TIGLViewerLogHistory>(new TIGLViewerLogHistory);
    logHistory->SetVerbosity(TILOG_DEBUG4);
    splitter->AddLogger(logHistory);

    logDirect = CSharedPtr<TIGLViewerLogRedirection>(new TIGLViewerLogRedirection);
    logDirect->SetVerbosity(TILOG_WARNING);
    tigl::PTiglLogger logHTMLDecorator(new TIGLViewerLoggerHTMLDecorator(logDirect));
    splitter->AddLogger(logHTMLDecorator);

    // register logger at tigl
    tigl::CTiglLogging::Instance().SetLogger(splitter);

    QPalette p = console->palette();
    p.setColor(QPalette::Base, Qt::black);
    console->setPalette(p);

    //cpacsConfiguration = new TIGLViewerDocument(this);
    scriptEngine = new TIGLScriptEngine(this);

    setAcceptDrops(true);

    initCreatorInterface();

    connectSignals();
    createMenus();
    updateMenus();

    loadSettings();

    statusBar()->showMessage(tr("A context menu is available by right-clicking"));

    setMinimumSize(160, 160);
}

TIGLViewerWindow::~TIGLViewerWindow()
{
    delete stdoutStream;
    delete errorStream;
    delete adapter;
    delete cpacsTreeView;
    delete modificatorManager;
    delete profilesDB;
}

void TIGLViewerWindow::dragEnterEvent(QDragEnterEvent* ev)
{
    QList<QUrl> urls = ev->mimeData()->urls();
    foreach (QUrl url, urls) {
        if (!url.toLocalFile().isEmpty()) {
            QString suffix = QFileInfo(url.toLocalFile()).suffix();
            if (suffix == "xml" || suffix == "brep" || suffix == "stp" || suffix == "igs" || suffix == "mesh") {
                ev->accept();
            }
        }
    }
}

void TIGLViewerWindow::dropEvent(QDropEvent* ev)
{
    QList<QUrl> urls = ev->mimeData()->urls();
    foreach (QUrl url, urls) {
        if (!url.toLocalFile().isEmpty()) {
            QString suffix = QFileInfo(url.toLocalFile()).suffix();
            if (suffix == "xml" || suffix == "brep" || suffix == "stp" || suffix == "igs" || suffix == "mesh") {
                ev->accept();
                // load file
                openFile(url.toLocalFile());
            }
        }
    }
}

void TIGLViewerWindow::setInitialControlFile(QString filename)
{
    TIGLViewerControlFile cf;
    if (cf.read(filename.toStdString().c_str()) == CF_SUCCESS) {
        if (cf.showConsole == CF_TRUE) {
            console->setVisible(true);
            showConsoleAction->setChecked(true);
        }
        else if (cf.showConsole == CF_FALSE) {
            console->setVisible(false);
            showConsoleAction->setChecked(false);
        }
        if (cf.showToolbars == CF_TRUE) {
            toolBar->setVisible(true);
            toolBarView->setVisible(true);
        }
        else if (cf.showToolbars == CF_FALSE) {
            toolBar->setVisible(false);
            toolBarView->setVisible(false);
        }
    }
}

void TIGLViewerWindow::newFile()
{
    statusBar()->showMessage(tr("Invoked File|New"));
    //myOCC->getView()->ColorScaleErase();
    myScene->deleteAllObjects();
}

void TIGLViewerWindow::open()
{
    QString fileName;

    statusBar()->showMessage(tr("Invoked File|Open"));

    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), myLastFolder,
                                            tr("CPACS (*.xml);;"
                                               "Other drawing types (*.brep *.igs *iges *.stp *.step *.mesh);;"
                                               "BREP (*.brep);;"
                                               "STEP (*.step *.stp);;"
                                               "IGES (*.iges *.igs);;"
                                               "STL  (*.stl);;"
                                               "Hotsose Mesh (*.mesh)"));
    openFile(fileName);
}

void TIGLViewerWindow::openScript()
{
    QString fileName;

    statusBar()->showMessage(tr("Invoked File|Open Script"));

    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), myLastFolder, tr("Choofse your script (*)"));
    openScript(fileName);
}

void TIGLViewerWindow::openScript(const QString& fileName)
{
    scriptEngine->openFile(fileName);
}

void TIGLViewerWindow::close()
{
    closeCpacsConfigurationOnly();
    closeAdapter();

    // desactivate the standardization option
    standardizeAction->setEnabled(false);
    // clean the undo helper
    undoHelper.clean();
    setWindowTitle(QString("CPACSCreator"));
}

void TIGLViewerWindow::closeAdapter(){
    if(adapter){
        adapter->close();
    }
    updateCreatorInterfaceFromAdapter();
}


void TIGLViewerWindow::closeCpacsConfigurationOnly() {

    if(watcher){
        delete watcher;
        watcher = nullptr;
    }

    if (cpacsConfiguration) {
        getScene()->deleteAllObjects();
        delete cpacsConfiguration;
        cpacsConfiguration = NULL;
    }

    connectConfiguration();
    updateMenus();
    setTiglWindowTitle(QString("TiGL Viewer %1").arg(TIGL_MAJOR_VERSION));
}

void TIGLViewerWindow::setTiglWindowTitle(const QString &title, bool forceTitle)
{
    if (forceTitle) {
        QMainWindow::setWindowTitle(title);
        preferredTitle = title;
    }
    else if (preferredTitle.isEmpty()) {
        QMainWindow::setWindowTitle(title);
    }
}

void TIGLViewerWindow::openCpacsConfigurationOnly(QString filename ){

    TIGLViewerDocument* config = new TIGLViewerDocument(this);

    TiglReturnCode tiglRet     = config->openCpacsConfiguration(filename);
    if (tiglRet != TIGL_SUCCESS) {
        delete config;
        return;
    }
    cpacsConfiguration = config;

    watcher = new QFileSystemWatcher();
    watcher->addPath(filename);
    QObject::connect(watcher, SIGNAL(fileChanged(QString)), openTimer, SLOT(start()));

    // reset the tigl interface
    connectConfiguration();
    updateMenus();
}


void TIGLViewerWindow::openRecentFile()
{
    QAction* action = qobject_cast<QAction*>(sender());
    if (action) {
        openFile(action->data().toString());
    }
}


void TIGLViewerWindow::openFileNoCheckPointAdded(const QString& fileName,  bool askForStd, bool stdValue ) {

    QString fileType;
    QFileInfo fileInfo;

    TIGLViewerInputOutput::FileFormat format;
    TIGLViewerInputOutput reader;
    bool triangulation = false;
    bool success       = false;

    TIGLViewerScopedCommand command(getConsole());
    Q_UNUSED(command);
    statusBar()->showMessage(tr("Invoked File|Open"));

    fileInfo.setFile(fileName);
    fileType = fileInfo.suffix();

    if (!fileName.isEmpty()) { // if the file is empty -> this is the case when the user press cancel.

        // clean previous scene
        closeCpacsConfigurationOnly();
        closeAdapter();

        if (fileType.toLower() == tr("xml")) {

            // reset adapter
            adapter->resetFromFile(fileInfo.absoluteFilePath());
            // set the manager
            modificatorManager->resetAdapter(adapter);

            //Standardization process
            if (modificatorManager->isStandardized()) {
                // we do not want to call the standardization function the first time we set the value
                bool blockB = standardizeAction->blockSignals(true);
                standardizeAction->setChecked(true);
                standardizeAction->blockSignals(blockB);
            }
            else {
                bool needStd = stdValue;
                if ( askForStd){
                    QMessageBox msgBox;
                    msgBox.setText(
                            "The CPACS file does not use the Creator standard. Did you want to standardize the file?");
                    msgBox.setInformativeText("The Creator standard guaranty that creator functions work properly. "
                                              "Otherwise, the Creator functions can have unexpected behavior. ");
                    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                    msgBox.setDefaultButton(QMessageBox::Yes);
                    int ret = msgBox.exec();
                    if (ret == QMessageBox::Yes) {
                        needStd = true;
                    } else if (ret == QMessageBox::No) {
                        needStd = false;
                    }  else {
                        displayErrorMessage("Unexpected result from the previous message box", "Error");
                    }
                }

                if( needStd){
                    // it safe to call standardize from the modificator because we have disconnect the cpacstree view
                    modificatorManager->standardizeCurrentFile();
                    bool blockB = standardizeAction->blockSignals(true);
                    standardizeAction->setChecked(true);
                    standardizeAction->blockSignals(blockB);
                }else{
                    modificatorManager->setUseCPACSStandard(false);
                    bool blockB = standardizeAction->blockSignals(true);
                    standardizeAction->setChecked(false);
                    standardizeAction->blockSignals(blockB);
                }
            }
            standardizeAction->setEnabled(true);

            // update cpacsCreator interface;
            updateCreatorInterfaceFromAdapter();


            // Init TIGLViewerDocument
            openCpacsConfigurationOnly(fileInfo.absoluteFilePath());

            success = true;
        }

        else {

            if (fileType.toLower() == tr("brep")) {
                format = TIGLViewerInputOutput::FormatBREP;
            }
            if (fileType.toLower() == tr("step") || fileType.toLower() == tr("stp")) {
                format = TIGLViewerInputOutput::FormatSTEP;
            }
            if (fileType.toLower() == tr("iges") || fileType.toLower() == tr("igs")) {
                format = TIGLViewerInputOutput::FormatIGES;
            }
            if (fileType.toLower() == tr("stl")) {
                format = TIGLViewerInputOutput::FormatSTL;
            }
            if (fileType.toLower() == tr("mesh")) {
                format        = TIGLViewerInputOutput::FormatMESH;
                triangulation = true;
            }
            if (triangulation) {
                success = reader.importTriangulation(fileInfo.absoluteFilePath(), format, *getScene());
            }
            else {
                success = reader.importModel(fileInfo.absoluteFilePath(), format, *getScene());
            }

            // in the case of a .xml file this is done in openCpacsConfigurationOnly
            watcher = new QFileSystemWatcher();
            watcher->addPath(fileInfo.absoluteFilePath());
            QObject::connect(watcher, SIGNAL(fileChanged(QString)), openTimer, SLOT(start()));

        }

        setCurrentFile(fileInfo.absoluteFilePath()); // set the setting for the next opening
        myLastFolder = fileInfo.absolutePath();
        if (success) {
            myOCC->viewAxo();
            myOCC->fitAll();
        }
        else {
            delete watcher;
            displayErrorMessage("Error opening file " + fileName, "Error");
        }
    }

}

void TIGLViewerWindow::openFile(const QString& fileName)
{
    QString fileType;
    QFileInfo fileInfo;

    fileInfo.setFile(fileName);
    fileType = fileInfo.suffix();

    if (!fileName.isEmpty()) { // cancel case
        undoHelper.init(fileName);
        openFileNoCheckPointAdded(undoHelper.currentFile());
    }

}


void TIGLViewerWindow::reopenCurrentFile()
{
    QString baseFile = undoHelper.originalFile();
    openFileNoCheckPointAdded(undoHelper.currentFile(), false, modificatorManager->useCPACSStandard() );
}

// open the base file form undoHelper
void TIGLViewerWindow::reopenOriginalFile()
{
    QString baseFile = undoHelper.originalFile();
    close();
    openFile(baseFile);
}


void TIGLViewerWindow::setCurrentFile(const QString& fileName)
{
    setWindowTitle(QString("%1 - CPACSCreator ").arg(QDir::toNativeSeparators(QFileInfo(fileName).absoluteFilePath())));

    QSettings settings("DLR SC-HPC", "TiGLViewer3");
    QStringList files = settings.value("recentFileList").toStringList();
    files.removeAll(fileName);
    files.prepend(fileName);
    while (files.size() > MaxRecentFiles) {
        files.removeLast();
    }

    settings.setValue("recentFileList", files);
    settings.setValue("lastFolder", myLastFolder);

    updateRecentFileActions();
}

void TIGLViewerWindow::loadSettings()
{
    QSettings settings("DLR SC-HPC", "TiGLViewer3");

    bool showConsole = settings.value("show_console", QVariant(true)).toBool();
    bool showCreator = settings.value("show_creator", QVariant(true)).toBool();

    restoreGeometry(settings.value("MainWindowGeom").toByteArray());
    restoreState(settings.value("MainWindowState").toByteArray());

    consoleDockWidget->setVisible(showConsole);
    showConsoleAction->setChecked(showConsole);

    creatorDockWidget->setVisible(showCreator);
    showCreatorAction->setChecked(showCreator);

    tiglViewerSettings->loadSettings();
    settingsDialog->updateEntries();
    applySettings();
}

void TIGLViewerWindow::saveSettings()
{
    QSettings settings("DLR SC-HPC", "TiGLViewer3");

    bool showConsole = consoleDockWidget->isVisible();
    settings.setValue("show_console", showConsole);

    bool showCreator = creatorDockWidget->isVisible();
    settings.setValue("show_creator", showCreator);

    settings.setValue("MainWindowGeom", saveGeometry());
    settings.setValue("MainWindowState", saveState());

    tiglViewerSettings->storeSettings();
}

void TIGLViewerWindow::applySettings()
{
    QColor col = tiglViewerSettings->BGColor();
    myOCC->setBackgroundGradient(col.red(), col.green(), col.blue());
    getScene()->getContext()->SetIsoNumber(tiglViewerSettings->numFaceUIsosForDisplay(), AIS_TOI_IsoU);
    getScene()->getContext()->SetIsoNumber(tiglViewerSettings->numFaceVIsosForDisplay(), AIS_TOI_IsoV);
    getScene()->getContext()->UpdateCurrentViewer();
    if (tiglViewerSettings->debugBooleanOperations()) {
        qputenv("TIGL_DEBUG_BOP", "1");
    }
    else {
        deleteEnvVar("TIGL_DEBUG_BOP");
    }
}

void TIGLViewerWindow::changeSettings()
{
    settingsDialog->updateEntries();
    settingsDialog->exec();
    applySettings();
}

TIGLViewerWidget* TIGLViewerWindow::getViewer()
{
    return myOCC;
}

void TIGLViewerWindow::saveAs()
{
    QString fileName;

    statusBar()->showMessage(tr("Invoked File|Save"));
    fileName = QFileDialog::getSaveFileName(this, tr("Save as..."), myLastFolder,
                                            tr("CPACS (*.xml);;") +
                                            tr("IGES Geometry (*.igs);;") + tr("STEP Geometry (*.stp);;") +
                                                tr("STL Triangulation (*.stl);;") + tr("BRep Geometry (*.brep)"));

    if (!fileName.isEmpty()) {
        TIGLViewerScopedCommand command(getConsole());
        Q_UNUSED(command);
        saveFile(fileName);

        QFileInfo fileInfo;
        fileInfo.setFile(fileName);
        myLastFolder = fileInfo.absolutePath();
    }
}


void TIGLViewerWindow::saveInOriginal() {
    undoHelper.saveInOriginal();
}

bool TIGLViewerWindow::saveFile(const QString& fileName)
{
    TIGLViewerInputOutput::FileFormat format;
    QFileInfo fileInfo;

    fileInfo.setFile(fileName);
    QString fileType = fileInfo.suffix();
    if (fileType.toLower() == tr("brep") || fileType.toLower() == tr("rle")) {
        format = TIGLViewerInputOutput::FormatBREP;
    }
    else if (fileType.toLower() == tr("step") || fileType.toLower() == tr("stp")) {
        format = TIGLViewerInputOutput::FormatSTEP;
    }
    else if (fileType.toLower() == tr("iges") || fileType.toLower() == tr("igs")) {
        format = TIGLViewerInputOutput::FormatIGES;
    }
    else if (fileType.toLower() == tr("stl")) {
        format = TIGLViewerInputOutput::FormatSTL;
    }
    else if (fileType.toLower() == tr("xml")){
        undoHelper.saveInFile(fileName);
        return true;
    }
    else {
        LOG(ERROR) << "Unknown file format " << fileType.toStdString();
        return false;
    }

    TIGLViewerInputOutput writer;
    return writer.exportModel(fileInfo.absoluteFilePath(), format, getScene()->getContext());
}

void TIGLViewerWindow::setBackgroundImage()
{
    QString fileName;
    QString fileType;
    QFileInfo fileInfo;

    statusBar()->showMessage(tr("Invoked File|Load Background Image"));

    fileName = QFileDialog::getOpenFileName(this, tr("Open Background Image"), myLastFolder,
                                            tr("Images (*.jpg *.png *.gif *.bmp);;"));
    if (!fileName.isEmpty()) {
        fileInfo.setFile(fileName);
        fileType = fileInfo.suffix();

        if (fileType.toLower() == tr("bmp") || fileType.toLower() == tr("gif") || fileType.toLower() == tr("jpg") ||
            fileType.toLower() == tr("png")) {
            myOCC->setBGImage(fileName);
        }
        else {
            displayErrorMessage(tr("Invalid image format!"), tr("TIGL Error"));
        }
    }
}

void TIGLViewerWindow::about()
{
    QString text;
    QString tixiVersion(tixiGetVersion());
    QString tiglVersion(tiglGetVersion());
    QString occtVersion =
        QString("%1.%2.%3").arg(OCC_VERSION_MAJOR).arg(OCC_VERSION_MINOR).arg(OCC_VERSION_MAINTENANCE);

    text = "The <b>CPACSCreator</b> is based on the TiGL library and CPACSCreatorLib and allows you to view and edit "
           "CPACS geometries. ";
    text += "CPACSCreator uses the following Open Source libraries:<br/><br/>";

    if (tiglVersion.contains("-r")) {
        QStringList list = tiglVersion.split("-r");
        QString ver      = list[0];
        QString rev      = list[1];

        tiglVersion =
            QString("%1-r%2").arg(ver).arg(makeLink(rev, QString("https://github.com/DLR-SC/tigl/commit/%1").arg(rev)));
    }

    text += makeLink("TiXI", "https://github.com/dlr-sc/tixi") + ": v" + tixiVersion + "<br/>";
    text += makeLink("TiGL", "https://github.com/dlr-sc/tigl") + ": v" + tiglVersion + "<br/>";
    text += makeLink("CPACSCreator", "https://github.com/cfsengineering/CPACSCreator.git") + ": v" + "1.0.0" + "<br/>";
    text += makeLink("OpenCASCADE", "https://www.opencascade.com/") + ": v" + occtVersion + "<br/><br/>";

    text += "Visit the CPACSCreator project page at " +
            makeLink("https://github.com/cfsengineering/CPACSCreator.git",
                     "https://github.com/cfsengineering/CPACSCreator.git") +
            "<br/><br/>";
    text += "Visit the TiGL project page at " +
            makeLink("http://software.dlr.de/p/tigl/", "http://software.dlr.de/p/tigl/") + "<br/><br/>";

    text += "&copy; 2017 German Aerospace Center (DLR) <br/>";
    text += "&copy; 2018 CFS Engineering ";


    QMessageBox::about(this, tr("About CPACSCreator"), text);
}

void TIGLViewerWindow::aboutQt()
{
    statusBar()->showMessage(tr("Invoked Help|About Qt"));
    qApp->aboutQt();
}

void TIGLViewerWindow::xyzPosition(V3d_Coordinate X, V3d_Coordinate Y, V3d_Coordinate Z)
{
    QString aString;
    QTextStream ts(&aString);
    ts << X << "," << Y << "," << Z;
    //statusBar()->showMessage(aString); // do not bother user with x,y,z crap
}

void TIGLViewerWindow::statusMessage(const QString aMessage)
{
    statusBar()->showMessage(aMessage);
}

void TIGLViewerWindow::displayErrorMessage(const QString aMessage, QString aHeader = "TIGL Error")
{
    TIGLViewerErrorDialog dialog(this);
    dialog.setMessage(QString("<b>%1</b><br /><br />%2").arg(aHeader).arg(aMessage));
    dialog.setWindowTitle("Error");
    dialog.setDetailsText(logHistory->GetAllMessages());
    dialog.exec();
}

void TIGLViewerWindow::connectConfiguration()
{
    if (!cpacsConfiguration) {
        return;
    }

    // CPACS Wing Actions
    connect(drawWingProfilesAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawWingProfiles()));
    connect(drawWingOverlayCPACSProfilePointsAction, SIGNAL(triggered()), cpacsConfiguration,
            SLOT(drawWingOverlayProfilePoints()));
    connect(drawWingGuideCurvesAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawWingGuideCurves()));
    connect(drawWingsAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawWing()));
    connect(drawWingTriangulationAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawWingTriangulation()));
    connect(drawWingSamplePointsAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawWingSamplePoints()));
    connect(drawFusedWingAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawFusedWing()));
    connect(drawWingComponentSegmentAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawWingComponentSegment()));
    connect(drawWingCSPointAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawWingComponentSegmentPoints()));
    connect(drawWingShellAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawWingShells()));
    connect(drawWingStructureAction, SIGNAL(triggered(bool)), cpacsConfiguration, SLOT(drawWingStructure()));

    // CPACS Aircraft Actions

    connect(showAllWingsAndFuselagesAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawConfiguration()));
    connect(showAllWingsAndFuselagesSurfacePointsAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawAllFuselagesAndWingsSurfacePoints()));

    connect(drawFusedAircraftAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawFusedAircraft()));
    connect(drawIntersectionAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawIntersectionLine()));
    connect(showFusedAirplaneTriangulation, SIGNAL(triggered()), cpacsConfiguration,
            SLOT(drawFusedAircraftTriangulation()));
    connect(drawFarFieldAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawFarField()));
    connect(drawSystemsAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawSystems()));
    connect(drawComponentAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawComponent()));

    // CPACS Fuselage Actions
    connect(drawFuselageProfilesAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawFuselageProfiles()));
    connect(drawFuselageAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawFuselage()));
    connect(drawFuselageTriangulationAction, SIGNAL(triggered()), cpacsConfiguration,
            SLOT(drawFuselageTriangulation()));
    connect(drawFuselageSamplePointsAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawFuselageSamplePoints()));
    connect(drawFuselageSamplePointsAngleAction, SIGNAL(triggered()), cpacsConfiguration,
            SLOT(drawFuselageSamplePointsAngle()));
    connect(drawFusedFuselageAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawFusedFuselage()));
    connect(drawFuselageGuideCurvesAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawFuselageGuideCurves()));

    // CPACS RotorBlade Actions
    connect(drawRotorProfilesAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawRotorProfiles()));
    connect(drawRotorBladeOverlayCPACSProfilePointsAction, SIGNAL(triggered()), cpacsConfiguration,
            SLOT(drawRotorBladeOverlayProfilePoints()));
    connect(drawRotorBladeGuideCurvesAction, SIGNAL(triggered()), cpacsConfiguration,
            SLOT(drawRotorBladeGuideCurves()));
    connect(drawRotorBladesAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawRotorBlade()));
    connect(drawRotorBladeTriangulationAction, SIGNAL(triggered()), cpacsConfiguration,
            SLOT(drawRotorBladeTriangulation()));
    connect(drawRotorBladeSamplePointsAction, SIGNAL(triggered()), cpacsConfiguration,
            SLOT(drawRotorBladeSamplePoints()));
    connect(drawFusedRotorBladeAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawFusedRotorBlade()));
    connect(drawRotorBladeComponentSegmentAction, SIGNAL(triggered()), cpacsConfiguration,
            SLOT(drawRotorBladeComponentSegment()));
    connect(drawRotorBladeCSPointAction, SIGNAL(triggered()), cpacsConfiguration,
            SLOT(drawRotorBladeComponentSegmentPoints()));
    connect(drawRotorBladeShellAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawRotorBladeShells()));

    // CPACS Rotorcraft Actions
    connect(drawRotorsAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(drawRotor()));
    connect(showRotorPropertiesAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(showRotorProperties()));

    // Export functions
    connect(tiglExportFusedIgesAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportFusedAsIges()));
    connect(tiglExportIgesAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportAsIges()));
    connect(tiglExportFusedStepAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportAsStepFused()));
    connect(tiglExportStepAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportAsStep()));
    connect(tiglExportMeshedWingSTL, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportMeshedWingSTL()));
    connect(tiglExportMeshedFuselageSTL, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportMeshedFuselageSTL()));
    connect(tiglExportMeshedConfigSTL, SIGNAL(triggered(bool)), cpacsConfiguration, SLOT(exportMeshedConfigSTL()));
    connect(tiglExportMeshedWingVTK, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportMeshedWingVTK()));
    connect(tiglExportMeshedWingVTKsimple, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportMeshedWingVTKsimple()));
    connect(tiglExportMeshedFuselageVTK, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportMeshedFuselageVTK()));
    connect(tiglExportMeshedConfigVTK, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportMeshedConfigVTK()));
    connect(tiglExportMeshedConfigVTKNoFuse, SIGNAL(triggered()), cpacsConfiguration,
            SLOT(exportMeshedConfigVTKNoFuse()));
    connect(tiglExportWingColladaAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportWingCollada()));
    connect(tiglExportFuselageColladaAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportFuselageCollada()));
    connect(tiglExportConfigurationColladaAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportConfigCollada()));
    connect(tiglExportFuselageBRepAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportFuselageBRep()));
    connect(tiglExportWingBRepAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportWingBRep()));
    connect(tiglExportFusedConfigBRep, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportFusedConfigBRep()));
    connect(tiglExportWingCurvesBRepAction, SIGNAL(triggered()), cpacsConfiguration, SLOT(exportWingCurvesBRep()));
    connect(tiglExportFuselageCurvesBRepAction, SIGNAL(triggered()), cpacsConfiguration,
            SLOT(exportFuselageCurvesBRep()));

    connect(cpacsConfiguration, SIGNAL(documentUpdated(TiglCPACSConfigurationHandle)), this, SLOT(updateMenus()));

    // Set functions

    // need to synchronize the adpater first
    //connect(cpacsConfiguration, SIGNAL(documentUpdated(TiglCPACSConfigurationHandle)), this, SLOT(updateCreatorInterfaceFromAdapter()));
}

void TIGLViewerWindow::connectSignals()
{
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));
    connect(openScriptAction, SIGNAL(triggered()), this, SLOT(openScript()));
    connect(closeAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(reopenOriginalFileAction, SIGNAL(triggered()), this, SLOT(reopenOriginalFile()));
    connect(redoAction_2, SIGNAL(triggered()), this, SLOT(redoCommit()));
    connect(undoAction_2, SIGNAL(triggered()), this, SLOT(undoCommit()));
    connect(standardizeAction, SIGNAL(toggled(bool)), this, SLOT(standardizeCurrentFile(bool)));

    for (int i = 0; i < MaxRecentFiles; ++i) {
        recentFileActions[i] = new QAction(this);
        recentFileActions[i]->setVisible(false);
        connect(recentFileActions[i], SIGNAL(triggered()), this, SLOT(openRecentFile()));
    }


    connect(saveInOriginalAction, SIGNAL(triggered()), this, SLOT(saveInOriginal()));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));
    connect(saveScreenshotAction, SIGNAL(triggered()), this, SLOT(makeScreenShot()));
    connect(setBackgroundAction, SIGNAL(triggered()), this, SLOT(setBackgroundImage()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
    connect(aboutQtAction, SIGNAL(triggered()), this, SLOT(aboutQt()));

    // Misc drawing actions
    connect(drawPointAction, SIGNAL(triggered()), this, SLOT(drawPoint()));
    connect(drawVectorAction, SIGNAL(triggered()), this, SLOT(drawVector()));

    // view->actions menu
    connect(fitAction, SIGNAL(triggered()), myOCC, SLOT(fitExtents()));
    connect(fitAllAction, SIGNAL(triggered()), myOCC, SLOT(fitAll()));
    //connect(zoomAction, SIGNAL(triggered()), myOCC, SLOT(fitArea()));
    connect(zoomAction, SIGNAL(triggered()), myOCC, SLOT(zoom()));
    connect(panAction, SIGNAL(triggered()), myOCC, SLOT(pan()));
    connect(rotAction, SIGNAL(triggered()), myOCC, SLOT(rotation()));
    connect(selectAction, SIGNAL(triggered()), myOCC, SLOT(selecting()));

    // select all is not present in any menu or bar
    addAction(selectAllAction);
    connect(selectAllAction, SIGNAL(triggered(bool)), myScene, SLOT(selectAll()));

    // view->grid menu
    connect(gridOnAction, SIGNAL(toggled(bool)), myScene, SLOT(toggleGrid(bool)));
    connect(gridXYAction, SIGNAL(triggered()), myScene, SLOT(gridXY()));
    connect(gridXZAction, SIGNAL(triggered()), myScene, SLOT(gridXZ()));
    connect(gridYZAction, SIGNAL(triggered()), myScene, SLOT(gridYZ()));
    connect(gridRectAction, SIGNAL(triggered()), myScene, SLOT(gridRect()));
    connect(gridCircAction, SIGNAL(triggered()), myScene, SLOT(gridCirc()));

    // Standard View
    connect(viewFrontAction, SIGNAL(triggered()), myOCC, SLOT(viewFront()));
    connect(viewBackAction, SIGNAL(triggered()), myOCC, SLOT(viewBack()));
    connect(viewTopAction, SIGNAL(triggered()), myOCC, SLOT(viewTop()));
    connect(viewBottomAction, SIGNAL(triggered()), myOCC, SLOT(viewBottom()));
    connect(viewLeftAction, SIGNAL(triggered()), myOCC, SLOT(viewLeft()));
    connect(viewRightAction, SIGNAL(triggered()), myOCC, SLOT(viewRight()));
    connect(viewAxoAction, SIGNAL(triggered()), myOCC, SLOT(viewAxo()));
    connect(viewGridAction, SIGNAL(triggered()), myOCC, SLOT(viewGrid()));
    connect(viewResetAction, SIGNAL(triggered()), myOCC, SLOT(viewReset()));
    connect(viewZoomInAction, SIGNAL(triggered()), myOCC, SLOT(zoomIn()));
    connect(viewZoomOutAction, SIGNAL(triggered()), myOCC, SLOT(zoomOut()));
    connect(showConsoleAction, SIGNAL(toggled(bool)), consoleDockWidget, SLOT(setVisible(bool)));
    connect(consoleDockWidget, SIGNAL(visibilityChanged(bool)), showConsoleAction, SLOT(setChecked(bool)));
    connect(showCreatorAction, SIGNAL(toggled(bool)), creatorDockWidget, SLOT(setVisible(bool)));
    connect(creatorDockWidget, SIGNAL(visibilityChanged(bool)), showCreatorAction, SLOT(setChecked(bool)));
    connect(showWireframeAction, SIGNAL(toggled(bool)), myScene, SLOT(wireFrame(bool)));
#if OCC_VERSION_HEX >= VERSION_HEX_CODE(6, 7, 0)
    connect(showReflectionLinesAction, SIGNAL(toggled(bool)), myScene, SLOT(setReflectionlinesEnabled(bool)));
#else
    showReflectionLinesAction->setVisible(false);
    showReflectionLinesAction->setEnabled(false);
#endif

    connect(openTimer, SIGNAL(timeout()), this, SLOT(reopenCurrentFile()));

    // The co-ordinates from the view
    connect(myOCC, SIGNAL(mouseMoved(V3d_Coordinate, V3d_Coordinate, V3d_Coordinate)), this,
            SLOT(xyzPosition(V3d_Coordinate, V3d_Coordinate, V3d_Coordinate)));

    connect( myOCC, SIGNAL(sendStatus(const QString)), this,  SLOT  (statusMessage(const QString)) );
    connect( myOCC, SIGNAL(initialized()), this, SIGNAL(windowInitialized()));

    connect(stdoutStream, SIGNAL(sendString(QString)), console, SLOT(output(QString)));
    connect(errorStream, SIGNAL(sendString(QString)), console, SLOT(output(QString)));

    connect(logDirect.get(), SIGNAL(newMessage(QString)), console, SLOT(output(QString)));

    connect(scriptEngine, SIGNAL(scriptResult(QString)), console, SLOT(output(QString)));
    connect(scriptEngine, SIGNAL(scriptError(QString)), console, SLOT(outputError(QString)));
    connect(scriptEngine, SIGNAL(evalDone()), console, SLOT(endCommand()));
    connect(console, SIGNAL(onChange(QString)), scriptEngine, SLOT(textChanged(QString)));
    connect(console, SIGNAL(onCommand(QString)), scriptEngine, SLOT(eval(QString)));

    connect(settingsAction, SIGNAL(triggered()), this, SLOT(changeSettings()));
}

void TIGLViewerWindow::createMenus()
{
    for (int i = 0; i < MaxRecentFiles; ++i) {
        recentFileMenu->addAction(recentFileActions[i]);
    }
    updateRecentFileActions();
}



void TIGLViewerWindow::initCreatorInterface()
{
    profilesDB = new ProfilesDBManager();

    adapter            = new CPACSCreatorAdapter(profilesDB);
    modificatorManager = new ModificatorManager(adapter, widgetApply, transforamtionModificator, wingModificator,
                                                profilesDB, positioningsModificator, fuselageModificator);

    // create the cpacs tree view that is linked to the tree view of the interface
    cpacsTreeView = new CPACSTreeView(treeView, adapter);

    // We do not allow to standardize until one file is open
    standardizeAction->setEnabled(false);

    connect(cpacsTreeView, SIGNAL( newSelectedTreeItem(cpcr::CPACSTreeItem *)), modificatorManager,
            SLOT(dispatch(cpcr::CPACSTreeItem*)));

    // not in modificatorManager because we need to disconnect the model
    connect(commitButton, SIGNAL(pressed()), this, SLOT(applyModifications()));

    // not in modificatorManager because we need to disconnect the model
    connect(cancelButton, SIGNAL(pressed()), modificatorManager, SLOT(applyCurrentCancellation()));
}





void TIGLViewerWindow::updateCreatorInterfaceFromAdapter() // need a valid cpacsConfiguaration
{
    if(!adapter || (! adapter->isValid()) ) {
        profilesDB->clearAirfoilsFromCurrentCpacsFile();
        cpacsTreeView->disconnectAdapter();
        modificatorManager->resetAdapter(adapter);
    }
    else{
        profilesDB->setAirfoilsFromCurrentCpacsFile(adapter->getAirfoilsUid());
        modificatorManager->resetAdapter(adapter);
        cpacsTreeView->connectAdapter(adapter);

    }
}

void TIGLViewerWindow::applyModifications()
{

    // close cpacsConfiguration (delete watcher and cpacsConfiguration -> not signal emited)
    closeCpacsConfigurationOnly();
    // disconnect tree to not have tree access during this operation
    cpacsTreeView->disconnectAdapter();

    undoHelper.addCheckPoint();

    modificatorManager->applyCurrentModifications();

    // reset the creator interface (remark adapter is still the same)
    updateCreatorInterfaceFromAdapter();

    // reopen cpacsConfiguration
    openCpacsConfigurationOnly(undoHelper.currentFile());

}



void TIGLViewerWindow::undoCommit()
{

    if (undoHelper.undoIsAvailable()) {

        QString fileToRestore = undoHelper.undo();
        // cpacsConfig + adapter + creator interface + tigl interface will be close and restored during the opening
        openFileNoCheckPointAdded(fileToRestore, false, modificatorManager->useCPACSStandard());
    }
    else {
        LOG(WARNING) << "Undo unavaible!" << std::endl;
    }
}

void TIGLViewerWindow::redoCommit()
{
    if (undoHelper.redoIsAvailable()) {

        QString fileToRestore = undoHelper.redo();
        // cpacsConfig + adapter + creator interface + tigl interface will be close and restored during the opening
        openFileNoCheckPointAdded(fileToRestore, false, modificatorManager->useCPACSStandard() );
    }
    else {
        LOG(WARNING) << "Redo unavaible!" << std::endl;
    }
}

void TIGLViewerWindow::standardizeCurrentFile(bool standardize)
{

    if (modificatorManager != nullptr) {
        if (standardize) {

            // close cpacsConfiguration
            closeCpacsConfigurationOnly();
            // disconnect tree to not have tree access during this operation
            cpacsTreeView->disconnectAdapter();

            undoHelper.addCheckPoint();

            modificatorManager->standardizeCurrentFile();

            // reset the creator interface (remark adapter is still the same)
            updateCreatorInterfaceFromAdapter();

            // reopen cpacsConfiguration
            openCpacsConfigurationOnly(undoHelper.currentFile());
        }
        else {
            LOG(WARNING) << "Standardization function is unchecked! Nothing will happend directly, but"
                         << "the cpacs creator standardization will nomore be forced by the software. "
                         << "This can leads to strange strucutre in the cpacs file and the impossiblity to "
                         << "use properly some function of cpacs creator. " << std::endl;
        }
    }
    else {
        LOG(WARNING) << "modificatorManager is null impossible to standardize!" << std::endl;
    }
}

void TIGLViewerWindow::updateRecentFileActions()
{
    QSettings settings("DLR SC-HPC", "TiGLViewer3");
    QStringList files = settings.value("recentFileList").toStringList();

    int numRecentFiles = qMin(files.size(), (int)MaxRecentFiles);

    for (int i = 0; i < numRecentFiles; ++i) {
        QString text = tr("&%1 %2").arg(i + 1).arg(QFileInfo(files[i]).fileName());
        recentFileActions[i]->setText(text);
        recentFileActions[i]->setData(files[i]);
        recentFileActions[i]->setVisible(true);
    }
    for (int j = numRecentFiles; j < MaxRecentFiles; ++j) {
        recentFileActions[j]->setVisible(false);
    }

    recentFileMenu->setEnabled(numRecentFiles > 0);

    myLastFolder = settings.value("lastFolder").toString();
}

void TIGLViewerWindow::updateMenus()
{
    int nWings     = 0;
    int nFuselages = 0;
    int hand       = 0;
    if (cpacsConfiguration) {
        hand = cpacsConfiguration->getCpacsHandle();
        if (hand > 0) {
            tiglGetWingCount(hand, &nWings);
            tiglGetFuselageCount(hand, &nFuselages);
        }
    }

    menuFuselages->setEnabled(nFuselages > 0);
    menuAircraft->setEnabled(nWings > 0 || nFuselages > 0);

    tiglMenu->setEnabled(hand > 0);

    tiglExportMeshedFuselageSTL->setEnabled(nFuselages > 0);
    tiglExportMeshedFuselageVTK->setEnabled(nFuselages > 0);
    tiglExportMeshedFuselageVTKsimple->setEnabled(nFuselages > 0);
    tiglExportFuselageBRepAction->setEnabled(nFuselages > 0);
    tiglExportFuselageColladaAction->setEnabled(nFuselages > 0);
    tiglExportFuselageCurvesBRepAction->setEnabled(nFuselages > 0);

    tiglExportMeshedWingSTL->setEnabled(nWings > 0);
    tiglExportMeshedWingVTK->setEnabled(nWings > 0);
    tiglExportMeshedWingVTKsimple->setEnabled(nWings > 0);
    tiglExportWingBRepAction->setEnabled(nWings > 0);
    tiglExportWingColladaAction->setEnabled(nWings > 0);
    tiglExportWingCurvesBRepAction->setEnabled(nWings > 0);

    closeAction->setEnabled(hand > 0);

    bool hasFarField  = false;
    bool hasACSystems = false;
    int nRotorBlades  = 0;
    int nRotors       = 0;
    try {
        if (hand > 0) {
            tigl::CCPACSConfiguration& config = tigl::CCPACSConfigurationManager::GetInstance().GetConfiguration(hand);
            hasFarField                       = config.GetFarField().GetType() != tigl::NONE;
            hasACSystems                      = config.GetGenericSystemCount() > 0;
            nRotorBlades                      = config.GetRotorBladeCount();
            nRotors                           = config.GetRotorCount();
        }
    }
    catch (tigl::CTiglError&) {
    }
    drawFarFieldAction->setEnabled(hasFarField);
    drawSystemsAction->setEnabled(hasACSystems);
    drawRotorsAction->setEnabled(nRotors > 0);
    menuRotorcraft->setEnabled((nRotors > 0) || (nRotorBlades > 0));
    menuRotorBlades->setEnabled(nRotorBlades > 0);
    menuWings->setEnabled(nWings - nRotorBlades > 0);
}

void TIGLViewerWindow::closeEvent(QCloseEvent*)
{
    saveSettings();
}

TIGLViewerSettings& TIGLViewerWindow::getSettings()
{
    return *tiglViewerSettings;
}

Console* TIGLViewerWindow::getConsole()
{
    return console;
}

void TIGLViewerWindow::makeScreenShot()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Screenshot"), myLastFolder,
                                                    tr("PNG-Image (*.png);;") + tr("JPEG-Image (*.jpg);;") +
                                                        tr("Windows-BMP-Image (*.bmp)"));

    if (!fileName.isEmpty() && myOCC) {

        TIGLViewerScreenshotDialog dialog(fileName, this);
        dialog.setQualityValue(80);
        dialog.setImageSize(myOCC->width(), myOCC->height());
        if (dialog.exec() != QDialog::Accepted) {
            return;
        }

        int width, height;
        dialog.getImageSize(width, height);
        if (!myOCC->makeScreenshot(fileName, dialog.getWhiteBGEnabled(), width, height, dialog.getQualityValue())) {
            displayErrorMessage("Error saving screenshot.", "Error");
        }
    }
}

void TIGLViewerWindow::drawPoint()
{
    TIGLViewerDrawVectorDialog dialog("Draw Point", this);
    dialog.setDirectionEnabled(false);

    if (dialog.exec() != QDialog::Accepted) {
        return;
    }

    gp_Pnt point = dialog.getPoint().Get_gp_Pnt();
    std::stringstream stream;
    stream << "(" << point.X() << ", " << point.Y() << ", " << point.Z() << ")";
    getScene()->displayPoint(point, stream.str().c_str(), Standard_True, 0, 0, 0, 1.);
}

void TIGLViewerWindow::drawVector()
{
    TIGLViewerDrawVectorDialog dialog("Draw Vector", this);

    if (dialog.exec() != QDialog::Accepted) {
        return;
    }

    gp_Pnt point = dialog.getPoint().Get_gp_Pnt();
    gp_Vec dir   = dialog.getDirection().Get_gp_Pnt().XYZ();
    std::stringstream stream;
    stream << "(" << point.X() << ", " << point.Y() << ", " << point.Z() << ")";
    getScene()->displayVector(point, dir, stream.str().c_str(), Standard_True, 0, 0, 0, 1.);
}

/// This function is copied from QtCoreLib (>5.1)
/// and is not available in qt4
bool TIGLViewerWindow::deleteEnvVar(const char* varName)
{
#if defined(_MSC_VER) && _MSC_VER >= 1400
    return _putenv_s(varName, "");
#elif (defined(_POSIX_VERSION) && (_POSIX_VERSION - 0) >= 200112L) || defined(Q_OS_BSD4)
    // POSIX.1-2001 and BSD have unsetenv
    return unsetenv(varName) == 0;
#elif defined(Q_CC_MINGW)
    // On mingw, putenv("var=") removes "var" from the environment
    QByteArray buffer(varName);
    buffer += '=';
    return putenv(buffer.constData()) == 0;
#else
    // Fallback to putenv("var=") which will insert an empty var into the
    // environment and leak it
    QByteArray buffer(varName);
    buffer += '=';
    char* envVar = qstrdup(buffer.constData());
    return putenv(envVar) == 0;
#endif
}
