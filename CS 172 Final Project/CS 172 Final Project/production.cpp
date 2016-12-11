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
	this->cookiesProduced = cookiesProduced;
}

long int Production::getCookieSellValue()
{
	return cookieSellValue;
}

void Production::setCookieSellValue(long int cookieSellValue)
{
	this->cookiesProduced = cookiesProduced;

}

long int Production::getProductionCost()
{
	return productionCost;
}

void Production::setProductionCost(long int productionCost)
{
	this->productionCost = productionCost;
}

int Production::getCatastrophicFailureChance()
{
	return catastrophicFailureChance;
}

void Production::setCatastrophicFailureChance(int catastrophicFailureChance)
{
    this->catastrophicFailureChance = catastrophicFailureChance;
}

vector<Upgrade*>* Production::getUpgrades()
{
	return nullptr;
}
