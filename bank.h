#ifndef BANK_H
#define BANK_H

#include <string>

using namespace Intern;

class bank
{

    public:
        // Constructor
        bank();

        // functies om values te weten te komen
        int getGeld();

        // functies om values te veranderen
        void krijgGeld(int hoeveelheid);
        void verliesGeld(int hoeveelheid);

    private:

        int geld;
};

#endif // BANK_H
