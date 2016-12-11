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

	this->upgradeName = upgradeName;

	this->upgradeCost = upgradeCost;

	this->upgradeDescription = upgradeDescription;
}

long int Upgrade::activeUpgrade(Production * productionMethod)
{
	productionMethod->setCookiesProduced(productionMethod->getCookiesProduced()*upgradeCppmMultiplicative + upgradeCppmAdditive);
    
	productionMethod->setCookieSellValue(productionMethod->getCookieSellValue()*upgradeSellPriceMultiplicative + upgradeSellPriceAdditive);
    
	productionMethod->setProductionCost(productionMethod->getProductionCost()*upgradeProductionCostMultiplicative + upgradeProductionCostAdditive);
    
	productionMethod->setCatastrophicFailureChance(productionMethod->getCatastrophicFailureChance()*upgradeRiskFactorMultiplicative + upgradeRiskFactorAdditive);
    
	return upgradeCost;
}

void Upgrade::displayUpgradeParameters()
{
	cout << upgradeName << " $" << upgradeCost << ": " << upgradeDescription;
}

long int Upgrade::getUpgradeCost()
{
	return upgradeCost;
}
