#include "functions.h"

void GameWorld::displayEntireWorld() {
	cout << "---------------------\n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {

			cout << "| " << field[i][j] << " ";
		
		}
		cout << "|" << "\n---------------------\n";
	}
}

void GameWorld::displayVisibleWorld() {

	// skip is used to skip adding spaces after the 'U' is found in the board
	int skip = 0;
	cout << "---------------------\n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {

			cout << "| ";

			// print item to the top left of user if user is not in corner
			if (field[i + 1][j - 1] == 'U' && (j != 0 || i != 0)) {

				skip = 1;
				cout << field[i][j];
				cout << " ";
			}

			// print item above user if user isnt at the top
			if (field[i + 1][j] == 'U' && i != 0) {

				skip = 1;
				cout << field[i][j];
				cout << " ";
			}

			// print item in top right corner if user isnt in corner
			if (field[i + 1][j + 1] == 'U' && (j != 4 || i != 0)) {

				skip = 1;
				cout << field[i][j];
				cout << " ";
			}

			// print item 1 space left of user
			if (field[i][j - 1] == 'U' && j != 0){
				
				skip = 1;
				cout << field[i][j];
				cout << " ";
			}

			// print user
			if (field[i][j] == 'U') {

				skip = 1;
				cout << field[i][j];
				cout << " ";
			}
			
			// print item 1 space right of user
			if (field[i][j + 1] == 'U' && j != 4) {
				skip = 1;
				cout << field[i][j];
				cout << " ";
			}

			// print item to the bottom left of user if user is not in bottom corner
			if (field[i - 1][j - 1] == 'U' && (j != 0 || i != 4)) {
				skip = 1;
				cout << field[i][j];
				cout << " ";
			}

			// print item below user if user is not at bottom 
			if (field[i - 1][j] == 'U' && i != 4) {
				skip = 1;
				cout << field[i][j];
				cout << " ";
			}

			// print item in bottom right corner if user is not at bottom right corner
			if (field[i - 1][j + 1] == 'U' && (j != 4 || i != 4)) {
				skip = 1;
				cout << field[i][j];
				cout << " ";
			}

			if (skip == 0)
			cout << "  ";
			
			skip = 0;
		}
		cout << "|" << "\n---------------------\n";
	}
	 
}

void GameWorld::setPos() {

	// set player to random position
	int x = rand() % 5, y = rand() % 5;
	field[x][y] = 'U';

	// set wumpus location on board
	// check if location contains player
	while (field[x][y] == 'U') 
	    x = rand() % 5, y = rand() % 5;
	
	field[x][y] = 'W';

	// set gold location and check if empty
	while (field[x][y] == 'U' || field[x][y] == 'W')
		x = rand() % 5, y = rand() % 5;
	
	field[x][y] = 'G';

	// set pitt locations and check if empty
	// determine random location for each pitt a random amount of times
	int pitts = (5 + rand() % 5);
	for (int i = 0; i < pitts; i++) {

		while (field[x][y] == 'U' || field[x][y] == 'W' ||
			    field[x][y] == 'G' || field[x][y] == 'P')
		    x = rand() % 5, y = rand() % 5;
			
		// set pit location
		field[x][y] = 'P';
	}
}

void GameWorld::displayPlayerWorld() {

	int skip = 0;
	cout << "---------------------\n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {

			cout << "| ";

			// print user
			if (field[i][j] == 'U') {

				skip = 1;
				cout << field[i][j];
				cout << " ";
			}
			if (skip == 0)
				cout << "  ";

			skip = 0;
		}
		cout << "|" << "\n---------------------\n";
	}
}
