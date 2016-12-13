#include "BreedableCookies.h"

BreedableCookies::BreedableCookies()
{
	cookiesProduced = 6500000000;
	cookieSellValue = 280;
	productionCost = 7000000;
	catastrophicFailureChance = 5;
	initializeUpgrades();
	initialCost = 100000000000;
}

void BreedableCookies::initializeUpgrades()
{
	upgrades->push_back(new Upgrade(0, 1, 0, 1, 0, 1, 0, 1, "Cold Adaptation", 0, ""));
	upgrades->push_back(new Upgrade(0, 1, 0, 1, 0, 1, 0, 1, "Tmeperature stasis adaptation", 0, ""));
	upgrades->push_back(new Upgrade(0, 1, 0, 1, 0, 1, 0, 1, "Faster Bredding", 0, ""));
	upgrades->push_back(new Upgrade(0, 1, 0, 1, 0, 1, 0, 1, "Increased growth horomone", 0, ""));
	upgrades->push_back(new Upgrade(0, 1, 0, 1, 0, 1, 0, 1, "Survival of the best selling", 0, ""));
	upgrades->push_back(new Upgrade(0, 1, 0, 1, 0, 1, 0, 1, "", 0, ""));
}

string BreedableCookies::checkForFailure()
{
	// Generate a random number to determine whether or not failure occurs.
	if (rand() % 100 < catastrophicFailureChance) {

		// Incur the effects of the failure.


		// Let the user know what happened.
		return "";

	}
	else return "";
}

string BreedableCookies::getNameOfProductionType()
{
	return "Breedable Cookies";
}
