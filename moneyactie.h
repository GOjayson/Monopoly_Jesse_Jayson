#ifndef MONEYACTIE_H
#define MONEYACTIE_H

#include "player.h"
#include "bank.h"
#include "acties.h"


class moneyactie : public acties
{
    public:

        // constructor
        moneyactie();
        moneyactie(string keuzeNaam);
        moneyactie(string keuzeNaam, int geldInput);

        //functies
        void betaalGeld(player *player1, player *player2, int hoeveelheid);
        int getGeld();
        void exeActie(player* player1, Player* player2, int hoeveelheid);
        void bankVerliest(player* player1, bank* bank1, int hoeveelheid);
        void bankKrijgt(player* player1, bank* bank1, int hoeveelheid);

    private:
        int geld;

};

#endif // MONEYACTIE_H
