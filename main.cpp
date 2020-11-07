include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <mainwindow.h>
#include "myRect.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene
    myRect * rect = new myRect();
    rect->setRect(0,0,100,100);

    // add the item to the scene
    scene->addItem(rect);

    //make item focusable (anders is het item niet responsive)
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // add a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);

    //show the view
    view->setWindowTitle("My app");
    view->show();

    return a.exec();
}


