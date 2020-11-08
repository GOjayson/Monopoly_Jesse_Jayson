#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

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

};

#endif // GAME_H
