#include "dice.h"

#include <cstdlib>
#include <ctime>

dice::dice()
{
    sides = 12; //omdat het 2 dobbelstenen zijn
}

int dice::gooidice()
{

    int roll = 0;
    roll = rand() % sides + 1;

    return roll;
}
