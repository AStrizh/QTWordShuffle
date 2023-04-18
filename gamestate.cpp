#include "gamestate.h"

GameState &GameState::getInstance()
{
    static GameState instance;
    return instance;
}

GameState::GameState()
{
}

GameState::~GameState()
{
}

void GameState::clearLists(){
    qDeleteAll(imageLabels);
    qDeleteAll(imageTargets);
    imageLabels.clear();
    imageTargets.clear();
}
