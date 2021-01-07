#ifndef GANAARACTIE_H
#define GANAARACTIE_H

#include "acties.h"
#include "player.h"


class gaNaarActie : public acties
{

    public:
        gaNaarActie();
        void executeActie(Player* player1, Player* player2, int hoeveelheid);

    private:
        int locatie;
};

#endif // GANAARACTIE_H
