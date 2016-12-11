#include "upgrade.h"

Upgrade::Upgrade(long int upgradeCppmAdditive, double upgradeCppmMultiplicative, long int upgradeRiskFactorAdditive, double upgradeRiskFactorMultiplicative, long int upgradeSellPriceAdditive, double upgradeSellPriceMultiplicative, long int upgradeProductionCostAdditive, double upgradeProductionCostMultiplicative, string upgradeName, long int upgradeCost, string upgradeDescription)
{
	this->upgradeCppmAdditive = upgradeCppmAdditive;
	this->upgradeCppmMultiplicative = upgradeCppmMultiplicative;

	this->upgradeRiskFactorAdditive = upgradeRiskFactorAdditive;
	this->upgradeRiskFactorMultiplicative = upgradeRiskFactorMultiplicative;

	this->upgradeSellPriceAdditive = upgradeSellPriceAdditive;
	this->upgradeSellPriceMultiplicative = upgradeSellPriceMultiplicative;

	this->upgradeProductionCostAdditive = upgradeProductionCostAdditive;
	this->upgradeProductionCostMultiplicative = upgradeProductionCostMultiplicative;

	upgradeName = "";

	upgradeCost = 0;

	upgradeDescription = "";
}

long int Upgrade::activeUpgrade(Production * productionMethod)
{
	return 0;
}

void Upgrade::displayUpgradeParameters()
{
    
}

long int Upgrade::getUpgradeCost()
{
	return upgradeCost;
}
