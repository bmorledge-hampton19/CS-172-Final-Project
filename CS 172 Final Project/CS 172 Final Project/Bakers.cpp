#include "Bakers.h"

Bakers::Bakers()
{
	
	// Default values and initial cost
	cookiesProduced = 5000;
	cookieSellValue = 2;
	productionCost = 2000;
	catastrophicFailureChance = 5;
	initialCost = 10000;
	initializeUpgrades();

}

void Bakers::initializeUpgrades()
{

	// These upgrades will be structured on a risk-return system.  You can give your employees a raise at any time to mitigate the risk incurred by upgrades, but where's the fun in that?
	upgrades->push_back(new Upgrade(0, 3, 10, 1, 0, 1, 0, 1, "Midnight Shifts", 20000, "Make your bakers work into the night!\n Triples production, but they won't be happy about it..."));
	upgrades->push_back(new Upgrade(0, 1, 10, 1, 0, 3, 0, 1, "Quality Control", 100000, "Add supervisors to make sure your cookies are top notch!\n They'll sell for 3 times as much, but you're bakers won't be happy about it..."));
	upgrades->push_back(new Upgrade(0, 1, 10, 1, 0, 1, 0, .5, "Pay Cuts", 0, "Cut your employees wages in half! Free of charge!\n They're not going to like it though..."));
	upgrades->push_back(new Upgrade(5000, 1, 10, 1, 0, 1, 0, 1, "Nepotism", 10000, "Employ your relatives for a boost in production! Gives +5000 cppm. \n However, your bakers will be displeased by your favoritism."));
	upgrades->push_back(new Upgrade(5000, 1, 10, 1, 0, 1, 0, 1, "NO BREAKS!", 25000, "Make your employees work around the clock! Gives +5000 cppm. \n Beware of rebellion..."));
	upgrades->push_back(new Upgrade(0, 1, 10, 1, 2, 1, 0, 1, "Hazardous Ingredients", 50000, "Add ingredients that make your cookies extra delicious\n at the risk of your baker's health. +2 value. Increases cookie value by 3, but angers bakers."));
	upgrades->push_back(new Upgrade(0, 1, 10, 1, 2, 1, 0, 1, "Remove Employee Discounts", 125000, "All cookies are full price all the time! \n +2 value, but unhappiness abounds..."));
	upgrades->push_back(new Upgrade(0, 1, 10, 1, 0, 1, -1500, 1, "No Health Benefits!", 100000, "Pay off your employees to abandon them when they're in need! \n -1500 to production cost, but you (and your bakers) will regret it later..."));
	
	upgrades->push_back(new Upgrade(0, 1, -20, 1, 0, 1, 0, 1.4, "Raises For All!", 0, "Increaes your employees' pay by 40% to make them happier."));
	upgrades->push_back(new Upgrade(0, 1, -20, 1, 0, 1, 0, 1.2, "Oprah Winfrey", 50000, "You get a 20% raise!  You get a 20% raise! \n Everyone gets a 20% raise!"));
	upgrades->push_back(new Upgrade(0, 1, -20, 1, 0, 1, 2000, 1, "Holiday Bonuses", 0, "Give everyone a Christmas Bonus!  Hooray! \n +2000 Production Cost."));
	upgrades->push_back(new Upgrade(0, 1, -20, 1, 0, 1, 0, 1, "Money Confetti Cannons", 1000000, "Spray money on your employees! WOOOO HOOOO!!!"));

}

string Bakers::checkForFailure()
{
	// Generate a random number to determine whether or not failure occurs.
	if (rand() % 100 < catastrophicFailureChance) {

		// Incur the effects of the failure.
		productionCost *= 1.20;

		// Let the user know what happened.
		return "You've been treating your bakers poorly and now they're on strike!\nThey're demanding a 20% raise and you have no choice but to give them one...\n";

	}
	else return "";
}

string Bakers::getNameOfProductionType()
{
	return "Bakers";
}
