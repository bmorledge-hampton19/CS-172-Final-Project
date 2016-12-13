#include "CookieTimeLords.h"

CookieTimeLords::CookieTimeLords()
{
	cookiesProduced = 80000000000000;
	cookieSellValue = 30000;
	productionCost = 300000000000000000;
	catastrophicFailureChance = 5;
	initializeUpgrades();
	initialCost = 50000000000000000;
}

void CookieTimeLords::initializeUpgrades()
{
	upgrades->push_back(new Upgrade(0, 1.25, 0, 1.34, 0, 1, 0, 1, "Tardis", 10000000000000, "Increases production but also increases risk factor"));
	upgrades->push_back(new Upgrade(0, 1, 0, 1, 0, 1.3, 0, 1.2, "Sonic Tools", 1298000000000, "Increases Sell Price but also increses overhead"));
	upgrades->push_back(new Upgrade(0, 2, 0, 1.5, 0, 1, 0, 1, "Temporal Movement", 30050000000000, "Vastly increases cookie production but also increases risk factor"));
	upgrades->push_back(new Upgrade(20000000000, 1, 0, 2, 0, 1, 0, 0.87, "Gallifrey Discovery", 40050005000700, "Massive Influx of cookies and a slight drop in overhead but a large increase in risk"));
	upgrades->push_back(new Upgrade(0, 1.66, 2, 1, 0, 1, 0, 0.83, "Gallifreyan High Council", 20030001000400, "Cookie production increase and decrease in overhead but increases risk"));
	upgrades->push_back(new Upgrade(0, 1, 0, 1, 0, 1.45, 0, 1.3, "Portal to view time itself", 100500300004005003, "Increase in sell price but increases overhead"));
	upgrades->push_back(new Upgrade(0, 1.75, 2, 1, 0, 1.35, 0, 1, "Spatial Movement", 400300070098000200, "Increase cookie price and production but also hugely increases tisk factor"));
	upgrades->push_back(new Upgrade(0, 3, 0, 2, 0, 3, 0, 1, "Continuity Bomb", 9999999999999999999, "Huge increase in cookie production and sell price with a very large increase in risk"));
}

string CookieTimeLords::checkForFailure()
{
	// Generate a random number to determine whether or not failure occurs.
	if (rand() % 100 < catastrophicFailureChance) {

		// Incur the effects of the failure.
		cookiesProduced *= 0.09;
		cookieSellValue *= 0.2;

		// Let the user know what happened.
		return "The cookie Daleks attacked your cookie timelords and it resulted in much death and destruction of your cookie Time Lords. Your cookie production is severly hampered and sell value falls immensly.\n";

	}
	else return "";
}

string CookieTimeLords::getNameOfProductionType()
{
	return "Cookie Time Lords";
}
