#include "mainwindow.h"

#include <QApplication>
#include <QPropertyAnimation>
#include <QFont>
#include <QList>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

#include "wordchallenge.h"
#include "challengegenerator.h"
#include "DraggableLabel.h"
#include "targetlabel.h"

#include "calculations.h"
#include "gamestate.h"



QList<DraggableLabel *> createImageLabels(const QString &word, QWidget *parent);
QList<TargetLabel *> createImageTargets(const QString &word, QWidget *parent);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    window.setFixedSize(QSize(800, 600));


    //Initializes the database and the WordChallenge object
    ChallengeGenerator gen;
    WordChallenge challenge = gen.getChallenge();
    GameState &gameState = GameState::getInstance();


    //Creates the label, button, alignment info, and attaches it to the window
    QLabel *label = new QLabel(challenge.getDefinition());
    QFont font;
    font.setWeight(QFont::Bold);
    font.setPixelSize(14);
    label->setAlignment(Qt::AlignJustify);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label->setFont(font);
    label->setWordWrap(true);

    QVBoxLayout  *layout = new QVBoxLayout ();
    layout->addWidget(label, 0, Qt::AlignCenter);
    layout->setAlignment(Qt::AlignCenter);

    window.setCentralWidget(new QWidget(&window));
    window.centralWidget()->setLayout(layout);


    QWidget *dragLabelParent = new QWidget(&window);
    dragLabelParent->setGeometry(0, 0, window.width(), window.height());

    gameState.setImageLabels(createImageLabels(challenge.getShuffled(), dragLabelParent));
    gameState.setImageTargets(createImageTargets(challenge.getWord(), dragLabelParent));

    QLabel* lastWord = window.findChild<QLabel*>("lastWord");
    QFont lastFont;
    //lastFont.setWeight(QFont::Bold);
    lastFont.setPixelSize(16);
    lastWord->setFont(lastFont);
    lastWord->setParent(dragLabelParent);


    QLabel *skipLabel = new QLabel("SKIP", dragLabelParent);
    QLabel *nextLabel = new QLabel("NEXT", dragLabelParent);
    QLabel *resetLabel = new QLabel("RESET", dragLabelParent);


    QFont labelFont;
    labelFont.setWeight(QFont::Bold);
    labelFont.setPixelSize(14);
    skipLabel->setFont(labelFont);
    nextLabel->setFont(labelFont);
    resetLabel->setFont(labelFont);
    skipLabel->setAlignment(Qt::AlignCenter);
    nextLabel->setAlignment(Qt::AlignCenter);
    resetLabel->setAlignment(Qt::AlignJustify);


    QPushButton *redArrow = window.findChild<QPushButton*>("red_arrow");
    redArrow->setParent(dragLabelParent);

    QPushButton *greenArrow = window.findChild<QPushButton*>("green_arrow");
    greenArrow->setParent(dragLabelParent);

    QPushButton *resetArrow = window.findChild<QPushButton*>("reset");
    resetArrow->setParent(dragLabelParent);


    QObject::connect(redArrow, &QPushButton::clicked, [&]() {

        lastWord->setText(QString("The last word was: <b>%1</b>").arg(challenge.getWord()));

        challenge = gen.getChallenge();
        label->setText(challenge.getDefinition());

        gameState.clearLists();

        gameState.setImageLabels(createImageLabels(challenge.getShuffled(), dragLabelParent));
        gameState.setImageTargets(createImageTargets(challenge.getWord(), dragLabelParent));
        Calculations::updateLabelPositions(gameState.getImageLabels(),gameState.getImageTargets(), dragLabelParent);
    });

    QObject::connect(greenArrow, &QPushButton::clicked, [&]() {

        lastWord->setText(QString("The last word was: <b>%1</b>").arg(challenge.getWord()));

        challenge = gen.getChallenge();
        label->setText(challenge.getDefinition());

        gameState.clearLists();

        gameState.setImageLabels(createImageLabels(challenge.getShuffled(), dragLabelParent));
        gameState.setImageTargets(createImageTargets(challenge.getWord(), dragLabelParent));
        Calculations::updateLabelPositions(gameState.getImageLabels(),gameState.getImageTargets(), dragLabelParent);

        greenArrow->setVisible(false);
        nextLabel->setVisible(false);

        redArrow->setVisible(true);
        skipLabel->setVisible(true);

        resetArrow->setVisible(true);
        resetLabel->setVisible(true);
    });

    QObject::connect(resetArrow, &QPushButton::clicked, [&]() {

        for(DraggableLabel* label : gameState.getImageLabels()){
            label->moveToStart();
        }
    });


    window.show();

    lastWord->move(lastWord->pos().x(),window.height() - 75);

    redArrow->move(100, window.height() - 100);
    greenArrow->move(window.width() - 150, window.height() - 100);
    resetArrow->move(window.width() - 150, window.height() - 90);


    // Set the size of the arrow buttons
    redArrow->setFixedSize(QSize(80, 70));
    greenArrow->setFixedSize(QSize(70, 70));
    resetArrow->setFixedSize(QSize(40, 40));

    // Set the arrow images
    redArrow->setStyleSheet("image:url(:/Arrows/red-arrow.png); border: none;");
    greenArrow->setStyleSheet("image:url(:/Arrows/green-arrow.png); border: none;");
    resetArrow->setStyleSheet("image:url(:/Arrows/reset.png); border: none;");



    int skipLabelPositionX = redArrow->x() + (redArrow->width() - skipLabel->sizeHint().width()) / 2;
    int skipLabelPositionY = redArrow->y() - skipLabel->sizeHint().height();
    skipLabel->move(skipLabelPositionX, skipLabelPositionY);

    int nextLabelPositionX = greenArrow->x() + (greenArrow->width() - nextLabel->sizeHint().width()) / 2;
    int nextLabelPositionY = greenArrow->y() - nextLabel->sizeHint().height();
    nextLabel->move(nextLabelPositionX, nextLabelPositionY);

    resetLabel->move(nextLabelPositionX - 15, nextLabelPositionY);

    gameState.setRedButton(redArrow);
    gameState.setGreenButton(greenArrow);
    gameState.setResetButton(resetArrow);

    gameState.setNextLabel(nextLabel);
    gameState.setSkipLabel(skipLabel);
    gameState.setResetLabel(resetLabel);

    greenArrow->setVisible(false);
    nextLabel->setVisible(false);

    Calculations::updateLabelPositions(gameState.getImageLabels(), gameState.getImageTargets(), dragLabelParent);

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
            label->setLetter(word.at(i));
            label->setPixmap(pixmap.scaled(55,55,Qt::KeepAspectRatio,Qt::SmoothTransformation));
            imageLabels.append(label);
    }
    return imageLabels;
}

QList<TargetLabel *> createImageTargets(const QString &word, QWidget *parent)
{
    const int size = word.size();
    QList<TargetLabel *> imageTargets;
    for (int i = 0; i < size; ++i)
    {
            TargetLabel *label = new TargetLabel(parent);
            QPixmap pixmap(":/Letters/target.png");
            label->setExpectedLetter(word.at(i));
            label->setPixmap(pixmap.scaled(60,60,Qt::KeepAspectRatio,Qt::SmoothTransformation));
            imageTargets.append(label);
    }
    return imageTargets;
}
