#include "pawnP1-UI.h"

#include <QPixmap>

namespace monopoly
{
    pawnP1::pawnP1(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
    {
        setPixmap(QPixmap(":/Pictures/Hat-Blue.png"));
    }
}


