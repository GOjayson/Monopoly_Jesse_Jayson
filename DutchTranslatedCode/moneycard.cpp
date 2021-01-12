#include "moneycard.h"

moneyCard::moneyCard() : card()
{
    kaartText = "Kaart Naam";
    geld = 0;
}

void moneyCard::setHoeveelheid(int num)
{
    geld = num;
}

void moneyCard::setKaartText(string text1)
{
    kaartText = text1;
}

void moneyCard::kaartActie(bank* bank1, Player* player1)
{
    bank1->verliesGeld(geld);
    player1->krijgGeld(geld);
}

string moneyCard::getKaartText(int num)
{
    return kaartText;
}


