#ifndef PAWNP1_H
#define PAWNP1_H


#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

namespace monopoly
{
    class pawnP1: public QGraphicsPixmapItem
    {
        public:
            //constructors
            pawnP1(QGraphicsItem* parent=nullptr);
            ~pawnP1() {}
    };
}

#endif // PAWNP1_H
