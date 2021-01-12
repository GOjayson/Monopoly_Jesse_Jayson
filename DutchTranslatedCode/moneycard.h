#ifndef MONEYCARD_H
#define MONEYCARD_H

#include <card.h>

class moneyCard : public card
{
    public:
        moneyCard();
        void setHoeveelheid(int num);
        void setKaartText(string text1);
        void kaartActie(bank* bank1, Player* player1);
        string getKaartText(int num);

    private:
        string kaartText;
        int geld;
};

#endif // MONEYCARD_H
