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

	if (tempProfit >= upgradeCost()) {
		//purchase the type of production
	}
	else {
		cout << "Sorry you are unable to purchase that. Please make more cookies." << endl;
	}

	//hand back the modified amount of profit

	return 0;
}

void Production::initializeUpgrades()
{
}

string Production::getNameOfProductionType()
{
	return  ;
}
