//
// Created by cfse on 9/26/18.
//

#include "TIGLViewerFuselageWidget.h"
#include "ModificatorManager.h"

TIGLViewerFuselageWidget::TIGLViewerFuselageWidget(QWidget *parent) : ModificatorWidget(parent) {

}


void TIGLViewerFuselageWidget::init(ModificatorManager * associate ) {
    ModificatorWidget::init(associate);

    spinBoxLength = this->findChild<QDoubleSpinBox*>("spinBoxLength");
    widgetLengthDetails = this->findChild<QWidget*>("widgetLengthDetails");
    btnExpendLengthDetails =  this->findChild<QPushButton*>("btnExpendLengthDetails");
    comboBoxLengthE1 = this->findChild<QComboBox*>("comboBoxE1");
    comboBoxLengthE2 = this->findChild<QComboBox*>("comboBoxE2");
    spinBoxPartialLength = this->findChild<QDoubleSpinBox*>("spinBoxPartialLength");

    spinBoxCircumference = this->findChild<QDoubleSpinBox*>("spinBoxCircumference");
    spinBoxRadius = this->findChild<QDoubleSpinBox*>("spinBoxRadius");

    widgetLengthDetails->hide();



    // anchor interface
    spinBoxAnchorX = this->findChild<QDoubleSpinBox*>("spinBoxFuselageAnchorX") ;
    spinBoxAnchorY = this->findChild<QDoubleSpinBox*>("spinBoxFuselageAnchorY") ;
    spinBoxAnchorZ = this->findChild<QDoubleSpinBox*>("spinBoxFuselageAnchorZ") ;




    // connect the extend buttons with their slot
    connect(btnExpendLengthDetails, SIGNAL(clicked(bool)), this, SLOT(expendLengthDetails(bool)) );
    connect(comboBoxLengthE1,SIGNAL(currentIndexChanged(int )), this, SLOT(setPartialLengthFromComboBoxes()));
    connect(comboBoxLengthE2,SIGNAL(currentIndexChanged(int )), this, SLOT(setPartialLengthFromComboBoxes()));
    connect(spinBoxPartialLength, SIGNAL(valueChanged(double)), this, SLOT(recomputeTotalLength(double)));

    // connect spinBoxRadius with spinBoxCircumference
    connect(spinBoxRadius, SIGNAL(valueChanged(double)), this, SLOT(setCircumferenceFromRadius(double)));
    connect(spinBoxCircumference, SIGNAL(valueChanged(double)), this, SLOT(setRadiusFromCircumference(double)));



}


// inverse the visibility
void TIGLViewerFuselageWidget::expendLengthDetails(bool checked) {
    widgetLengthDetails->setVisible(! (widgetLengthDetails->isVisible() ));
    if(widgetLengthDetails->isVisible()){
        // Reset the values to the file values, avoid modifying from details and main at the same time
        internalLength = associateManager->getAdapter()->getFuselageLength(fuselageItem);
        spinBoxLength->setValue(internalLength);
        setPartialLengthFromComboBoxes();
        spinBoxLength->setReadOnly(true);

    }else{
        // Reset the values to the file values, avoid modifying from details and main at the same time
        internalLength = associateManager->getAdapter()->getFuselageLength(fuselageItem);
        spinBoxLength->setValue(internalLength);
        setPartialLengthFromComboBoxes();
        spinBoxLength->setReadOnly(false);

    }

}


void TIGLViewerFuselageWidget::setPartialLengthFromComboBoxes(){

    QString uid1 = comboBoxLengthE1->currentText();
    QString uid2 = comboBoxLengthE2->currentText();
    internalPartialLength = associateManager->getAdapter()->getFuselageLengthBetween(uid1, uid2);
    spinBoxPartialLength->setValue(internalPartialLength);

}

void TIGLViewerFuselageWidget::recomputeTotalLength(double newPartialLength){

    if( !( isApprox(newPartialLength, internalPartialLength) )){ // avoid diff between spin box implementation and double
        double diff = newPartialLength - internalPartialLength;
        spinBoxLength->setValue(internalLength + diff);
    }
}



void TIGLViewerFuselageWidget::setCircumferenceFromRadius(double newRadius) {
    bool block = spinBoxCircumference->blockSignals(true); // to avoid infinite loop with setRadiusFromCircumference
    spinBoxCircumference->setValue(2.0* M_PI * newRadius);
    spinBoxCircumference->blockSignals(block);

}


