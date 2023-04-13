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
#include "calculations.h"
#include "targetlabel.h"




//QString shuffle(QString word);
QList<DraggableLabel *> createImageLabels(const QString &word, QWidget *parent);
QList<TargetLabel *> createImageTargets(const int, QWidget *parent);

void updateLabelPositions(QList<DraggableLabel *> &imageLabels,
                         QList<QLabel *> &imageTargets,
                         QWidget *dragLabelParent);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;


    window.setFixedSize(QSize(800, 600));


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

    window.setCentralWidget(new QWidget(&window));
    window.centralWidget()->setLayout(layout);



    QWidget *dragLabelParent = new QWidget(&window);
    dragLabelParent->setGeometry(0, 0, window.width(), window.height());
    QList<DraggableLabel *> imageLabels = createImageLabels(challenge.getShuffled(), dragLabelParent);
    QList<TargetLabel *> imageTargets = createImageTargets(challenge.getWord().size(), dragLabelParent);




    //Gets the button object defined in the ui class and attches "clicked" functionality to it (calls getChallenge())
    QPushButton *button = window.findChild<QPushButton*>("pushButton");
    button->setParent(dragLabelParent);
    QObject::connect(button, &QPushButton::clicked, [&]() {
        challenge = gen.getChallenge();
        label->setText(challenge.getShuffled() + "\n" + challenge.getWord() + "\n" + challenge.getDefinition());

        qDeleteAll(imageLabels);
        qDeleteAll(imageTargets);
        imageLabels.clear();
        imageTargets.clear();

        imageLabels = createImageLabels(challenge.getShuffled(), dragLabelParent);
        imageTargets = createImageTargets(challenge.getWord().size(), dragLabelParent);
        Calculations::updateLabelPositions(imageLabels,imageTargets, dragLabelParent);

        window.repaint();

    });


    window.show();

    int buttonPosition = (window.width() - button->size().width())/2;
    button->move(buttonPosition, window.height() - 100);


    Calculations::updateLabelPositions(imageLabels,imageTargets, dragLabelParent);

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

QList<TargetLabel *> createImageTargets(const int size, QWidget *parent)
{
    QList<TargetLabel *> imageTargets;
    for (int i = 0; i < size; ++i)
    {
            TargetLabel *label = new TargetLabel(parent);
            QPixmap pixmap(":/Letters/target.png");
            label->setPixmap(pixmap.scaled(60,60,Qt::KeepAspectRatio,Qt::SmoothTransformation));
            imageTargets.append(label);
    }
    return imageTargets;
}

