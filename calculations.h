
#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <QApplication>
#include <QList>
#include <QLabel>

#include "draggablelabel.h"
#include "targetlabel.h"





class Calculations
{
public:
    Calculations();
    static void updateLabelPositions(QList<DraggableLabel *> &imageLabels,
                              QList<TargetLabel *> &imageTargets,
                              QWidget *dragLabelParent);


private:
    //QList<TargetLabel *> &imageTargets;
};

#endif // CALCULATIONS_H
