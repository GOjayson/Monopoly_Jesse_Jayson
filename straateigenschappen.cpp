#include "straateigenschappen.h"
#include <iostream>

void setNaam(string inputNaam, string inputNaam2)
{
    naam[0] = inputNaam;
    naam[1] = inputNaam2;
    huizen = 0;
}

void setStraatText(string inputStaatText, string inputStraatText2)
{
    straatText[0] = inputStaatText;
    straatText[1] = inputStraatText2;
    huizen = 0;
}

void setType(string inputType)
{
    straatType = inputType;
}

void setEigendomPrijs(int inputPrijs)
{
    eigendomPrijs = inputPrijs;
}

void setParking(int inputGeld)
{
    parking = inputGeld;
}

void setBezet(int inputBezet)
{
    bezet = inputBezet;
}

void setEigenaar(int inputEigenaar)
{
    eigendom = inputEigenaar;
}

void setHypotheek(bool inputHypotheek)
{
    hypotheek = inputHypotheek;
}

void setHuur(int inputHuur)
{
    huur = inputHuur;
}

void setTax(int inputTax)
{
    tax = inputTax
}

string getNaam(int naamIndex)
{
    return naam[naamIndex];
}

string getStraatText(int textIndex)
{
    return straatText[textIndex];
}

int getEigendomPrijs()
{
    return eigendomPrijs;
}

int getParking()
{
    return parking;
}

bool getHypotheek()
{
    return hypotheek;
}

int getHuur()
{
    return huur;
}

int getTax()
{
    return tax;
}

string getType()
{
    return straatType;
}

int getEigenaar()
{
    return eigendom;
}

int getHuizen()
{
    return huizen;
}

void setHuizen(int inputHuizen)
{
    huizen = inputHuizen;
}

bool upgrade()
{
    if(huizen < 5)
    {
        huur = huur*2;
        huizen++;
        return true;
    }

    else
    {
        return false;
    }
}
