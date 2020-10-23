#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dice.h"

using namespace std;
int dice()
{
    srand(time(0));
    for (int i = 0; i<10; i++)
    {
        int dice1 = (int) (1+rand()%6);
        int dice2 = (int) (1+rand()%6);
        int diceSum = dice1 + dice2;
        cout << diceSum << endl;
    }

    return 0;
}

