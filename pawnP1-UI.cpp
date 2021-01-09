#include "pawnP1-UI.h"

#include <QBrush>

namespace monopoly
{
    pawnP1::pawnP1(QGraphicsItem *parent):QGraphicsEllipseItem(parent)
    {
        //setRect maar omdat het van een elipseitem komt is het eigenlijk een elipse
        setRect(0,0,(unsigned char)30,(unsigned char)30);

        //kleuren van de pion in de juiste kleur van speler
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::darkBlue);
        setBrush(brush);
    }
}


