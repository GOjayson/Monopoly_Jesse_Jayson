#include "moneycard.h"

moneyCard::moneyCard() : card()
{
    kaartText = "Kaart Naam";
    geld = 0;
}

void setHoeveelheid(int num)
{
    geld = num;
}

void setKaartText(string text1)
{
    kaartText = text1;
}

void kaartActie(bank* bank1, player* player1)
{
    bank1->verliesGeld(geld);
    player1->krijgGeld(geld);
}

string getKaartText(int num)
{
    return kaartText;
}


