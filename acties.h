#ifndef ACTIES_H
#define ACTIES_H

#include <string>
#include <player.h>

using namespace std;

class acties
{
    public:
        // constructor
        acties();
        acties(string inputNaam);

        virtual void executeActie(Player* player1, Player* player2, int hoeveelheid) = 0;

    private:
        string naam;
};

#endif // ACTIES_H
