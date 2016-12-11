#pragma once

#include "Production.h"
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Production;

class Upgrade {

private:
	//upgrade modifying values
	long long int upgradeCppmAdditive;
	double upgradeCppmMultiplicative;

	int upgradeRiskFactorAdditive;
	double upgradeRiskFactorMultiplicative;

	long long int upgradeSellPriceAdditive;
	double upgradeSellPriceMultiplicative;

	long long int upgradeProductionCostAdditive;
	double upgradeProductionCostMultiplicative;

	//upgrade parameters
	string upgradeName;
	long long int upgradeCost;
	string upgradeDescription;

public:
	//class definition
	Upgrade(long long int upgradeCppmAdditive, double upgradeCppmMultiplicative, int upgradeRiskFactorAdditive, double upgradeRiskFactorMultiplicative, long long int upgradeSellPriceAdditive, double upgradeSellPriceMultiplicative, long long int upgradeProductionCostAdditive, double upgradeProductionCostMultiplicative, string upgradeName, long long int upgradeCost, string upgradeDescription);

	//I Don't quite remember what this was supposed to do
	long long int activeUpgrade(Production* productionMethod);
	
	//I'm not entirely sure what this is supposed to do
	//If I remember correctly it was to display the upgrade parameters to the menu
	void displayUpgradeParameters();

	// Returns the cost of the upgrade.
	long long int getUpgradeCost();
};