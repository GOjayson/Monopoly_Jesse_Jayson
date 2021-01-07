#ifndef MOVEACTIE_H
#define MOVEACTIE_H

#include "player.h"
#include "acties.h"

class moveactie : public acties
{

    public:

        //constructors
        moveactie();
        moveactie(string keuzeNaam, int inputHoeveelheid);
        moveactie(string keuzeNaam);

        // functies
        void setHoeveelheid(int inputHoeveelheid);
        void moveHoeveelheid(Player *player1, int inputHoeveelheid);
        void getHoeveelheid();

    private:

        int hoeveelheid;

};

#endif // MOVEACTIE_H
