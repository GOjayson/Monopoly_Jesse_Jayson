#ifndef MOVECARD_H
#define MOVECARD_H

#include <card.h>

class movecard : public card
{
    public:
        movecard();
        void setHoeveelheid(int num);
        void setKaartText(string text1);
        void kaartActie(bank* bank1, Player* player1);
        string getKaartText(int num);

    private:
        string kaartText;
        int locatieNum;
};

#endif // MOVECARD_H
