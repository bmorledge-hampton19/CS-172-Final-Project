// Pre-Processor Directives
#include "Menu.h"
#include "production.h"
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
			cout << i << ". " << (*productionForSale)[i]->getNameOfProductionType() << " - $" << (*productionForSale)[i]->getProductionCost() << endl;
		}

		// Also give the user the option to return to the main menu.
		cout << "0. Return to the main menu" << endl;

	}
	else if (menuState == 2) {

		// Have the user choose a production method to view upgrades from.
		cout << "Which production method do you want to purchase upgrades from?" << endl << endl;

		// Display all of the purchased production methods.
		for (int i = 0; i < (int)productionPurchased->size(); i++) {
			cout << i << ". " << (*productionPurchased)[i]->getNameOfProductionType() << endl;
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
			cout << i << ". "; 
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
			cout << i << ". " << (*productionPurchased)[i]->getNameOfProductionType() << endl;
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
	return false;
}

void Menu::purchaseProduction(int productionIndex)
{
}

void Menu::calculateMonthlyOutcome()
{
}
