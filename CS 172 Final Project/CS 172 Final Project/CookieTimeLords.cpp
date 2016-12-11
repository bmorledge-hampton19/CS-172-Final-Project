#include "CookieTimeLords.h"

CookieTimeLords::CookieTimeLords()
{
}

void CookieTimeLords::initializeUpgrades()
{
}

string CookieTimeLords::checkForFailure()
{
	// Generate a random number to determine whether or not failure occurs.
	if (rand() % 100 < catastrophicFailureChance) {

		// Incur the effects of the failure.


		// Let the user know what happened.
		return "";

	}
	else return "";
}

string CookieTimeLords::getNameOfProductionType()
{
	return "Cookie Time Lords";
}
