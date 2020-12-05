#ifndef MONEYCARD_H
#define MONEYCARD_H

#include <card.h>

class moneyCard : public card
{
    public:
        moneyCard();
        void setHoeveelheid;
        void setKaartText;
        void kaartActie;
        string getKaartText(int num);

    private:
        string kaartText;
        int geld;
};

#endif // MONEYCARD_H
