#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QObject>
#include <QList>
#include <QLabel>
#include <QPushButton>
#include "DraggableLabel.h"
#include "TargetLabel.h"

class GameState : public QObject
{
    Q_OBJECT

public:
    static GameState &getInstance();
    void clearLists();


    QList<DraggableLabel *> &getImageLabels() { return imageLabels; }
    void setImageLabels(const QList<DraggableLabel *> &labels) { imageLabels = labels; }

    QList<TargetLabel *> &getImageTargets() { return imageTargets; }
    void setImageTargets(const QList<TargetLabel *> &targets) { imageTargets = targets; }

    void setRedButton(QPushButton *button){redArrow=button;}
    void setGreenButton(QPushButton *button){greenArrow=button;}
    void setResetButton(QPushButton *button){resetArrow=button;}

    void setSkipLabel(QLabel *label){skipLabel=label;}
    void setNextLabel(QLabel *label){nextLabel=label;}
    void setResetLabel(QLabel *label){resetLabel=label;}



    void redButtonVisible(bool visibility){redArrow->setVisible(visibility);}
    void greenButtonVisible(bool visibility){greenArrow->setVisible(visibility);}
    void resetButtonVisible(bool visibility){resetArrow->setVisible(visibility);}

    void skipLabelVisible(bool visibility){skipLabel->setVisible(visibility);}
    void nextLabelVisible(bool visibility){nextLabel->setVisible(visibility);}
    void resetLabelVisible(bool visibility){resetLabel->setVisible(visibility);}


private:
    GameState();
    ~GameState();
    GameState(const GameState &) = delete;
    GameState &operator=(const GameState &) = delete;

    QList<DraggableLabel *> imageLabels;
    QList<TargetLabel *> imageTargets;

    QPushButton *redArrow;
    QPushButton *greenArrow;
    QPushButton *resetArrow;

    QLabel *skipLabel;
    QLabel *nextLabel;
    QLabel *resetLabel;

};

#endif // GAMESTATE_H
