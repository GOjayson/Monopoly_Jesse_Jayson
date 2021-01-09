#ifndef SHOWCARDSMENU_H
#define SHOWCARDSMENU_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

namespace monopoly
{
    class showCardsMenu: public QGraphicsView
    {
        public:
            //constructors
            showCardsMenu(QWidget* parent=nullptr);
            ~showCardsMenu(){}

            //public attributes
            QGraphicsScene* scene;
    };
}

#endif // SHOWCARDSMENU_H
