#include "straateigenschappen.h"
#include <iostream>

void straateigenschappen::setNaam(string inputNaam, string inputNaam2)
{
    naam[0] = inputNaam;
    naam[1] = inputNaam2;
    huizen = 0;
}

void straateigenschappen::setStraatText(string inputStaatText, string inputStraatText2)
{
    straatText[0] = inputStaatText;
    straatText[1] = inputStraatText2;
    huizen = 0;
}

void straateigenschappen::setType(string inputType)
{
    straatType = inputType;
}

void straateigenschappen::setEigendomPrijs(int inputPrijs)
{
    eigendomPrijs = inputPrijs;
}

void straateigenschappen::setParking(int inputGeld)
{
    parking = inputGeld;
}

void straateigenschappen::setBezet(int inputBezet)
{
    bezet = inputBezet;
}

void straateigenschappen::setEigenaar(int inputEigenaar)
{
    eigendom = inputEigenaar;
}

void straateigenschappen::setHypotheek(bool inputHypotheek)
{
    hypotheek = inputHypotheek;
}

void straateigenschappen::setHuur(int inputHuur)
{
    huur = inputHuur;
}

void straateigenschappen::setTax(int inputTax)
{
    tax = inputTax;
}

string straateigenschappen::getNaam(int naamIndex)
{
    return naam[naamIndex];
}

string straateigenschappen::getStraatText(int textIndex)
{
    return straatText[textIndex];
}

int straateigenschappen::getEigendomPrijs()
{
    return eigendomPrijs;
}

int straateigenschappen::getParking()
{
    return parking;
}

bool straateigenschappen::getHypotheek()
{
    return hypotheek;
}

int straateigenschappen::getHuur()
{
    return huur;
}

int straateigenschappen::getTax()
{
    return tax;
}

string straateigenschappen::getType()
{
    return straatType;
}

int straateigenschappen::getEigenaar()
{
    return eigendom;
}

int straateigenschappen::getHuizen()
{
    return huizen;
}

void straateigenschappen::setHuizen(int inputHuizen)
{
    huizen = inputHuizen;
}

bool straateigenschappen::upgrade()
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
