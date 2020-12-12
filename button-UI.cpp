#include "button-UI.h"
#include "game-UI.h"

#include <QBrush>
#include <QGraphicsTextItem>
#include <iostream>

button::button(QString Name, QGraphicsItem* parent):QGraphicsRectItem(parent)
{
    //draw rect
    setRect(0,0,200,50);

    //paint the rect
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(game::getWhosTurnColor());
    setBrush(brush);
    std::cout << "setbrush"<< std::endl;

    //draw the text
    text = new QGraphicsTextItem (Name, this);
    text->setDefaultTextColor(Qt::white);
    //om de text in het midden van de knop te krijgen (de knop is de parent)
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    //allowing responding to hover events
    setAcceptHoverEvents(true);



}

void button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
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
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(game::getWhosTurnColor());
    setBrush(brush);
}
