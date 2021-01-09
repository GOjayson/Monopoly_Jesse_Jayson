#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

#include "board-UI.h"
#include "button-UI.h"
#include "pawnP1-UI.h"
#include "pawnP2-UI.h"

namespace monopoly
{
    class game: public QGraphicsView
    {
        Q_OBJECT //moet voor signals en slots
        public:
            //constructors
            game(QWidget* parent=nullptr);
            ~game(){}

            //public methods
            void displayMainMenu();
            void setWhosTurn(QString player);
            QString getWhosTurn() {return (game::whosTurn);}
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
            void throwDice();
            void NO();
            void YES();
            void showCards();

        private:
            QGraphicsTextItem* noteText;
            QGraphicsTextItem* moneyText;
            QGraphicsTextItem* whosTurnText;
            board *monopolyboard;
            button* showCardsButton;
            button* diceButton;
            button* nextButton;
            button* noButton;
            button* yesButton;
            pawnP1* player1Pawn;
            pawnP2* player2Pawn;

            QString whosTurn;

            unsigned char diceRollP1;
            unsigned char diceRollP2;
            unsigned char tempP1;
            unsigned char tempP2;

            unsigned short xStartPos1;
            unsigned short yStartPos1;
            unsigned short xStartPos2;
            unsigned short yStartPos2;

            bool beveiligingDice;
            bool diceButtonClicked;
            bool noButtonClicked;
            bool yesButtonClicked;

            static QColor whosTurnColor;
    };
}

#endif // GAME_H
