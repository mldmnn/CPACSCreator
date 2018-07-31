//
// Created by makem on 29/04/18.
//




#include "gtest/gtest.h"
#include "AircraftTree.h"

#include "Helper.h"

#include "CreatorException.h"

#include "tigl.h"

#include "MyTestHelperFunctions.h"


using namespace cpcr;

class AircraftTreeTest : public  ::testing::Test {

protected:

    std::string DATA_DIR="/home/cfse/Stage_Malo/CPACSCreatorLib/CPACSCreatorLibTests/CreatorTests/Data/";


    std::string fileName1 = DATA_DIR + "AircraftTreeTest1.xml";
    std::string fileName1b = DATA_DIR + "AircraftTreeTest1b-doubleModel.xml";
    std::string fileName2 = DATA_DIR + "AircraftTreeTest2-getWingSweep2.xml";
    std::string fileName2b = DATA_DIR + "AircraftTreeTest2-getWingSweep2-withPositioning.xml";
    std::string fileName3 = DATA_DIR + "AircraftTreeTest3.xml";
    std::string fileName4 = DATA_DIR + "AircraftTreeTest4-composeTransformRecursively.xml";
    std::string fileName5 = DATA_DIR + "AircraftTreeTest5-setWingSweep2-D150.xml";
    std::string fileName5b = DATA_DIR + "AircraftTreeTest5-setWingSweep2-withPositioning.xml";
    std::string fileName7 = DATA_DIR + "AircraftTreeTest7-getGlobalTransformMatrixOfElement.xml";
    std::string fileName6 = DATA_DIR + "AircraftTreeTest6-positionings.xml";
    std::string fileName8  = DATA_DIR + "Aircraft-unusal-segments-ordering.xml";
    std::string fileName9 = DATA_DIR + "AircraftTreeTest9-getWingSweep.xml";




    std::string currentFile = "not set";
    AircraftTree tree ;
    CPACSTreeItem* root;
    TiglCPACSConfigurationHandle* tiglHandle = tree.getTiglHandle();
    UniqueXPath rootXPath = UniqueXPath("/cpacs/vehicles/aircraft/model[1]");
    std::string outFileName = DATA_DIR + "AircraftTreeTest-out.xml";

    double tempArea, bAreaXY, bAreaXZ, bAreaYZ,bArea, aAreaXY, aAreaXZ,aAreaYZ,aArea;
    void backupReferenceAreaValues() {
        // backup before area
        tiglWingGetReferenceArea(*tiglHandle,1, TIGL_X_Y_PLANE,&bAreaXY);
        // tiglWingGetReferenceArea(*tiglHandle,1, TIGL_X_Z_PLANE,&bAreaXZ);
        tiglWingGetReferenceArea(*tiglHandle,1, TIGL_Y_Z_PLANE,&bAreaYZ);
        // tiglWingGetReferenceArea(*tiglHandle,1, TIGL_NO_SYMMETRY,&bArea);
    }

    void checkCurrentAreasWithBackup(){
        tiglWingGetReferenceArea(*tiglHandle,1, TIGL_X_Y_PLANE,&aAreaXY);
        //tiglWingGetReferenceArea(*tiglHandle,1, TIGL_X_Z_PLANE,&aAreaXZ);
        tiglWingGetReferenceArea(*tiglHandle,1, TIGL_Y_Z_PLANE,&aAreaYZ);
        //tiglWingGetReferenceArea(*tiglHandle,1, TIGL_NO_SYMMETRY,&aArea);

        EXPECT_TRUE(fabs( bAreaXY - aAreaXY) <= 0.001 );
        //EXPECT_EQ(bAreaXZ, aAreaXZ);
        EXPECT_TRUE(fabs( bAreaYZ - aAreaYZ) <= 0.001) ;
        //EXPECT_EQ(bArea, aArea);

    }



    // used to check if chords of the wing has changed
    std::vector<cpcr::UID> UIDs;
    std::map<cpcr::UID, Eigen::Vector4d> lEsB;
    std::map<cpcr::UID, Eigen::Vector4d> tEsB;
    std::map<cpcr::UID, Eigen::Vector4d> lEsA;
    std::map<cpcr::UID, Eigen::Vector4d> tEsA;

    void backupChordPointsOfWing(std::string wingUID) {

        CPACSTreeItem *wing = tree.getRoot()->getChildByUid(wingUID);

        UIDs = tree.getAllElementUIDsUsedInAWing(wing->getUid());
        lEsB = tree.getChordPointsOfElements(wing->getUid(), 0);
        tEsB = tree.getChordPointsOfElements(wing->getUid(), 1);
    }

    void checkCurrentChordPointsWithBackup(std::string wingUID){

        CPACSTreeItem *wing = tree.getRoot()->getChildByUid(wingUID);
        lEsA = tree.getChordPointsOfElements(wing->getUid(), 0);
        tEsA = tree.getChordPointsOfElements(wing->getUid(), 1);

        for(UID u: UIDs )
        {
            EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.0001) );
            EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.0001) ) ;
        }

    }




    void setVariables(std::string fileName){
        currentFile = DATA_DIR + fileName;
        tree.build(currentFile, rootXPath);
        root = tree.getRoot();
        tree.writeToFile(outFileName);  // for visual test
    }

};

TEST_F(AircraftTreeTest, buildAndClose ){

    AircraftTree aircraftTree ;
    EXPECT_TRUE(aircraftTree.getRoot() == nullptr);
    EXPECT_TRUE(aircraftTree.isBuild() == false);
    aircraftTree.close();
    EXPECT_TRUE(aircraftTree.getRoot() == nullptr);
    EXPECT_TRUE(aircraftTree.isBuild() == false);

    std::string tempFilename = DATA_DIR + "D150_AGILE_Hangar_3.xml";
    aircraftTree.build(tempFilename, rootXPath);

    EXPECT_TRUE(aircraftTree.getRoot() != nullptr);
    EXPECT_TRUE(aircraftTree.isBuild() != false);
    CPACSTreeItem* backupRoot = aircraftTree.getRoot();
    EXPECT_TRUE(backupRoot->getUid() == "D150_VAMP");

    aircraftTree.close();
    EXPECT_TRUE(aircraftTree.getRoot() == nullptr);
    EXPECT_TRUE(aircraftTree.isBuild() == false);

    aircraftTree.build(tempFilename, rootXPath);

    EXPECT_TRUE(aircraftTree.getRoot() != nullptr);
    EXPECT_TRUE(aircraftTree.isBuild() != false);
    EXPECT_TRUE(aircraftTree.getRoot()->getUid() == "D150_VAMP");
    EXPECT_TRUE(aircraftTree.getRoot() != backupRoot);

    aircraftTree.close();
    EXPECT_TRUE(aircraftTree.getRoot() == nullptr);
    EXPECT_TRUE(aircraftTree.isBuild() == false);


}



