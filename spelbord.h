#ifndef SPELBORD_H
#define SPELBORD_H

#include "straateigenschappen.h"
#include "moveactie.h"
#include "player.h"

class spelBord
{
    public:

        //constructor
        spelBord();

        // functies
        void creerspeler(int numPlayers);
        void setSpelerNaam(int playerNum, string inputNaam);
        void setPion(int playerNum, string inputPion)

        string getSpelerNaam(int playerNum);
        string getPionNaam(int playerNum);

        player* getSpeler(int num);
        int getSpelerLocatie(int playerNum);
        void move(int numPlayer, int inputHoeveelheid);
        int getSpelerGeld(int playerNum);
        string straatType(int inputIndex);
        int getStraatEigenaar(int straatIndex);
        int getEigendomPrijs(int straatIndex);
        void setEigenaar(int straatIndex, int playerNum);
        int getHuur(int straatIndex);
        int getTax(int straatIndex);
        int getParking(int straatIndex);
        string getNaam(int straatIndex, int index);
        void straatUpgrade(int straatIndex);
        bool leeftSpeler(int playerNum);
        void spelerDood(int playerNum);

    private:
        straatEigenschappen straten[40];
        player* players;
        moveactie movement;



};

#endif // SPELBORD_H
