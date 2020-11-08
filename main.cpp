#include <QApplication>
#include <game.h>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game *game1 = new game;

    //Game tonen
    game1->show();
    game1->displayMainMenu();

    return a.exec();
}


