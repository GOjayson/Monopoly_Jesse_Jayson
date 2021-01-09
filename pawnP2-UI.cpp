#include "pawnP2-UI.h"

#include <QPixmap>

namespace monopoly
{
    pawnP2::pawnP2(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
    {
        setPixmap(QPixmap(":/Pictures/Car-Red.png"));
    }
}



