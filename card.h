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
        virtual void cardActie(bank* bank1, player* player1) = 0;
        virtual string getCardText(int num) = 0;

    private:
        string naam;
};

#endif // CARD_H
