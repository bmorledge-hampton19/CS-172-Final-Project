#include "upgrade.h"

Upgrade::Upgrade(long long int upgradeCppmAdditive, double upgradeCppmMultiplicative, int upgradeRiskFactorAdditive, double upgradeRiskFactorMultiplicative, long long int upgradeSellPriceAdditive, 
	double upgradeSellPriceMultiplicative, long long int upgradeProductionCostAdditive, double upgradeProductionCostMultiplicative, string upgradeName, long long int upgradeCost, string upgradeDescription)
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

long long int Upgrade::activeUpgrade(Production * productionMethod)
{
	productionMethod->setCookiesProduced((long)(productionMethod->getCookiesProduced()*upgradeCppmMultiplicative) + upgradeCppmAdditive);
    
	productionMethod->setCookieSellValue((long)(productionMethod->getCookieSellValue()*upgradeSellPriceMultiplicative) + upgradeSellPriceAdditive);
    
	productionMethod->setProductionCost((long)(productionMethod->getProductionCost()*upgradeProductionCostMultiplicative) + upgradeProductionCostAdditive);
    
	productionMethod->setCatastrophicFailureChance((long)(productionMethod->getCatastrophicFailureChance()*upgradeRiskFactorMultiplicative) + upgradeRiskFactorAdditive);
    
	return upgradeCost;
}

void Upgrade::displayUpgradeParameters()
{
	cout << upgradeName << " $" << Menu::neatlyDisplayNumber(upgradeCost) << ": " << upgradeDescription;
}

long long int Upgrade::getUpgradeCost()
{
	return upgradeCost;
}
