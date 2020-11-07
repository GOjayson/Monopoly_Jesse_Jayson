#include "moveCard.h"
#include "cstdio"

int gaNaarStart()
{
    printf("Ga naar start en krijg $200./n");
    vakje(0);
    return;
}

int gaNaarTinLoverStraat()
{
    prinft("Ga naar TinLoverStraat, krijg $200 indien je voorbij start komt./n");
    vakje(13);
    return;
}

int gaNaarStukkenStraat()
{
    printf("Ga naar StukkenStraat, krijg $200 indien je voorbij start komt./n");
    vakje(24);
    return;
}

int gaNaarOV()
{
    printf("Ga naar het dichtsbijzijnste Station./n");
    ???
    return; //doe je dit best met classes? Class=station. daarna gwn zien waar je staat en dan afstand van station van elkaar aftrekken; kleinste verschil = dichtbijzinste station
}

int krijg50()
{
    printf("U krijgt $50 van de bank./n");
    geld().krijg(50).bank;
    return ;
}

int geenJail()
{
    printf("de eerstvolgende keer dat u naar jail moet gebeurt dit niet./n");
    jail(2);
    return;  // jail 0 = geen jail, jail = 1 is wel jail en jail 2 zet je instant naar jail 0 als je op jail 1 komt
}

int driePlaatsen terug
{
    printf("ga 3 vakjes terug./n");
    vakje(-3);
    return;
}

int jail()
{
    printf("Ga meteen naar jail./n");
    jail(1);
    return;
}

int belasting()
{
    printf("Betaal $15 aan belastingen./n");
    geld().betaal(15).bank;
    return;
}

int gaNaarDiamondStraat()
{
    printf("ga naar DiamondStraat./n");
    vakje(39);
    return;
}

int vrijgevig()
{
    printf("Je bent heel vrijgevig en geeft elke speler $50./n");
    geld().betaal(50).allPlayers;
    return;
}

int eigendomTax()
{
    printf("Betaal voor elk appartement $25./n");
    geld().betaal(25*appartement().totaal).bank;
    return;

}

