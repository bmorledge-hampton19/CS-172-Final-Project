#include "AutomatedOvens.h"

AutomatedOvens::AutomatedOvens()
{
    coockiesProduced = 5000;
    cookieSellValue = 8;
    productionCost = 3500;
    catastrophicFailureChance = 20;
    initializeUpgrades();
    initialCost = 1000000;
}

void AutomatedOvens::initializeUpgrades()
{
    upgrades->push_back(new Upgrade(0, 0, 0, 0, 0, 0, 0, 0, "Maintennce Guy", 0, ""))
    upgrades->push_back(new Upgrade(600, 0, 0, 0, 0, 0, 200, 0, "Cookie Almost-Perfection Sensor", 300000, "increase overall cookie production by 700 cookies, but increases cost of production\n"));
    upgrades->push_back(new Upgrade(0, 0, 4, 0, 0, 1.35, 100, 0, "Cookie Perfection Detecting Eye Implant", 500000, "Increases the sell price of cookies by 4, but increases the risk factor and slightly increase production cost")
}

string AutomatedOvens::checkForFailure()
{
	// Generate a random number to determine whether or not failure occurs.
	if (rand() % 100 < catastrophicFailureChance) {

		// Incur the effects of the failure.


		// Let the user know what happened.
        return "Your beloved titanium automated ovens stopped automatically funneling perfectly\n baked cookies in the sale containers. your cookie production has been decreased by\n 1500 and your production cost has increased by 1000.\n";

	}
	else return "";
}

string AutomatedOvens::getNameOfProductionType()
{
	return "Automated Ovens";
}
