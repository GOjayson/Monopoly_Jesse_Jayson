#include "game-UI.h"
#include "board-UI.h"
#include "button-UI.h"
#include "pawn1-UI.h"
#include "showCardsMenu-UI.h"
#include "dice.h"

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QtCore>

QColor game::whosTurnColor;

game::game(QWidget* parent)
{
    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1500,1000);

    //Create a scene (soort storage voor alle QGraphicsItems en QGraphicView)
    scene = new QGraphicsScene(this); //de "this" is om de QGraphicsView een parent te maken van deze scene
    scene->setSceneRect(0,0,1500,1000); // make the scene 1000x1000 instead of ifinity
    setScene(scene);
}

void game::setWhosTurn(QString player)
{
    //change the Qstring
    whosTurn = player;

    if(whosTurn == "NONE")
    {
        //change color for who's turn it is
        game::whosTurnColor = Qt::darkGreen;
    }
    if(whosTurn == "PLAYER 1")
    {
        //change color for who's turn it is
        game::whosTurnColor = Qt::darkBlue;
    }
    if(whosTurn == "PLAYER 2")
    {
        //change color for who's turn it is
        game::whosTurnColor = Qt::darkRed;
    }

    //change the text
    whosTurnText->setPlainText(player);
}

void game::displayMainMenu()
{
    //place whosTurn text
    whosTurnText = new QGraphicsTextItem();
    setWhosTurn(QString("NONE"));
    delete whosTurnText;

    //create title
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Monopoly"));
    QFont titleFont("showcard gothic", 50);
    titleText->setFont(titleFont);
    titleText->setDefaultTextColor(Qt::darkGreen);

    //positie/plaatsen titel
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    //create the dice button
    button* playButton = new button(QString("Play"));
    int pxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int pyPos = 275;
    playButton->setPos(pxPos,pyPos);
    connect(playButton, SIGNAL(clicked()),this,SLOT(whosturnMenuP1()));
    scene->addItem(playButton);

    //create the quite button
    button* quiteButton = new button(QString("Quite"));
    int qxPos = this->width()/2 - quiteButton->boundingRect().width()/2;
    int qyPos = 350;
    quiteButton->setPos(qxPos,qyPos);
    connect(quiteButton, SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quiteButton);
}

void game::whosturnMenuP1()
{
    //clear screen
    scene->clear();

    //text
    QGraphicsTextItem* whosturnMenuText = new QGraphicsTextItem(QString("Player 1, throw the dice!"));
    QFont textFont("showcard gothic", 30);
    whosturnMenuText->setFont(textFont);
    whosturnMenuText->setDefaultTextColor(Qt::darkGreen);

    //positie/plaatsen text
    int txPos = this->width()/2 - whosturnMenuText->boundingRect().width()/2;
    int tyPos = 150;
    whosturnMenuText->setPos(txPos,tyPos);
    scene->addItem(whosturnMenuText);

    //create the play button
    button* diceButton = new button(QString("Throw the dice"));
    int pxPos = this->width()/2 - diceButton->boundingRect().width()/2;
    int pyPos = 275;
    diceButton->setPos(pxPos,pyPos);
    connect(diceButton, SIGNAL(clicked()),this,SLOT(displayWhosturnP1()));
    scene->addItem(diceButton);
}

void game::displayWhosturnP1()
{
    int diceRoll1 = dice().gooidice();
    QString s = QStringLiteral("Je hebt het nummer %1 gegooid!").arg(diceRoll1);

    //text
    noteText = new QGraphicsTextItem(s);
    QFont textFont("Berlin Sans BF", 15);
    noteText->setFont(textFont);
    //positie/plaatsen text
    int txPos = this->width()/2 - noteText->boundingRect().width()/2;
    int tyPos = 500;
    noteText->setPos(txPos,tyPos);
    scene->addItem(noteText);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(whosturnMenuP2()));
    timer->start(2500);
}

