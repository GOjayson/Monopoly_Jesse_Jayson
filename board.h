#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class board : public QGraphicsPixmapItem{
public:
        //constructors
        board(QGraphicsItem * parent =nullptr);
};

#endif // BOARD_H
