#include "moveactie.h"

moveactie::moveactie(string keuzeNaam, int inputHoeveelheid) : acties(keuzeNaam)
{
    hoeveelheid = inputHoeveelheid;
}

moveactie::moveactie(string keuzeNaam) : acties(keuzeNaam)
{
    hoeveelheid = 0;
}

moveactie::moveactie() : acties()
{
    hoeveelheid = 0;
}

void moveactie::setHoeveelheid(int inputHoeveelheid)
{
    hoeveelheid = inputHoeveelheid;
}

void moveactie::moveHoeveelheid(Player *player1, int inputHoeveelheid)
{
    Player->movePlayer(int inputHoeveelheid);
}

int moveactie::getHoeveelheid()
{
    return hoeveelheid;
}

