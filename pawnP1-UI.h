#ifndef PAWNP1_H
#define PAWNP1_H

#include <QGraphicsEllipseItem>

namespace monopoly
{
    class pawnP1: public QGraphicsEllipseItem
    {
        public:
            //constructors
            pawnP1(QGraphicsItem* parent=nullptr);
            ~pawnP1() {}
    };
}

#endif // PAWNP1_H
