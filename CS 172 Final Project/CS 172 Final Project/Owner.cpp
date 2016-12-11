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

	// Generate a random number to determine whether or not failure occurs.
	if (rand() % 100 < catastrophicFailureChance) {
		
		// Incur the effects of the failure.


		// Let the user know what happened.
		return "";

	}
	else return "";

}

string Owner::getNameOfProductionType()
{
	return "Owner";
}
