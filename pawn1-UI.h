#ifndef PAWN1_H
#define PAWN1_H

#include <QGraphicsEllipseItem>

class pawn1: public QGraphicsEllipseItem{
public:
    //constructors
    pawn1(QGraphicsItem* parent=nullptr);

    //public methods
    int setPosPawn1(int diceRoll);
};

#endif // PAWN1_H
