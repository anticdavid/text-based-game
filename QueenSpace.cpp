
#include "QueenSpace.h"
#include <cstdlib>

QueenSpace::QueenSpace()
{
	hp = 200; //queen's hp
	pedestals = 0; //number of amulets placed on pedestal
	awake = false; //variable indicating whether queen is awake or not
	def = 15; //base defense of queen
	this->skipable = true; //you can leave this room without completing the challenge
	this->isCleared = false;
	this->checked = false;
}

QueenSpace::~QueenSpace()
{
}

void QueenSpace::description() // give space description
{
	if (!awake) { //if queen's not awake
		cout << "This is QueenSpace. You can see the Queen asleep in her throne." << endl;
		cout << "There are three pedestals in front of the Queen. Maybe there's some meaning?" <<

			endl;
	}
	else if (isCleared) { //if space is cleared
		cout << "This space is already cleared. Proceed to next one..." << endl;
	}
}

void QueenSpace::challenge() //try challenge in this space
{
	description(); //print description
	if (awake && !isCleared) { //if queen is awake and challenge's not cleared
		cout << "Queen is awake! Prepare for battle..." << endl;
		while (Player::hp > 0 && hp > 0) { //while both queen and player are alive
			for (int i = 0; i < Player::speed; i++) { //player can attack as many times as his speed is (it's either 1 or 2)
				cout << "________________________________________________" << endl;
				cout << "What do you want to do? " << endl;
				cout << "______________________________" << endl;
				cout << "(1) Attack with weapon" << endl; //player can attack with weapon
				cout << "(2) Use lightning bolt" << endl; //or he can use lightning bolt
				cout << "(3) Check bag" << endl; //or he can use item from bag
				cout << "________________________________________________" << endl;
				int ans = readNumber();
				while (ans != 1 && ans != 2 && ans != 3) {
					cout << "________________________________________________" << endl;
					cout << "Wrong input! Try again..." << endl;
					cout << "______________________________" << endl;
					cout << "(1) Attack with weapon" << endl;
					cout << "(2) Use lightning bolt" << endl;
					cout << "(3) Check bag" << endl;
					cout << "________________________________________________" << endl;
					ans = readNumber();
				}
				if (ans == 1) {
					hp -= Player::attack() - def; //queen's health is being lowered
					cout << "Queen lost " << Player::attack() - def << " HP" << endl;
				}
				else if (ans == 2) {
					hp -= Player::lightningbolt() - def; //queen's health is being lowered
					cout << "Queen lost " << Player::lightningbolt() - def << " HP" <<

						endl;
				}
				else {
					Player::bag->takeAction();
				}
			}
			if (hp > 0) { //if queen is still alive
				int t = rand() % 100; //choose some random number
				if (t < 85) {
					fireball(); //queen has 85% chance of using fireball
				}
				else if (t < 95) {
					guarded(); //10% chance of using guarded
				}
				else {
					firestorm(); //5% chance of using firestorm
				}
			}
		}
		if (Player::hp <= 0) { //if player's health reach 0 or lower, he is dead
			cout << "You lost" << endl;
			Player::alive = false; 
		}
		else { //if player won
			cout << "You won" << endl;
			cleared(); //room is cleared
			Player::gainXP(80); //player gains 80xp
			cout << "You got enchantment: Queen's blessing. +5 Defense, +10 Attack" << endl; //player gets enchantment
			Player::atk += 10; //player's attack is being rased
			Player::def += 5; //player's defense is being rased
		}
	}
}

void QueenSpace::checkSurroundings(Bag * bag) //check surroundings for items or for other actions
{
	if (!checked) { //if space is not checked
		cout << "You found potion! Do you want to place it in your bag? (y/n)" << endl;
		char ans = readChar();
		if (tolower(ans) == 'y') {
			bag->addItem(new HealingPotion()); //give player healing potion
		}
		checked = true;
	}
	if (!awake) { //if queen's not awake
		cout << "Do you want to place item here? (y/n)" << endl;
		char ans = readChar();
		if (tolower(ans) == 'y') { 
			if (bag->placeItem()) { //allow player to place amulet on pedestal
				cout << "Queen's amulet placed on pedestal." << endl;
				pedestals++;
				if (pedestals == 3) { //if there are 3 amulets placed
					awake = true; //queen is waking up
					skipable = false; //and player cannot leave room until the queen is defeated
				}
			}
			else { //if player does not have an amulet in bag
				cout << "There is no item to be placed" << endl;
			}
		}
	}
	else {
		cout << "This space is already cleared. Proceed to next one..." << endl;
	}
}

void QueenSpace::fireball() //queens fireball attack
{
	cout << "Queen used Spell: Fireball" << endl;
	Player::healthBuff(-25); //fireball deals 25 damage to health
}

void QueenSpace::firestorm() //queen's firestorm attack
{
	cout << "Queen used Spell: Firestorm" << endl;
	Player::healthBuff(-40); //fireball deals 40 damage to health
}

void QueenSpace::guarded() //queen's spell guarded
{
	cout << "Queen used Enchantment: Guarded" << endl;
	def = 25; //guarded enchantment gives queen 25 defense
}
