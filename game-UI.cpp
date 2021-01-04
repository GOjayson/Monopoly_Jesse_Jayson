#include "game-UI.h"
#include "board-UI.h"
#include "button-UI.h"
#include "pawnP1-UI.h"
#include "showCardsMenu-UI.h"
#include "dice.h"

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <iostream>

QColor game::whosTurnColor;

game::game(QWidget* parent)
{
    //pointers die meermaals gerbuikt worden declareren
    monopolyboard   =   new board();
    whosTurnText    =   new QGraphicsTextItem();
    moneyText       =   new QGraphicsTextItem();
    showCardsButton =   new button(QString("Show cards"));
    diceButton      =   new button(QString("Throw the dice"));
    player1Pawn     =   new pawnP1();
    player2Pawn     =   new pawnP2();
    nextButton      =   new button(QString("Next ->"));
    noButton        =   new button(QString("Nope"));
    yesButton        =   new button(QString("Yes my master"));

    connect(showCardsButton, SIGNAL(clicked()),this,SLOT(showCards()));
    connect(diceButton, SIGNAL(clicked()),this,SLOT(throwDice()));
    connect(nextButton, SIGNAL(clicked()),this,SLOT(start()));
    connect(noButton, SIGNAL(clicked()),this,SLOT(NO()));
    connect(yesButton, SIGNAL(clicked()),this,SLOT(YES()));

    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1500,1000);

    //Create a scene (soort storage voor alle QGraphicsItems en QGraphicView)
    scene = new QGraphicsScene(this); //de "this" is om de QGraphicsView een parent te maken van deze scene
    scene->setSceneRect(0,0,1500,1000); // make the scene 1000x1000 instead of ifinity
    setScene(scene);

}

void game::setWhosTurn(QString player)
{
    //change the Qstring
    whosTurn = player;

    if(whosTurn == "NONE")
    {
        //change color for who's turn it is
        game::whosTurnColor = Qt::darkGreen;
    }
    if(whosTurn == "PLAYER 1")
    {
        //change color for who's turn it is
        game::whosTurnColor = Qt::darkBlue;
    }
    if(whosTurn == "PLAYER 2")
    {
        //change color for who's turn it is
        game::whosTurnColor = Qt::darkRed;
    }

    //change the text
    whosTurnText->setPlainText(player);
}

void game::displayMainMenu()
{
    //place whosTurn text
    setWhosTurn(QString("NONE")); //om de kleur van de buttons te bepalden

    //create title
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Monopoly"));
    QFont titleFont("showcard gothic", 50);
    titleText->setFont(titleFont);
    titleText->setDefaultTextColor(Qt::darkGreen);

    //positie/plaatsen titel
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    //create the dice button
    button* playButton = new button(QString("Play"));
    int pxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int pyPos = 275;
    playButton->setPos(pxPos,pyPos);
    connect(playButton, SIGNAL(clicked()),this,SLOT(whosturnMenuP1()));
    scene->addItem(playButton);

    //create the quite button
    button* quiteButton = new button(QString("Quite"));
    int qxPos = this->width()/2 - quiteButton->boundingRect().width()/2;
    int qyPos = 350;
    quiteButton->setPos(qxPos,qyPos);
    connect(quiteButton, SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quiteButton);
}

void game::whosturnMenuP1()
{
    //clear screen
    scene->clear();

    //text
    QGraphicsTextItem* whosturnMenuText = new QGraphicsTextItem(QString("Player 1, throw the dice!"));
    QFont textFont("showcard gothic", 30);
    whosturnMenuText->setFont(textFont);
    whosturnMenuText->setDefaultTextColor(game::getWhosTurnColor());

    //positie/plaatsen text
    int txPos = this->width()/2 - whosturnMenuText->boundingRect().width()/2;
    int tyPos = 150;
    whosturnMenuText->setPos(txPos,tyPos);
    scene->addItem(whosturnMenuText);

    //create the dice button
    button* diceButton = new button(QString("Throw the dice"));
    int pxPos = this->width()/2 - diceButton->boundingRect().width()/2;
    int pyPos = 275;
    diceButton->setPos(pxPos,pyPos);
    connect(diceButton, SIGNAL(clicked()),this,SLOT(displayWhosturnP1()));
    scene->addItem(diceButton);
}

void game::displayWhosturnP1()
{
    //dice gooien en resultaat in text duwen
    diceRollP1 = dice().gooidice();
    QString s = QStringLiteral("Je hebt het nummer %1 gegooid!").arg(diceRollP1);

    //text
    noteText = new QGraphicsTextItem(s);
    QFont textFont("Berlin Sans BF", 15);
    noteText->setFont(textFont);

    //positie/plaatsen text
    int txPos = this->width()/2 - noteText->boundingRect().width()/2;
    int tyPos = 500;
    noteText->setPos(txPos,tyPos);
    scene->addItem(noteText);

    //create the next button
    button* nextButton = new button(QString("Next ->"));
    int pxPos = 1275;
    int pyPos = 925;
    nextButton->setPos(pxPos,pyPos);
    connect(nextButton, SIGNAL(clicked()),this,SLOT(whosturnMenuP2()));
    scene->addItem(nextButton);
}

