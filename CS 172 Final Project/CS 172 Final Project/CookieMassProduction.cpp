#include "CookieMassProduction.h"

CookieMassProduction::CookieMassProduction()
{
}

void CookieMassProduction::initializeUpgrades()
{
}

string CookieMassProduction::checkForFailure()
{
	// Generate a random number to determine whether or not failure occurs.
	if (rand() % 100 < catastrophicFailureChance) {

		// Incur the effects of the failure.


		// Let the user know what happened.
		return "";

	}
	else return "";
}

string CookieMassProduction::getNameOfProductionType()
{
	return "Cookie Mass Production Facilities";
}
