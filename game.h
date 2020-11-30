#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

#include <QtCore> //voor timer (mss verwijderen later)

class game: public QGraphicsView{
    Q_OBJECT //moet voor signals en slots
public:
    //constructors
    game(QWidget* parent=nullptr);

    //public methods
    void displayMainMenu();

    //public attributes
    QGraphicsScene* scene;
    QTimer* timer; //voor timer (mss verwijderen later)

public slots:
    void start();
    void showCards();
    void throwDice();
    void removeDiceText(); //voor timer (mss verwijderen later)

private:
    QGraphicsTextItem* text;

};

#endif // GAME_H
