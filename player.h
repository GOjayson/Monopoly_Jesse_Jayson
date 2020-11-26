#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player
{

    public:
        // Constructor
        Player();
        Player(int money);

        // functies om values te weten te komen
        string getSpelerNaam();
        int getGeld();
        int getLocatie();
        string getPionNaam();
        bool getIsEigenaar(int inputIndex);
        bool isAlive()

        // functies om values te veranderen
        void setSpelerNaam(string inputSpelerNaam);
        void setPionNaam(string inputPionNaam);
        void setLocatie(int locatieNummer);
        void krijgGeld(int hoeveelheid);
        void verliesGeld(int hoeveelheid);
        void movePlayer(int hoeveelheid);
        void geefStraat(int inputIndex, bool isEigenaar);
        void setGeld(int inputNum);

        // andere functies
        void dead();

    private:
        int geld;
        int locatie;
        bool alive;
        string spelerNaam;
        string pionNaam;
        bool straatIndex[40];





};

#endif // PLAYER_H