void game::whosturnMenuP2()
{
    //clear screen
    scene->clear();

    //text
    QGraphicsTextItem* whosturnMenuText = new QGraphicsTextItem(QString("Player 2, throw the dice!"));
    QFont textFont("showcard gothic", 30);
    whosturnMenuText->setFont(textFont);
    whosturnMenuText->setDefaultTextColor(Qt::darkGreen);

    //positie/plaatsen text
    int txPos = this->width()/2 - whosturnMenuText->boundingRect().width()/2;
    int tyPos = 150;
    whosturnMenuText->setPos(txPos,tyPos);
    scene->addItem(whosturnMenuText);

    //create the dice button
    button* diceButton = new button(QString("Throw the dice"));
    int pxPos = this->width()/2 - diceButton->boundingRect().width()/2;
    int pyPos = 275;
    diceButton->setPos(pxPos,pyPos);
    connect(diceButton, SIGNAL(clicked()),this,SLOT(displayWhosturnP2()));
    scene->addItem(diceButton);

}

void game::displayWhosturnP2()
{
    int diceRoll1 = dice().gooidice();
    QString s = QStringLiteral("Je hebt het nummer %1 gegooid!").arg(diceRoll1);
    //text
    noteText = new QGraphicsTextItem(s);
    QFont textFont("Berlin Sans BF", 15);
    noteText->setFont(textFont);
    //positie/plaatsen text
    int txPos = this->width()/2 - noteText->boundingRect().width()/2;
    int tyPos = 500;
    noteText->setPos(txPos,tyPos);
    scene->addItem(noteText);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(finalDecisionWhosturn()));
    timer->start(2500);
}

void game::finalDecisionWhosturn()
{
    //clear screen
    scene->clear();

    //text
    QGraphicsTextItem* whosturnMenuText = new QGraphicsTextItem(QString("Hier zou de winnaar moeten staan!"));
    QFont textFont("showcard gothic", 30);
    whosturnMenuText->setFont(textFont);
    whosturnMenuText->setDefaultTextColor(Qt::darkGreen);

    //positie/plaatsen text
    int txPos = this->width()/2 - whosturnMenuText->boundingRect().width()/2;
    int tyPos = 150;
    whosturnMenuText->setPos(txPos,tyPos);
    scene->addItem(whosturnMenuText);

    //create the play button
    button* diceButton = new button(QString("start"));
    int pxPos = this->width()/2 - diceButton->boundingRect().width()/2;
    int pyPos = 275;
    diceButton->setPos(pxPos,pyPos);
    connect(diceButton, SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(diceButton);

}

void game::start()
{
    //clear screen
    scene->clear();

    //create board
    board *monopolyboard = new board();
    scene->addItem(monopolyboard);

    //place whosTurn text
    whosTurnText = new QGraphicsTextItem();
    //deciding whosturn---------------//
    setWhosTurn(QString("PLAYER 2"));
    //--------------------------------//
    QFont playerFont("showcard gothic", 20);
    whosTurnText->setFont(playerFont);
    whosTurnText->setDefaultTextColor(game::getWhosTurnColor());
    whosTurnText->setPos(1050,35);
    scene->addItem(whosTurnText);

    //place geldbedrag
    moneyText = new QGraphicsTextItem("$1000");
    QFont moneyFont("showcard gothic", 20);
    moneyText->setFont(moneyFont);
    moneyText->setDefaultTextColor(game::getWhosTurnColor());
    moneyText->setPos(1050,70);
    scene->addItem(moneyText);

    //show cards button
    button* showCardsButton = new button(QString("Show cards"));
    int showCxPos = 1150;
    int showCyPos = 225;
    showCardsButton->setPos(showCxPos,showCyPos);
    connect(showCardsButton, SIGNAL(clicked()),this,SLOT(showCards()));
    scene->addItem(showCardsButton);

    //create the dice button
    button* diceButton = new button(QString("Throw the dice"));
    int dxPos = 1150;
    int dyPos = 325;
    diceButton->setPos(dxPos,dyPos);
    connect(diceButton, SIGNAL(clicked()),this,SLOT(throwDice()));
    scene->addItem(diceButton);

}

void game::showCards()
{
    showCardsMenu *window2 = new showCardsMenu;
    window2->show();
}

void game::throwDice()
{
    int diceRoll1 = dice().gooidice();
    QString s = QStringLiteral("Je hebt het nummer %1 gegooid!").arg(diceRoll1);

    //text
    noteText = new QGraphicsTextItem(s);

    //positie/plaatsen text
    noteText->setPos(1150,500);
    scene->addItem(noteText);

    //voor timer (mss verwijderen later)
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(removeDiceText()));
    timer->start(2000);
}

void game::removeDiceText()
{
    delete noteText;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(start()));
    timer->start(0);
}


