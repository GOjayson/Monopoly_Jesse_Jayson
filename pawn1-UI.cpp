#include "pawn1-UI.h"

#include <QBrush>

pawn1::pawn1(QGraphicsItem *parent):QGraphicsEllipseItem(parent)
{
    setRect(0,0,30,30);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkBlue);
    setBrush(brush);

}

int pawn1::setPosPawn1(int diceRoll)
{
    setPos(1500,900);
}
