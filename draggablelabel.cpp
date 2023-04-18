#include "draggablelabel.h"
#include "calculations.h"



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

    Calculations::checkPositions(this);

}

