#include "Owner.h"

Owner::Owner()
{
    cookiesProduced = 700;
    cookieSellValue = 1;
    productionCost = 500;
    catastrophicFailureChance = 5;
    initializeUpgrades();
    initialCost = 0;
}

void Owner::initializeUpgrades()
{
	upgrades->push_back(new Upgrade(225, 1, 0, 1, 0, 1, 50, 1, "Electric mixer", 100, "Increases overall cookie production by 225.  Slightly increases cost of production."));
	upgrades->push_back(new Upgrade(0, 1, 0, 1, 2, 1, 0, 2, "Exotic ingredients", 400, "Increases sell price of cookies by 2, but doubles production cost."));
	upgrades->push_back(new Upgrade(0, 2, 2, 1, 0, 1, 0, 1, "Faster ovens", 1000, "Doubles both cookie production and risk factor."));
	upgrades->push_back(new Upgrade(0, 1, -5, 1, 0, 1, 0, 1, "Asbestos oven mitts", 2000, "Moderately decreases risk factor (as well as your lifespan)"));
	upgrades->push_back(new Upgrade(0, 2, 0, 1, 0, 1, 0, 1.25, "Moar Ovens", 4000, "Doubles production and increases cost of production by 25%"));
	upgrades->push_back(new Upgrade(0, 2, 0, 1, 0, 1, 0, 1.25, "Even MOAR Ovens", 8000, "Doubles production once more and increases cost of production by 25%"));
	upgrades->push_back(new Upgrade(0, 2, 0, 1, 0, 1, 0, 1.25, "ALL OF THE OVENS", 16000, "Doubles production yet again and increases cost of production by 25%"));
	upgrades->push_back(new Upgrade(0, 5, 0, 1, 0, 5, 0, 1, "Monastic Cookie Training", 250000, "Master the art of baking in a mountain-top temple. \n Quintuples cookie production and sell value."));

}

string Owner::checkForFailure()
{

	// Generate a random number to determine whether or not failure occurs.
	if (rand() % 100 < catastrophicFailureChance) {
		
		// Incur the effects of the failure.
		cookiesProduced -= 100;

		// Let the user know what happened.
        return "You burned your hand on a hot cookie sheet. Your cookie production has been reduced by 100 cppm.\n";

	}
	else return "";

}

string Owner::getNameOfProductionType()
{
	return "Owner";
}
