
#include "RookSpace.h"
#include <cstdlib>

RookSpace::RookSpace()
{
	this->skipable = false; //you have to take challenge here in order to proceed
	this->isCleared = false;
	this->checked = false;
	counter = 0;
}


RookSpace::~RookSpace()
{
}

void RookSpace::challenge()//try challenging the rook
{
	int guess; 
	description(); //print space description
	if (!isCleared) { //while the room is not cleared
		a = rand() % 10; //a is number in range[0,9]
		b = a + 24; // b is upper limit of range
		sol = rand() % 24 + a;// solution is in range [a,b]
		cout << "Number is in range [" << a << "," << b << "], can you guess it?" << endl;
	}
	while (!isCleared && Player::alive) { //while space is not cleared and player is alive
		cout << "Your guess : ";
		guess = readNumber(); 
		counter++; //number of guesses increments
		if (guess == sol) { //if the guess is right
			cleared(); //space is cleared
			cout << "Challenge cleared!" << endl;

			if (counter <= 4) { //if there are more 4 or less guesses
				if (randChance(2)) { //1 in 2 chance of enchantment
					cout << "You got enchantment: Guarded. +3 Defense" << endl;
					Player::def += 3; //player gets 3 more defense points
				}
			}
			else {
				if (randChance(10)) { //otherwise, 1 in 10
					cout << "You got enchantment: Guarded. +3 Defense" << endl;
					Player::def += 3;
				}
			}
			Player::gainXP(15); //player gains 15xp
		}
		else if (guess > sol) { //if guess is bigger than solution
			cout << "Wrong, number he's thinking of is smaller than that..." << endl; //notify player
			if (counter > 4) { //if there are more than 4 guesses, player loses 12hp
				Player::healthBuff(-12); //decrease player's health
				if (Player::hp <= 0) { //if player's hp goes bellow 0
					Player::alive = false; //player is dead
				}
			}
		}
		else { //same if guess is smaller than solution
			cout << "Wrong, number he's thinking of is greater than that..." << endl;
			if (counter > 4) { //if there are more than 4 guesses
				Player::healthBuff(-12); //decrease player's health
				if (Player::hp <= 0) {
					Player::alive = false; //player is dead
				}
			}
		}
	}
}

void RookSpace::description() //this space description
{
	if (isCleared) { //if the space is cleared
		cout << "This space is already cleared. Proceed to next one..." << endl;
	}
	else {
		cout << "This is RookSpace! Rook is thinking of a number." << endl;
	}
}

void RookSpace::checkSurroundings(Bag * bag) //try checking surroundings for items
{
	if (!checked) { //there is nothing here
		cout << "You found nothing..." << endl;
		checked = true; //space is now checked
	}
	else {
		cout << "You already checked this place." << endl;
	}
}
