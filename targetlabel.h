#ifndef TARGETLABEL_H
#define TARGETLABEL_H

#include <QLabel>
#include <QPoint>

#include "draggablelabel.h"

class TargetLabel : public QLabel
{
    Q_OBJECT

public:
    explicit TargetLabel(QWidget *parent = nullptr);
    void generateCenter();
    QPoint getCenter(){ return center;}
    bool correctLetter();
    void attachLetter(DraggableLabel* letter){this->attached = letter;}
    DraggableLabel* getAttachedLetter(){return attached;}
    void clearLetter(){attached = NULL;}
    void setExpectedLetter(QChar letter){expectedLetter = letter;}
    QChar getExpectedLetter(){return expectedLetter;}

private:
    QPoint center;
    DraggableLabel* attached = NULL;
    QChar expectedLetter;

};

#endif // TARGETLABEL_H
