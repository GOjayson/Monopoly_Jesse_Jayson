#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

class game: public QGraphicsView{
    Q_OBJECT //moet voor signals en slots
public:
    //constructors
    game(QWidget* parent=NULL);

    //public methods
    void displayMainMenu();

    //public attributes
    QGraphicsScene* scene;

public slots:
    void start();
    void showCards();
    void throwDice();

};

#endif // GAME_H
