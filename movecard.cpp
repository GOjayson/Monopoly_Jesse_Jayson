#include "movecard.h"

movecard::movecard() : card()
{
    kaartText = "Kaart Naam";
    locatieNum = -1;
}

void setHoeveelheid(int num)
{
    locatieNum = num;
}

void setKaartText(string text1)
{
    kaartText = text1
}

void kaartActie(bank* bank1, player* player1)
{
    player1->setLocatie(locatieNum);
}

string getKaartText(int num)
{
    return kaartText;
}
