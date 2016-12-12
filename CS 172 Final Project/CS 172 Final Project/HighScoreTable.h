#pragma once

// Pre-Processor Directives
#include <vector>
#include <string>
using namespace std;

// A class to store high scores in a text file and display them when necessary.
class HighScoreTable {

private:

	// A vector to hold all of the high score values as the number of months taken to complete the game.
	vector <int> * highScoreValues = new vector <int>;

	// A vector to hold the names associated with each score.
	vector <string> * highScoreNames = new vector <string>;

public:
	
	// The default constructor which merely calls the restoreTable function.
	HighScoreTable();

	// The destructor which deletes the two vector objects and calls the saveTable function.
	~HighScoreTable();

	// Prints the contents of the high score table to the screen.
	void displayTable();

	// Checks to see if a given score is better than any on the table.
	bool doesScoreQualify(int months);

	// Adds a given score to the highScoreValues vector where it belongs numerically.
	// Also prompts the user for their name and adds that to the highScoreNames vector in the appropriate location.
	void addScore(int months);

	// Reads in values for the two vectors from a text file.
	// If the text file doesn't exist, it fills the vectors with default values.
	void restoreTable();

	// Writes the contents of the two vectors to a text file.
	void saveTable();

};