TEST_F(AircraftTreeTest, build){

    // initial state ( aircraftTree is construct each time by the gtest lib)
    tiglHandle =  tree.getTiglHandle();

    EXPECT_FALSE( tree.isBuild());
    EXPECT_EQ( (int) *(tiglHandle) , 0);

    // construct the tree
    tree.build(fileName1, UniqueXPath("/cpacs/vehicles/aircraft/model[1]"));
    root = tree.getRoot();


    // check result
    EXPECT_EQ( root->getXPath().toString(), "/cpacs/vehicles/aircraft/model[1]" );
    EXPECT_EQ( root->getType(), "model");
    EXPECT_TRUE( tree.isBuild() );
    TiglBoolean isValid;
    tiglIsCPACSConfigurationHandleValid(*(tiglHandle), &isValid );
    EXPECT_EQ( isValid, TIGL_TRUE);

    EXPECT_EQ( root->getChildren().size(), 3);
    EXPECT_EQ( root->hasChildOfType("name"), true );
    EXPECT_EQ( root->hasChildOfType("fuselages"), true );
    EXPECT_EQ( root->hasChildOfType("wings"), true );

    CPACSTreeItem* child = root->getChild(UniqueXPath("wings"))->getChild(UniqueXPath("wing"));
    EXPECT_EQ( child->getType(),"wing");
    EXPECT_EQ( child->getChildren().size(), 4);
    EXPECT_TRUE( child->hasChildOfType("transformation")) ;

    CPACSTreeItem* fuselage = root->getChild("./fuselages/fuselage");
    EXPECT_EQ(fuselage->getUid(), "SimpleFuselage");


    // double model check & tigl updat

    // construct an other tree with the object
    tree.build(fileName1b, UniqueXPath("/cpacs/vehicles/aircraft/model[2]"));
    root = tree.getRoot();

    EXPECT_EQ(root->getUid(), "Cpacs2Test");
    tiglIsCPACSConfigurationHandleValid(*(tiglHandle), &isValid );
    EXPECT_EQ( isValid, TIGL_TRUE);
    int count  = 0;
    tiglGetWingCount(*(tiglHandle), &count);
    EXPECT_EQ(count, 0);
    EXPECT_EQ(root->findAllChildrenOfTypeRecursively("wing").size(),0);


    // construct an other tree with the object
    tree.build(fileName1b, UniqueXPath("/cpacs/vehicles/aircraft/model[1]"));
    root = tree.getRoot();

    EXPECT_EQ(root->getUid(), "mDsave");
    tiglIsCPACSConfigurationHandleValid(*(tiglHandle), &isValid );
    EXPECT_EQ( isValid, TIGL_TRUE);
    count  = 0;
    tiglGetWingCount(*(tiglHandle), &count);
    EXPECT_EQ(count, 3);
    EXPECT_EQ(root->findAllChildrenOfTypeRecursively("wing").size(),3);


    // incorrect xpath (not a model)
    EXPECT_THROW(tree.build(fileName1,UniqueXPath("/cpacs/vehicles/aircraft")), CreatorException);
    EXPECT_EQ(tree.isBuild(), false);
    tiglIsCPACSConfigurationHandleValid(*(tiglHandle), &isValid );
    EXPECT_EQ( isValid, TIGL_FALSE);

    // TODO INCORRECT INVALID XPATH BEHAVIOR

}



TEST_F(AircraftTreeTest, getTransformToPlaceElementAt ){


    tree.build(fileName3, UniqueXPath("/cpacs/vehicles/aircraft/model[1]") );
    root = tree.getRoot();

    Eigen::Vector4d wantedP ;
    wantedP << 30,14,3, 1;
    UID elementToPlace = "Wing_section1_element1";

    CPACSTransformation e(1,1,1,0,0,0,30,14,-2);
    CPACSTransformation t = tree.getTransformToPlaceElementByTranslationAt(elementToPlace, wantedP);
    EXPECT_TRUE( t == e);

    wantedP << 0,10,0, 1;
    elementToPlace = "Wing_section2_element1";
    e = CPACSTransformation(1,1,1,0,0,0,0,7.0710678118654,-7.0710678118654);
    t = tree.getTransformToPlaceElementByTranslationAt(elementToPlace, wantedP);
    EXPECT_TRUE( t.getTransformationAsMatrix().isApprox(e.getTransformationAsMatrix(), 0.0001) );


    wantedP << 0,0,0, 1;
    elementToPlace = "Wing_section3_element1";
    e = CPACSTransformation(1,1,1,0,0,0,4.22-1,7.84-1,4.53-0);
    t = tree.getTransformToPlaceElementByTranslationAt(elementToPlace, wantedP);
    EXPECT_TRUE( t.getTransformationAsMatrix().isApprox(e.getTransformationAsMatrix(), 0.01) );


}



TEST_F(AircraftTreeTest, determinePositionBySweepAngle ){

    tree.build(fileName2, UniqueXPath("/cpacs/vehicles/aircraft/model[1]") );
    root = tree.getRoot();

    Eigen::Vector4d a,b,c, r, e ;
    a << 0,0,0,1;
    b << 10,4,0,1;
    c << 0,4,0,1;
    e << 3,4,0,1; // the expected value

    double angle = RadianToDegree( (acos(0.8)) );
    r = tree.computePositionToHaveSweepAngle(a, b, angle);
    EXPECT_TRUE( e.isApprox(r) );

    a << 3,3,3,1;
    b << 13,7,3,1;
    e << 6,7,3,1; // the expected value

    angle = RadianToDegree( (acos(0.8)) );
    r = tree.computePositionToHaveSweepAngle(a, b, angle);
    EXPECT_TRUE( e.isApprox(r) );

    a << 3,3,3,1;
    b << 13,3.866025403,-1,1;
    e << 3.5,3.866025403,-1,1; // the expected value
    angle = 30 ;
    r = tree.computePositionToHaveSweepAngle(a, b, angle);
    EXPECT_TRUE( e.isApprox(r, 0.0001) );


}



