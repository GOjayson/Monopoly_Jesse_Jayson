#include "dice.h"

#include <cstdlib>
#include <ctime>

namespace monopoly
{
    unsigned char dice::gooidice()
    {
        unsigned char roll = 0;
        roll = rand() % sides + (unsigned char) 1;

        return roll;
    }
}

