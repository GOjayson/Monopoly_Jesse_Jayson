#include "bank.h"

bank::bank()
{
    geld = 999999;
}

void bank::krijgGeld(int hoeveelheid)
{
    geld = geld + hoeveelheid;
}

int bank::getGeld()
{
    return geld;
}

void bank::verliesGeld(int hoeveelheid)
{
    geld = geld - hoeveelheid;
}
