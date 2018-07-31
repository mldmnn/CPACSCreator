//
// Created by makem on 07/04/18.
//

#ifndef CPACSCREATORLIB_CPACSFILE_H
#define CPACSCREATORLIB_CPACSFILE_H


#include "tixi3/tixicpp.h"
#include "tixi.h"

#include <string>
#include <vector>

#include "Point.h"
#include "CPACSTransformation.h"
#include "CPACSPositioning.h"
#include "Eigen/Dense"

#include "UniqueXPath.h"
#include "CPACSPointsProfile.h"
#include "CPACSSegment.h"


namespace cpcr {

/**
 *  Read and write cpacs file.
 *
 *  Allow access to CPACS elements, no logic nor intelligence is implemented in this class.
 *  It can be view as a "dummy" modifier.
 *
 *
 *
 */


class CPACSFile {

public:

    CPACSFile();

    // open the tixiHandle // TODO Check the validity of the document
    void open(std::string fileName);

    // close the tixi document ( that does not save the document before)
    void close();

    void save();
    void save(std::string savingFileName);

    inline TixiDocumentHandle  getTixiHandle(){ return tixiHandle ;};

    Point getPoint(UniqueXPath target);
    void setPoint(UniqueXPath target, const Point& point );
    void createPoint(UniqueXPath target, const Point& point );

    CPACSTransformation getTransformation(UniqueXPath target);
    void setTransformation(UniqueXPath target, const CPACSTransformation& transform);
    void createTransformation(UniqueXPath target, const CPACSTransformation& transform);

    CPACSPositioning getPositioning(UniqueXPath target);
    void setPositioning(UniqueXPath target, const CPACSPositioning& positioning);
    /***
     * @remark The aircraft tree is obvusly not updated by this function
     * @param target
     * @param positioning
     */
    UniqueXPath createPositioning(UniqueXPath target, const CPACSPositioning& positioning);
    /***
     * Remove all positioning of poistionings
     */
    void clearPositionings(UniqueXPath target);


    CPACSSegment getSegment(UniqueXPath target);
    void setSegment(UniqueXPath target, const CPACSSegment& segment);
    void createSegment(UniqueXPath target, std::string uid,  const CPACSSegment& segment);

    /***
    * Create a standard section with one element
     * @return the XPath of the new section
    */
    UniqueXPath createEmptySection(UniqueXPath target, std::string newUid);
    void createEmptyElement(UniqueXPath target, std::string newUid);
    void createEmptyWing(UniqueXPath target, std::string wingUID);



    bool wingAirfoilExist(std::string uid);
    bool isWingAirfoilPointList(std::string uid);
    CPACSPointsProfile getAirfoil(std::string uid);
    // the profile uid can change if there is already some similar uid in file
    CPACSPointsProfile addWingAirfoil(CPACSPointsProfile& profile);
    CPACSPointsProfile addWingAirfoil(std::string filename);
    CPACSPointsProfile addWingAirfoilOverwriteIfExist(CPACSPointsProfile& profile);
    // return all airfoil uids described in the current file
    std::vector<std::string> getAirfoilsUid();


    void setSymmetry(UniqueXPath target, std::string symmetry);

    std::string getSymmetry(UniqueXPath target);

    // get basic info about the element pointed by the xpath

    std::string getUid(UniqueXPath target, std::string defaultRetrunedValue = "") ;
    void setUid(UniqueXPath target, std::string newUid);
    int getNumberOfChildren(UniqueXPath target );

    // check if the UID is already used in the file, if it is the case return a new unique UID
    std::string makeUIDUnique(std::string uid);


    inline bool isValid(){return tixiHandle > 0; };

    template<typename T>
    T retrieve(UniqueXPath target, T defaultValue, bool warningEnable = true);

    // set the value in TIXI structure ( is not write in the file until document is saved)
    template<typename T>
    void setValue(UniqueXPath target, T value);

protected:

    bool isValidWithWarning();


    bool isAValidTiglSymmetry(std::string symmetry);



private:




    TixiDocumentHandle  tixiHandle;
    std::string fileName;

};


}; // end of namespace cpcr





#endif //CPACSCREATORLIB_CPACSFILE_H