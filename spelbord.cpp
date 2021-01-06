#include "spelbord.h"
#include "cmath"
#include "iostream"

spelBord::spelBord()
{
    // elke straat
    // 0
    straten[0].setNaam("    GO!     ","           ");
    straten[0].setType("START");
    straten[0].setEigendomPrijs(0);
    straten[0].setParking(0);
    straten[0].setBezet(true);
    straten[0].setEigenaar(-1);
    straten[0].setHypotheek(false);
    straten[0].setTax(0);
    straten[0].setHuur(0);
    straten[0].setStraatText("     GO!     ","  Krijg $200  ");

    // 1

    straten[1].setNaam("          ","           ");
    straten[1].setType("Eigendom");
    straten[1].setEigendomPrijs(50);
    straten[1].setParking(0);
    straten[1].setBezet(false);
    straten[1].setEigenaar(-1);
    straten[1].setHypotheek(false);
    straten[1].setTax(0);
    straten[1].setHuur(0);
    straten[1].setStraatText("        ","     ");

    // 2

    straten[2].setNaam("   Community     ","     Chest      ");
    straten[2].setType("Community Chest");
    straten[2].setEigendomPrijs(0);
    straten[2].setParking(0);
    straten[2].setBezet(false);
    straten[2].setEigenaar(-1);
    straten[2].setHypotheek(false);
    straten[2].setTax(0);
    straten[2].setHuur(0);
    straten[2].setStraatText("     Pak een     ","  kaart  ");

    // 3

    straten[3].setNaam("         ","           ");
    straten[3].setType("Eigendom");
    straten[3].setEigendomPrijs(0);
    straten[3].setParking(0);
    straten[3].setBezet(false);
    straten[3].setEigenaar(-1);
    straten[3].setHypotheek(false);
    straten[3].setTax(0);
    straten[3].setHuur(0);
    straten[3].setStraatText("         ","    ");

    //4

    straten[4].setNaam("        ","           ");
    straten[4].setType("Tax");
    straten[4].setEigendomPrijs(0);
    straten[4].setParking(0);
    straten[4].setBezet(false);
    straten[4].setEigenaar(-1);
    straten[4].setHypotheek(false);
    straten[4].setTax(0);
    straten[4].setHuur(0);
    straten[4].setStraatText("          ","    ");

    // 5

    straten[5].setNaam("    GO!     ","           ");
    straten[5].setType("OV");
    straten[5].setEigendomPrijs(0);
    straten[5].setParking(0);
    straten[5].setBezet(false);
    straten[5].setEigenaar(-1);
    straten[5].setHypotheek(false);
    straten[5].setTax(0);
    straten[5].setHuur(0);
    straten[5].setStraatText("     GO!     ","  Krijg $200  ");

    //6

    straten[6].setNaam("    GO!     ","           ");
    straten[6].setType("Eigendom");
    straten[6].setEigendomPrijs(0);
    straten[6].setParking(0);
    straten[6].setBezet(false);
    straten[6].setEigenaar(-1);
    straten[6].setHypotheek(false);
    straten[6].setTax(0);
    straten[6].setHuur(0);
    straten[6].setStraatText("     GO!     ","  Krijg $200  ");

    //7

    straten[7].setNaam("    GO!     ","           ");
    straten[7].setType("Chance");
    straten[7].setEigendomPrijs(0);
    straten[7].setParking(0);
    straten[7].setBezet(false);
    straten[7].setEigenaar(-1);
    straten[7].setHypotheek(false);
    straten[7].setTax(0);
    straten[7].setHuur(0);
    straten[7].setStraatText("     GO!     ","  Krijg $200  ");

    //8

    straten[8].setNaam("    GO!     ","           ");
    straten[8].setType("Eigendom");
    straten[8].setEigendomPrijs(0);
    straten[8].setParking(0);
    straten[8].setBezet(false);
    straten[8].setEigenaar(-1);
    straten[8].setHypotheek(false);
    straten[8].setTax(0);
    straten[8].setHuur(0);
    straten[8].setStraatText("     GO!     ","  Krijg $200  ");

    //9

    straten[9].setNaam("    GO!     ","           ");
    straten[9].setType("Eigendom");
    straten[9].setEigendomPrijs(0);
    straten[9].setParking(0);
    straten[9].setBezet(false);
    straten[9].setEigenaar(-1);
    straten[9].setHypotheek(false);
    straten[9].setTax(0);
    straten[9].setHuur(0);
    straten[9].setStraatText("     GO!     ","  Krijg $200  ");

    //10

    straten[10].setNaam("    GO!     ","           ");
    straten[10].setType("Jail");
    straten[10].setEigendomPrijs(0);
    straten[10].setParking(0);
    straten[10].setBezet(false);
    straten[10].setEigenaar(-1);
    straten[10].setHypotheek(false);
    straten[10].setTax(0);
    straten[10].setHuur(0);
    straten[10].setStraatText("     GO!     ","  Krijg $200  ");

    //11

    straten[11].setNaam("    GO!     ","           ");
    straten[11].setType("Eigendom");
    straten[11].setEigendomPrijs(0);
    straten[11].setParking(0);
    straten[11].setBezet(false);
    straten[11].setEigenaar(-1);
    straten[11].setHypotheek(false);
    straten[11].setTax(0);
    straten[11].setHuur(0);
    straten[11].setStraatText("     GO!     ","  Krijg $200  ");

    //12

    straten[12].setNaam("    GO!     ","           ");
    straten[12].setType("Nutsvoorziening");
    straten[12].setEigendomPrijs(0);
    straten[12].setParking(0);
    straten[12].setBezet(false);
    straten[12].setEigenaar(-1);
    straten[12].setHypotheek(false);
    straten[12].setTax(0);
    straten[12].setHuur(0);
    straten[12].setStraatText("     GO!     ","  Krijg $200  ");

    //13

    straten[13].setNaam("    GO!     ","           ");
    straten[13].setType("Eigendom");
    straten[13].setEigendomPrijs(0);
    straten[13].setParking(0);
    straten[13].setBezet(false);
    straten[13].setEigenaar(-1);
    straten[13].setHypotheek(false);
    straten[13].setTax(0);
    straten[13].setHuur(0);
    straten[13].setStraatText("     GO!     ","  Krijg $200  ");

    //14

    straten[14].setNaam("    GO!     ","           ");
    straten[14].setType("Eigendom");
    straten[14].setEigendomPrijs(0);
    straten[14].setParking(0);
    straten[14].setBezet(false);
    straten[14].setEigenaar(-1);
    straten[14].setHypotheek(false);
    straten[14].setTax(0);
    straten[14].setHuur(0);
    straten[14].setStraatText("     GO!     ","  Krijg $200  ");

    //15

    straten[15].setNaam("    GO!     ","           ");
    straten[15].setType("OV");
    straten[15].setEigendomPrijs(0);
    straten[15].setParking(0);
    straten[15].setBezet(false);
    straten[15].setEigenaar(-1);
    straten[15].setHypotheek(false);
    straten[15].setTax(0);
    straten[15].setHuur(0);
    straten[15].setStraatText("     GO!     ","  Krijg $200  ");

    //16

    straten[16].setNaam("    GO!     ","           ");
    straten[16].setType("Eigendom");
    straten[16].setEigendomPrijs(0);
    straten[16].setParking(0);
    straten[16].setBezet(false);
    straten[16].setEigenaar(-1);
    straten[16].setHypotheek(false);
    straten[16].setTax(0);
    straten[16].setHuur(0);
    straten[16].setStraatText("     GO!     ","  Krijg $200  ");

    //17

    straten[17].setNaam("    GO!     ","           ");
    straten[17].setType("Community Chest");
    straten[17].setEigendomPrijs(0);
    straten[17].setParking(0);
    straten[17].setBezet(false);
    straten[17].setEigenaar(-1);
    straten[17].setHypotheek(false);
    straten[17].setTax(0);
    straten[17].setHuur(0);
    straten[17].setStraatText("     GO!     ","  Krijg $200  ");

    //18

    straten[18].setNaam("    GO!     ","           ");
    straten[18].setType("Eigendom");
    straten[18].setEigendomPrijs(0);
    straten[18].setParking(0);
    straten[18].setBezet(false);
    straten[18].setEigenaar(-1);
    straten[18].setHypotheek(false);
    straten[18].setTax(0);
    straten[18].setHuur(0);
    straten[18].setStraatText("     GO!     ","  Krijg $200  ");

    //19

    straten[19].setNaam("    GO!     ","           ");
    straten[19].setType("Eigendom");
    straten[19].setEigendomPrijs(0);
    straten[19].setParking(0);
    straten[19].setBezet(false);
    straten[19].setEigenaar(-1);
    straten[19].setHypotheek(false);
    straten[19].setTax(0);
    straten[19].setHuur(0);
    straten[19].setStraatText("     GO!     ","  Krijg $200  ");

    //20

    straten[20].setNaam("    GO!     ","           ");
    straten[20].setType("Parking");
    straten[20].setEigendomPrijs(0);
    straten[20].setParking(0);
    straten[20].setBezet(false);
    straten[20].setEigenaar(-1);
    straten[20].setHypotheek(false);
    straten[20].setTax(0);
    straten[20].setHuur(0);
    straten[20].setStraatText("     GO!     ","  Krijg $200  ");

    //21

    straten[21].setNaam("    GO!     ","           ");
    straten[21].setType("Eigendom");
    straten[21].setEigendomPrijs(0);
    straten[21].setParking(0);
    straten[21].setBezet(false);
    straten[21].setEigenaar(-1);
    straten[21].setHypotheek(false);
    straten[21].setTax(0);
    straten[21].setHuur(0);
    straten[21].setStraatText("     GO!     ","  Krijg $200  ");

    //22

    straten[22].setNaam("    GO!     ","           ");
    straten[22].setType("Chance");
    straten[22].setEigendomPrijs(0);
    straten[22].setParking(0);
    straten[22].setBezet(false);
    straten[22].setEigenaar(-1);
    straten[22].setHypotheek(false);
    straten[22].setTax(0);
    straten[22].setHuur(0);
    straten[22].setStraatText("     GO!     ","  Krijg $200  ");

    //23

    straten[23].setNaam("    GO!     ","           ");
    straten[23].setType("Eigendom");
    straten[23].setEigendomPrijs(0);
    straten[23].setParking(0);
    straten[23].setBezet(false);
    straten[23].setEigenaar(-1);
    straten[23].setHypotheek(false);
    straten[23].setTax(0);
    straten[23].setHuur(0);
    straten[23].setStraatText("     GO!     ","  Krijg $200  ");

    //24

    straten[24].setNaam("    GO!     ","           ");
    straten[24].setType("Eigendom");
    straten[24].setEigendomPrijs(0);
    straten[24].setParking(0);
    straten[24].setBezet(false);
    straten[24].setEigenaar(-1);
    straten[24].setHypotheek(false);
    straten[24].setTax(0);
    straten[24].setHuur(0);
    straten[24].setStraatText("     GO!     ","  Krijg $200  ");

    //25

    straten[25].setNaam("    GO!     ","           ");
    straten[25].setType("OV");
    straten[25].setEigendomPrijs(0);
    straten[25].setParking(0);
    straten[25].setBezet(false);
    straten[25].setEigenaar(-1);
    straten[25].setHypotheek(false);
    straten[25].setTax(0);
    straten[25].setHuur(0);
    straten[25].setStraatText("     GO!     ","  Krijg $200  ");

    //26

    straten[26].setNaam("    GO!     ","           ");
    straten[26].setType("Eigendom");
    straten[26].setEigendomPrijs(0);
    straten[26].setParking(0);
    straten[26].setBezet(false);
    straten[26].setEigenaar(-1);
    straten[26].setHypotheek(false);
    straten[26].setTax(0);
    straten[26].setHuur(0);
    straten[26].setStraatText("     GO!     ","  Krijg $200  ");

    //27

    straten[27].setNaam("    GO!     ","           ");
    straten[27].setType("Eigendom");
    straten[27].setEigendomPrijs(0);
    straten[27].setParking(0);
    straten[27].setBezet(false);
    straten[27].setEigenaar(-1);
    straten[27].setHypotheek(false);
    straten[27].setTax(0);
    straten[27].setHuur(0);
    straten[27].setStraatText("     GO!     ","  Krijg $200  ");

    //28

    straten[28].setNaam("    GO!     ","           ");
    straten[28].setType("Nutsvoorziening");
    straten[28].setEigendomPrijs(0);
    straten[28].setParking(0);
    straten[28].setBezet(false);
    straten[28].setEigenaar(-1);
    straten[28].setHypotheek(false);
    straten[28].setTax(0);
    straten[28].setHuur(0);
    straten[28].setStraatText("     GO!     ","  Krijg $200  ");

    //29

    straten[29].setNaam("    GO!     ","           ");
    straten[29].setType("Eigendom");
    straten[29].setEigendomPrijs(0);
    straten[29].setParking(0);
    straten[29].setBezet(false);
    straten[29].setEigenaar(-1);
    straten[29].setHypotheek(false);
    straten[29].setTax(0);
    straten[29].setHuur(0);
    straten[29].setStraatText("     GO!     ","  Krijg $200  ");

    //30

    straten[30].setNaam("    GO!     ","           ");
    straten[30].setType("GoJail");
    straten[30].setEigendomPrijs(0);
    straten[30].setParking(0);
    straten[30].setBezet(false);
    straten[30].setEigenaar(-1);
    straten[30].setHypotheek(false);
    straten[30].setTax(0);
    straten[30].setHuur(0);
    straten[30].setStraatText("     GO!     ","  Krijg $200  ");

    //31

    straten[31].setNaam("    GO!     ","           ");
    straten[31].setType("Eigendom");
    straten[31].setEigendomPrijs(0);
    straten[31].setParking(0);
    straten[31].setBezet(false);
    straten[31].setEigenaar(-1);
    straten[31].setHypotheek(false);
    straten[31].setTax(0);
    straten[31].setHuur(0);
    straten[31].setStraatText("     GO!     ","  Krijg $200  ");

    //32

    straten[32].setNaam("    GO!     ","           ");
    straten[32].setType("Eigendom");
    straten[32].setEigendomPrijs(0);
    straten[32].setParking(0);
    straten[32].setBezet(false);
    straten[32].setEigenaar(-1);
    straten[32].setHypotheek(false);
    straten[32].setTax(0);
    straten[32].setHuur(0);
    straten[32].setStraatText("     GO!     ","  Krijg $200  ");

    //33

    straten[33].setNaam("    GO!     ","           ");
    straten[33].setType("Community Chest");
    straten[33].setEigendomPrijs(0);
    straten[33].setParking(0);
    straten[33].setBezet(false);
    straten[33].setEigenaar(-1);
    straten[33].setHypotheek(false);
    straten[33].setTax(0);
    straten[33].setHuur(0);
    straten[33].setStraatText("     GO!     ","  Krijg $200  ");

    //34

    straten[34].setNaam("    GO!     ","           ");
    straten[34].setType("Eigendom");
    straten[34].setEigendomPrijs(0);
    straten[34].setParking(0);
    straten[34].setBezet(false);
    straten[34].setEigenaar(-1);
    straten[34].setHypotheek(false);
    straten[34].setTax(0);
    straten[34].setHuur(0);
    straten[34].setStraatText("     GO!     ","  Krijg $200  ");

    //35

    straten[35].setNaam("    GO!     ","           ");
    straten[35].setType("OV");
    straten[35].setEigendomPrijs(0);
    straten[35].setParking(0);
    straten[35].setBezet(false);
    straten[35].setEigenaar(-1);
    straten[35].setHypotheek(false);
    straten[35].setTax(0);
    straten[35].setHuur(0);
    straten[35].setStraatText("     GO!     ","  Krijg $200  ");

    //36

    straten[36].setNaam("    GO!     ","           ");
    straten[36].setType("Chance");
    straten[36].setEigendomPrijs(0);
    straten[36].setParking(0);
    straten[36].setBezet(false);
    straten[36].setEigenaar(-1);
    straten[36].setHypotheek(false);
    straten[36].setTax(0);
    straten[36].setHuur(0);
    straten[36].setStraatText("     GO!     ","  Krijg $200  ");

    //37

    straten[37].setNaam("    GO!     ","           ");
    straten[37].setType("Eigendom");
    straten[37].setEigendomPrijs(0);
    straten[37].setParking(0);
    straten[37].setBezet(false);
    straten[37].setEigenaar(-1);
    straten[37].setHypotheek(false);
    straten[37].setTax(0);
    straten[37].setHuur(0);
    straten[37].setStraatText("     GO!     ","  Krijg $200  ");

    //38

    straten[38].setNaam("    GO!     ","           ");
    straten[38].setType("Tax");
    straten[38].setEigendomPrijs(0);
    straten[38].setParking(0);
    straten[38].setBezet(false);
    straten[38].setEigenaar(-1);
    straten[38].setHypotheek(false);
    straten[38].setTax(0);
    straten[38].setHuur(0);
    straten[38].setStraatText("     GO!     ","  Krijg $200  ");

    //39

    straten[39].setNaam("    GO!     ","           ");
    straten[39].setType("Eigendom");
    straten[39].setEigendomPrijs(0);
    straten[39].setParking(0);
    straten[39].setBezet(false);
    straten[39].setEigenaar(-1);
    straten[39].setHypotheek(false);
    straten[39].setTax(0);
    straten[39].setHuur(0);
    straten[39].setStraatText("     GO!     ","  Krijg $200  ");

    for(int i = 0; i<40; i++)
    {
        straten[i].setHuizen(0);
    }

}

