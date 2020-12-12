#include "game-UI.h"
#include "showCardsMenu-UI.h"

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game *window1 = new game;

    //Game tonen
    window1->show();
    window1->displayMainMenu();

    return a.exec();
}


