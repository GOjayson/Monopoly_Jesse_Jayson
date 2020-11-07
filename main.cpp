#include <QApplication>
#include <game.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Game tonen
    game *Game = new game;
    Game->show();

    return a.exec();
}


