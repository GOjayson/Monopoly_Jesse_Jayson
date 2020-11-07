#include "player.h"

Player::Player() // Start profiel voor spelers
{

    geld = 1000;
    locatie = 0;
    alive = 1;
    spelerNaam = "Bart";
    pionNaam = "PC";

}

// CODE VOOR GUI COORDINATEN MOETEN HIER NOG INGEVOEGD WORDEN + PION AFBEELDING

void setSpelerNaam(string inputSpelerNaam)
{
    spelerNaam = inputSpelerNaam;
}

void setPionNaam(string inputPionNaam)
{
    pionNaam = inputPionNaam;
}

void setLocatie(int locatieNummer) // loc 0 is start,....
{
    locatie = locatieNummer;
}

string getSpelerNaam()
{
    return spelerNaam;
}

void geefGeld(int hoeveelheid)
{
    geld = geld + hoeveelheid;
}

int krijgGeld()
{
    return geld
}

void pakGeld(int hoeveelheid)
{
    geld = geld - hoeveelheid;
}

void movePlayer(int hoeveelheid)
{
    locatie = locatie + hoeveelheid;
}

int getLocatie()
{
    return locatie;
}

int getPionNaam()
{
    return pionNaam;
}







