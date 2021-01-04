#include "showCardsMenu-UI.h"
#include "button-UI.h"

#include <QGraphicsScene>

showCardsMenu::showCardsMenu(QWidget *parent)
{
    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(500,500);

    //Create a scene (soort storage voor alle QGraphicsItems en QGraphicView)
    scene = new QGraphicsScene(this); //de "this" is om de QGraphicsView een parent te maken van deze scene
    scene->setSceneRect(0,0,500,500); // make the scene 1000x1000 instead of ifinity
    setScene(scene);


}


