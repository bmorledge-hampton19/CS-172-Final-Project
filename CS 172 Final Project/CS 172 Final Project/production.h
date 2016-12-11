#pragma once

#include "upgrade.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
//<<<<<<< HEAD
#include "upgrade.h"
#include "Menu.h"
//=======
//>>>>>>> 941928a37621e3279a44b6f672a18c9cf75b4f99
using namespace std;

class Upgrade;

class Production {
protected:
	long int cookiesProduced;
	long int cookieSellValue;
	long int productionCost;
	int catastrophicFailureChance;
	vector <Upgrade*> * upgrades = new vector <Upgrade*>;
	bool activated;
	long int initialCost;

public:
	long int calculateMonthlyProfit();

	virtual string checkForFailure();

	long int purchaseProduction(long int currentFunds);

	long int purchaseUpgrade(int upgradeIndex, long int currentFunds);

	virtual void initializeUpgrades();

	virtual string getNameOfProductionType();

	long int getCookiesProduced();

	void setCookiesProduced(long int cookiesProduced);

	long int getCookieSellValue();

	void setCookieSellValue(long int cookieSellValue);

	long int getProductionCost();

	void setProductionCost(long int productionCost);

	int getCatastrophicFailureChance();

	void setCatastrophicFailureChance(int catastrophicFailureChance);

	vector <Upgrade*> * getUpgrades();
};