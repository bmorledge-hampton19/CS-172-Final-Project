// Pre-Processor Directives
#include "Menu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


// Main function
int main() {

	// Create a new menu object.
	Menu* menu = new Menu;

	// The user's input.
	int userInput = 0;

	// keeps track of whether or not the user has given reasonable input.
	bool validInput = false;

	// A simple check to prevent the system from clearing the introduction.
	bool isFirstTime = true;

	// Give the player some introduction.
	cout << "Welcome to the grand Cookie Empire!" << endl;
	cout << "Your goal is to produce 1 trillion cookies in a single month!  Wow!" << endl;
	cout << "Start slowly, and work your way up to the top with upgrades and new production methods." << endl;
	cout << "You can do it!  Best of luck!" << endl;

	while (!menu->checkForEnding()) {

		// Clear the screen if it is not the first time through the loop.
		if (!isFirstTime) system("cls");
		
		// Reset the boolean so that the screen is cleared in the future.
		isFirstTime = false;

		// Redraw the menu.
		menu->drawMenu();

		// Reset validInput
		validInput = false;

		// Loop until the user's input is valid.
		while (!validInput) {
			// Prompt the user for input, clear the buffer, receive the input, and pass it to the menu to deal with it.
			cout << "What is your choice?";

			// Check to make sure the user gave an integer.
			while (!(cin >> userInput)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter a number.";
			}

			validInput = menu->interpretUserInput(userInput);

			// If the input was invalid, let the user know.
			if (!validInput) cout << "I'm sorry.  That input was invalid.  Please a number from the given list." << endl;
		}

	}

	// Delete the menu.
	delete menu;

	// End function.  Everything is ok!
	return 0;

}