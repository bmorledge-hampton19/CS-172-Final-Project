#pragma once

#include "Production.h"
#include <iostream>
#include <cstring>
#include <vector>
<<<<<<< HEAD
#include "production.h"
#include "Menu.h"
=======
>>>>>>> 941928a37621e3279a44b6f672a18c9cf75b4f99
using namespace std;

class Production;

class Upgrade {

private:
	//upgrade modifying values
	long int upgradeCppmAdditive;
	double upgradeCppmMultiplicative;

	long int upgradeRiskFactorAdditive;
	double upgradeRiskFactorMultiplicative;

	long int upgradeSellPriceAdditive;
	double upgradeSellPriceMultiplicative;

	long int upgradeProductionCostAdditive;
	double upgradeProductionCostMultiplicative;

	//upgrade parameters
	string upgradeName;
	long int upgradeCost;
	string upgradeDescription;

public:
	//class definition
	Upgrade(long int upgradeCppmAdditive, double upgradeCppmMultiplicative, long int upgradeRiskFactorAdditive, double upgradeRiskFactorMultiplicative, long int upgradeSellPriceAdditive, double upgradeSellPriceMultiplicative, long int upgradeProductionCostAdditive, double upgradeProductionCostMultiplicative, string upgradeName, long int upgradeCost, string upgradeDescription);

	//I Don't quite remember what this was supposed to do
	long int activeUpgrade(Production* productionMethod);
	
	//I'm not entirely sure what this is supposed to do
	//If I remember correctly it was to display the upgrade parameters to the menu
	void displayUpgradeParameters();

	// Returns the cost of the upgrade.
	long int getUpgradeCost();
};