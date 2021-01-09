#ifndef PAWNP2_H
#define PAWNP2_H

#include <QGraphicsEllipseItem>

namespace monopoly
{
    class pawnP2: public QGraphicsEllipseItem
    {
        public:
            //constructors
            pawnP2(QGraphicsItem* parent=nullptr);
            ~pawnP2() {}
    };
}

#endif // PAWNP2_H

