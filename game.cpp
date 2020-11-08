#include "game.h"
#include "board.h"
#include "button.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>

game::game(QWidget* parent)
{
    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,1000);

    //Create a scene (soort storage voor alle QGraphicsItems en QGraphicView)
    scene = new QGraphicsScene(this); //de "this" is om de QGraphicsView een parent te maken van deze scene
    scene->setSceneRect(0,0,1000,1000); // make the scene 1000x1000 instead of ifinity
    setScene(scene);
}

void game::start()
{
    //momenteel voor te testen

    //create board
    board *monopolyboard = new board();

    //add the board to the scene
    scene->addItem(monopolyboard);

}

void game::displayMainMenu()
{
    //create title
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Monopoly"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);

    //positie/plaatsen titel
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    //create the play button
    button* playButton = new button(QString("Play"));

    //positie/ plaatsen play button
    int pxPos = this->width()/2 - titleText->boundingRect().width()/2;
    int pyPos = 275;
    titleText->setPos(pxPos,pyPos);
    //playbutton connecten met de start functie
    connect(playButton, SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    //create the quite button
    button* quiteButton = new button(QString("Play"));

    //positie/ plaatsen quit button
    int qxPos = this->width()/2 - titleText->boundingRect().width()/2;
    int qyPos = 350;
    titleText->setPos(qxPos,qyPos);
    //quitbutton connecten met de close functie
    connect(quiteButton, SIGNAL(clicked()),this,SLOT(close));
    scene->addItem(quiteButton);

}
