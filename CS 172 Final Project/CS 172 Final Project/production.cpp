#include "Production.h"

long int Production::calculateMonthlyProfit()
{
	int monthlyProfit = 0;

	monthlyProfit = (cookiesProduced * cookieSellValue) - productionCost;

	return monthlyProfit;
}

string Production::checkForFailure()
{
    return "";
}

void Production::initializeUpgrades()
{
    
}

string Production::getNameOfProductionType()
{
	return "";
}

long int Production::getCookiesProduced()
{
	return cookiesProduced;
}

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
	return upgrades;
}
