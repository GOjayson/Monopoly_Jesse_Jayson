#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

#include "board-UI.h"
#include "button-UI.h"
#include "pawnP1-UI.h"


class game: public QGraphicsView{
    Q_OBJECT //moet voor signals en slots
public:
    //constructors
    game(QWidget* parent=nullptr);

    //public methods
    void displayMainMenu();
    void setWhosTurn(QString player);
    int movePawn1(int diceRoll);
    QString getWhosTurn() const {return (whosTurn);} //nog niet gebruikt
    static QColor getWhosTurnColor() {return (game::whosTurnColor);}

    //public attributes
    QGraphicsScene* scene;

public slots:
    void whosturnMenuP1();
    void displayWhosturnP1();
    void whosturnMenuP2();
    void displayWhosturnP2();
    void finalDecisionWhosturn();
    void start();
    void showCards();
    void throwDice();

private:
    QGraphicsTextItem* noteText;
    QGraphicsTextItem* moneyText;
    QGraphicsTextItem* whosTurnText;
    board *monopolyboard;
    button* showCardsButton;
    button* diceButton;
    pawnP1* player1Pawn;
    button* nextButton;

    QString whosTurn; //mss ook pointer van maken?

    int diceRollP1;
    int diceRollP2;

    static QColor whosTurnColor;

};

#endif // GAME_H