void move(int numPlayer, int inputHoeveelheid)
{
    movement.moveHoeveelheid(&(players[numPlayer]), inputHoeveelheid);
}

void creerspeler(int numPlayers)
{
    players = new Player[numPlayers]; // NEW zorgt voor memory handling
}

void setSpelerNaam(int playerNum, string inputNaam)
{
    players[playerNum].setSpelerNaam(inputNaam);
}

void setPion(int playerNum, string inputPion)
{
    players[playerNum].setPionNaam(inputPion);
}

string getSpelerNaam(int playerNum)
{
    return players[playerNum].getSpelerNaam();
}

string getPionNaam(int playerNum)
{
    return players[playerNum].getPionNaam();
}

player* getSpeler(int num)
{
    return &players[num];
}

int getSpelerLocatie(int playerNum)
{
    return players[playerNum].getLocatie();
}

int getSpelerGeld(int playerNum)
{
    return players[playerNum].getGeld();
}

string straatType(int inputIndex)
{
    return straten[inputIndex].getType();
}

int getStraatEigenaar(int straatIndex)
{
    return straten[straatIndex].getEigenaar();
}

int getEigendomPrijs(int straatIndex)
{
    return straten[straatIndex].getEigendomPrijs();
}

void setEigenaar(int straatIndex, int playerNum)
{
    straten[straatIndex].setEigenaar(playerNum);
}

int getHuur(int straatIndex)
{
    return straten[straatIndex].getHuur();
}

int getTax(int straatIndex)
{
    return straten[straatIndex].getTax();
}

int getParking(int straatIndex)
{
    return straten[straatIndex].getParking();
}

string getNaam(int straatIndex, int index)
{
    return straten[straatIndex].getNaam(index);
}

void straatUpgrade(int straatIndex)
{
    straten[straatIndex].upgrade();
}

bool leeftSpeler(int playerNum)
{
    return players[playerNum].isAlive();
}

void spelerDood(int playerNum)
{
    players[playerNum].dead()
}