TEST_F(AircraftTreeTest, getTransformationChainForOneElement){


    tree.build(fileName6, UniqueXPath("/cpacs/vehicles/aircraft/model[1]") );
    root = tree.getRoot();

    CPACSTransformation identity, expected;


    // Case 1 (basic)
    CPACSTreeItem* element = root->getChildByUid("Wing_section2_element1");

    auto r = tree.getTransformationChainForOneElement(element);

    EXPECT_EQ(r.size(), 4);

    EXPECT_EQ(r[3].first->getUid(), "Wing_transformation1");
    EXPECT_TRUE(r[3].second.isApprox( identity.getTransformationAsMatrix()) );


    expected = CPACSTransformation(1,1,1,0,0,0,0,3.3,0);
    EXPECT_EQ(r[2].first->getUid(), "pos1");
    EXPECT_TRUE(r[2].second.isApprox( expected.getTransformationAsMatrix()) );


    expected = CPACSTransformation(0.5,1,1,0,0,0,0,0,0);
    EXPECT_EQ(r[1].first->getUid(), "Wing_section2_transformation1");
    EXPECT_TRUE(r[1].second.isApprox( expected.getTransformationAsMatrix()) );

    expected = CPACSTransformation(2,1,1,0,0,0,0,3,0);
    EXPECT_EQ(r[0].first->getUid(), "Wing_section2_element1_transformation1");
    EXPECT_TRUE(r[0].second.isApprox( expected.getTransformationAsMatrix()) );


    // Case 2 (no positioning )
    element = root->getChildByUid("Wing_section1_element1");
    r = tree.getTransformationChainForOneElement(element);

    EXPECT_EQ(r.size(), 4);

    EXPECT_EQ(r[3].first->getUid(), "Wing_transformation1");
    EXPECT_TRUE(r[3].second.isApprox( identity.getTransformationAsMatrix()) );


    EXPECT_EQ(r[2].first, nullptr);
    EXPECT_TRUE(r[2].second.isApprox( identity.getTransformationAsMatrix()) );


    expected = CPACSTransformation(1,1,1,0,0,0,0,-0.5,0);
    EXPECT_EQ(r[1].first->getUid(), "Wing_section1_transformation1");
    EXPECT_TRUE(r[1].second.isApprox( expected.getTransformationAsMatrix()) );

    expected = CPACSTransformation(2.2,1,1,0,0,0,0,0,0);
    EXPECT_EQ(r[0].first->getUid(), "Wing_section1_element1_transformation1");
    EXPECT_TRUE(r[0].second.isApprox( expected.getTransformationAsMatrix()) );


    // case 3 ( multiple positioning)

    // positioning 1
    element = root->getChildByUid("Wing2_section1_element1");
    r = tree.getTransformationChainForOneElement(element);

    EXPECT_EQ(r.size(), 4);

    EXPECT_EQ(r[3].first->getUid(), "Wing2_transformation1");
    EXPECT_TRUE(r[3].second.isApprox( identity.getTransformationAsMatrix()) );

    expected = CPACSTransformation(1,1,1,0,0,0,4.22,7.84,4.53);
    EXPECT_EQ(r[2].first->getUid(), "Wing2_positioning1" );
    EXPECT_TRUE(r[2].second.isApprox( expected.getTransformationAsMatrix(), 0.05) );

    EXPECT_EQ(r[1].first->getUid(), "Wing2_section1_transformation1");
    EXPECT_TRUE(r[1].second.isApprox( identity.getTransformationAsMatrix()) );

    EXPECT_EQ(r[0].first->getUid(), "Wing2_section1_element1_transformation1");
    EXPECT_TRUE(r[0].second.isApprox( identity.getTransformationAsMatrix()) );

    // positioning 2
    element = root->getChildByUid("Wing2_section2_element1");
    r = tree.getTransformationChainForOneElement(element);

    EXPECT_EQ(r.size(), 4);

    EXPECT_EQ(r[3].first->getUid(), "Wing2_transformation1");
    EXPECT_TRUE(r[3].second.isApprox( identity.getTransformationAsMatrix()) );

    expected = CPACSTransformation(1,1,1,0,0,0,7.07,5.42,4.54);
    EXPECT_EQ(r[2].first->getUid(), "Wing2_positioning2");
    EXPECT_TRUE(r[2].second.isApprox( expected.getTransformationAsMatrix(), 0.01) );

    EXPECT_EQ(r[1].first->getUid(), "Wing2_section2_transformation1");
    EXPECT_TRUE(r[1].second.isApprox( identity.getTransformationAsMatrix()) );

    EXPECT_EQ(r[0].first->getUid(), "Wing2_section2_element1_transformation1");
    EXPECT_TRUE(r[0].second.isApprox( identity.getTransformationAsMatrix()) );

    // positioning 3
    element = root->getChildByUid("Wing2_section3_element1");
    r = tree.getTransformationChainForOneElement(element);

    EXPECT_EQ(r.size(), 4);

    EXPECT_EQ(r[3].first->getUid(), "Wing2_transformation1");
    EXPECT_TRUE(r[3].second.isApprox( identity.getTransformationAsMatrix()) );

    expected = CPACSTransformation(1,1,1,0,0,0,11.29,13.25,9.07);
    EXPECT_EQ(r[2].first->getUid(), "Wing2_positioning3");
    EXPECT_TRUE(r[2].second.isApprox( expected.getTransformationAsMatrix(), 0.02) );

    EXPECT_EQ(r[1].first->getUid(), "Wing2_section3_transformation1");
    EXPECT_TRUE(r[1].second.isApprox( identity.getTransformationAsMatrix()) );

    EXPECT_EQ(r[0].first->getUid(), "Wing2_section3_element1_transformation1");
    EXPECT_TRUE(r[0].second.isApprox( identity.getTransformationAsMatrix()) );

}



TEST_F(AircraftTreeTest, getGlobalTransformMatrixOfElement){

    tree.build(fileName7, UniqueXPath("/cpacs/vehicles/aircraft/model[1]") );
    root = tree.getRoot();


    Eigen::Vector4d o, r ,e;

    Eigen::Matrix3d mEuler ;
    Eigen::Vector3d o3d, e3d, r3d , r13d, r23d;
    // Euler rotation matrix X45 Y'30 Z"20 taken from internet
    mEuler.row(0) <<  0.8137977, -0.2961981,  0.5000000;
    mEuler.row(1) <<   0.5740763,  0.5435407, -0.6123725;
    mEuler.row(2) <<   -0.0903867,  0.7853854,  0.6123725 ;



    auto m = tree.getGlobalTransformMatrixOfElement("Wing_section2_element1");

    o3d << 3,-2,10;
    r3d = mEuler * o3d;

    o << 0,0,0,1;
    e << r3d[0], r3d[1] , r3d[2],  1 ;

    r = m * o;

    EXPECT_TRUE( r.isApprox(e, 0.0001) );



    o3d << 0,0,0;
    r3d = mEuler * o3d;

    o << -3,2,-10,1;
    e << r3d[0], r3d[1] , r3d[2],  1 ;

    r = m * o;

    EXPECT_TRUE( r.isApprox(e, 0.0001) );


    o3d << 3 + 1,-2 + 3 ,10 + 4;
    r3d = mEuler * o3d;

    o << 1,3,4,1;
    e << r3d[0], r3d[1] , r3d[2],  1 ;

    r = m * o;

    EXPECT_TRUE( r.isApprox(e, 0.0001) );

}



TEST_F(AircraftTreeTest, writeToFile){

    tree.build(fileName5, UniqueXPath("/cpacs/vehicles/aircraft/model[1]") );
    root = tree.getRoot();
    tiglHandle = tree.getTiglHandle();

    TiglCPACSConfigurationHandle tiglHandleBackUp = *tiglHandle;

    tree.setWingSweepByShearing("D150_VAMP_wing_W1", 40);
    tree.writeToFile(DATA_DIR +"out-AircraftTreeTest5-setWingSweep2-D150.xml");

    EXPECT_EQ(tree.isBuild(), true);
    EXPECT_EQ(tree.getFilename(), DATA_DIR +"out-AircraftTreeTest5-setWingSweep2-D150.xml");
    EXPECT_FALSE( *tiglHandle == tiglHandleBackUp);
    tiglHandleBackUp = *tiglHandle;

    tree.writeToFile();
    EXPECT_EQ(tree.isBuild(), true);
    EXPECT_EQ(tree.getFilename(), DATA_DIR +"out-AircraftTreeTest5-setWingSweep2-D150.xml");
    EXPECT_FALSE( *tiglHandle == tiglHandleBackUp);


}



TEST_F(AircraftTreeTest, getWingSweep){


    double sweep = -1;

    // fileName2 is define with leading edge airfoil at (0,0,0)

    std::string filename = "AircraftTreeTest2-getWingSweep2.xml";
    setVariables(filename);

    sweep = tree.getWingSweep("D150_VAMP_wing_W1",0);
    EXPECT_TRUE( sweep > 19 && sweep < 21 );

    sweep = tree.getWingSweep("D150_VAMP_htp_HL1",0);
    EXPECT_TRUE( sweep > 26.5 && sweep < 26.6 );

    sweep = tree.getWingSweep("D150_VAMP_vtp_SL1",0);
    EXPECT_TRUE( sweep > 40 && sweep < 42 );



    filename = "AircraftTreeTest9-getWingSweep.xml";
    setVariables(filename);

    sweep = tree.getWingSweep("D150_VAMP_wing_W1",0.5);
    EXPECT_TRUE( sweep > 19 && sweep < 21 );

    sweep = tree.getWingSweep("D150_VAMP_htp_HL1",0.5);
    EXPECT_TRUE( sweep > 26.5 && sweep < 26.6 );

}



