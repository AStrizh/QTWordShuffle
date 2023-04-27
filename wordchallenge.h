#ifndef WORDCHALLENGE_H
#define WORDCHALLENGE_H
#include <QString>

class WordChallenge
{
private:
    QString word;
    QString shuffled;
    QString definition;

public:
    WordChallenge(QString word, QString shuffled, QString definition);
    void SetChallenge(QString word, QString shuffled, QString definition);

    QString getWord(){ return word; }
    QString getShuffled(){ return shuffled; }
    QString getDefinition(){ return definition; }
};

#endif // WORDCHALLENGE_H
