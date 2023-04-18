#include "targetlabel.h"
#include <QResizeEvent>

TargetLabel::TargetLabel(QWidget *parent) : QLabel(parent)
{
}

void TargetLabel::generateCenter()
{
    int centerX = pos().x() + size().width()/2;
    int centerY = pos().y() + size().height()/2;
    center = QPoint(centerX, centerY);
}
