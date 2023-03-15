#include "wordchallenge.h"

WordChallenge::WordChallenge(QString word, QString definition)
{
    SetChallenge( word, definition);
}

void WordChallenge::SetChallenge(QString word, QString definition){
    this->word = word;
    this->definition = definition;
}
