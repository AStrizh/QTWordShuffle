#ifndef CHALLENGEGENERATOR_H
#define CHALLENGEGENERATOR_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

#include "wordchallenge.h"
#include "DraggableLabel.h"
#include "targetlabel.h"

class ChallengeGenerator
{
private:
    QSqlDatabase db;
    QString shuffle(QString);

public:
    ChallengeGenerator();
    WordChallenge getChallenge();
    void closedb(){ db.close();}
};

#endif // CHALLENGEGENERATOR_H
