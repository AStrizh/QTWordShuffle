#include "draggablelabel.h"
#include "calculations.h"

#include <QPropertyAnimation>

DraggableLabel::DraggableLabel(QWidget *parent)
    : QLabel(parent), m_dragging(false)
{
}

void DraggableLabel::mousePressEvent(QMouseEvent *event)
{
    this -> raise();
    if (event->button() == Qt::LeftButton)
    {
        m_startPosition = event->pos();
        m_dragging = true;
    }
}

void DraggableLabel::mouseMoveEvent(QMouseEvent *event)
{
    if (m_dragging && (event->buttons() & Qt::LeftButton))
    {
        move(pos() + event->pos() - m_startPosition);
    }
}

void DraggableLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_dragging = false;
    }

    //If this letter was attached to a target then moved, clears out their relationship
    if(attached != NULL){
        attached->clearLetter();
        attached = NULL;
    }

    Calculations::checkPositions(this);
}

void DraggableLabel::moveToStart(){

    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(250);
    animation->setStartValue(QRect(this->pos().x(), this->pos().y(), this->width(), this->height()));
    animation->setEndValue(QRect(initialPosition.x(), initialPosition.y(), this->width(), this->height()));

    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

