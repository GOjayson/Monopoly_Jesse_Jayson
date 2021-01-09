#include "board-UI.h"

#include <QPixmap>

namespace monopoly
{
    board::board(QGraphicsItem* parent)
    {
        //monopoly bord verwezenlijken
        setPixmap(QPixmap(":/Pictures/monopolyBoardV2.jpg")); //is 1000px op 1000px groot
    }
}


