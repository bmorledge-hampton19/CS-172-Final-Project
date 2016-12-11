#include "Production.h"

long int Production::calculateMonthlyProfit()
{
	int monthlyProfit = 0;

	monthlyProfit = (cookiesProduced * cookieSellValue) - productionCost;

	return monthlyProfit;
}

string Production::checkForFailure()
{
	int failureCheck;
	int tempFailure;
	tempFailure = getCatastrophicFailureChance();
	if (tempFailure >= 10) {
		failureCheck = 1;
	}
	else {
		failureCheck = 0;
	}
}

long int Production::purchaseProduction(long int currentFunds)
{
	int tempProfit;
	tempProfit = calculateMonthlyProfit();

	if (tempProfit >= getProductionCost()) {
		//purchase the type of production
	}
	else {
		cout << "Sorry you are unable to purchase that. Please make more cookies." << endl;
	}

	//hand back the modified amount of profit
	
	return 0;
}

long int Production::purchaseUpgrade(int upgradeIndex, long int currentFunds)
{
	int tempProfit;
	tempProfit = calculateMonthlyProfit();

	if (tempProfit >= (*upgrades)[upgradeIndex]->getUpgradeCost()) {
		//purchase the type of upgrade
		currentFunds = tempProfit - ((*upgrades)[upgradeIndex]->getUpgradeCost());
	}
	else {
		cout << "Sorry you are unable to purchase that. Please make more cookies." << endl;
	}

	//hand back the modified amount of profit
	

	return currentFunds;
}

void Production::initializeUpgrades()
{
}

string Production::getNameOfProductionType()
{
	return  ;
}

long int Production::getCookiesProduced()
{
	return cookiesProduced;
}
//It seemed as though for a lot of these I needed access to the production vector however
//due to the circular reference that could be created by including the menu header in production
//I avoided doing just that. some of these may also not make much sense or they do and I'm just missing
//a preprocessor directive to allow me to use what I'm using.
void Production::setCookiesProduced(long int cookiesProduced)
{
	long int cookiesProducedAdditive = (Production * productionMethod) + upgradeCppmAdditive;
	long int cookiesProducedMultiplicative = (Production* productionMethod) * upgradeCppmMultiplicative;
	cookiesProduced = cookiesProducedAdditive + cookiesProducedMultiplicative;
}

long int Production::getCookieSellValue()
{
	return cookieSellValue;
}

void Production::setCookieSellValue(long int cookieSellValue)
{
	long int cookieSellValueAdditive = (Production* productionMethod) + upgradeSellPriceAdditive;
	long int cookieSellValueMultiplicative = (Production* productionMethod) * upgradeSellPriceMultiplicative;
	cookieSellValue = cookieSellValueAdditive + cookieSellValueMultiplicative;

}

long int Production::getProductionCost()
{
	return productionCost;
}

void Production::setProductionCost(long int productionCost)
{
	long int productionCostAdditive = ;
	long int productionCostMultiplicative = ;
	productionCost = productionCostAdditive + productionCostMultiplicative;
}

int Production::getCatastrophicFailureChance()
{
	return catastrophicFailureChance;
}

void Production::setCatastrophicFailureChance(int catastrophicFailureChance)
{
	long int catastrophicFailureChanceAdditive = (Production* productionMethod) + upgradeRiskFactorAdditive;
	long int catastrophicFailureChanceMultiplicative = (Production* productionMethod) * upgradeRiskFactorMultiplicative;
	catastrophicFailureChance = catastrophicFailureChanceAdditive + catastrophicFailureChanceMultiplicative;
}

vector<Upgrade*>* Production::getUpgrades()
{
	return nullptr;
}
