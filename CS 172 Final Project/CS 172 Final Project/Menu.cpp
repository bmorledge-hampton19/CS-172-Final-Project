// Pre-Processor Directives
#include "Menu.h"
#include "Owner.h"
#include "Bakers.h"
#include "AutomatedOvens.h"
#include "CookieMassProduction.h"
#include "BreedableCookies.h"
#include "SentientCookies.h"
#include "CookieTimeLords.h"

Menu::Menu()
{
	// Set default values.
	playerMoney = 0;
	currentCppm = 0;
	menuState = 0;
	monthsPassed = 0;

	// Put an owner object into the productionPurchased vector as the first method of production.
	productionPurchased->push_back(new Owner);

	// Fill the productionForSale vector with each of the remaining production methods.
	productionForSale->push_back(new Bakers);
	productionForSale->push_back(new AutomatedOvens);
	productionForSale->push_back(new CookieMassProduction);
	productionForSale->push_back(new BreedableCookies);
	productionForSale->push_back(new SentientCookies);
	productionForSale->push_back(new CookieTimeLords);

}

void Menu::drawMenu()
{

	// Before displaying a specific menu, display the most recent notifications and the player's current funds.  Also, reset the notifications string.
	cout << notifications << endl << endl;
	cout << "Your total funds: $" << playerMoney << endl;
	cout << "Last month you produced " << currentCppm << " cookies.";
	cout << "--------------------------------------------------" << endl;
	notifications = "";


	// Determine which menu to draw based on the menu state.
	if (menuState == 0) {

		// Give the user the four basic options from the main menu.
		cout << "--------------------------------------------" << endl;
		cout << "|What would you like to do?                |" << endl;
		cout << "|                                          |" << endl;
		cout << "|1. Purchase a new production method       |" << endl;
		cout << "|2. Purchase a new Upgrade                 |" << endl;
		cout << "|3. View statistics of a production method |" << endl;
		cout << "|4. Continue to the next month             |" << endl;
		cout << "--------------------------------------------" << endl;

	}

	else if (menuState == 1) {

		// Have the user choose a production method to purchase.
		cout << "What production method would you like to purchase?" << endl;
		
		// Display all of the production methods available for purchase along with their prices.
		for (int i = 0; i < (int)productionForSale->size(); i++) {
			cout << (i +1) << ". " << (*productionForSale)[i]->getNameOfProductionType() << " - $" << (*productionForSale)[i]->getProductionCost() << endl;
		}

		// Also give the user the option to return to the main menu.
		cout << "0. Return to the main menu" << endl;

	}

	else if (menuState == 2) {

		// Have the user choose a production method to view upgrades from.
		cout << "Which production method do you want to purchase upgrades from?" << endl << endl;

		// Display all of the purchased production methods.
		for (int i = 0; i < (int)productionPurchased->size(); i++) {
			cout << (i+1) << ". " << (*productionPurchased)[i]->getNameOfProductionType() << endl;
		}

		// Also give the user the option to return to the main menu.
		cout << "0. Return to the main menu" << endl;

	}

	else if (menuState == 3) {

		// Create a temporary pointer to the Upgrade vector being accessed. (Just for convenience)
		vector <Upgrade*> * upgrade = (*productionPurchased)[currentProductionAccessing]->getUpgrades();

		// Have the user choose an upgrade to purchase.
		cout << "Which upgrade whould you like to purchase?" << endl << endl;

		// Display all of the available upgrades, along with a description of each of their effects and prices.
		for (int i = 0; i < (int)upgrade->size(); i++) {
			cout << (i+1) << ". "; 
			(*upgrade)[i]->displayUpgradeParameters();
			cout << endl;
		}
		
		// Also give the user the option to return to the main menu.
		cout << "0. Return to the main menu" << endl;

	}

	else if (menuState == 4) {

		// Have the user choose a production method to view its stats.
		cout << "Which prodcution method do you want to view stats for?" << endl << endl;

		// Display all of the purchased production methods.
		for (int i = 0; i < (int)productionPurchased->size(); i++) {
			cout << (i+1) << ". " << (*productionPurchased)[i]->getNameOfProductionType() << endl;
		}

		// Also give the user the option to return to the main menu.
		cout << "0. Return to the main menu" << endl;

	}

	else if (menuState == 5) {

		// Create a temporary pointer to the production method object being used. (Just for convenience)
		Production* production = (*productionPurchased)[currentProductionAccessing];

		// Display the parameters for the chosen production method.
		cout << "Statistics for " << production->getNameOfProductionType() << ":" << endl << endl;

		cout << "Expected cookies produced per month: " << production->getCookiesProduced() << endl;
		cout << "Expected sale price for cookies: $" << production->getCookieSellValue() << endl;
		cout << "Expected cost of production per month: $" << production->getProductionCost() << endl;
		cout << "Expected monthly profit: $" << (production->getCookiesProduced() * production->getCookieSellValue() - production->getProductionCost()) << endl;
		
		cout << "Danger of catastrophic failure for production type: ";

		// Display the danger of failure as none, low, moderate, high, or very high based on the percent chance (which the user can't see).
		if (production->getCatastrophicFailureChance() == 0) cout << "None";
		else if (production->getCatastrophicFailureChance() <= 5) cout << "Low";
		else if (production->getCatastrophicFailureChance() <= 10) cout << "Moderate";
		else if (production->getCatastrophicFailureChance() <= 20) cout << "High";
		else cout << "Very High";
		cout << endl;

		// Tell the user how to return to the main menu.
		cout << "Enter 0 to Return to the main menu" << endl;
		

	}

}

