#include "showCardsMenu-UI.h"
#include "button-UI.h"

#include <QGraphicsScene>

namespace monopoly
{
    showCardsMenu::showCardsMenu(QWidget *parent)
    {
        //set up the screen
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize((unsigned short)500,(unsigned short)500);

        //Create a scene (soort storage voor alle QGraphicsItems en QGraphicView)
        scene = new QGraphicsScene(this);
        scene->setSceneRect(0,0,(unsigned short)500,(unsigned short)500);
        setScene(scene);
    }
}



