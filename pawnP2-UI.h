#ifndef PAWNP2_H
#define PAWNP2_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

namespace monopoly
{
    class pawnP2: public QGraphicsPixmapItem
    {
        public:
            //constructors
            pawnP2(QGraphicsItem* parent=nullptr);
            ~pawnP2() {}
    };
}

#endif // PAWNP2_H

