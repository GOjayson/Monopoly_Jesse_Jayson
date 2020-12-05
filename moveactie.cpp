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

void setHoeveelheid(int inputHoeveelheid)
{
    hoeveelheid = inputHoeveelheid;
}

void moveHoeveelheid(player *player1, int inputHoeveelheid)
{
    player->movePlayer(int inputHoeveelheid)
}

void getHoeveelheid()
{
    return hoeveelheid;
}

