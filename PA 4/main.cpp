#include "functions.h"
#include <fstream>

int main() {

	char choice;
	string username;
	GameWorld game;

	//get username
	game.setName();

	//file output for game scores
	fstream data;
	data.open("GameScores.txt", ios::out);

	// time seed
	srand(time(0));

	// set postions of wumpus, player, gold and pitt
	game.setPos();

	// display user on game board
	game.displayPlayerWorld();

	// gameplay loop
	do {

		// if i have won the game, stop the game
		if (game.haveIWon() == true) {
			data << "Score for " << game.getName() << ": " << game.getScores() << endl;
			system("cls");
			cout << "\nCongrats! You found the gold. Please select an option below.\n";
			cout << "Restart game with same player\t(r)" << endl;
			cout << "Restart game with new player \t(n)" << endl;
			cout << "Quit game \t\t\t(q)" << endl;

			cin >> choice;
		}
		// if i am dead, stop the game
		else if (game.amIAlive() == false) {
			system("cls");
			cout << "You died! Please select an option...\n";
			cout << "Restart game with same player\t(r)" << endl;
			cout << "Restart game with new player \t(n)" << endl;
			cout << "Quit game \t\t\t(q)" << endl;

			cin >> choice;
		}// if i am alive continue playing
		else if (game.amIAlive() == true) {

			cout << "Enter a choice: " << endl << endl;
			cout << "Move up \t\t\t(i)" << endl;
			cout << "Move down \t\t\t(k)" << endl;
			cout << "Move left \t\t\t(j)" << endl;
			cout << "Move right \t\t\t(l)" << endl;
			cout << "Display visible world \t\t(v)" << endl;
			cout << "Display entire world(cheat) \t(c)" << endl;
			cout << "Restart game with same player\t(r)" << endl;
			cout << "Restart game with new player \t(n)" << endl;
			cout << "Quit game \t\t\t(q)" << endl;

			cin >> choice;
		}
		system("cls");

		switch (choice) {
		case 'c':
			game.displayEntireWorld();
			game.setScores(-5);
			break;
		case 'v':
			game.displayVisibleWorld();
			game.setScores(-2);
			break;
		case 'i':
			game.moveUp();
			game.setScores(5);
			game.displayPlayerWorld();
			break;
		case 'k':
			game.moveDown();
			game.setScores(5);
			game.displayPlayerWorld();
			break;
		case 'j':
			game.moveLeft();
			game.setScores(5);
			game.displayPlayerWorld();
			break;
		case 'l':
			game.moveRight();
			game.setScores(5);
			game.displayPlayerWorld();
			break;
		case 'r': // reset positions
			cout << "Game restarted... good luck!\n";
			game = GameWorld();
			game.setPos();
			game.displayPlayerWorld();
			break;
		case 'n': // reset game with new player
			cout << "Game restarted... good luck!\n"; 
			game = GameWorld();
			game.setName();
			game.setPos();
			game.displayPlayerWorld();
			break;
		}

	} while (choice != 'q');

	data.close();

	return 0;
}