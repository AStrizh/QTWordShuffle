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
        imageLabels[i]->setPosition(QPoint(x,y));
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

bool Calculations::distanceClose(QPoint letterPos, QPoint targetPos){
    // Euclidean distance between two points
    int distance = qSqrt(qPow(letterPos.x() - targetPos.x(), 2)
                         + qPow(letterPos.y() - targetPos.y(), 2));
    return (distance <= MIN_DISTANCE);
}

//TODO: Perhaps give Draggeble label a refrence to the target. It would know when it gets moved
void Calculations::checkPositions(DraggableLabel* letter){

    for(TargetLabel* target : GameState::getInstance().getImageTargets()){

        if (Calculations::distanceClose(letter->pos(), target->pos())){
            int newX =  target->getCenter().x() - letter->size().width()/2;
            int newY =  target->getCenter().y() - letter->size().height()/2;

            if(target->getAttachedLetter() != NULL){
                target->getAttachedLetter()->moveToStart();
                target->getAttachedLetter()->clearTarget();
            }

            letter->move(newX,newY);
            target->attachLetter(letter);
            letter->attachTarget(target);

            if(challengeSolved()){
                GameState::getInstance().greenButtonVisible(true);
                GameState::getInstance().nextLabelVisible(true);
                GameState::getInstance().redButtonVisible(false);
                GameState::getInstance().skipLabelVisible(false);
                GameState::getInstance().resetButtonVisible(false);
                GameState::getInstance().resetLabelVisible(false);
            }
            break;
        }
    }      
}

bool Calculations::challengeSolved(){
    for(TargetLabel* target : GameState::getInstance().getImageTargets()){
        if(!target->correctLetter())
            return false;
    }
    return true;
}
