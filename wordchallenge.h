#ifndef WORDCHALLENGE_H
#define WORDCHALLENGE_H
#include <QString>


class WordChallenge
{
private:
    QString word;
    QString definition;

public:
    WordChallenge(QString word, QString definition);
    void SetChallenge(QString word, QString definition);

    QString getWord(){ return word; }
    QString getDefinition(){ return definition; }
};

#endif // WORDCHALLENGE_H
