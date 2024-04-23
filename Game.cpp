
#include "Game.h"
#include <limits>

Game::Game()
{
}


Game::~Game() //game destructor
{
	currentSpace = NULL;//clearing all pointers
	sp11->setSides(NULL, NULL, NULL, NULL);
	sp12->setSides(NULL, NULL, NULL, NULL);
	sp13->setSides(NULL, NULL, NULL, NULL);
	sp14->setSides(NULL, NULL, NULL, NULL);
	sp15->setSides(NULL, NULL, NULL, NULL);
	//
	sp21->setSides(NULL, NULL, NULL, NULL);
	sp22->setSides(NULL, NULL, NULL, NULL);
	sp23->setSides(NULL, NULL, NULL, NULL);
	sp24->setSides(NULL, NULL, NULL, NULL);
	sp25->setSides(NULL, NULL, NULL, NULL);
	//
	sp31->setSides(NULL, NULL, NULL, NULL);
	sp32->setSides(NULL, NULL, NULL, NULL);
	sp33->setSides(NULL, NULL, NULL, NULL);
	sp34->setSides(NULL, NULL, NULL, NULL);
	sp35->setSides(NULL, NULL, NULL, NULL);
	//deleting pointers
	delete sp11;
	delete sp12;
	delete sp13;
	delete sp14;
	delete sp15;
	//
	delete sp21;
	delete sp22;
	delete sp23;
	delete sp24;
	delete sp25;
	//
	delete sp31;
	delete sp32;
	delete sp33;
	delete sp34;
	delete sp35;
	//
}

void Game::generateMap()
{
	//creating all spaces
	sp11 = new EmptySpace();
	sp12 = new PawnSpace();
	sp13 = new BishopSpace();
	sp14 = new PawnSpace();
	sp15 = new QueenSpace();
	//
	sp21 = new PawnSpace();
	sp22 = new RookSpace();
	sp23 = new PawnSpace();
	sp24 = new KnightSpace();
	sp25 = new RookSpace();
	//
	sp31 = new BishopSpace();
	sp32 = new PawnSpace();
	sp33 = new RookSpace();
	sp34 = new BishopSpace();
	sp35 = new KingSpace();
	//linking all spaces
	sp11->setSides(NULL, sp21, NULL, sp12);
	sp12->setSides(NULL, sp22, sp11, sp13);
	sp13->setSides(NULL, sp23, sp12, sp14);
	sp14->setSides(NULL, sp24, sp13, sp15);
	sp15->setSides(NULL, sp25, sp14, NULL);
	//
	sp21->setSides(sp11, sp31, NULL, sp22);
	sp22->setSides(sp12, sp32, sp21, sp23);
	sp23->setSides(sp13, sp33, sp22, sp24);
	sp24->setSides(sp14, sp34, sp23, sp25);
	sp25->setSides(sp15, sp35, sp24, NULL);
	//
	sp31->setSides(sp21, NULL, NULL, sp32);
	sp32->setSides(sp22, NULL, sp31, sp33);
	sp33->setSides(sp23, NULL, sp32, sp34);
	sp34->setSides(sp24, NULL, sp33, sp35);
	sp35->setSides(sp25, NULL, sp34, NULL);
	//setting current space
	currentSpace = sp11;
	//locating player and creating map
	playerMap[0][0] = 1;
	playerMap[0][1] = 0;
	playerMap[0][2] = 0;
	playerMap[0][3] = 0;
	playerMap[0][4] = 0;
	//
	playerMap[1][0] = 0;
	playerMap[1][1] = 0;
	playerMap[1][2] = 0;
	playerMap[1][3] = 0;
	playerMap[1][4] = 0;
	//
	playerMap[2][0] = 0;
	playerMap[2][1] = 0;
	playerMap[2][2] = 0;
	playerMap[2][3] = 0;
	playerMap[2][4] = 0;
	//
	curr_i = 0;
	curr_j = 0;
}

void Game::startGame()
{
	//creating all needed spaces
	generateMap();
	////STARTING GAME ///// 
	bool exit = false;
	//introduction
	cout << "You stand at the door of a castle. " << endl <<
		"Legend says that the castle is inhabited by the old king and his subjects." << endl;
	cout << "You came here seeking adventure, glory and treasure." << endl;
	cout << "But the king is not going to let you just walk in and take his property" << endl;
	cout << "He is ready to raise his sword and army to take you down if necessary " << endl;
	cout << "You slowly open the door, ready to explore..." << endl;
	currentSpace->description();
	while (Player::alive && Counter::counter<15 && !exit) { //while player is alive and not all spaces are cleared and player didn't try to exit
		cout << "________________________________________________" << endl;
		cout << "What do you want to do? " << endl; //give player list of possible actions
		cout << "______________________________" << endl;
		cout << "(1) Check surroundings" << endl;
		cout << "(2) Challenge" << endl;
		cout << "(3) Leave room" << endl;
		cout << "(4) Check stats" << endl;
		cout << "(5) Check bag" << endl;
		cout << "(6) Display map" << endl;
		cout << "(7) Exit game" << endl;
		cout << "________________________________________________" << endl;
		int ans = readNumber();
		while (ans != 1 && ans != 2 && ans != 3 && ans != 4 && ans != 5 && ans != 6 && ans != 7) { //while input is not ok
			cout << "________________________________________________" << endl;
			cout << "What do you want to do? " << endl;
			cout << "______________________________" << endl;
			cout << "(1) Check surroundings" << endl;
			cout << "(2) Challenge" << endl;
			cout << "(3) Leave room" << endl;
			cout << "(4) Check stats" << endl;
			cout << "(5) Check bag" << endl;
			cout << "(6) Display map" << endl;
			cout << "(7) Exit game" << endl;
			cout << "________________________________________________" << endl;
			int ans = readNumber();
		}
		switch (ans) { //do what player wanted to do
		case 1:
			this->checkSurroundings(); //check surroundings in current space
			break;
		case 2:
			this->challenge(); //try challenge in current space
			break;
		case 3:
			this->leaveRoom(); //try to leave room
			break;
		case 4:
			this->checkStats(); //check player stats
			break;
		case 5:
			this->openBag(); //open bag
			break;
		case 6:
			this->displayMap(); //draw map
			break;
		case 7:
			exit = true; //exit game
			break;
		}
	}
	if(exit) { //display message at the end, depending on outcome
		cout << "You exited the game" << endl;
	} else if (Player::alive) {
		cout << "You cleared the game" << endl;
	} else {
		cout << "You lost the game" << endl;
	}
	delete Player::bag;
}

