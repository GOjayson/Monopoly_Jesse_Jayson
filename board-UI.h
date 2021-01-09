#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

namespace monopoly
{
    class board : public QGraphicsPixmapItem
    {
        public:
            //constructors
            board(QGraphicsItem* parent=nullptr);
            ~board(){}
    };
}

#endif // BOARD_H
