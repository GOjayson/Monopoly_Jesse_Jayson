#ifndef CARD_H
#define CARD_H

#include <string>
#include "bank.h"
#include "player.h"


class card
{

    public:
        card();
        virtual void setHoeveelheid(int num) = 0;
        virtual void setCardText(string text1) = 0;
        virtual void cardActie(bank* bank1, Player* player1) = 0;
        virtual string getCardText(int num) = 0;

    private:
        string naam;
};

#endif // CARD_H

//
// zie setCardText(string text1)
// als dit geen void was dan
// zou je telkens een nieuwe functie moeten maken omdat de functie niet weet welke text je wil
// voor elke nieuwe kaart die wordt toegevoegd
// 10 kaarten? ---> 10 keer dezelfde functie met een andere naam bv:
// setCardText1(string text1)
// setCardText2(string text1)
// ...
//
