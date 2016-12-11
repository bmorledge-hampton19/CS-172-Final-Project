#include "upgrade.h"

Upgrade::Upgrade(long int upgradeCppmAdditive, double upgradeCppmMultiplicative, long int upgradeRiskFactorAdditive, double upgradeRiskFactorMultiplicative, long int upgradeSellPriceAdditive, double upgradeSellPriceMultiplicative, long int upgradeProductionCostAdditive, double upgradeProductionCostMultiplicative, string upgradeName, long int upgradeCost, string upgradeDescription)
{
	upgradeCppmAdditive = 0;
	upgradeCppmMultiplicative = 0;

	upgradeRiskFactorAdditive = 0;
	upgradeRiskFactorMultiplicative = 0;

	upgradeSellPriceAdditive = 0;
	upgradeSellPriceMultiplicative = 0;

	upgradeProductionCostAdditive = 0;
	upgradeProductionCostMultiplicative = 0;

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
	cout << upgradeName << " $" << upgradeCost << ": " << upgradeDescription;
}

long int Upgrade::getUpgradeCost()
{
	return upgradeCost;
}
