
#include "calculations.h"

Calculations::Calculations()
{

}

void Calculations::updateLabelPositions(QList<DraggableLabel *> &imageLabels,
                          QList<TargetLabel *> &imageTargets,
                          QWidget *dragLabelParent){

    imageLabels[0]->show();
    //Size of the space the letters will occupy
    int letterWidths = imageLabels[0]->size().width();
    int windowSize = dragLabelParent->width();

    int letterChunkSize = letterWidths * imageLabels.size();
    int offseLettertStart = (windowSize - letterChunkSize)/2;

    for (int i = 0; i < imageLabels.size(); ++i)
    {
        int x = offseLettertStart + i * (letterWidths);
        int y = 50;
        imageLabels[i]->move(x, y);
        imageLabels[i]->show();
    }

    imageTargets[0]->show();
    //Size of the space the targets will occupy
    int targetWidths = imageTargets[0]->size().width();
    int targetOffset = 25;
    int targetSpace = targetWidths + targetOffset;

    int targetChunkSize = targetSpace * imageTargets.size();
    int offseTargetStart = (windowSize - targetChunkSize)/2;
    for (int i = 0; i < imageTargets.size(); ++i)
    {
        int x = offseTargetStart + i * (targetSpace);
        int y = 150;
        imageTargets[i]->move(x, y);
        imageTargets[i]->show();

        imageTargets[i]->generateCenter();
    }
}
