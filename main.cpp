#include "mainwindow.h"
#include <qpushbutton.h>

#include <QApplication>
#include <QFont>
#include <QList>
#include <QLabel>
#include <QHBoxLayout>

#include "wordchallenge.h"
#include "challengegenerator.h"


QString shuffle(QString word);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //Initializes the database and the WordChallenge object
    ChallengeGenerator gen;
    WordChallenge challenge = gen.getChallenge();


    //Creates the label, button, alignment info, and attaches it to the window
    QLabel *label = new QLabel("Push button to get the challenge!");
    QFont font;
    font.setWeight(QFont::Bold);
    font.setPixelSize(12);
    label->setAlignment(Qt::AlignCenter);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label->setFont(font);

    //Gets the button object defined in the ui class and attches "clicked" functionality to it (calls getChallenge())
    QPushButton *button = w.findChild<QPushButton*>("pushButton");
    QObject::connect(button, &QPushButton::clicked, [&]() {
        challenge = gen.getChallenge();
        label->setText(shuffle(challenge.getWord()) + "\n" + challenge.getWord() + "\n" + challenge.getDefinition());
    });

    QVBoxLayout  *layout = new QVBoxLayout ();
    layout->addWidget(label, 0, Qt::AlignCenter);
    layout->addWidget(button, 0, Qt::AlignCenter);
    layout->setAlignment(Qt::AlignCenter);

    w.setCentralWidget(new QWidget(&w));
    w.centralWidget()->setLayout(layout);

    w.show();

    gen.closedb();
    return a.exec();
}

//Shuffles the string. Will likely put this in a utilities class once I have more of the project done.
QString shuffle(QString word){
    QString shuffled = "";
    QList<QString> letters = word.split("");

    std::shuffle(letters.begin(), letters.end(), std::mt19937(std::random_device()()));
        for (auto & letter : letters)
            shuffled.append(letter);

    return shuffled;
}
