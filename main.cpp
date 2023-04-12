#include "mainwindow.h"
#include <qpushbutton.h>

#include <QApplication>
#include <QFont>
#include <QList>
#include <QLabel>
#include <QHBoxLayout>

#include "wordchallenge.h"
#include "challengegenerator.h"
#include "DraggableLabel.h"


//QString shuffle(QString word);
QList<DraggableLabel *> createImageLabels(const QString &word, QWidget *parent);
QList<QLabel *> createImageTargets(const int, QWidget *parent);


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //Initializes the database and the WordChallenge object
    ChallengeGenerator gen;
    WordChallenge challenge = gen.getChallenge();


    //Creates the label, button, alignment info, and attaches it to the window
    QLabel *label = new QLabel(challenge.getShuffled() + "\n" + challenge.getWord() + "\n" + challenge.getDefinition());
    QFont font;
    font.setWeight(QFont::Bold);
    font.setPixelSize(14);
    label->setAlignment(Qt::AlignJustify);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label->setFont(font);
    label->setWordWrap(true);

    //Gets the button object defined in the ui class and attches "clicked" functionality to it (calls getChallenge())
//    QPushButton *button = w.findChild<QPushButton*>("pushButton");
//    QObject::connect(button, &QPushButton::clicked, [&]() {
//        challenge = gen.getChallenge();
//        label->setText(shuffle(challenge.getWord()) + "\n" + challenge.getWord() + "\n" + challenge.getDefinition());
//    });

    QVBoxLayout  *layout = new QVBoxLayout ();
    layout->addWidget(label, 0, Qt::AlignCenter);
//    layout->addWidget(button, 0, Qt::AlignCenter);
    layout->setAlignment(Qt::AlignCenter);

    w.setCentralWidget(new QWidget(&w));
    w.centralWidget()->setLayout(layout);





    w.setFixedSize(QSize(800, 600));

    QWidget *dragLabelParent = new QWidget(&w);
    dragLabelParent->setGeometry(0, 0, w.width(), w.height());

    QList<DraggableLabel *> imageLabels = createImageLabels(challenge.getWord(), dragLabelParent);
    QList<QLabel *> imageTargets = createImageTargets(challenge.getWord().size(), dragLabelParent);

    //Gets the button object defined in the ui class and attches "clicked" functionality to it (calls getChallenge())
    QPushButton *button = w.findChild<QPushButton*>("pushButton");
    button->setParent(dragLabelParent);
    QObject::connect(button, &QPushButton::clicked, [&]() {
        challenge = gen.getChallenge();
        label->setText(challenge.getShuffled() + "\n" + challenge.getWord() + "\n" + challenge.getDefinition());
    });


    w.show();

    int buttonPosition = (w.width() - button->size().width())/2;
    button->move(buttonPosition, w.height() - 100);

    //Size of the space the letters will occupy
    int letterWidths = imageLabels[0]->size().width();
    int windowSize = w.size().width();

    int letterChunkSize = letterWidths * imageLabels.size();
    int offseLettertStart = (windowSize - letterChunkSize)/2;
    for (int i = 0; i < imageLabels.size(); ++i)
    {
        int x = offseLettertStart + i * (letterWidths);
        int y = 50;
        imageLabels[i]->move(x, y);
    }

    //Size of the space the targets will occupy
    int targetWidths = imageTargets[0]->size().width();
    int targetOffset = 25;
    int targetSpace = targetWidths + targetOffset;

    int targetChunkSize = targetSpace * imageTargets.size();
    int offseTargetStart = (windowSize - targetChunkSize)/2;
    for (int i = 0; i < imageTargets.size(); ++i)
    {
        int x = offseTargetStart + i * (targetSpace);
        int y = 150;
        imageTargets[i]->move(x, y);
    }


    gen.closedb();
    return a.exec();
}



QList<DraggableLabel *> createImageLabels(const QString &word, QWidget *parent)
{
    QList<DraggableLabel *> imageLabels;
    for (int i = 0; i < word.length(); ++i)
    {
            DraggableLabel *label = new DraggableLabel(parent);
            // Load the image for the current letter and set it as a pixmap for the label
            QPixmap pixmap(QString(":/Letters/%1.png").arg(word.at(i)));
            label->setPixmap(pixmap.scaled(55,55,Qt::KeepAspectRatio,Qt::SmoothTransformation));
            imageLabels.append(label);
    }
    return imageLabels;
}

QList<QLabel *> createImageTargets(const int size, QWidget *parent)
{
    QList<QLabel *> imageTargets;
    for (int i = 0; i < size; ++i)
    {
            QLabel *label = new QLabel(parent);
            // Load the image for the current letter and set it as a pixmap for the label
            QPixmap pixmap(":/Letters/target.png");
            label->setPixmap(pixmap.scaled(60,60,Qt::KeepAspectRatio,Qt::SmoothTransformation));
            imageTargets.append(label);
    }
    return imageTargets;
}
