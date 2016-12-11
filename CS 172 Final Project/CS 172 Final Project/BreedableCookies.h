#pragma once

#include "production.h"
#include <string>
using namespace std;

// A derivative of the Production class.
//
class BreedableCookies : public Production {

public:

	// Basic constructor which sets default values and calls the initializeUpgrades function.
	//
	BreedableCookies();

	// Creates all of the upgrade objects for the class.
	virtual void initializeUpgrades();

	// Checks to see if catastrophic failure occured.
	//
	virtual string checkForFailure();

	// Returns the name of the class.
	virtual string getNameOfProductionType();

};