TEST_F(AircraftTreeTest, setWingSweepByTranslation){


    //
    //  TEST leading edge set wing sweep (chordPercent = 0)
    //

    tree.build(fileName5, UniqueXPath("/cpacs/vehicles/aircraft/model[1]") );
    root = tree.getRoot();
    tree.writeToFile(outFileName);


    // set to 40
    double before = tree.getWingSweep("D150_VAMP_wing_W1",0);
    EXPECT_TRUE( before > 24 && before < 25);

    tree.setWingSweepByTranslation("D150_VAMP_wing_W1", 40, 0);

    tree.writeToFile(outFileName);
    double after = tree.getWingSweep("D150_VAMP_wing_W1", 0);
    EXPECT_TRUE(after > 39.9 && after < 40.1);


    tree.setWingSweepByTranslation("D150_VAMP_wing_W1", 70);

    after = tree.getWingSweep("D150_VAMP_wing_W1");
    EXPECT_TRUE(after > 69.9 && after < 70.1);

    tree.writeToFile(outFileName);


    // set to 7
    tree.setWingSweepByTranslation("D150_VAMP_wing_W1", 7);

    after = tree.getWingSweep("D150_VAMP_wing_W1");
    EXPECT_TRUE(after > 6.9 && after < 7.1);

    tree.writeToFile(outFileName);

    // TODO : limit case around 90 degrees


    //
    //  TEST set wing sweep with chord middle (chordPercent = 0.5)
    //
    // fileName9 is the same file as fileName2 but with centered airfoil
    // -> so getWingSweepOfOrigin( x ) is more or less  equivalent to getWingSweep(x, 0.5)
    tree.build(fileName9, UniqueXPath("/cpacs/vehicles/aircraft/model[1]") );
    root = tree.getRoot();

    tree.writeToFile(outFileName);

    before = tree.getWingSweep("D150_VAMP_wing_W1",0.5);

    tree.setWingSweepByTranslation("D150_VAMP_wing_W1", 30, 0.5);

    after = tree.getWingSweep("D150_VAMP_wing_W1",0.5);

    EXPECT_TRUE( after > 29 && after < 31 );

    double alterSweep = tree.getWingSweep("D150_VAMP_wing_W1",0);
    EXPECT_FALSE(  alterSweep > 29 && alterSweep < 31 );

    tree.writeToFile(outFileName);

    //

    currentFile = DATA_DIR + "wing-simple.xml";
    tree.build(currentFile, rootXPath );
    root = tree.getRoot();
    tree.writeToFile(outFileName);

    before = tree.getWingSweep("Wing");
    EXPECT_TRUE( before > -0.1 && before < 0.1 );
    tree.setWingSweepByTranslation("Wing",20,0);
    after = tree.getWingSweep("Wing");
    EXPECT_TRUE( after > 19.9 && after < 20.1 );
    tree.writeToFile(outFileName);


    // TEST CASE bwb

    setVariables("TestCases/blendedWingBody.xml");
    std::string wingUID = "BWB450_wingID";
    before = tree.getWingSweep(wingUID,0);
    EXPECT_TRUE( before > 50 && before < 55 );
    tree.setWingSweepByTranslation(wingUID,20,0);
    tree.writeToFile(outFileName);
    after = tree.getWingSweep(wingUID);
    EXPECT_TRUE( after > 19.9 && after < 20.1 );
    tree.writeToFile(outFileName);


    // The wing transform should not influence the wing sweep
    setVariables("blendedWingBody-rot20.xml");

    before = tree.getWingSweep(wingUID,0);
    EXPECT_TRUE( before > 50 && before < 55 );
    tree.setWingSweepByTranslation(wingUID,20,0);
    tree.writeToFile(outFileName);
    after = tree.getWingSweep(wingUID);
    EXPECT_TRUE( after > 19.9 && after < 20.1 );


}



TEST_F(AircraftTreeTest, setWingSweepByShearingSimpleWing){


    /*
     * WING SIMPLE
     */

    currentFile = DATA_DIR + "wing-simple.xml";
    tree.build(currentFile, rootXPath );
    root = tree.getRoot();

    tree.writeToFile(outFileName);  // to follow the process with tiglviewer

    // Test the value before the modification
    double before = tree.getWingSweep("Wing",0);

    backupReferenceAreaValues();

    // set to 60
    tree.setWingSweepByShearing("Wing", 60, 0);
    tree.writeToFile(outFileName);

    // check the values after
    double after = tree.getWingSweep("Wing", 0);
    EXPECT_TRUE(after > 59.9 && after < 70.1);
    std::map<cpcr::UID, Eigen::Vector4d>  chordPoints = tree.getChordPointsOfElements("Wing", 0);
    Eigen::Vector4d chord1E, chord2E  ;
    chord1E << -1, 0, 0,1;
    chord2E << 0.73205081, 1, 0,1;
    EXPECT_TRUE(chordPoints["Wing_section1_element1"].isApprox(chord1E, 0.0001));
    EXPECT_TRUE(chordPoints["Wing_section2_element1"].isApprox(chord2E, 0.0001));

    checkCurrentAreasWithBackup(); // areas need to stand the same



    /*
     * WING SIMPLE ROTATIONS
     */

    // create the tree
    currentFile = DATA_DIR + "wing-simple-rotations-2.xml";
    tree.build(currentFile, rootXPath );
    root = tree.getRoot();
    tree.writeToFile(outFileName);
    // check the values before
    before = tree.getWingSweep("Wing",0.5);
    EXPECT_TRUE( before > -0.1 && before < 0.1);
    backupReferenceAreaValues();
    // set to 60
    tree.setWingSweepByShearing("Wing", 60, 0);
    tree.writeToFile(outFileName);
    after = tree.getWingSweep("Wing", 0);
    checkCurrentAreasWithBackup();




    /*
     * WING SIMPLE ONE KICK
     */

    currentFile = DATA_DIR + "wing-one-kick.xml";
    tree.build(currentFile, UniqueXPath("/cpacs/vehicles/aircraft/model[1]") );
    root = tree.getRoot();
    tree.writeToFile(outFileName);  // for visual test
    before = tree.getWingSweep("Wing",0);
    backupReferenceAreaValues();
    EXPECT_TRUE( before > 26.56 && before < 26.9);
    tree.setWingSweepByShearing("Wing", 60, 0);
    tree.writeToFile(outFileName);
    after = tree.getWingSweep("Wing", 0);
    EXPECT_TRUE(after > 59.9 && after < 70.1);
    checkCurrentAreasWithBackup();


    /*
     * WING SIMPLE ONE KICK + ROTATIONS
     */

    currentFile = DATA_DIR + "wing-one-kick-rotations-scales.xml";
    tree.build(currentFile, UniqueXPath("/cpacs/vehicles/aircraft/model[1]") );
    root = tree.getRoot();
    tree.writeToFile(outFileName);  // for visual test
    before = tree.getWingSweep("Wing",0.5);
    backupReferenceAreaValues();
    EXPECT_TRUE( before > 26.56 && before < 26.9);
    tree.setWingSweepByShearing("Wing", 60, 0.5);
    tree.writeToFile(outFileName);
    after = tree.getWingSweep("Wing", 0);
    EXPECT_TRUE(after > 59.9 && after < 70.1);
    checkCurrentAreasWithBackup();


    // TEST CASE D150

    setVariables("TestCases/d150.xml");
    std::string wingUID = "D150_VAMP_vtp_SL1";
    tree.writeToFile();

    before = tree.getWingSweep(wingUID, 0);
    backupReferenceAreaValues();
    EXPECT_TRUE(before > 40 && before < 41);
    tree.setWingSweepByShearing(wingUID, 12);
    tree.writeToFile();
    after = tree.getWingSweep(wingUID, 0);
    EXPECT_TRUE(after > 11.9 && after < 12.1);
    checkCurrentAreasWithBackup();


    before = tree.getWingSweep(wingUID, 1);
    backupReferenceAreaValues();
    EXPECT_TRUE(before > -22 && before <  -20);
    tree.setWingSweepByShearing(wingUID, 12, 1);
    tree.writeToFile();
    after = tree.getWingSweep(wingUID, 1);
    EXPECT_TRUE(after > 11.9 && after < 12.1);
    checkCurrentAreasWithBackup();



    // TEST CASE BOXWING

    setVariables("TestCases/boxWing.xml");
    wingUID = "D150_VAMP_W1";


    before = tree.getWingSweep(wingUID, 0);
    backupReferenceAreaValues();
    EXPECT_TRUE(before > 26 && before < 28);

    tree.setWingSweepByShearing(wingUID, 12, 0.5);
    tree.writeToFile();
    after = tree.getWingSweep(wingUID, 0.5);
    EXPECT_TRUE(after > 11.9 && after < 12.1);
    checkCurrentAreasWithBackup();


    backupReferenceAreaValues();
    tree.setWingSweepByShearing(wingUID, 72, 0.5);
    tree.writeToFile();
    after = tree.getWingSweep(wingUID, 0.5);
    EXPECT_TRUE(after > 71.9 && after < 72.1);
    checkCurrentAreasWithBackup();


    backupReferenceAreaValues();
    tree.setWingSweepByShearing(wingUID, 23, 1);
    tree.writeToFile();
    after = tree.getWingSweep(wingUID, 1);
    EXPECT_TRUE(after > 22.9 && after < 23.1);
    checkCurrentAreasWithBackup();





}