bool Menu::interpretUserInput(char input)
{

	// First, if the user's input is 0, transport them back to the main menu.
	if (input == 0) {
		menuState = 0;
		return true;
	}

	// Otherwise, check the current "menuState" to determine how to handle input.
	else if (menuState == 0) {

		// Switch to the menu for purchasing production methods if the first option was chosen.
		if (input == 1) {
			menuState = 1;
			return true;
		}

		// Switch to the menu for choosing a production method to purchase upgrades from.
		else if (input == 2) {
			menuState = 2;
			return true;
		}

		// Switch to the menu for choosing a production method to view statistics for.
		else if (input == 3) {
			menuState = 4;
			return true;
		}

		// Advance to the next month.
		else if (input == 4) {
			calculateMonthlyOutcome();
			return true;
		}

	}

	else if (menuState == 1) {

		// Check to see if the user's input falls within the range of possible values, given the number of production methods available for purchase.
		if (input > 0 && input <= productionForSale->size()) {

			// Attempt to purchase the given method of production, letting the user know the result of the purchase (success/failure) and purchasing it if necessary.
			if ((*productionForSale)[input - 1]->getInitialCost() <= playerMoney) {
				notifications = "You successfully purchased the " + (*productionForSale)[input - 1]->getNameOfProductionType() + " production method.";
				purchaseProduction(input - 1);
			}
			else {
				notifications = "You do not have enough money to purchase the " + (*productionForSale)[input - 1]->getNameOfProductionType() + " production method.";
			}
			return true;

		}

	}

	else if (menuState == 2) {

		// Check to see if the user's input falls within the range of possible values, given the number of purchased production methods.
		if (input > 0 && input <= productionPurchased->size()) {

			// Change the currentProductionAccessing variable according to the user's input, and change the menu state to choose an upgrade from the selected production method.
			currentProductionAccessing = (input - 1);
			menuState = 3;
			return true;
		}

	}

	else if (menuState == 3) {

		// Create a temporary pointer to the Upgrade vector being accessed. (Just for convenience)
		vector <Upgrade*> * upgrade = (*productionPurchased)[currentProductionAccessing]->getUpgrades();

		// Check to see if the user's input falls within the range of possible values, given the number of upgrades available for purchase.
		if (input > 0 && input <= upgrade->size()) {

			// Attempt to purchase the given upgrade, letting the user know the result of the purchase (success/failure) and activating it if necessary.
			if ((*upgrade)[input - 1]->getUpgradeCost() <= playerMoney) {
				notifications = "You successfully purchased the upgrade.";
				purchaseUpgrade(input - 1);
			}
			else {
				notifications = "You do not have enough money to purchase the upgrade.";
			}
			return true;
			
		}

	}

	else if (menuState == 4) {

		// Check to see if the user's input falls within the range of possible values, given the number of purchased production methods.
		if (input > 0 && input <= productionPurchased->size()) {

			// Change the currentProductionAccessing variable according to the user's input, and change the menu state to view stats for the selected production method.
			currentProductionAccessing = (input - 1);
			menuState = 5;
			return true;
		}

	}

	// If none of the checks determined that the input was valid, return false.
	return false;

}

void Menu::purchaseProduction(int productionIndex)
{
	// Subtract the cost of the production from the player's funds.
	playerMoney -= (*productionForSale)[productionIndex]->getInitialCost();

	// Move the production method over to the "purchased" vector and delete it from the "for sale" vector.
	productionPurchased->push_back((*productionForSale)[productionIndex]);
	productionForSale->erase(productionForSale->begin() + productionIndex);
}

void Menu::purchaseUpgrade(int upgradeIndex)
{
	// Create a temporary pointer to the Upgrade vector being accessed. (Just for convenience)
	vector <Upgrade*> * upgrade = (*productionPurchased)[currentProductionAccessing]->getUpgrades();

	// Subtract the cost of the production from the player's funds, and activate it.
	playerMoney -= (*upgrade)[upgradeIndex]->activeUpgrade((*productionPurchased)[currentProductionAccessing]);

	// Remove the upgrade from the list of available upgrades.
	upgrade->erase(upgrade->begin() + upgradeIndex);

}

void Menu::calculateMonthlyOutcome()
{

	// An integer to keep track of this month's profit.
	long long int monthlyProfit = 0;

	// Reset the cookies produced per month counter to 0.
	currentCppm = 0;

	// Start generating the notification string. (It will end up being multiple lines long.)
	notifications = "This month's results:\n\n";

	// Run through each production method, generating profit, adding to the total number of cookies produced and checking for catastrophic failure.
	for (int i = 0; i < productionPurchased->size(); i++) {

		// Add this production method's parameters to the two counter variables.
		currentCppm += (*productionPurchased)[i]->getCookiesProduced();
		monthlyProfit += (*productionPurchased)[i]->calculateMonthlyProfit();

		// Add the results to the notifications.
		notifications += "Your " + (*productionPurchased)[i]->getNameOfProductionType() + " produced ";
		notifications += (*productionPurchased)[i]->getCookiesProduced() + " cookies which sold for $";
		notifications += (*productionPurchased)[i]->calculateMonthlyProfit() + ".\n";
		
		// Check for catastrophic failure, adding its information to notifications if necesarry.
		notifications += (*productionPurchased)[i]->checkForFailure();

	}

	// Add the totals to notifications.
	notifications += "\nIn total, you produced "; 
	notifications += currentCppm + " cookies which sold for $";
	notifications += monthlyProfit + ".";

	// Update playerMoney
	playerMoney += monthlyProfit;

}
