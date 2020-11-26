#include "bank.h"

bank::bank()
{
    geld = 999999;
}

void krijgGeld(int hoeveelheid)
{
    geld = geld + hoeveelheid;
}

int getGeld()
{
    return geld
}

void verliesGeld(int hoeveelheid)
{
    geld = geld - hoeveelheid;
}
