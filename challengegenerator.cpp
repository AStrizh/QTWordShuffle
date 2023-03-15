#include "challengegenerator.h"



ChallengeGenerator::ChallengeGenerator()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("word.db");
}

WordChallenge ChallengeGenerator::getChallenge(){

    if (db.open()) {

        QSqlQuery query;

        QString wordResult="hello";
        QString definitionResult = "goodbye";
        QString definitionProcessed = "";
        QString idValue = "-57";

        query.exec("SELECT * FROM words WHERE id IN (SELECT id FROM words ORDER BY RANDOM() LIMIT 1)");

        if(query.next()){
            idValue = query.value(0).toString();
            wordResult = query.value(1).toString();
            definitionResult = query.value(3).toString();
        }

        QStringList defSplit = definitionResult.split("|");
        for(const auto &def : defSplit)
            definitionProcessed.append(def.trimmed() + "\n");

        return WordChallenge(wordResult,definitionProcessed.trimmed());


    } else {
        qDebug() << "Failed to open the database";
        return WordChallenge("Database","Failure");
    }

}
