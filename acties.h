#ifndef ACTIES_H
#define ACTIES_H

#include <string>
#include <player.h>

using namespace Intern;

class acties
{
    public:
        // constructor
        acties();
        acties(string inputNaam);

        virtual void executeActie(player* player1, player* player2, int hoeveelheid) = 0;

    private:
        string naam;
};

#endif // ACTIES_H
