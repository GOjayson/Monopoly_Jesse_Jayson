#ifndef SHOWCARDSMENU_H
#define SHOWCARDSMENU_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

class showCardsMenu: public QGraphicsView{
public:
    //constructors
    showCardsMenu(QWidget* parent=NULL);

    //public methods
   // void displayMainMenu();

    //public attributes
    QGraphicsScene* scene;

};

#endif // SHOWCARDSMENU_H
