#include "ganaaractie.h"

gaNaarActie::gaNaarActie() : actie()
{
    locatie = 0;
}

void executeActie(player* player1, player* player2, int hoeveelheid)
{
    player1->setLocatie(hoeveelheid);
}
