
#include "PawnSpace.h"
#include <cstdlib>

PawnSpace::PawnSpace()
{
	this->skipable = true; //can be skiped without doing challenge
	this->checked = false;
	this->isCleared = false;
}


PawnSpace::~PawnSpace()
{
}

void PawnSpace::challenge()
{
	description();
	while (!isCleared && Player::alive) { //while player is alive and space is not cleared
		a = rand() % 20; //generate two random numbers
		b = rand() % 20; //
		cout << a << " + " << b << " = "; //print a + b
		sol = readNumber(); //read response from player
		if (sol == a + b) { //if the response is right
			cleared(); //space is cleared

			cout << "Challenge cleared!" << endl; 
			Player::gainXP(5); //player gains 5xp for clearing challenge

		}
		else { //otherwise, if the response is wrong
			Player::healthBuff(-8); //player loses 5hp
			if (Player::hp <= 0) { //and if player's hp is equal to or below 0
				Player::alive = false; //player is dead
			}
		}
	}
}

void PawnSpace::description() //prints the description of space
{
	if (isCleared) { //if space is cleared
		cout << "This space is already cleared. Proceed to next one..." << endl; //print this
	}
	else {
		cout << "This is PawnSpace! Calculate sum in order to clear this room!" << endl; //otherwise print this
	}
}

void PawnSpace::checkSurroundings(Bag * bag)  //checking space surroundings for items or other possibilities
{
	if (!checked) { //if player didn't check surroundings
		if (randChance(5)) { //one in 5 chance of getting a potion
			cout << "You found potion! Do you want to place it in your bag? (y/n)" << endl;
			char ans = readChar();
			if (tolower(ans) == 'y') { //if player wrote 'y' or 'Y'
				bag->addItem(new HealingPotion()); //add potion to his bag
			}
		}
		else { cout << "You found nothing..." << endl; } //
		checked = true;//once the room is checked, don't allow player to check it again
	}
	else {
		cout << "You already checked this place." << endl; //if player already checked room once and tried checking again, this message will be displayed
	}
}
