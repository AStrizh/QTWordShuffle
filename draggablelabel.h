
#ifndef DRAGGABLELABEL_H
#define DRAGGABLELABEL_H

#include <QLabel>
#include <QMouseEvent>


class DraggableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit DraggableLabel(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QPoint m_startPosition;
    bool m_dragging;
};

#endif // DRAGGABLELABEL_H
