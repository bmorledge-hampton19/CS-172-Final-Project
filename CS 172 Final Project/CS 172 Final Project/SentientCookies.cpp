#include "SentientCookies.h"

SentientCookies::SentientCookies()
{

	// Default values and initial cost
	cookiesProduced = 10000000000;
	cookieSellValue = 2500;
	productionCost =  10000000000000;
	catastrophicFailureChance = 5;
	initialCost =     50000000000000;
	initializeUpgrades();

}

void SentientCookies::initializeUpgrades()
{

	upgrades->push_back(new Upgrade(0, 2, 10, 1, 0, 2, 0, 5, "Cookie Capitalism", 25000000000000, "Teach your cookies the wonders of a free market! \n Doubles production and sale value but increases risk factor and quintuples overhead."));
	upgrades->push_back(new Upgrade(0, .75, -4, 1, 0, .75, 0, .5, "Cookie Communism", 25000000000000, "Join with the motherland, Cookie Comrade! \n Reduces production and sale value by 25% but cuts overhead in half and reduces risk factor."));
	upgrades->push_back(new Upgrade(5000000000, 1, 0, 1, 1000, 1, 0, 2, "Cosmic Cookie Program", 100000000000000, "Stimulate the economy with a space program! \n Increase production by 50,000,000,000, sell value by 1000, and overhead by 100%"));
	upgrades->push_back(new Upgrade(-2500000000, 1.30, 0, 1, -600, 1.30, 0, 1, "Ecookienomics", 100000000000000, "Unravel the science behind money-making. \n Decrease production by 2,500,000,000 and sell value by 1000 after increases both by 30%."));
	upgrades->push_back(new Upgrade(0, 1.5, 10, 1, 0, 1.5, 10000000000000, 1, "Cookie Crusades", 500000000000000, "Unleash your military might on other nations! \n Increase production and sale value by 50% but increase overhead by 10,000,000,000,000 and risk factor."));
	upgrades->push_back(new Upgrade(0, 1, 0, 1, 2000, 1, 0, 1.25, "Cookie Call to Arms", 500000000000000, "Isolate your cookies from outside civilization, making your \n cookies exotic. Increases sale value by 2000 and overhead by 25%."));
	upgrades->push_back(new Upgrade(10000000000, 3, 0, 1, 5000, 2, 0, 1, "Cookie Nationalism", 2500000000000000, "We're Number 1!! A general increase in production and sell value."));
	upgrades->push_back(new Upgrade(50000000000, 1, 0, 1, 50000, 2, 0, 1, "Cookie Union", 7500000000000000, "Peace and harmony among all cookies. \n Massive boosts to production and sell value."));

}

string SentientCookies::checkForFailure()
{
	// Generate a random number to determine whether or not failure occurs.
	if (rand() % 100 < catastrophicFailureChance) {

		// Incur the effects of the failure.
		cookiesProduced -= 1000000000;

		// Let the user know what happened.
		return "Due to political unrest, the cookies have become engaged in a brutal civil war. \nThe number of cookies being produced has consequently been reduced by 1,000,000,000\n";

	}
	else return "";
}

string SentientCookies::getNameOfProductionType()
{
	return "Sentient Cookies";
}
