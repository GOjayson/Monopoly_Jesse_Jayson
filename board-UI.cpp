#include "board-UI.h"

#include <QPixmap>

board::board(QGraphicsItem* parent)
{
    //set the graphics
    setPixmap(QPixmap(":/Pictures/monopolyBoardV2.jpg"));//is 1000px op 1000px groot

}
