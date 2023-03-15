#include "mainwindow.h"

#include <QApplication>
#include <QFont>
#include <QList>
#include <QLabel>
#include <QHBoxLayout>

#include "wordchallenge.h"
#include "challengegenerator.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    ChallengeGenerator gen;
    WordChallenge challenge = gen.getChallenge();



    QLabel *label = new QLabel(challenge.getWord() + "\n" + challenge.getDefinition());
    QFont font;
    font.setWeight(QFont::Bold);
    font.setPixelSize(12);
    label->setAlignment(Qt::AlignCenter);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label->setFont(font);

    QVBoxLayout  *layout = new QVBoxLayout ();
    layout->addWidget(label, 0, Qt::AlignCenter);
    layout->setAlignment(Qt::AlignCenter);

    w.setCentralWidget(new QWidget(&w));
    w.centralWidget()->setLayout(layout);

    w.show();

    gen.closedb();
    return a.exec();
}


