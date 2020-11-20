#include "showCardsMenu.h"
#include "button.h"
#include <QGraphicsScene>

showCardsMenu::showCardsMenu(QWidget *parent)
{
    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1500,1000);

    //Create a scene (soort storage voor alle QGraphicsItems en QGraphicView)
    scene = new QGraphicsScene(this); //de "this" is om de QGraphicsView een parent te maken van deze scene
    scene->setSceneRect(0,0,1500,1000); // make the scene 1000x1000 instead of ifinity
    setScene(scene);

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