TEST_F(AircraftTreeTest, getWingDihedral)
{

    double dihedral = -1;
    double sweep = -1;


    //
    //  SIMPLE WING WITH NO DIHEDRAL AND NOR SWEEP
    //


    setVariables( "wing-simple.xml") ;

    dihedral = tree.getWingDihedral("Wing", 0);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 0));

    dihedral = tree.getWingDihedral("Wing", 0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 0));

    dihedral = tree.getWingDihedral("Wing", 1);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 0));


    //
    //  SIMPLE WING WITH DIHEDRAL AND SWEEP
    //

    setVariables( "wing-simple-d30-s30-by-positioning.xml");


    // just some check about the sweep (remember the sweep angle is not the same as in the positiong in cpacs file)
    sweep = tree.getWingSweep("Wing");
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(sweep,33.69));

    sweep = tree.getWingSweep("Wing",0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(sweep,33.69));

    // dihedral
    dihedral = tree.getWingDihedral("Wing", 0);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 30));

    dihedral = tree.getWingDihedral("Wing", 0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 30));

    dihedral = tree.getWingDihedral("Wing", 1);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 30));

    //
    //  SIMPLE WING WITH NEGATIVE DIHEDRAL AND NEGATIVE SWEEP
    //

    setVariables( "wing-simple-dm30-sm30-by-positioning.xml");


    // just some check about the sweep (remember the sweep angle is not the same as in the positiong in cpacs file)
    sweep = tree.getWingSweep("Wing");
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(sweep,-33.69));

    sweep = tree.getWingSweep("Wing",0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(sweep,-33.69));

    // dihedral
    dihedral = tree.getWingDihedral("Wing", 0);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, -30));

    dihedral = tree.getWingDihedral("Wing", 0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, -30));

    dihedral = tree.getWingDihedral("Wing", 1);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, -30));



    //
    //  SIMPLE WING WITH NEGATIVE DIHEDRAL AND POSITIVE SWEEP
    //

    setVariables( "wing-simple-dm30-s30-by-positioning.xml");

    // just some check about the sweep (remember the sweep angle is not the same as in the positiong in cpacs file)
    sweep = tree.getWingSweep("Wing");
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(sweep,33.69));

    sweep = tree.getWingSweep("Wing",0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(sweep,33.69));

    // dihedral
    dihedral = tree.getWingDihedral("Wing", 0);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, -30));

    dihedral = tree.getWingDihedral("Wing", 0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, -30));

    dihedral = tree.getWingDihedral("Wing", 1);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, -30));



    //
    //  SIMPLE WING WITH POSITIVE DIHEDRAL AND NEGATIVE SWEEP
    //

    setVariables( "wing-simple-d30-sm30-by-positioning.xml");

    // just some check about the sweep (remember the sweep angle is not the same as in the positiong in cpacs file)
    sweep = tree.getWingSweep("Wing");
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(sweep,-33.69));

    sweep = tree.getWingSweep("Wing",0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(sweep,- 33.69));

    // dihedral
    dihedral = tree.getWingDihedral("Wing", 0);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 30));

    dihedral = tree.getWingDihedral("Wing", 0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 30));

    dihedral = tree.getWingDihedral("Wing", 1);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 30));


    // TEST CASE D150

    setVariables("d150-vt-dihedral.xml");
    std::string wingUID = "D150_VAMP_vtp_SL1";
    tree.writeToFile();

    double before = tree.getWingDihedral(wingUID, 0);
    EXPECT_TRUE(before > 9.9 && before < 10.1);

    before = tree.getWingDihedral(wingUID, 1);
    EXPECT_TRUE(before > 9.9 && before < 10.1);

}



TEST_F(AircraftTreeTest, setWingDihedral)
{

    double oldDihedral, newDihedral;


    //
    //  SIMPLE WING WITH NO DIHEDRAL AND NOR SWEEP
    //

    setVariables( "wing-simple.xml") ;

    oldDihedral = tree.getWingDihedral("Wing", 0);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(oldDihedral, 0));

    backupReferenceAreaValues();
    tree.setWingDihedral("Wing",30);
    tree.writeToFile(outFileName);
    newDihedral = tree.getWingDihedral("Wing");
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(newDihedral, 30));
    checkCurrentAreasWithBackup();


    //
    //  SIMPLE WING WITH POSITIVE DIHEDRAL AND NEGATIVE SWEEP
    //

    setVariables( "wing-simple-d30-sm30-by-positioning.xml");


    oldDihedral = tree.getWingDihedral("Wing", 0);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(oldDihedral, 30));
    backupReferenceAreaValues();

    tree.setWingDihedral("Wing",20);
    tree.writeToFile(outFileName);
    newDihedral = tree.getWingDihedral("Wing");
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(newDihedral, 20));
    checkCurrentAreasWithBackup();



    /*
     * WING SIMPLE ONE KICK + ROTATIONS
     */

    setVariables( "wing-one-kick-rotations-scales.xml");
    oldDihedral = tree.getWingDihedral("Wing");
    backupReferenceAreaValues();

    tree.setWingDihedral("Wing", 15 , 0.5);
    tree.writeToFile(outFileName);
    newDihedral = tree.getWingDihedral("Wing", 0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(newDihedral, 15));



    // TEST CASE BOXWING

    double before , after;

    setVariables("TestCases/boxWing.xml");
    std::string wingUID = "D150_VAMP_W1";

    before = tree.getWingDihedral(wingUID, 0);
    backupReferenceAreaValues();
    EXPECT_TRUE(before > 2 && before < 8);
    tree.setWingDihedral(wingUID, -12, 0.5);
    tree.writeToFile();
    after = tree.getWingDihedral(wingUID, 0.5);
    EXPECT_TRUE(after > -12.1 && after < -11.9);
    checkCurrentAreasWithBackup();


    backupReferenceAreaValues();
    tree.setWingDihedral(wingUID, 72, 0.5);
    tree.writeToFile();
    after = tree.getWingDihedral(wingUID, 0.5 );
    EXPECT_TRUE(after > 71.9 && after < 72.1);
    checkCurrentAreasWithBackup();


    backupReferenceAreaValues();
    tree.setWingDihedral(wingUID, 23, 1);
    tree.writeToFile();
    after = tree.getWingDihedral(wingUID, 1);
    EXPECT_TRUE(after > 22.9 && after < 23.1);
    checkCurrentAreasWithBackup();





}



