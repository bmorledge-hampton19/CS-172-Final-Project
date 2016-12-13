#include "Production.h"

Production::~Production()
{
	// Delete the contents of the upgrade vector, and then delete the vector.
	for (int i = 0; i < upgrades->size(); i++) {
		delete (*upgrades)[i];
	}
	delete upgrades;
}

long long int Production::calculateMonthlyProfit()
{
	return (cookiesProduced * cookieSellValue - productionCost);
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

long long int Production::getCookiesProduced()
{
	return cookiesProduced;
}

void Production::setCookiesProduced(long long int cookiesProduced)
{
	this->cookiesProduced = cookiesProduced;
}

long long int Production::getCookieSellValue()
{
	return cookieSellValue;
}

void Production::setCookieSellValue(long long int cookieSellValue)
{
	this->cookieSellValue = cookieSellValue;

}

long long int Production::getProductionCost()
{
	return productionCost;
}

void Production::setProductionCost(long long int productionCost)
{
	this->productionCost = productionCost;
}

int Production::getCatastrophicFailureChance()
{
	return catastrophicFailureChance;
}

void Production::setCatastrophicFailureChance(int catastrophicFailureChance)
{
	if (catastrophicFailureChance < 1) this->catastrophicFailureChance = 1;
	else this->catastrophicFailureChance = catastrophicFailureChance;
}

long long int Production::getInitialCost()
{
	return initialCost;
}

vector<Upgrade*>* Production::getUpgrades()
{
	return upgrades;
}
