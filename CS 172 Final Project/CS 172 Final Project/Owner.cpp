#include "Owner.h"

Owner::Owner()
{
    cookiesProduced = 700;
    cookieSellValue = 1;
    productionCost = 500;
    catastrophicFailureChance = 15;
    initializeUpgrades();
    initialCost = 0;
}

void Owner::initializeUpgrades()
{
    Upgrade* Upgrade1 = new Upgrade(225, 0, 
}

string Owner::checkForFailure()
{
    int
}

string Owner::getNameOfProductionType()
{
	return string();
}