TEST_F(AircraftTreeTest, setWingAirfoils)
{
    std::string filename = "AircraftTreeTest-setAirfoils.xml";
    setVariables(filename);
    tree.writeToFile(outFileName);

    tree.setWingAirfoilsFromExternalFile("Wing", DATA_DIR + "profile-simple.dat", false);
    tree.writeToFile(outFileName);

    tree.setWingAirfoilsFromExternalFile("Wing", DATA_DIR + "profile-mdAirfoil2.dat");
    tree.writeToFile(outFileName);

    tree.setWingAirfoilsFromExternalFile("Wing", DATA_DIR + "profile-BW050209.dat");
    tree.writeToFile(outFileName);

    tree.setWingAirfoilsFromExternalFile("Wing", DATA_DIR + "profile-BW050209.dat"); // should add a suffix
    tree.writeToFile(outFileName);

    tree.setWingAirfoilsByUID("Wing", "profile-mdAirfoil2");
    tree.writeToFile(outFileName);

    EXPECT_THROW(tree.setWingAirfoilsByUID("Wing","dasdfas"), CreatorException);


    tree.setWingAirfoilsFromExternalFile("Wing", DATA_DIR + "profile-simple-shifted.dat", true); // should not shift
    tree.writeToFile(outFileName);


    tree.setWingAirfoilsByUID("Wing","profile-BW050209", true); // should shift one more
    tree.writeToFile(outFileName);


    tree.setWingAirfoilsFromExternalFile("Wing", DATA_DIR + "profile-simple-shifted.dat", false); // should shift one more
    tree.writeToFile(outFileName);


}



TEST_F(AircraftTreeTest, getAirfoilsUID)
{
    std::string filename = "AircraftTreeTest-getAirfoils.xml";
    setVariables(filename);

    std::vector<UID> r = tree.getAllAirfoilsUIDInThisWing("Wing");
    std::vector<UID> e;
    e.push_back("profile-mdAirfoil2");
    e.push_back("profile-mdAirfoil3");

    EXPECT_EQ(r,e);

}



TEST_F(AircraftTreeTest, getWingGraph)
{
    std::string filename = "wing-simple-1.xml";
    setVariables(filename);

    // Test basic case

    CPACSTreeItem* wing = tree.getRoot()->getChildByUid("Wing");
    std::map<cpcr::CPACSTreeItem *, std::vector<cpcr::CPACSTreeItem *> >  r = tree.getWingGraph(wing);

    EXPECT_EQ(r.size(), 2);

    CPACSTreeItem* e1 = tree.getRoot()->getChildByUid("Wing_section1_element1");
    CPACSTreeItem* e2 = tree.getRoot()->getChildByUid("Wing_section2_element1");
    EXPECT_EQ(r[e1][0], e2);
    EXPECT_EQ(r[e1].size(), 1);
    EXPECT_EQ(r[e2][0], e1);
    EXPECT_EQ(r[e2].size(), 1);

    // Test cyclic cae

    filename = "wing-double-segments.xml";
    setVariables(filename);


    wing = tree.getRoot()->getChildByUid("Wing");
    r = tree.getWingGraph(wing);

    EXPECT_EQ(r.size(), 3);

    e1 = tree.getRoot()->getChildByUid("Wing_section1_element1");
    e2 = tree.getRoot()->getChildByUid("Wing_section2_element1");
    CPACSTreeItem* e3 = tree.getRoot()->getChildByUid("Wing_section3_element1");
    EXPECT_EQ(r[e1][0], e2);
    EXPECT_EQ(r[e1][1], e3);
    EXPECT_EQ(r[e1].size(), 2);
    EXPECT_EQ(r[e2][0], e1);
    EXPECT_EQ(r[e2][1], e3);
    EXPECT_EQ(r[e1].size(), 2);
    EXPECT_EQ(r[e3][0], e1);
    EXPECT_EQ(r[e3][1], e2);
    EXPECT_EQ(r[e1].size(), 2);



    // Test use case

    filename = "BWB_DoE_102_modWP4.4_CS_v3.xml";
    setVariables(filename);

    wing = tree.getRoot()->getChildByUid("BWB450_wingID");
    r = tree.getWingGraph(wing);

    EXPECT_EQ(r.size(), 13);

    for(CPACSTreeItem* e : tree.getRoot()->findAllChildrenOfTypeRecursively("element")){

        EXPECT_TRUE( 0 < r[e].size() && r[e].size()  < 3 );

    }



}



TEST_F(AircraftTreeTest, formatWingGraph)
{
    std::string filename = "wing-simple-1.xml";
    setVariables(filename);

    // Test basic case

    CPACSTreeItem* wing = tree.getRoot()->getChildByUid("Wing");
    std::map<cpcr::CPACSTreeItem *, std::vector<cpcr::CPACSTreeItem *> >  graph = tree.getWingGraph(wing);

    std::vector<cpcr::CPACSTreeItem *> formatedGraph = tree.formatGraph(graph);

    EXPECT_EQ(formatedGraph.size(), 2);

    CPACSTreeItem* e1 = tree.getRoot()->getChildByUid("Wing_section1_element1");
    CPACSTreeItem* e2 = tree.getRoot()->getChildByUid("Wing_section2_element1");
    EXPECT_EQ(formatedGraph[0], e1);
    EXPECT_EQ(formatedGraph[1], e2);




    // Test cyclic case

    filename = "wing-double-segments.xml";
    setVariables(filename);


    wing = tree.getRoot()->getChildByUid("Wing");
    graph = tree.getWingGraph(wing);

    EXPECT_THROW( tree.formatGraph(graph), CreatorException );



    // Test use case

    filename = "BWB_DoE_102_modWP4.4_CS_v3.xml";
    setVariables(filename);

    wing = tree.getRoot()->getChildByUid("BWB450_wingID");
    graph = tree.getWingGraph(wing);
    formatedGraph = tree.formatGraph(graph);

    EXPECT_EQ( formatedGraph.size() , 13);
    EXPECT_EQ( formatedGraph[0]->getUid(), "BWB450_wingSection1IDElement1");
    EXPECT_EQ( formatedGraph[6]->getUid(), "BWB450_wingSection7IDElement1");
    EXPECT_EQ( formatedGraph[12]->getUid(), "BWB450_wingSection13IDElement1");

}


TEST_F(AircraftTreeTest, airfoilWingNormalization ){

    std::string filename = "wing-one-kick-rotations-scales-dihedral-multiple-airfoils.xml";
    setVariables(filename);
    std::string wingUID = "Wing";

    std::vector<cpcr::UID> UIDs = tree.getAllElementUIDsUsedInAWing(wingUID);
    std::map<cpcr::UID, Eigen::Vector4d> lEsB = tree.getChordPointsOfElements(wingUID, 0);
    std::map<cpcr::UID, Eigen::Vector4d> tEsB = tree.getChordPointsOfElements(wingUID, 0);
    std::vector<std::string> airfoilUIDsB = tree.getAllAirfoilsUIDInThisWing(wingUID);

    tree.airfoilsStandardizationForWing(wingUID);
    tree.writeToFile();

    std::map<cpcr::UID, Eigen::Vector4d> lEsA = tree.getChordPointsOfElements(wingUID, 0);
    std::map<cpcr::UID, Eigen::Vector4d> tEsA = tree.getChordPointsOfElements(wingUID, 0);
    std::vector<std::string> airfoilUIDsA = tree.getAllAirfoilsUIDInThisWing(wingUID);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.000001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.000001) ) ;
    }

    EXPECT_FALSE(airfoilUIDsA == airfoilUIDsB);




    filename = "wing-one-kick-multiple-airfoils.xml";
    setVariables(filename);
    wingUID = "Wing";


    UIDs = tree.getAllElementUIDsUsedInAWing(wingUID);
    lEsB = tree.getChordPointsOfElements(wingUID, 0);
    tEsB = tree.getChordPointsOfElements(wingUID, 0);
    airfoilUIDsB = tree.getAllAirfoilsUIDInThisWing(wingUID);

    tree.airfoilsStandardizationForWing(wingUID);
    tree.writeToFile();

    lEsA = tree.getChordPointsOfElements(wingUID, 0);
    tEsA = tree.getChordPointsOfElements(wingUID, 0);
    tree.getAllAirfoilsUIDInThisWing(wingUID);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.000001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.000001) ) ;
    }

    EXPECT_FALSE(airfoilUIDsA == airfoilUIDsB);



    filename = "BWB_DoE_102_modWP4.4_CS_v3.xml";
    setVariables(filename);
    wingUID = "BWB450_wingID";

    UIDs = tree.getAllElementUIDsUsedInAWing(wingUID);
    lEsB = tree.getChordPointsOfElements(wingUID, 0);
    tEsB = tree.getChordPointsOfElements(wingUID, 0);
    airfoilUIDsB = tree.getAllAirfoilsUIDInThisWing(wingUID);

    tree.airfoilsStandardizationForWing(wingUID);
    tree.writeToFile();

    lEsA = tree.getChordPointsOfElements(wingUID, 0);
    tEsA = tree.getChordPointsOfElements(wingUID, 0);
    tree.getAllAirfoilsUIDInThisWing(wingUID);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.000001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.000001) ) ;
    }

    EXPECT_FALSE(airfoilUIDsA == airfoilUIDsB);


}