void TIGLViewerFuselageWidget::setRadiusFromCircumference(double newCircumference) {
    bool block = spinBoxRadius->blockSignals(true); // to avoid infinite loop with setCircumferenceFromRadius
    spinBoxRadius->setValue( newCircumference/ ( M_PI * 2.0));
    spinBoxRadius->blockSignals(block);

}


void TIGLViewerFuselageWidget::setFuselage(cpcr::CPACSTreeItem *fuselageItem) {
    this->fuselageItem = fuselageItem;
    internalLength = associateManager->getAdapter()->getFuselageLength(fuselageItem);
    spinBoxLength->setValue(internalLength);
    comboBoxLengthE1->clear();
    QStringList elementsUids = associateManager->getAdapter()->getFuselageElementUIDs(fuselageItem);
    comboBoxLengthE1->addItems(elementsUids);
    comboBoxLengthE2->clear();
    comboBoxLengthE2->addItems(elementsUids);
    comboBoxLengthE2->setCurrentIndex(elementsUids.size() -1 ); // set the last element of the list
    setPartialLengthFromComboBoxes();
    // do total length after partial length, because changing partial can change total
    internalLength = associateManager->getAdapter()->getFuselageLength(fuselageItem);
    spinBoxLength->setValue(internalLength);
    widgetLengthDetails->setVisible(false);

    // circumference
    internalCircumference = associateManager->getAdapter()->getFuselageMaximalCircumference(this->fuselageItem);
    spinBoxCircumference->setValue(internalCircumference);


    // anchor
    // set anchor
    associateManager->getAdapter()->getAnchorValues(this->fuselageItem, internalAnchorX, internalAnchorY, internalAnchorZ);
    spinBoxAnchorX->setValue(internalAnchorX);
    spinBoxAnchorY->setValue(internalAnchorY);
    spinBoxAnchorZ->setValue(internalAnchorZ);

}

void TIGLViewerFuselageWidget::apply() {

   bool anchorHasChanged = ( (!isApprox(internalAnchorX, spinBoxAnchorX->value()))
                              || (! isApprox(internalAnchorY, spinBoxAnchorY->value()))
                              || (! isApprox(internalAnchorZ , spinBoxAnchorZ->value())) );

   bool lengthHasChanged = ( (! isApprox(internalLength, spinBoxLength->value()) ) );
   bool partialLengthHasChanged = ( ! isApprox(internalPartialLength, spinBoxPartialLength->value() ) );
   bool isPartialCase = widgetLengthDetails->isVisible(); // if expend length details is shown, the details modifications prime on the main mofif
   bool circumferenceHasChanged = ( (! isApprox(internalCircumference, spinBoxCircumference->value())) );


    if( anchorHasChanged ){
        internalAnchorX = spinBoxAnchorX->value();
        internalAnchorY = spinBoxAnchorY->value();
        internalAnchorZ = spinBoxAnchorZ->value();
        associateManager->getAdapter()->setAnchorValues(fuselageItem, internalAnchorX, internalAnchorY, internalAnchorZ);
    }

   if(lengthHasChanged && (!isPartialCase)){
       internalLength = spinBoxLength->value();
       associateManager->getAdapter()->setFuselageLength(fuselageItem, internalLength);
   }
   if(partialLengthHasChanged && isPartialCase){
        internalPartialLength = spinBoxPartialLength->value();
        QString uid1 = comboBoxLengthE1->currentText();
        QString uid2 = comboBoxLengthE2->currentText();
        associateManager->getAdapter()->setFuselageLengthBetween(uid1, uid2, internalPartialLength);
   }

   if( circumferenceHasChanged){
       internalCircumference = spinBoxCircumference->value();
       associateManager->getAdapter()->setFuselageMaximalCircumference(fuselageItem, internalCircumference);
   }

   if(anchorHasChanged || lengthHasChanged || partialLengthHasChanged || circumferenceHasChanged ){
       associateManager->getAdapter()->writeToFile();
   }

}


void TIGLViewerFuselageWidget::reset() {
    if(fuselageItem != nullptr){
        this->setFuselage(this->fuselageItem);
    }else{
        LOG(WARNING) << "TIGLViewerWingWidget: reset call but wing is not set!";
    }
}

