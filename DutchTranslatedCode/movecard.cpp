#include "movecard.h"

movecard::movecard() : card()
{
    kaartText = "Kaart Naam";
    locatieNum = -1;
}

void movecard::setHoeveelheid(int num)
{
    locatieNum = num;
}

void movecard::setKaartText(string text1)
{
    kaartText = text1;
}

void movecard::kaartActie(bank* bank1, Player* player1)
{
    player1->setLocatie(locatieNum);
}

string movecard::getKaartText(int num)
{
    return kaartText;
}
