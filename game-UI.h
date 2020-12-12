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
    void setWhosTurn(QString player);
    int movePawn1(int diceRoll);
    QString getWhosTurn() const {return (whosTurn);} //nog niet gebruikt
    static QColor getWhosTurnColor() {return (game::whosTurnColor);}

    //public attributes
    QGraphicsScene* scene;
    QTimer* timer; //voor timer (mss verwijderen later)

public slots:
    void whosturnMenuP1();
    void displayWhosturnP1();
    void whosturnMenuP2();
    void displayWhosturnP2();
    void finalDecisionWhosturn();
    void start();
    void showCards();
    void throwDice();
    void removeDiceText(); //voor timer (mss verwijderen later)

private:
    QGraphicsTextItem* noteText;
    QGraphicsTextItem* moneyText;
    QGraphicsTextItem* whosTurnText;
    QString whosTurn;
    static QColor whosTurnColor;

};

#endif // GAME_H
