#include "game.h"
#include "board.h"
#include "button.h"
#include "pawn1.h"
#include "showCardsMenu.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>


#include <iostream> //voor de dice --> verwijder later
#include <cstdlib>
#include <ctime>

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
/*    scene->addItem(whosTurnText);
    scene->removeItem(whosTurnText); */

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

    //create the play button
    button* playButton = new button(QString("Play"));
    int pxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int pyPos = 275;
    playButton->setPos(pxPos,pyPos);
    connect(playButton, SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    //create the quite button
    button* quiteButton = new button(QString("Quite"));
    int qxPos = this->width()/2 - quiteButton->boundingRect().width()/2;
    int qyPos = 350;
    quiteButton->setPos(qxPos,qyPos);
    connect(quiteButton, SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quiteButton);

}

void game::start() //knoppen zijn 200x50
{
    //clear screen
    scene->clear();

    //create board
    board *monopolyboard = new board();
    scene->addItem(monopolyboard);

    //place whosTurn text
    whosTurnText = new QGraphicsTextItem();
    setWhosTurn(QString("PLAYER 1"));
    QFont playerFont("showcard gothic", 20);
    whosTurnText->setFont(playerFont);
    whosTurnText->setDefaultTextColor(Qt::darkBlue);
    whosTurnText->setPos(1050,35);
    scene->addItem(whosTurnText);

    //place geldbedrag
    moneyText = new QGraphicsTextItem("$1000");
    QFont moneyFont("showcard gothic", 20);
    moneyText->setFont(moneyFont);
    moneyText->setDefaultTextColor(Qt::darkBlue);
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

    //create pawn1
    pawn1 *pawnNumber1 = new pawn1();
    pawnNumber1->setPos(900,900);
    scene->addItem(pawnNumber1);

}

void game::showCards()
{
    showCardsMenu *window2 = new showCardsMenu;
    window2->show();
}

void game::throwDice()
{
    //scene->removeItem(text);

    /*onderstaande code wordt in de toekomst vervangen met een opgeroepen functie*/
    srand(time(0));
    int dice1 = (int) (1+rand()%6);
    int dice2 = (int) (1+rand()%6);
    int diceSum = dice1 + dice2;
    /*---------------------------------------------------------------------------*/

    QString s = QStringLiteral("Je hebt het nummer %1 gegooid!").arg(diceSum);

    //text
    noteText = new QGraphicsTextItem(s);
    noteText->setPos(1150,500);
    scene->addItem(noteText);

    //voor timer (mss verwijderen later)
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(removeDiceText));
    timer->start(1000);


}

void game::removeDiceText() //voor timer (mss verwijderen later)
{
    noteText = new QGraphicsTextItem(QString("hoi"));
    noteText->setPos(1150,500);
    scene->addItem(noteText);
    scene->removeItem(noteText);
}


