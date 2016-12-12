#pragma once

#include "upgrade.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

class Upgrade;

class Production {
protected:
	long long int cookiesProduced;
	long long int cookieSellValue;
	long long int productionCost;
	int catastrophicFailureChance;
	vector <Upgrade*> * upgrades = new vector <Upgrade*>;
	bool activated;
	long long int initialCost;

public:

	// The destructor which deletes all objects allocated to the heap.
	~Production();

	long long int calculateMonthlyProfit();

	virtual string checkForFailure();

	virtual void initializeUpgrades();

	virtual string getNameOfProductionType();

	long long int getCookiesProduced();

	void setCookiesProduced(long long int cookiesProduced);

	long long int getCookieSellValue();

	void setCookieSellValue(long long int cookieSellValue);

	long long int getProductionCost();

	void setProductionCost(long long int productionCost);

	int getCatastrophicFailureChance();

	void setCatastrophicFailureChance(int catastrophicFailureChance);

	long long int getInitialCost();

	vector <Upgrade*> * getUpgrades();
};
