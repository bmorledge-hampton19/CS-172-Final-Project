#include "HighScoreTable.h"
#include <fstream>
#include <iostream>
using namespace std;

HighScoreTable::HighScoreTable()
{
	restoreTable();
}

HighScoreTable::~HighScoreTable()
{

	// Save the high score table.
	saveTable();

	// Delete objects allocated to the heap.
	delete highScoreNames;
	delete highScoreValues;

}

void HighScoreTable::displayTable()
{

	// Print out a header of sorts.
	cout << "Fastest times to reach 1,000,000,000 cookies!" << endl << endl;

	// Run through a loop and display each of the scores and names, from first to last.
	for (int i = 0; i < highScoreNames->size(); i++) {

		cout << i + 1 << ". " << (*highScoreValues)[i] << " months achieved by " << (*highScoreNames)[i];

	}

}

bool HighScoreTable::doesScoreQualify(int months)
{
	// Return whether or not the score is at least less than the highest value in the scores vector.
	return (months < highScoreValues->back());
}

void HighScoreTable::addScore(int months)
{

	// Determine where the score belongs in the table with a for loop.
	for (int i = (int)highScoreValues->size() - 1; i <= 0; i--) {
		
		// If the value at the given location is greater than the given value for months, the new score belongs in its place.
		// Everything else behind it needs to pushed back one place.
		if ((*highScoreValues)[i] > months) {

			// Insert the score into the vector at this location, and get rid of the score at the end of the vector.
			highScoreValues->insert(highScoreValues->begin() + i, months);
			highScoreValues->pop_back();

			// Now do the same for a name that the user inputs.
			string userName;
			cout << "You achieved a high score!  Input your name (no spaces please): ";
			cin >> userName;
			highScoreNames->insert(highScoreNames->begin() + i, userName);
			highScoreNames->pop_back();
			
		}

	}

}

void HighScoreTable::restoreTable()
{
	
	// The input stream to read in data from the high scores text file.
	ifstream restorer;

	// Attempt to open the highscore table's text file.
	restorer.open("HighScores.txt");

	// If the file doesn't exist, create it with some values.
	if (restorer.fail()) {

		highScoreNames->push_back("Billy");
		highScoreNames->push_back("Billy");
		highScoreNames->push_back("Billy");
		highScoreNames->push_back("Billy");
		highScoreNames->push_back("Billy");
		highScoreNames->push_back("Billy");
		highScoreNames->push_back("Billy");
		highScoreNames->push_back("Billy");
		highScoreNames->push_back("Billy");
		highScoreNames->push_back("Billy");

		highScoreValues->push_back(100);
		highScoreValues->push_back(100);
		highScoreValues->push_back(100);
		highScoreValues->push_back(100);
		highScoreValues->push_back(100);
		highScoreValues->push_back(100);
		highScoreValues->push_back(100);
		highScoreValues->push_back(100);
		highScoreValues->push_back(100);
		highScoreValues->push_back(100);

	}
	
	// Otherwise, read in values from the text file.
	else {

		// A string to keep track of the current name.
		string name;

		// An integer to keep track of the current score.
		int score;

		while (!restorer.eof()) {
			
			// Read in this lines name and score.
			cin >> name;
			cin >> score;

			// Add those values to the vector.
			highScoreNames->push_back(name);
			highScoreValues->push_back(score);

		}

	}

	// Close the input stream.
	restorer.close();

}

void HighScoreTable::saveTable()
{

	// The output stream to save data to the high scores text file.
	ofstream saver;

	// Attempt to open the highscore table's text file.
	saver.open("HighScores.txt");

	// Write the highscores into the text file.
	for (int i = 0; i < highScoreNames->size(); i++) {

		cout << (*highScoreNames)[i] << " " << (*highScoreValues)[i] << endl;

	}

	// Close the output stream.
	saver.close();

}
