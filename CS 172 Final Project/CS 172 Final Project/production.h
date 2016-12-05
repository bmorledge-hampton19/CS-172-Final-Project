#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "upgrade.h"
using namespace std;

class Production {
protected:
	long int cookiesProduced;
	long int cookieSellValue;
	long int productionCost;
	int catastrophicFailureChance;
	vector<Upgrade*> upgrades;
	bool activated;
	long int initialCost;

public:
	long int calculateMonthlyProfit();

	virtual void checkForFailure();

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

	vector<Upgrade*> getUpgrades();
};