#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>

class game: public QGraphicsView{
public:
    //member functions
    game();
    //member attributes
    QGraphicsScene * scene;
};

#endif // GAME_H
