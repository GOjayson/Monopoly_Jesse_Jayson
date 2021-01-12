#include "player.h"

Player::Player() // Start profiel voor spelers (wordt veranderd)
{

    geld = 1000;
    locatie = 0;
    alive = true;
    spelerNaam = "Bart";
    pionNaam = "PC";

    //Start met 0 eigendommen
    for(int i = 0; i < 40; i++)
    {
        straatIndex[i] = false;
    }

}

Player::Player(int money)
{

    geld = money;
    locatie = 0;
    alive = true;

    for(int i = 0; i < 40; i++)
    {
        straatIndex[i] = false;
    }

}

// CODE VOOR GUI COORDINATEN MOETEN HIER NOG INGEVOEGD WORDEN + PION AFBEELDING/ICON
// --> samenzitten met Jesse
// .h file erna niet vergeten

void Player::setSpelerNaam(string inputSpelerNaam) // geeft speler eigen gekozen naam
{
    spelerNaam = inputSpelerNaam;
}

void Player::setPionNaam(string inputPionNaam)  // geeft speler eigen gekozen pion
{
    pionNaam = inputPionNaam;
}

void Player::setLocatie(int locatieNummer) // loc 0 is start,....
{
    locatie = locatieNummer;
}

string Player::getSpelerNaam()  // vb: je verliest --> bart verliest
{
    return spelerNaam;
}

void Player::krijgGeld(int hoeveelheid) // Speler krijgt geld door i.e. start
{
    geld = geld + hoeveelheid;
}

int Player::getGeld() // bart heeft $300
{
    return geld;
}

void Player::verliesGeld(int hoeveelheid) // verliest geld door i.e. belastingen
{
    geld = geld - hoeveelheid;
}

void Player::movePlayer(int hoeveelheid) // Bij dobbelen
{
    locatie = (locatie + hoeveelheid) % 40; // We gebruiken een restdeling omdat de locatie zich dan automatisch reset naar 0
}

int Player::getLocatie() // bart staat op corda campus
{
    return locatie;
}

string Player::getPionNaam()// de boot
{
    return pionNaam;
}

void Player::geefStraat(int inputIndex, bool isEigenaar) // maakt speler eigenaar van straat
{
    straatIndex[inputIndex] = isEigenaar;
}

bool Player::getIsEigenaar(int inputIndex) // is speler eigenaar van?
{
    return straatIndex[inputIndex];
}

bool Player::isAlive() // check als speler leeft
{
    return alive;
}

void Player::dead() // speler heeft verloren
{
    geld = 0;
    locatie = 0;
    alive = false;
}

void Player::setGeld(int inputNum) // Om geld in te cheaten (mainly voor debugging)
{
    geld = inputNum;
}











