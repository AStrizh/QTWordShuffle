#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QObject>
#include <QList>
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

private:
    GameState();
    ~GameState();
    GameState(const GameState &) = delete;
    GameState &operator=(const GameState &) = delete;

    QList<DraggableLabel *> imageLabels;
    QList<TargetLabel *> imageTargets;
};

#endif // GAMESTATE_H
