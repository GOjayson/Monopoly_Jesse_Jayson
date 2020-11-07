#include "game.h"
#include <QGraphicsScene>
#include "board.h"

game::game()
{
    //Create a scene (soort storage voor alle QGraphicsItems en QGraphicView)
    scene = new QGraphicsScene(this); //de "this" is om de QGraphicsView een parent te maken van deze scene

    scene->setSceneRect(0,0,1500,1000); // make the scene 1000x1000 instead of ifinity

    //set the scene
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1500,1000);

    //create board
    board *Board = new board();

    //add the board to the scene
    scene->addItem(Board);
}
