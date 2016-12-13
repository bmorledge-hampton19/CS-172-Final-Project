#include "BreedableCookies.h"

BreedableCookies::BreedableCookies()
{
	cookiesProduced = 6500000000;
	cookieSellValue = 280;
	productionCost = 2800000000000;
	catastrophicFailureChance = 5;
	initializeUpgrades();
	initialCost = 100000000000;
}

void BreedableCookies::initializeUpgrades()
{
	upgrades->push_back(new Upgrade(0, 1, 0, 1, 0, 1.3, 0, 1, "Cold Adaptation", 0, "increases sell price"));
	upgrades->push_back(new Upgrade(0, 1, 0, 1.2, 0, 1.66, 0, 1.33, "Tmeperature stasis adaptation", 0, "increase sell price, risk factor, and overhead"));
	upgrades->push_back(new Upgrade(0, 1.68, 0, 1.14, 0, 1, 0, 1.44, "Faster Bredding", 0, "increased cookie production, riskfactor and overhead"));
	upgrades->push_back(new Upgrade(0, 1, 0, 2, 0, 1.08, 0, 1, "Increased growth horomone", 0, "increase cookie sell price slightly but increase risk factor a lot"));
	upgrades->push_back(new Upgrade(0, 0.8, 0, 1, 0, 3, 0, 1, "Survival of the best selling", 0, "large increase in cookie sell price but a decrease in production"));
	upgrades->push_back(new Upgrade(0, 1.3, 0, 1.12, 0, 1, 0, 1.3, "Adapted Intelligence", 0, "increase production but increases risk factor and overhead"));
}

string BreedableCookies::checkForFailure()
{
	// Generate a random number to determine whether or not failure occurs.
	if (rand() % 100 < catastrophicFailureChance) {

		// Incur the effects of the failure.
		cookiesProduced *= 0.66;
		cookieSellValue *= 0.2;

		// Let the user know what happened.
		return "Your Customers begin to notice the odd abilites of your cookies and an investigative reporter\n looks in to your company and finds that you are illegally breeding cookies.\n Your production decreases and your sell price hits an all-time low";

	}
	else return "";
}

string BreedableCookies::getNameOfProductionType()
{
	return "Breedable Cookies";
}
