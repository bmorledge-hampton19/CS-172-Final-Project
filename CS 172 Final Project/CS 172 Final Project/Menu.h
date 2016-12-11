#pragma once

// Pre-Processor Directives
#include "Production.h"
#include "HighScoreTable.h"
#include <vector>
#include <string>
using namespace std;

// A class for handling all of the user input and text being displayed to the user.
// Also brings together all of the Production objects and sends information
class Menu {

private:

	// A vector to keep track of all of the Production objects that have been purchased.
	vector <Production*> * productionPurchased = new vector <Production*>;

	// A vector to keep track of all of the Production objects that have yet to be purchased.
	vector <Production*> * productionForSale = new vector <Production*>;

	// Keeps track of the funds available to the player.
	long long int playerMoney;

	// Keeps track of the cookies produced each month.
	long int currentCppm;

	// Keeps track of the current production object being accessed for purchasing upgrades.
	int currentProductionAccessing;

	// Keeps track of what phase the menu is currently in as follows:
	// 0 = Main menu where the user chooses to buy production, buy upgrades, look at current production, or advance to the next month.  Also displays last month's stats.
	// 1 = Menu where the user is choosing a production method to purchase.
	// 2 = Menu where the user is choosing a purchased production method to purchase upgrades from.
	// 3 = Menu where the user is choosing an upgrade to purchase from a previously selected production method.
	// 4 = Menu where the user is choosing a purchased production method to look at its stats.
	// 5 = Menu where the user is viewing the stats of a purchased production method.
	int menuState;

	// The high score table that shows the fastest times to reach 1,000,000 cookies produced in a month.
	HighScoreTable* highScoreTable = new HighScoreTable;

	// Keeps track of how many months have passed since the beginning of the game.
	int monthsPassed;

	// Text displayed at the top of a menu to notify the user of the results of recent events.
	string notifications;

public:

	// Constructs the menu object with default values.  See implementation for more info.
	Menu();

	// Draws the menu according to the current menuState.
	void drawMenu();

	// Given the user's input, takes action based on the menu state if the input merits it, and returns true for valid input and false for invalid input.
	bool interpretUserInput(int input);

	// Activates a production method, moving it from the ForSale vector to the Purchased vector.
	void purchaseProduction(int productionIndex);

	// Activates an upgrade, applying its affects to its production method and removing it from its production method's upgrades vector.
	void purchaseUpgrade(int upgradeIndex);

	// Determine the results of a month based on each of the production method's parameters.
	void calculateMonthlyOutcome();

};