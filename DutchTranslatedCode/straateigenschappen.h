#ifndef STRAATEIGENSCHAPPEN_H
#define STRAATEIGENSCHAPPEN_H

#include <acties.h>


class straateigenschappen
{

    public:
        // functies om values te weten te komen
        int getHuizen();
        int getEigenaar();
        string getType();
        int getTax();
        int getHuur();
        bool getHypotheek();
        int getParking();
        int getEigendomPrijs();
        string getStraatText(int textIndex);
        string getNaam(int naamIndex);

        // functies om values te veranderen
        void setTax(int inputTax);
        void setHuur(int inputHuur);
        void setHypotheek(bool inputHypotheek);
        void setEigenaar(int inputEigenaar);
        void setBezet(int inputBezet);
        void setParking(int inputGeld);
        void setEigendomPrijs(int inputPrijs);
        void setType(string inputType);
        void setStraatText(string inputStaatText, string inputStraatText2);
        void setNaam(string inputNaam, string inputNaam2);
        void setHuizen(int inputHuizen);
        bool upgrade();

    private:
        string naam[2];
        string straatText[2];
        string straatType;
        int eigendomPrijs;
        int parking;
        int bezet;
        int eigendom;
        int hypotheek;
        int huur;
        int tax;
        int huizen;
};

#endif // STRAATEIGENSCHAPPEN_H
