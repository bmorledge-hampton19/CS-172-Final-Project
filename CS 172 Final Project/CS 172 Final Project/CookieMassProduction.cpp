#include "CookieMassProduction.h"

CookieMassProduction::CookieMassProduction()
{
	cookiesProduced = 500000;
	cookieSellValue = 11;
	productionCost = 700000000;
	catastrophicFailureChance = 5;
	initializeUpgrades();
	initialCost = 500000000;
}

void CookieMassProduction::initializeUpgrades()
{
	upgrades->push_back(new Upgrade(0, 1, 0, 0.85, 0, 1, 0, 1, "Many Maintenance Guys", 10000000, "Ya one wasn't really enough. Reduce Risk Factor."));
	upgrades->push_back(new Upgrade(0, 1, 0, 0.9, 0, 1, 0, 0.9, "Slightly better smoke stacks", 15000000, "slightly reduces the risk factor and overhead."));
	upgrades->push_back(new Upgrade(0, 1.15, 0, 1, 3, 1, 0, 1.2, "A Lot more automated Ovens", 30000000, "You got more of those automated adamnatium ovens. Increase production and sell price slightly but it increases overhead slightly."));
	upgrades->push_back(new Upgrade(0, 1.25, 2, 1, 0, 1, 0, 1, "Coal powered mega oven and facotry", 100000000, "increases cookie production but also increases risk factor."));
	upgrades->push_back(new Upgrade(0, 1.33, 0, 1, 0, 1, 0, 1.22, "Human Assembly line", 175000000, "Increases Production but increases overhead"));
	upgrades->push_back(new Upgrade(0, 1.25, 2, 1, 0, 1, 0, 1, "Diesel Powered mega oven and factory", 250000000, "Increases Production but increases risk factor"));
	upgrades->push_back(new Upgrade(0, 1.33, 0, 1, 0, 1, 0, 0.88, "Partially Automated Assembly line", 300000000, "Increases production and slightly reduces overhead overhead"));
	upgrades->push_back(new Upgrade(0, 1.25, 2, 1, 0, 1, 0, 1, "Solar Powered mega oven and factory", 450000000, "decreases risk factor but increases overhead"));
	upgrades->push_back(new Upgrade(0, 1, 0, 0.8, 0, 1, 0, 1.4, "A couple engineers", 6000000000, "Decreseses Risk Factor and increases overhead"));
	upgrades->push_back(new Upgrade(0, 1.33, 0, 1, 0, 1, 0, 0.88, "Fully Automated Production Line", 10000000000, "Increase in production and decrease in overhead"));
	upgrades->push_back(new Upgrade(0, 1.25, 4, 1, 0, 1, 0, 1, "Nuclear Powered mega oven and Factory", 100000000000, "vastly reduces risk factor and increases cookie production"));
	upgrades->push_back(new Upgrade(0, 1.4, 0, 1, 0, 1, 0, 1.7, "Cookie Biology research", 500000000000, "increases overhead and increases Production"));
	upgrades->push_back(new Upgrade(0, 1.8, 0, 1, 0, 1, 0, 1.6, "Cookie reproduction research", 800000000000, "incerases overhead and increases production"));
}

string CookieMassProduction::checkForFailure()
{
	// Generate a random number to determine whether or not failure occurs.
	if (rand() % 100 < catastrophicFailureChance) {

		// Incur the effects of the failure.
		cookiesProduced *= 0.75;
		cookieSellValue *= 0.35;

		// Let the user know what happened.
		return "Your Shiny new factories were stormed by the people who did not agree with the pollution that your factory is outputting.\n Your Cookie Sell Price and production per month decreases a large portion";

	}
	else return "";
}

string CookieMassProduction::getNameOfProductionType()
{
	return "Cookie Mass Production Facilities";
}
