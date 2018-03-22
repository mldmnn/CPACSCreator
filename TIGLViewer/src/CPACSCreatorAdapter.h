//
// Created by cfse on 3/20/18.
//

#ifndef TIGL_CPACSCREATORADAPTER_H
#define TIGL_CPACSCREATORADAPTER_H

#include <QObject>
#include "CPACSCreator.h"
#include "CPACSOverTreeItem.h"
#include "TIGLViewerDocument.h"
#include <QMutex>


class CPACSCreatorAdapter : public QObject{

    Q_OBJECT

signals:
    void newTransformationValues( double sx, double sy, double  sz,
                                  double rx, double ry, double  rz,
                                  double tx, double ty, double  tz);

public slots:

    void prepareTransformationValues(CPACSOverTreeItem * item);


public:

    CSharedPtr<CPACSOverTreeItem> getRoot()const;
    void resetCpacsConfig(const TIGLViewerDocument& config);


private:

    CPACSCreator creator;
    mutable QMutex mutex;   // to enshure that the tree root is not accessed when update is done

};


#endif //TIGL_CPACSCREATORADAPTER_H
