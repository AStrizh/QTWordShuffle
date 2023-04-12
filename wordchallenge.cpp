#include "wordchallenge.h"

WordChallenge::WordChallenge(QString word, QString shuffled, QString definition)
{
    SetChallenge( word, shuffled, definition);
}

void WordChallenge::SetChallenge(QString word, QString shuffled, QString definition){
    this->word = word;
    this->shuffled = shuffled;
    this->definition = definition;
}
