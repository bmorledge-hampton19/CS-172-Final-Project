#include "BreedableCookies.h"

BreedableCookies::BreedableCookies()
{
}

void BreedableCookies::initializeUpgrades()
{
}

string BreedableCookies::checkForFailure()
{
	// Generate a random number to determine whether or not failure occurs.
	if (rand() % 100 < catastrophicFailureChance) {

		// Incur the effects of the failure.


		// Let the user know what happened.
		return "";

	}
	else return "";
}

string BreedableCookies::getNameOfProductionType()
{
	return "Breedable Cookies";
}
