
#ifndef DRAGGABLELABEL_H
#define DRAGGABLELABEL_H

#include <QLabel>
#include <QMouseEvent>

// Forward declaration
class TargetLabel;

class DraggableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit DraggableLabel(QWidget *parent = nullptr);
    QChar getLetter(){return letter;}
    void setLetter(QChar letter){this->letter = letter;}
    void attachTarget(TargetLabel* target){this->attached = target;}
    void clearTarget(){attached = NULL;}
    void setPosition(QPoint position){initialPosition = position;}
    void moveToStart();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QPoint m_startPosition;
    bool m_dragging;

    QChar letter;
    TargetLabel* attached = NULL;
    QPoint initialPosition;
};

#endif // DRAGGABLELABEL_H
