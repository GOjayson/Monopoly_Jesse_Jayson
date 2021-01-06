#ifndef GANAARACTIE_H
#define GANAARACTIE_H

#include "acties.h"
#include "player.h"


class gaNaarActie : public acties
{

    public:
        gaNaarStart();
        void executeActie(player* player1, player* player2, int hoeveelheid);

    private:
        int locatie;
};

#endif // GANAARACTIE_H
