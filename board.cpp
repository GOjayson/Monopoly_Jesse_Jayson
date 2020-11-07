#include "board.h"
#include <QPixmap>

board::board(QGraphicsItem *parent)
{
    //set the graphics
    setPixmap(QPixmap(":/Pictures/monopolyBoardV2.jpg"));//is 1000pix op 1000pix groot

}