void Game::openBag()
{
	Player::bag->takeAction(); //open player's bag
}

void Game::challenge()
{
	currentSpace->challenge(); //try challenge
}

int Game::readNumber() //read number safely
{
	int number;
	cin >> number;
	while (cin.fail()) {
		cout << "Wrong input! Please insert integer..." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> number;
	}
	return number;
}

void Game::leaveRoom() //try to leave room
{
	if (currentSpace->escape()) { //if leaving room is possible
		bool success = false;
		int ans = -1;
		while (!success) { //while there's no good input
			cout << "________________________________________________" << endl;
			cout << "Which door you want to go through? " << endl; 
			cout << "______________________________" << endl;
			cout << "(1) Northern door" << endl;
			cout << "(2) Southern door" << endl;
			cout << "(3) Eastern door" << endl;
			cout << "(4) Western door" << endl;
			cout << "(5) Cancel" << endl;
			cout << "________________________________________________" << endl;
			ans = readNumber();
			if (ans == 1 || ans == 2 || ans == 3 || ans == 4 || ans == 5) {
				success = true;
			}
		}
		if (ans == 1 && currentSpace->checkPass('t')) { //if the player wants to go north and
			cout << "Room changed successfully " << endl; // there is space north (not NULL), then allow him to
			playerMap[curr_i][curr_j] = 0;				 //
			curr_i--;										//switch new location with previous
			playerMap[curr_i][curr_j] = 1;				//
			currentSpace = currentSpace->getNeigh('t'); //set currentSpace to new location
		}
		else if (ans == 2 && currentSpace->checkPass('b')) { //if the player wants to go south
			cout << "Room changed successfully " << endl;
			playerMap[curr_i][curr_j] = 0;
			curr_i++;
			playerMap[curr_i][curr_j] = 1;
			currentSpace = currentSpace->getNeigh('b');
		}
		else if (ans == 3 && currentSpace->checkPass('r')) { //if the player wants to go east
			cout << "Room changed successfully " << endl;
			playerMap[curr_i][curr_j] = 0;
			curr_j++;
			playerMap[curr_i][curr_j] = 1;
			currentSpace = currentSpace->getNeigh('r');
		}
		else if (ans == 4 && currentSpace->checkPass('l')) { //if the player wants to go west
			cout << "Room changed successfully " << endl;
			playerMap[curr_i][curr_j] = 0;
			curr_j--;
			playerMap[curr_i][curr_j] = 1;
			currentSpace = currentSpace->getNeigh('l');
		}
		else if (ans == 5) {
			cout << "Cancelled " << endl; //if player gave up changing room
		}
		else {
			cout << "You can't go there... " << endl;
		}
	}
	else { //if not able to change room
		cout << "You can't leave this room yet..." << endl;
	}
}

void Game::checkSurroundings()
{
	currentSpace->checkSurroundings(Player::bag); //check current room surroundings
}

void Game::checkStats()
{
	Player::showStatus(); //show player's stats
}

void Game::displayMap() //draw the map
{
	cout << "Drawing map..." << endl;
	cout << "__________________________" << endl;
	cout << "| ES | PS | BS | PS | QS | " << endl;
	cout << "| " << playerMap[0][0] << "  | " << playerMap[0][1] << "  | " << playerMap[0][2] << "  | "

		<< playerMap[0][3] << "  | " << playerMap[0][4] << "  |" << endl;
	cout << "__________________________" << endl;
	cout << "| PS | RS | PS | NS | RS | " << endl;
	cout << "| " << playerMap[1][0] << "  | " << playerMap[1][1] << "  | " << playerMap[1][2] << "  | "

		<< playerMap[1][3] << "  | " << playerMap[1][4] << "  |" << endl;
	cout << "__________________________" << endl;
	cout << "| BS | PS | RS | BS | KS | " << endl;
	cout << "| " << playerMap[2][0] << "  | " << playerMap[2][1] << "  | " << playerMap[2][2] << "  | "

		<< playerMap[2][3] << "  | " << playerMap[2][4] << "  |" << endl;
	cout << "__________________________" << endl;
	cout << "Legend: " << endl; //draw the legend for map
	cout << "\t 1 - Your location" << endl;
	cout << "\t ES - Entrance" << endl;
	cout << "\t PS - Pawn's room" << endl;
	cout << "\t BS - Bishop's office" << endl;
	cout << "\t RS - Rook's quarters" << endl;
	cout << "\t NS - Knight's chamber" << endl;
	cout << "\t QS - Queen's throne" << endl;
	cout << "\t KS - King's throne" << endl;
}
