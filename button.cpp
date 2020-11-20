#include "button.h"
#include <QBrush>
#include <QGraphicsTextItem>

button::button(QString Name, QGraphicsItem* parent):QGraphicsRectItem(parent)
{
    //draw rect
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGreen);
    setBrush(brush);

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
    brush.setColor(Qt::green);
    setBrush(brush);
}

void button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGreen);
    setBrush(brush);
}
