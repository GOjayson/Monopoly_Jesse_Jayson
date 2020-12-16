#include "game-UI.h"
#include "board-UI.h"
#include "button-UI.h"
#include "pawnP1-UI.h"
#include "showCardsMenu-UI.h"
#include "dice.h"

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <iostream>

QColor game::whosTurnColor;

game::game(QWidget* parent)
{
    //place whosTurn text
/*    whosTurnText = new QGraphicsTextItem();
    setWhosTurn(QString("NONE")); //om de kleur van de buttons te bepalden
    delete whosTurnText; */

    //pointers die meermaals gerbuikt worden declareren
    monopolyboard   =   new board();
    whosTurnText    =   new QGraphicsTextItem();
    moneyText       =   new QGraphicsTextItem();
    showCardsButton =   new button(QString("Show cards"));
    diceButton      =   new button(QString("Throw the dice"));
    player1Pawn     =   new pawnP1();
    nextButton      =   new button(QString("Next ->"));

    connect(showCardsButton, SIGNAL(clicked()),this,SLOT(showCards()));
    connect(diceButton, SIGNAL(clicked()),this,SLOT(throwDice()));
    connect(nextButton, SIGNAL(clicked()),this,SLOT(start()));

    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1500,1000);

    //Create a scene (soort storage voor alle QGraphicsItems en QGraphicView)
    scene = new QGraphicsScene(); //de "this" is om de QGraphicsView een parent te maken van deze scene
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
    setWhosTurn(QString("NONE")); //om de kleur van de buttons te bepalden

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
    whosturnMenuText->setDefaultTextColor(game::getWhosTurnColor());

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
    connect(diceButton, SIGNAL(clicked()),this,SLOT(displayWhosturnP1()));
    scene->addItem(diceButton);
}

void game::displayWhosturnP1()
{
    std::cout << "dice gooit  "<< diceRollP1 << std::endl;
    diceRollP1 = dice().gooidice();

    QString s = QStringLiteral("Je hebt het nummer %1 gegooid!").arg(diceRollP1);

    //text
    noteText = new QGraphicsTextItem(s);
    QFont textFont("Berlin Sans BF", 15);
    noteText->setFont(textFont);

    //positie/plaatsen text
    int txPos = this->width()/2 - noteText->boundingRect().width()/2;
    int tyPos = 500;
    noteText->setPos(txPos,tyPos);
    scene->addItem(noteText);

    //create the next button
    button* nextButton = new button(QString("Next ->"));
    int pxPos = 1275;
    int pyPos = 925;
    nextButton->setPos(pxPos,pyPos);
    connect(nextButton, SIGNAL(clicked()),this,SLOT(whosturnMenuP2()));
    scene->addItem(nextButton);
}

void game::whosturnMenuP2()
{
    //clear screen
    scene->clear();

    //text
    QGraphicsTextItem* whosturnMenuText = new QGraphicsTextItem(QString("Player 2, throw the dice!"));
    QFont textFont("showcard gothic", 30);
    whosturnMenuText->setFont(textFont);
    whosturnMenuText->setDefaultTextColor(game::getWhosTurnColor());

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
    diceRollP2 = dice().gooidice();

    QString s = QStringLiteral("Je hebt het nummer %1 gegooid!").arg(diceRollP2);

    //text
    noteText = new QGraphicsTextItem(s);
    QFont textFont("Berlin Sans BF", 15);
    noteText->setFont(textFont);

    //positie/plaatsen text
    int txPos = this->width()/2 - noteText->boundingRect().width()/2;
    int tyPos = 500;
    noteText->setPos(txPos,tyPos);
    scene->addItem(noteText);

    //create the next button
    button* nextButton = new button(QString("Next ->"));
    int pxPos = 1275;
    int pyPos = 925;
    nextButton->setPos(pxPos,pyPos);
    connect(nextButton, SIGNAL(clicked()),this,SLOT(finalDecisionWhosturn()));
    scene->addItem(nextButton);
}

