#include "game.h"
#include "board.h"
#include "button.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>

#include "showCardsMenu.h" //niet zeker


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

void game::showCards()
{
    showCardsMenu *window2 = new showCardsMenu;
    window2->show();
}

void game::start() //knoppen zijn 200x50
{
    //clear screen
    scene->clear();

    //create board
    board *monopolyboard = new board();
    scene->addItem(monopolyboard);

    //create the dice button
    button* diceButton = new button(QString("Throw the dice"));
    int dxPos = 1150;
    int dyPos = 275;
    diceButton->setPos(dxPos,dyPos);
    scene->addItem(diceButton);

    //show cards button
    button* showCardsButton = new button(QString("Show cards"));
    int showCxPos = 1150;
    int showCyPos = 350;
    showCardsButton->setPos(showCxPos,showCyPos);
    connect(showCardsButton, SIGNAL(clicked()),this,SLOT(showCards()));
    scene->addItem(showCardsButton);

}

void game::displayMainMenu()
{
    //create title
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Monopoly"));
    QFont titleFont("showcard gothic", 50);
    titleText->setFont(titleFont);

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
