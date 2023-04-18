
#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <QApplication>
#include <QList>
#include <QLabel>

#include "draggablelabel.h"
#include "targetlabel.h"
#include "gamestate.h"






class Calculations
{
public:
    Calculations();
    static void updateLabelPositions(QList<DraggableLabel *> &imageLabels,
                              QList<TargetLabel *> &imageTargets,
                              QWidget *dragLabelParent);

    static bool distanceClose(QPoint letterPos, QPoint targetPos);

    static void checkPositions(DraggableLabel* letter);
    static bool challengeSolved();


private:
    static const int MIN_DISTANCE = 35;
};

#endif // CALCULATIONS_H