TEST_F(AircraftTreeTest, setWingTransformation ) {

    std::string  filename = "TestCases/d150.xml";
    setVariables(filename);
    std::string wingUID = "D150_VAMP_wing_W1";

    std::vector<cpcr::UID> UIDs = tree.getAllElementUIDsUsedInAWing(wingUID);
    std::map<cpcr::UID, Eigen::Vector4d> lEsB = tree.getChordPointsOfElements(wingUID, 0);
    std::map<cpcr::UID, Eigen::Vector4d> tEsB = tree.getChordPointsOfElements(wingUID, 1);


    CPACSTransformation trans;
    trans.setRotation(Point(0,45,0));
    trans.setTranslation(Point(0,5,0));
    trans.setScaling(Point(2,2,2));
    tree.writeToFile();
    tree.setWingTransformation(wingUID, trans);
    tree.writeToFile();

    std::map<cpcr::UID, Eigen::Vector4d>  lEsA = tree.getChordPointsOfElements(wingUID, 0);
    std::map<cpcr::UID, Eigen::Vector4d>  tEsA = tree.getChordPointsOfElements(wingUID, 1);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.0001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.0001) ) ;
    }


    CPACSTransformation dT = tree.determineWingTransformation(wingUID);
    EXPECT_TRUE(dT.getRotation() == Point(0,0,0));
    EXPECT_TRUE(dT.getScaling() == Point(1,1,1));
    EXPECT_TRUE(dT.getTranslation() == Point(12.745585588751897,0,-1.1362781709599128));


    tree.setWingTransformation(wingUID, dT);
    tree.writeToFile();

    lEsA = tree.getChordPointsOfElements(wingUID, 0);
    tEsA = tree.getChordPointsOfElements(wingUID, 1);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.0001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.0001) ) ;
    }


    // Vertical wing
    wingUID = "D150_VAMP_vtp_SL1";

    UIDs = tree.getAllElementUIDsUsedInAWing(wingUID);
    lEsB = tree.getChordPointsOfElements(wingUID, 0);
    tEsB = tree.getChordPointsOfElements(wingUID, 1);


    dT = tree.determineWingTransformation(wingUID);
    EXPECT_TRUE(dT.getRotation() == Point(90,0,0));
    EXPECT_TRUE(dT.getScaling() == Point(1,1,1));
    EXPECT_TRUE(dT.getTranslation() == Point(29.837965090800001, -0.0020029219731199999, 1.89101464137));


    tree.setWingTransformation(wingUID, dT);
    tree.writeToFile();

    lEsA = tree.getChordPointsOfElements(wingUID, 0);
    tEsA = tree.getChordPointsOfElements(wingUID, 1);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.0001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.0001) ) ;
    }



    // Blended wing

    filename = "BWB_DoE_102_modWP4.4_CS_v3.xml";
    setVariables(filename);

    wingUID = "BWB450_wingID";


    UIDs = tree.getAllElementUIDsUsedInAWing(wingUID);
    lEsB = tree.getChordPointsOfElements(wingUID, 0);
    tEsB = tree.getChordPointsOfElements(wingUID, 1);


    trans;
    trans.setRotation(Point(0,45,0));
    trans.setTranslation(Point(0,5,0));
    trans.setScaling(Point(2,2,2));
    tree.writeToFile();
    tree.setWingTransformation(wingUID, trans);
    tree.writeToFile();

    lEsA = tree.getChordPointsOfElements(wingUID, 0);
    tEsA = tree.getChordPointsOfElements(wingUID, 1);
    tree.getAllAirfoilsUIDInThisWing(wingUID);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.0001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.0001) ) ;
    }


}




TEST_F(AircraftTreeTest, oneElementOneSection ) {



    std::string  filename = "wing-one-kick-double-elements-in-section.xml";
    setVariables(filename);

    std::string wingUID = "Wing";

    std::vector<cpcr::UID> UIDs = tree.getAllElementUIDsUsedInAWing(wingUID);
    std::map<cpcr::UID, Eigen::Vector4d> lEsB = tree.getChordPointsOfElements(wingUID, 0);
    std::map<cpcr::UID, Eigen::Vector4d> tEsB = tree.getChordPointsOfElements(wingUID, 1);

    EXPECT_FALSE( tree.checkIfOneSectionOneElementForWing(wingUID));
    tree.oneSectionOneElementStandardizationForWing(wingUID);
    EXPECT_TRUE( tree.checkIfOneSectionOneElementForWing(wingUID));

    tree.writeToFile();

    std::map<cpcr::UID, Eigen::Vector4d>  lEsA = tree.getChordPointsOfElements(wingUID, 0);
    std::map<cpcr::UID, Eigen::Vector4d>  tEsA = tree.getChordPointsOfElements(wingUID, 1);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.0001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.0001) ) ;
    }




    filename = "BWB_DoE_102_modWP4.4_CS_v3.xml";
    setVariables(filename);

    wingUID = "BWB450_wingID";

    EXPECT_TRUE(tree.checkIfOneSectionOneElementForWing(wingUID));



}



TEST_F(AircraftTreeTest, positioningsStandardization  ) {


    // temp varaibles
   CPACSTransformation newWingT;
    std::string filename;
    std::string wingUID;


    filename = "wing-one-kick-rotations-scales-dihedral-2.xml";
    wingUID = "Wing";
    setVariables(filename);


    backupChordPointsOfWing(wingUID);

    EXPECT_FALSE(tree.checkIfPositioningsAreStandardizedForWing(wingUID));
    tree.positioningsStandardizationForWing(wingUID);
    tree.writeToFile();

    EXPECT_TRUE(tree.checkIfPositioningsAreStandardizedForWing(wingUID));
    checkCurrentChordPointsWithBackup(wingUID);




    filename = "BWB_DoE_102_modWP4.4_CS_v3.xml";
    wingUID = "BWB450_wingID";
    setVariables(filename);

    EXPECT_TRUE(tree.checkIfPositioningsAreStandardizedForWing(wingUID));

}



