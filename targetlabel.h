#ifndef TARGETLABEL_H
#define TARGETLABEL_H

#include <QLabel>
#include <QPoint>

class TargetLabel : public QLabel
{
    Q_OBJECT

public:
    explicit TargetLabel(QWidget *parent = nullptr);
    void generateCenter();
    QPoint getCenter(){ return center;}

private:
    QPoint center;
};

#endif // TARGETLABEL_H
