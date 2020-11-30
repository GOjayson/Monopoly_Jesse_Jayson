#ifndef PAWN1_H
#define PAWN1_H

#include <QGraphicsEllipseItem>

class pawn1: public QGraphicsEllipseItem
{
public:
    //constructors
    pawn1(QGraphicsItem* parent=nullptr);

private:
    void movepawn(int dice); //nog niet gebruikt
};

#endif // PAWN1_H