TEST_F(AircraftTreeTest, completeNormalization  ) {


    // temp varaibles

    CPACSTransformation newWingT;
    std::string filename;
    std::string wingUID;


    // TEST CASE: BlendedWingBody

    filename = "TestCases/blendedWingBody.xml";
    wingUID = "BWB450_wingID";
    setVariables(filename);


    backupChordPointsOfWing(wingUID);
    EXPECT_FALSE(tree.isWingStandardized(wingUID));
    tree.completeStandardizationForWing(wingUID);
    EXPECT_TRUE(tree.isWingStandardized(wingUID));
    checkCurrentChordPointsWithBackup(wingUID);


    // TEST CASE : BoxWing

    filename = "TestCases/boxWing.xml";
    wingUID = "D150_VAMP_W1";
    setVariables(filename);

    backupChordPointsOfWing(wingUID);
    EXPECT_FALSE(tree.isWingStandardized(wingUID));
    tree.completeStandardizationForWing(wingUID);
    EXPECT_TRUE(tree.isWingStandardized(wingUID));
    checkCurrentChordPointsWithBackup(wingUID);


    // TEST CASE: crm (strange format)

    filename = "TestCases/crm.xml";
    wingUID = "NASA_CRM_wing1";
    setVariables(filename);

    backupChordPointsOfWing(wingUID);
    EXPECT_FALSE(tree.isWingStandardized(wingUID));
    tree.completeStandardizationForWing(wingUID);
    EXPECT_TRUE(tree.isWingStandardized(wingUID));
    checkCurrentChordPointsWithBackup(wingUID);




    // TEST CASE: d150

    filename = "TestCases/d150.xml";
    wingUID = "D150_VAMP_wing_W1";
    setVariables(filename);

    backupChordPointsOfWing(wingUID);
    EXPECT_FALSE(tree.isWingStandardized(wingUID));
    tree.completeStandardizationForWing(wingUID);
    EXPECT_TRUE(tree.isWingStandardized(wingUID));
    checkCurrentChordPointsWithBackup(wingUID);





    // TEST CASE: tp

    filename = "TestCases/tp.xml";
    wingUID = "wing";
    setVariables(filename);

    backupChordPointsOfWing(wingUID);
    EXPECT_FALSE(tree.isWingStandardized(wingUID));
    tree.completeStandardizationForWing(wingUID);
    EXPECT_TRUE(tree.isWingStandardized(wingUID));
    checkCurrentChordPointsWithBackup(wingUID);

//
//   // TODO manage case with trailing edge define with two points
//
//    filename = "TestCases/tp.xml";
//    wingUID = "vtp";
//    setVariables(filename);
//
//    backupChordPointsOfWing(wingUID);
//    EXPECT_FALSE(tree.isWingStandardized(wingUID));
//    tree.completeStandardizationForWing(wingUID);
//    EXPECT_TRUE(tree.isWingStandardized(wingUID));
//    checkCurrentChordPointsWithBackup(wingUID);



}




TEST_F(AircraftTreeTest, area){

    setVariables( "wing-simple.xml");

    double myArea;
    CPACSTreeItem* segment = tree.getRoot()->getChildByUid("Wing_segment1");

    // If there is no wing transformation and only one segment the area should be the same as in tigl

    tiglWingGetReferenceArea(*tiglHandle,1, TIGL_X_Y_PLANE,&tempArea);
    myArea = tree.getSegmentArea(segment, PLANE::XY_PLANE);
    EXPECT_EQ(tempArea, 2);
    EXPECT_EQ(tempArea, myArea);


    tiglWingGetReferenceArea(*tiglHandle,1, TIGL_X_Z_PLANE,&tempArea);
    myArea = tree.getSegmentArea(segment, PLANE::XZ_PLANE);
    EXPECT_EQ(tempArea, 0);
    EXPECT_EQ(tempArea, myArea);


    tiglWingGetReferenceArea(*tiglHandle,1, TIGL_Y_Z_PLANE,&tempArea);
    myArea = tree.getSegmentArea(segment, PLANE::YZ_PLANE);
    EXPECT_EQ(tempArea, 0);
    EXPECT_EQ(tempArea, myArea);


    tiglWingGetReferenceArea(*tiglHandle,1, TIGL_NO_SYMMETRY,&tempArea);
    myArea = tree.getSegmentArea(segment, PLANE::NO_PLANE);
    EXPECT_EQ(tempArea, 2);
    EXPECT_EQ(tempArea, myArea);

    // TEST CASE bwb

    setVariables("TestCases/blendedWingBody.xml");
    std::string wingUID = "BWB450_wingID";

    tiglWingGetReferenceArea(*tiglHandle,1, TIGL_X_Y_PLANE,&tempArea);
    myArea = tree.getWingPlanformArea(wingUID, PLANE::XY_PLANE);
    EXPECT_EQ(tempArea, myArea);

    tiglWingGetReferenceArea(*tiglHandle,1, TIGL_X_Z_PLANE,&tempArea);
    myArea = tree.getWingPlanformArea(wingUID, PLANE::XZ_PLANE);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(tempArea, myArea));

    tiglWingGetReferenceArea(*tiglHandle,1, TIGL_Y_Z_PLANE,&tempArea);
    myArea = tree.getWingPlanformArea(wingUID, PLANE::YZ_PLANE);
    EXPECT_EQ(tempArea, myArea);


    tiglWingGetReferenceArea(*tiglHandle,1, TIGL_NO_SYMMETRY,&tempArea);
    myArea = tree.getWingPlanformArea(wingUID, PLANE::NO_PLANE);
    EXPECT_EQ(tempArea, myArea);


    // In the case the wing is rotated by 90 degree

    setVariables("d150-vt0.xml");
    wingUID = "D150_VAMP_vtp_SL1";


    tiglWingGetReferenceArea(*tiglHandle,3, TIGL_X_Y_PLANE,&tempArea);
    myArea = tree.getWingPlanformArea(wingUID, PLANE::XZ_PLANE);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(tempArea, myArea));

    tiglWingGetReferenceArea(*tiglHandle,3, TIGL_X_Z_PLANE,&tempArea);
    myArea = tree.getWingPlanformArea(wingUID, PLANE::XY_PLANE);
    EXPECT_EQ(tempArea, myArea);


    tiglWingGetReferenceArea(*tiglHandle,3, TIGL_Y_Z_PLANE,&tempArea);
    myArea = tree.getWingPlanformArea(wingUID, PLANE::YZ_PLANE);
    EXPECT_EQ(tempArea, myArea);


    tiglWingGetReferenceArea(*tiglHandle,3, TIGL_NO_SYMMETRY,&tempArea);
    myArea = tree.getWingPlanformArea(wingUID, PLANE::NO_PLANE);
    EXPECT_EQ(tempArea, myArea);


}




TEST_F(AircraftTreeTest, symmetry){

    setVariables("TestCases/d150.xml");

    std::string symmetry = tree.getWingSymmetry("D150_VAMP_wing_W1");
    EXPECT_EQ(symmetry, "x-z-plane");

    symmetry = tree.getWingSymmetry("D150_VAMP_vtp_SL1");
    EXPECT_EQ(symmetry, "no-symmetry");

    tree.setWingSymmetry("D150_VAMP_vtp_SL1", "x-y-plane");
    symmetry = tree.getWingSymmetry("D150_VAMP_vtp_SL1");
    EXPECT_EQ(symmetry, "x-y-plane");
    tree.writeToFile();

    tree.setWingSymmetry("D150_VAMP_wing_W1", "y-z-plane");
    symmetry = tree.getWingSymmetry("D150_VAMP_wing_W1");
    EXPECT_EQ(symmetry, "y-z-plane");
    tree.writeToFile();

    tree.setWingSymmetry("D150_VAMP_wing_W1", "no-symmetry");
    symmetry = tree.getWingSymmetry("D150_VAMP_wing_W1");
    EXPECT_EQ(symmetry, "no-symmetry");
    tree.writeToFile();


}