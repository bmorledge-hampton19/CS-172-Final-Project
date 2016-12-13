#include "AutomatedOvens.h"

AutomatedOvens::AutomatedOvens()
{
    cookiesProduced = 50000;
    cookieSellValue = 8;
    productionCost = 35000;
    catastrophicFailureChance = 5;
    initializeUpgrades();
    initialCost = 1000000;
}

void AutomatedOvens::initializeUpgrades()
{
	upgrades->push_back(new Upgrade(0, 1, 0, 0.55, 0, 1, 2500, 1, "Maintennce Guy", 200000, "He reduces the risk factor of your Adamantium Automated Ovens but slightly increases overhead(He's a journeyman)"));
    upgrades->push_back(new Upgrade(6000, 1, 0, 1, 0, 1, 3000, 1, "Cookie Almost-Perfection Sensor", 300000, "increase overall cookie production by 700 cookies, but increases cost of production"));
	upgrades->push_back(new Upgrade(0, 1, 4, 1, 0, 1.35, 1500, 1, "Cookie Perfection Detecting Owner Eye Implant", 500000,
		"Increases the sell price of cookies by 4, but increases the risk factor and slightly increase production cost"));
	upgrades->push_back(new Upgrade(0, 1.4, 3, 1, 0, 1, 0, 1.2, "Electric Ovens", 700000, "Ovens are electric which increases production but also slightly increases risk factor and and overhead"));
	upgrades->push_back(new Upgrade(0, 0.25, 0, 1.15, 0, 1.1, 0, 1, "Rotational Turntable", 850000, "Turntable that evenly heats the cookies. Slightly increases cookie sell price but slightly decreases production and increases risk factor."));
	upgrades->push_back(new Upgrade(0, 1.45, 2, 1, 2, 1, 0, 0.15, "Better Heating Element", 1000000, "largely increases Productoin and sell price and decreases overhead but also increases risk factor"));
	upgrades->push_back(new Upgrade(0, 1, 0, 0.75, 0, 1, 0, 1, "Smart Capabilites", 1009000, "Decreases risk factor slightly"));
	upgrades->push_back(new Upgrade(0, 1, -3, 1, 0, 1, 0, 0.9, "Active Self-Cleaning Unit", 1200000, "Decrease Risk Factor and overhead"));
	upgrades->push_back(new Upgrade(0, 1.5, 0, 0.6, 1, 1, 0, 1.05, "Better Cookie Funneling", 2000000, "Increases Cookie production and decreases risk factor but increase overhead."));
	upgrades->push_back(new Upgrade(0, 1.5, 0, 1, 0, 1, 0, 0.85, "Best Heating Element", 30000000, "largely increases cookie production and slightly decreases risk factor"));
	upgrades->push_back(new Upgrade(0, 1, -2, 1, 0, 1.55, 112500, 1, "Cookie Perfection Detecting Bakers Eye Implant", 37500000, "increases cookie sell price and decreases risk factor but it largely increases overhead"));
	upgrades->push_back(new Upgrade(0, 1.4, 0, 0.8, 0, 1, 0, 1.05, "Best Cookie Funneling", 70000000, "increases cookie production and decreases risk factor but slightly increases overhead"));
	upgrades->push_back(new Upgrade(0, 2.4, 0, 0.9, 5, 1, 0, 0.65, "Cheaper, Better Ovens", 350000000, "Vastly increases cookie production and sell price and decreases risk factor and overhead"));
}

string AutomatedOvens::checkForFailure()
{
	// Generate a random number to determine whether or not failure occurs.
	if (rand() % 100 < catastrophicFailureChance) {

		// Incur the effects of the failure.
		cookiesProduced -= 15000;
		productionCost += 10000;

		// Let the user know what happened.
        return "Your beloved Adamantium automated ovens stopped automatically funneling perfectly\n baked cookies in the sale containers. your cookie production has been decreased by\n 15000 and your production cost has increased by 10000.\n";

	}
	else return "";
}

string AutomatedOvens::getNameOfProductionType()
{
	return "Automated Ovens";
}