void game::whosturnMenuP2()
{
    //clear screen
    scene->clear();

    //text
    QGraphicsTextItem* whosturnMenuText = new QGraphicsTextItem(QString("Player 2, throw the dice!"));
    QFont textFont("showcard gothic", 30);
    whosturnMenuText->setFont(textFont);
    whosturnMenuText->setDefaultTextColor(game::getWhosTurnColor());

    //positie/plaatsen text
    int txPos = this->width()/2 - whosturnMenuText->boundingRect().width()/2;
    int tyPos = 150;
    whosturnMenuText->setPos(txPos,tyPos);
    scene->addItem(whosturnMenuText);

    //create the dice button
    button* diceButton = new button(QString("Throw the dice"));
    int pxPos = this->width()/2 - diceButton->boundingRect().width()/2;
    int pyPos = 275;
    diceButton->setPos(pxPos,pyPos);
    connect(diceButton, SIGNAL(clicked()),this,SLOT(displayWhosturnP2()));
    scene->addItem(diceButton);

}

void game::displayWhosturnP2()
{
    //dice gooien en resultaat in text duwen
    diceRollP2 = dice().gooidice();
    QString s = QStringLiteral("Je hebt het nummer %1 gegooid!").arg(diceRollP2);

    //text
    noteText = new QGraphicsTextItem(s);
    QFont textFont("Berlin Sans BF", 15);
    noteText->setFont(textFont);

    //positie/plaatsen text
    int txPos = this->width()/2 - noteText->boundingRect().width()/2;
    int tyPos = 500;
    noteText->setPos(txPos,tyPos);
    scene->addItem(noteText);

    //create the next button
    button* nextButton = new button(QString("Next ->"));
    int pxPos = 1275;
    int pyPos = 925;
    nextButton->setPos(pxPos,pyPos);
    connect(nextButton, SIGNAL(clicked()),this,SLOT(finalDecisionWhosturn()));
    scene->addItem(nextButton);
}

