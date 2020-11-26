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
        acties(string inputNaam)

        virtual void executeActie(Player)
};

#endif // ACTIES_H
