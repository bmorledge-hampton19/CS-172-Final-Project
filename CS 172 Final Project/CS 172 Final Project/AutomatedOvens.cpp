#include "AutomatedOvens.h"

AutomatedOvens::AutomatedOvens()
{
}

void AutomatedOvens::initializeUpgrades()
{
}

string AutomatedOvens::checkForFailure()
{
	// Generate a random number to determine whether or not failure occurs.
	if (rand() % 100 < catastrophicFailureChance) {

		// Incur the effects of the failure.


		// Let the user know what happened.
		return "";

	}
	else return "";
}

string AutomatedOvens::getNameOfProductionType()
{
	return "Automated Ovens";
}
