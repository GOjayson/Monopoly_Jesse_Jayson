#include "pawnP2-UI.h"

#include <QBrush>

namespace monopoly
{
    pawnP2::pawnP2(QGraphicsItem *parent):QGraphicsEllipseItem(parent)
    {
        //setRect maar omdat het van een elipseitem komt is het eigenlijk een elipse
        setRect(0,0,(unsigned char)30,(unsigned char)30);

        //kleuren van de pion in de juiste kleur van speler
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::darkRed);
        setBrush(brush);
    }
}



