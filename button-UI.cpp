#include "button-UI.h"
#include "game-UI.h"

#include <QBrush>
#include <QGraphicsTextItem>
#include <iostream>

namespace monopoly
{
    button::button(QString Name, QGraphicsItem* parent):QGraphicsRectItem(parent)
    {
        //draw rect
        setRect(0,0,(unsigned char)200,(unsigned char) 50);

        //paint the rect
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(game::getWhosTurnColor());
        setBrush(brush);

        //draw the text
        text = new QGraphicsTextItem (Name, this);
        text->setDefaultTextColor(Qt::white);

        //om de text in het midden van de knop te krijgen (de knop is de parent)
        unsigned char divider = 2;
        unsigned char xPos = rect().width()/divider - text->boundingRect().width()/divider;
        unsigned char yPos = rect().height()/divider - text->boundingRect().height()/divider;
        text->setPos(xPos,yPos);

        //allowing responding to hover events
        setAcceptHoverEvents(true);
    }

    void button::mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        emit clicked();

        //speel geluidje af bij klikken van de buttons (omg spaties in de path naam :O)
        PlaySound(TEXT("C://Users//Jesse//OneDrive - PXL//School//2020 - 2021 - 2 AEIa//Github//Monopoly_Jesse_Jayson//buttonfx.wav"), NULL, SND_FILENAME| SND_ASYNC);
    }

    void button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);

        //kleur veranderen naargelang speler
        QColor color = game::getWhosTurnColor();
        if(color == Qt::darkGreen)
        {
            brush.setColor(Qt::green);
        }
        if(color == Qt::darkBlue)
        {
            brush.setColor(Qt::blue);
        }
        if(color == Qt::darkRed)
        {
            brush.setColor(Qt::red);
        }

        setBrush(brush);
    }

    void button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
    {
        //kleur veranderen bij hoveren
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(game::getWhosTurnColor());
        setBrush(brush);
    }
}

