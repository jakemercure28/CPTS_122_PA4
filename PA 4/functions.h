#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class GameWorld{

private:
	char field[5][5];
	int score;
	string name;
	
public:
	// constructor
	GameWorld() {
		score = 0;

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {

				// initialize the game board
				field[i][j] = ' ';

			}
		}
	}

	void displayEntireWorld();
	void displayVisibleWorld();
	void displayPlayerWorld();
	void setPos();

	void setName() {
		cout << "Enter your name: ";
		cin >> name;
	}
	string getName() {
		return name;
	}
	void setScores(int value) {

		score += value;
	}
	int getScores() {
		return score;
	}

	void moveUp() {

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {

				// check if user is at the top
				if (field[i][j] == 'U' && i != 0) {
					
					// if above item is a wumpus or pitt
					if (field[i - 1][j] == 'W' || field[i - 1][j] == 'P') {
						// remove player from game board, they died
						field[i][j] = ' ';

					} // if nothing detected continue with the move
					else {
						// move player on board 
						field[i - 1][j] = 'U';
						field[i][j] = ' ';
					}
				}// if play is at the top of the board
				else if (field[i][j] == 'U' && i == 0) {
					cout << "Cant move up!\n";
					system("pause");
					system("cls");
				}
			}
		}
	}
	void moveDown() {

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {

				// check if user is at the bottom
                if (field[i][j] == 'U' && i != 4) {
					
					// if below item is a wumpus or pitt
					if (field[i + 1][j] == 'W' || field[i + 1][j] == 'P') {
						// remove player from game board, they died
						field[i][j] = ' ';

					} // if nothing detected continue with the move
					else {
						// move player on board 
						field[i + 1][j] = 'U';
						field[i][j] = ' ';
						// break from loop to avoid moving multiple times
						j = 5, i = 5;
					}
				}
				else if (field[i][j] == 'U' && i == 4) {
					cout << "Cant move down!\n";
					system("pause");
					system("cls");
				}
			}
		}
	}
	void moveRight() {

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {

				// check if user is at the right of the board
				if (field[i][j] == 'U' && j != 4) {

					// if right item is a wumpus or pitt
					if (field[i][j + 1] == 'W' || field[i][j + 1] == 'P') {
						// remove player from game board, they died
						field[i][j] = ' ';

					} // if nothing detected continue with the move
					else {
						// move player on board 
						field[i][j + 1] = 'U';
						field[i][j] = ' ';
						// break from loop to avoid moving multiple times
						j = 5, i = 5;
					}
				}
				else if (field[i][j] == 'U' && j == 4) {
					cout << "Cant move right!\n";
					system("pause");
					system("cls");
				}
			}
		}
	}
	void moveLeft() {

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {

				// check if user is at the top
				if (field[i][j] == 'U' && j != 0) {

					// if right item is a wumpus or pitt
					if (field[i][j - 1] == 'W' || field[i][j - 1] == 'P') {
						// remove player from game board, they died
						field[i][j] = ' ';

					} // if nothing detected continue with the move
					else {
						// move player on board 
						field[i][j - 1] = 'U';
						field[i][j] = ' ';
						
					}
				}
				else if (field[i][j] == 'U' && j == 0) {
					cout << "Cant move left!\n";
					system("pause");
					system("cls");
				}
			}
		}
	}
	bool haveIWon() {

		bool status = true;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {

				// if gold is located in array, user hasnt found it yet
				if (field[i][j] == 'G') {

					status = false;
				}
			}
		}
		return status;
	}
	bool amIAlive() {

		bool status = false;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {

				// find user in array, if they are not in array, they are dead
				if (field[i][j] == 'U') {
					
					status = true;
				}
			}
		}
		return status;
	}





};