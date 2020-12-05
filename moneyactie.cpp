#include "moneyactie.h"

moneyactie::moneyactie(string keuzeNaam, int geldInput) : acties(keuzeNaam)
{
    geld = geldInput;
}

moneyactie::moneyactie(string keuzeNaam) : acties(keuzeNaam) // why
{
    geld = 0;
}

moneyactie::moneyactie() : acties(keuzeNaam) // why
{
    geld = 0;
}

void betaalGeld(player *player1, player *player2, int hoeveelheid)
{
    player1->verliesGeld(hoeveelheid);
    player2->krijgGeld(hoeveelheid);
}

int getGeld()
{
    return geld;
}

void exeActie(player* player1, Player* player2, int hoeveelheid) // waarom?
{
    player1->verliesGeld(hoeveelheid);
    player2->krijgGeld(hoeveelheid);
}

void bankVerliest(player* player1, bank* bank1, int hoeveelheid)
{
    bank1->verliesGeld(hoeveelheid);
    player1->krijgGeld(hoeveelheid);
}

void bankKrijgt(player* player1, bank* bank1, int hoeveelheid)
{
    bank1->krijgGeld(hoeveelheid);
    player1->verliesGeld(hoeveelheid);
}