void game::finalDecisionWhosturn()
{
    int winningDice = 0;
    char const* winningPlayer = "";

    //clear screen
    scene->clear();

    if(diceRollP1>diceRollP2)
    {
        winningDice = diceRollP1;
        winningPlayer = "Player 1";
        whosTurnText = new QGraphicsTextItem();
        setWhosTurn(QString("PLAYER 1"));
    }
    if(diceRollP2>diceRollP1)
    {
        winningDice = diceRollP2;
        winningPlayer = "Player 2";
        whosTurnText = new QGraphicsTextItem();
        setWhosTurn(QString("PLAYER 2"));
    }

    //text
    QString s = QStringLiteral("%1 is de winnaar!").arg(winningPlayer);
    QGraphicsTextItem* whosturnMenuText = new QGraphicsTextItem(s);
    QFont textFont("showcard gothic", 30);
    whosturnMenuText->setFont(textFont);
    whosturnMenuText->setDefaultTextColor(game::getWhosTurnColor());
    int txPos = this->width()/2 - whosturnMenuText->boundingRect().width()/2;
    int tyPos = 150;
    whosturnMenuText->setPos(txPos,tyPos);
    scene->addItem(whosturnMenuText);

    //notetext
    QString c = QStringLiteral("De winnaar heeft maar liefst %1 gegooid en mag als eerste starten!").arg(winningDice);
    noteText = new QGraphicsTextItem(c);
    QFont noteTextFont("Berlin Sans BF", 15);
    noteText->setFont(noteTextFont);
    int nxPos = this->width()/2 - noteText->boundingRect().width()/2;
    int nyPos = 500;
    noteText->setPos(nxPos,nyPos);
    scene->addItem(noteText);

    //create the start button
    button* startButton = new button(QString("Start"));
    int pxPos = this->width()/2 - startButton->boundingRect().width()/2;
    int pyPos = 275;
    startButton->setPos(pxPos,pyPos);
    connect(startButton, SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(startButton);

    //breng dice uitkomsten naar 0 zodat ze bij de start functie altijd terug van 0 beginnen
    diceRollP1 = 0;
    diceRollP2 = 0;

}

void game::start()
{
    //clear screen
    //scene->clear();

    //create board
    scene->addItem(monopolyboard);

    //style/positioneer text
    QFont playerFont("showcard gothic", 20);
    whosTurnText->setFont(playerFont);
    whosTurnText->setDefaultTextColor(game::getWhosTurnColor());
    whosTurnText->setPos(1050,35);
    scene->addItem(whosTurnText);

    //place geldbedrag
    moneyText->setPlainText("$1000");
    QFont moneyFont("showcard gothic", 20);
    moneyText->setFont(moneyFont);
    moneyText->setDefaultTextColor(game::getWhosTurnColor());
    moneyText->setPos(1050,70);
    scene->addItem(moneyText);

    //show cards button
    showCardsButton->setBrush(game::getWhosTurnColor());
    showCardsButton->setPos(1150,225);
    scene->addItem(showCardsButton);

    //create the dice button
    diceButton->setBrush(game::getWhosTurnColor());
    diceButton->setPos(1150,325);
    scene->addItem(diceButton);

    //plaatsen van pion
    player1Pawn->setPos(900 - (46 * diceRollP1),900);
    scene->addItem(player1Pawn);
}

void game::showCards()
{
    showCardsMenu *window2 = new showCardsMenu;
    window2->show();
}

void game::throwDice()
{

    int diceRollP1 = dice().gooidice();
    QString s = QStringLiteral("Je hebt het nummer %1 gegooid!").arg(diceRollP1);

    //text
    noteText = new QGraphicsTextItem(s);

    //positie/plaatsen text
    noteText->setPos(1150,500);
    scene->addItem(noteText);

    //create the next button
    nextButton->setPos(1275,925);
    scene->addItem(nextButton);
}



