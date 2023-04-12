#include "challengegenerator.h"



//maintains a persistent connection to the database
ChallengeGenerator::ChallengeGenerator()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("word.db");
}

//Generates a word challenge
WordChallenge ChallengeGenerator::getChallenge(){

    if (db.open()) {

        QSqlQuery query;

        //sets some generic string values to return incase there is no connection to the database
        //idValue was used for debugging and will likely be removed
        QString wordResult="hello";
        QString shuffled="hello";
        QString definitionResult = "goodbye";
        QString definitionProcessed = "";
        QString idValue = "-57";


        //Found this method for selecting a random DB entry on stack oververflow
        //Would have prefered to generate a random ID Value and select it but for some reason some entries were not entered into DB
        //Instead of debugging I decided not to worry about a couple of lost words and do this instead.

        query.exec("SELECT * FROM words WHERE id IN (SELECT id FROM words ORDER BY RANDOM() LIMIT 1)");

        if(query.next()){
            idValue = query.value(0).toString();
            wordResult = query.value(1).toString();
            shuffled = shuffle(wordResult);
            definitionResult = query.value(3).toString();
        }

        //The definitions are separated by the bar character. Here I split them and just add a newline between them
        //May decide to split them up some other way once the UI is ready
        QStringList defSplit = definitionResult.split("|");
        for(const auto &def : defSplit)
            definitionProcessed.append(def.trimmed() + "\n");

        return WordChallenge(wordResult, shuffled, definitionProcessed.trimmed());


    } else {
        qDebug() << "Failed to open the database";
        return WordChallenge("Database", "oopsie", "Failure");
    }

}

//Shuffles the string
QString ChallengeGenerator::shuffle(QString word){
    QString shuffled = "";
    QList<QString> letters = word.split("");

    std::shuffle(letters.begin(), letters.end(), std::mt19937(std::random_device()()));
    for (auto & letter : letters)
        shuffled.append(letter);

    return shuffled;
}
