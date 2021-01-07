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

void moneyactie::betaalGeld(Player *player1, Player *player2, int hoeveelheid)
{
    player1->verliesGeld(hoeveelheid);
    player2->krijgGeld(hoeveelheid);
}

int moneyactie::getGeld()
{
    return geld;
}

void moneyactie::exeActie(Player* player1, Player* player2, int hoeveelheid) // waarom?
{
    player1->verliesGeld(hoeveelheid);
    player2->krijgGeld(hoeveelheid);
}

void moneyactie::bankVerliest(Player* player1, bank* bank1, int hoeveelheid)
{
    bank1->verliesGeld(hoeveelheid);
    player1->krijgGeld(hoeveelheid);
}

void moneyactie::bankKrijgt(Player* player1, bank* bank1, int hoeveelheid)
{
    bank1->krijgGeld(hoeveelheid);
    player1->verliesGeld(hoeveelheid);
}