void game::finalDecisionWhosturn()
{
    int winningDice = 0;
    char const* winningPlayer = "";

    //clear screen
    scene->clear();

    //winnaar bepalen
    if(diceRollP1>diceRollP2)
    {
        winningDice = diceRollP1;
        winningPlayer = "Player 1";
        whosTurnText = new QGraphicsTextItem();
        setWhosTurn(QString("PLAYER 1"));
    }
    if(diceRollP2>diceRollP1)
    {
        winningDice = diceRollP2;
        winningPlayer = "Player 2";
        whosTurnText = new QGraphicsTextItem();
        setWhosTurn(QString("PLAYER 2"));
    }
    //bij gelijkspel mag player1 beginnen (discriminatie? mss.)
    if(diceRollP2 == diceRollP1)
    {
        winningDice = diceRollP1;
        winningPlayer = "Player 1";
        whosTurnText = new QGraphicsTextItem();
        setWhosTurn(QString("PLAYER 1"));
    }

    //text voor bekendmaking winnaar
    QString s = QStringLiteral("%1 is de winnaar!").arg(winningPlayer);
    QGraphicsTextItem* whosturnMenuText = new QGraphicsTextItem(s);
    QFont textFont("showcard gothic", 30);
    whosturnMenuText->setFont(textFont);
    whosturnMenuText->setDefaultTextColor(game::getWhosTurnColor());
    int txPos = this->width()/2 - whosturnMenuText->boundingRect().width()/2;
    int tyPos = 150;
    whosturnMenuText->setPos(txPos,tyPos);
    scene->addItem(whosturnMenuText);

    //notetext
    QString c = QStringLiteral("De winnaar heeft maar liefst %1 gegooid en mag als eerste starten!").arg(winningDice);
    noteText = new QGraphicsTextItem(c);
    QFont noteTextFont("Berlin Sans BF", 15);
    noteText->setFont(noteTextFont);
    int nxPos = this->width()/2 - noteText->boundingRect().width()/2;
    int nyPos = 500;
    noteText->setPos(nxPos,nyPos);
    scene->addItem(noteText);

    //create the start button
    button* startButton = new button(QString("Start"));
    int pxPos = this->width()/2 - startButton->boundingRect().width()/2;
    int pyPos = 275;
    startButton->setPos(pxPos,pyPos);
    connect(startButton, SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(startButton);

    //breng alle vriabelen naar de beginwaardes voor start
    diceRollP1 = 0;
    diceRollP2 = 0;
    xStartPos1 = 900;
    yStartPos1 = 900;
    xStartPos2 = 900;
    yStartPos2 = 920;
    tempP1     = 0;
    tempP2     = 0;

    //voor bij de volgende functie enkel clear scene te doen wanneer nodig
    diceButtonClicked = false;
    noButtonClicked  = false;
    yesButtonClicked = false;

}

void game::start()
{
    if (diceButtonClicked == false && noButtonClicked == false && yesButtonClicked == false)
    {        
        //clear screen
        scene->clear();

        //font stijlen instellen voor nodige items
        QFont moneyFont("showcard gothic", 20);
        moneyText->setFont(moneyFont);
        QFont playerFont("showcard gothic", 20);
        whosTurnText->setFont(playerFont);

        //alle items die steeds geupdatet worden aan de scene toevoegen
        scene->addItem(monopolyboard);
        scene->addItem(whosTurnText);
        scene->addItem(moneyText);
        scene->addItem(diceButton);
        scene->addItem(showCardsButton);
        scene->addItem(player1Pawn);
        scene->addItem(player2Pawn);
    }
    if (diceButtonClicked == true  && noButtonClicked == false && yesButtonClicked == false)
    {
        scene->removeItem(noteText);
        scene->removeItem(nextButton);

        //mededeling op welke straat je staat
        noteText = new QGraphicsTextItem("Je bent op straat '...' geeindigd!!        WIL JE DEZE KOPEN?");
        noteText->setTextWidth(200);
        noteText->setPos(1150,500);
        scene->addItem(noteText);

        //enkel positie players updaten als de dice button aangeklikt is
        if (game::getWhosTurn() == QString("PLAYER 1"))
        {
            tempP1= tempP1+ diceRollP1;
            if (xStartPos1 == 900 && yStartPos1 == 900)
            {
                xStartPos1 = 900 - (82 * diceRollP1);
                yStartPos1 = 900;
            }
            else
            {

                //onder
                if(yStartPos1 == 900 && tempP1<= 10)
                {
                    xStartPos1 = xStartPos1 - (82 * diceRollP1);
                    yStartPos1 = 900;
                }

                //links
                else if(yStartPos1 == 900 && tempP1> 10)
                {
                    int temp2 = tempP1- 10;
                    yStartPos1 = yStartPos1 - (82 * temp2);
                    xStartPos1 = 66;
                    tempP1= temp2;
                }
                else if (xStartPos1 == 66 && tempP1<= 10)
                {
                    yStartPos1 = yStartPos1 - (82 * diceRollP1);
                    xStartPos1 = 66;
                }

                //boven
                else if (xStartPos1 == 66 && tempP1> 10)
                {
                    int temp2 = tempP1- 10;
                    yStartPos1 = 90;
                    xStartPos1 = xStartPos1 + (82 * temp2);
                    tempP1= temp2;
                }
                else if (yStartPos1 == 90 && tempP1<= 10)
                {
                    yStartPos1 = 90;
                    xStartPos1 = xStartPos1 + (82 * diceRollP1);
                }

                //rechts
                else if (yStartPos1 == 90 && tempP1> 10)
                {
                    int temp2 = tempP1- 10;
                    yStartPos1 = yStartPos1 + (82 * temp2);
                    xStartPos1 = 900;
                    tempP1= temp2;
                }
                else if(xStartPos1 == 900 && tempP1< 10)
                {
                    yStartPos1 = yStartPos1 + (82 * diceRollP1);
                    xStartPos1 = 900;
                }
                else if(xStartPos1 == 900 && tempP1> 10)
                {
                    int temp2 = tempP1- 10;
                    yStartPos1 = 900;
                    xStartPos1 = xStartPos1 - (82 * temp2);
                    tempP1= temp2;

                }
                else if(xStartPos1 == 900 && tempP1== 10)
                {
                    xStartPos1 = 900;
                    yStartPos1 = 900;
                }

            }
        }
        if (game::getWhosTurn() == QString("PLAYER 2"))
        {
            tempP2= tempP2+ diceRollP2;
            if (xStartPos2 == 900 && yStartPos2 == 920)
            {
                xStartPos2 = 900 - (82 * diceRollP2);
                yStartPos2 = 920;
            }
            else
            {

                //onder
                if(yStartPos2 == 920 && tempP2<= 10)
                {
                    xStartPos2 = xStartPos2 - (82 * diceRollP2);
                    yStartPos2 = 920;
                }

                //links
                else if(yStartPos2 == 920 && tempP2> 10)
                {
                    int temp3 = tempP2- 10;
                    yStartPos2 = yStartPos2 - (82 * temp3);
                    xStartPos2 = 46;
                    tempP2= temp3;
                }
                else if (xStartPos2 == 46 && tempP2<= 10)
                {
                    yStartPos2 = yStartPos2 - (82 * diceRollP2);
                    xStartPos2 = 46;
                }

                //boven
                else if (xStartPos2 == 46 && tempP2> 10)
                {
                    int temp3 = tempP2- 10;
                    yStartPos2 = 70;
                    xStartPos2 = xStartPos2 + (82 * temp3);
                    tempP2= temp3;
                }
                else if (yStartPos2 == 70 && tempP2<= 10)
                {
                    yStartPos2 = 70;
                    xStartPos2 = xStartPos2 + (82 * diceRollP2);
                }

                //rechts
                else if (yStartPos2 == 70 && tempP2> 10)
                {
                    int temp3 = tempP2- 10;
                    yStartPos2 = yStartPos2 + (82 * temp3);
                    xStartPos2 = 900;
                    tempP2= temp3;
                }
                else if(xStartPos2 == 900 && tempP2< 10)
                {
                    yStartPos2 = yStartPos2 + (82 * diceRollP2);
                    xStartPos2 = 900;
                }
                else if(xStartPos2 == 900 && tempP2> 10)
                {
                    int temp3 = tempP2- 10;
                    yStartPos2 = 900;
                    xStartPos2 = xStartPos2 - (82 * temp3);
                    tempP2= temp3;

                }
                else if(xStartPos2 == 900 && tempP2== 10)
                {
                    xStartPos2 = 900;
                    yStartPos2 = 920;
                }

            }
        }

        //create the no button
        noButton->setBrush(game::getWhosTurnColor());
        noButton->setPos(1275,925);
        scene->addItem(noButton);

        //create the yes button
        yesButton->setBrush(game::getWhosTurnColor());
        yesButton->setPos(1025,925);
        scene->addItem(yesButton);

    }

    //update text
    whosTurnText->setDefaultTextColor(game::getWhosTurnColor());
    whosTurnText->setPos(1050,35);

    //update geldbedrag
    moneyText->setPlainText("$1000");
    moneyText->setDefaultTextColor(game::getWhosTurnColor());
    moneyText->setPos(1050,70);

    //update cards button
    showCardsButton->setBrush(game::getWhosTurnColor());
    showCardsButton->setPos(1150,225);

    //update the dice button
    diceButton->setBrush(game::getWhosTurnColor());
    diceButton->setPos(1150,325);

    //update positie pion player 1
    player1Pawn->setPos(xStartPos1,yStartPos1);

    //update positie pion player 2
    player2Pawn->setPos(xStartPos2,yStartPos2);
}

void game::throwDice()
{
    //alle klik bools weer updaten
    diceButtonClicked = true;
    noButtonClicked  = false;
    yesButtonClicked = false;

    //dice gooien en resultaat in text duwen
    if (game::getWhosTurn() == QString("PLAYER 1"))
    {
        diceRollP1 = dice().gooidice();
        QString s = QStringLiteral("Je hebt het nummer %1 gegooid!").arg(diceRollP1);
        noteText = new QGraphicsTextItem(s);
        noteText->setPos(1150,500);
        scene->addItem(noteText);
    }
    if (game::getWhosTurn() == QString("PLAYER 2"))
    {
        diceRollP2 = dice().gooidice();
        QString s = QStringLiteral("Je hebt het nummer %1 gegooid!").arg(diceRollP2);
        noteText = new QGraphicsTextItem(s);
        noteText->setPos(1150,500);
        scene->addItem(noteText);
    }

    //create the next button
    nextButton->setBrush(game::getWhosTurnColor());
    nextButton->setPos(1275,925);
    scene->addItem(nextButton);
}

void game::NO()
{
    //veranderen van player
    if (game::getWhosTurn() == QString("PLAYER 1"))
    {
        setWhosTurn(QString("PLAYER 2"));
    }
    else
    {
        setWhosTurn(QString("PLAYER 1"));
    }

    //alle klik bools weer updaten
    diceButtonClicked = false;
    noButtonClicked  = true;
    yesButtonClicked = false;

    //scene zuiveren
    scene->removeItem(noteText);
    scene->removeItem(noButton);
    scene->removeItem(yesButton);

    //en terug naar start "holé"
    start();
}

void game::YES()
{
    //veranderen van player
    if (game::getWhosTurn() == QString("PLAYER 1"))
    {
        setWhosTurn(QString("PLAYER 2"));
    }
    else
    {
        setWhosTurn(QString("PLAYER 1"));
    }
    //alle klik bools weer updaten
    diceButtonClicked = false;
    noButtonClicked  = false;
    yesButtonClicked = true;

    //scene zuiveren
    scene->removeItem(noteText);
    scene->removeItem(noButton);
    scene->removeItem(yesButton);

    //en terug naar start "holé"
    start();
}

void game::showCards()
{
    showCardsMenu *window2 = new showCardsMenu;
    window2->show();
}


