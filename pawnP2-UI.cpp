#include "pawnP2-UI.h"

#include <QBrush>

pawnP2::pawnP2(QGraphicsItem *parent):QGraphicsEllipseItem(parent)
{
    setRect(0,0,30,30);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);

}


