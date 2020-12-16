#ifndef PAWNP1_H
#define PAWNP1_H

#include <QGraphicsEllipseItem>

class pawnP1: public QGraphicsEllipseItem{
public:
    //constructors
    pawnP1(QGraphicsItem* parent=nullptr);

    //public methods
    int setPosPawn1(int diceRoll);
};

#endif // PAWN1_H
