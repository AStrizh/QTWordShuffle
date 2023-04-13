#include "targetlabel.h"
#include <QResizeEvent>

TargetLabel::TargetLabel(QWidget *parent) : QLabel(parent)
{
}

void TargetLabel::generateCenter()
{

    //center = this ->pos().x();
    qDebug() << this ->pos().x();

}
