#include "ganaaractie.h"

gaNaarActie::gaNaarActie() : acties()
{
    locatie = 0;
}

void gaNaarActie::executeActie(Player* player1, Player* player2, int hoeveelheid)
{
    player1->setLocatie(hoeveelheid);
}
