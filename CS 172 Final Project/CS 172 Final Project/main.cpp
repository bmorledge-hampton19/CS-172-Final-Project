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

	while (true) {

		// Clear the screen and redraw the menu.
		system("cls");
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

	// End function.  Everything is ok!
	return 0;

}