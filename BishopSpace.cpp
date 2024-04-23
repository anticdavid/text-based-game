
#include "BishopSpace.h"
#include <cstdlib>

BishopSpace::BishopSpace()
{
	this->skipable = true; //you don't have to challenge bishop in order to leave room
	this->checked = false; 
	this->isCleared = false;
	hp = 100; //bishop's health
}


BishopSpace::~BishopSpace()
{
}

void BishopSpace::challenge() //try challenge
{
	if (isCleared) { //if challenge is already finished once
		cout << "This space is already cleared. Proceed to next one..." << endl;
	}
	else {
		description(); //print description of space
		while (!isCleared && Player::alive) { //while player is alive and space is not cleared
			while (Player::hp > 0 && hp > 0) { //simulation of a fight, stops when either players or bishops health reach 0
				for (int i = 0; i<Player::speed; i++) { //player can attack as many times as the value of his speed, either once or twice
					cout << "________________________________________________" << endl;
					cout << "What do you want to do? " << endl;
					cout << "______________________________" << endl;
					cout << "(1) Attack with weapon" << endl; //use regular attack
					cout << "(2) Use lightning bolt" << endl; //use lightning bolt
					cout << "(3) Check bag" << endl; //check bag
					cout << "________________________________________________" << endl;
					int ans = readNumber();
					while (ans != 1 && ans != 2 && ans != 3) { //repeat until input is good
						cout << "________________________________________________" <<

							endl;
						cout << "Wrong input! Try again..." << endl;
						cout << "______________________________" << endl;
						cout << "(1) Attack with weapon" << endl;
						cout << "(2) Use lightning bolt" << endl;
						cout << "(3) Check bag" << endl;
						cout << "________________________________________________" <<

							endl;
						ans = readNumber();
					}
					if (ans == 1) {
						hp -= Player::attack(); //decrease bishop's hp
						cout << "Bishop lost " << Player::attack() << " HP" << endl; //display result of attack
					}
					else if (ans == 2) {
						hp -= Player::lightningbolt(); //decrease bishop's hp
						cout << "Bishop lost " << Player::lightningbolt() << " HP" << endl; //display result of attack
					}
					else {
						Player::bag->takeAction(); //let player check bag
					}
				}
				if (hp>0) { //if the bishop is alive
					int t = rand() % 100;
					if (t < 85) { //85% chance of spear stab
						spearstab();
					}
					else {
						fireball(); //15% chance of fireball
					}
					t = rand() % 100;
					if (t < 85) { //bishop can attack twice
						spearstab();
					}
					else {
						fireball();
					}
				}
			}
			if (Player::hp <= 0) { //if player's health reach 0 or go below that
				cout << "You lost." << endl;
				Player::alive = false;//he is dead
			}
			else {
				cout << "You won." << endl; //otherwise, player won fight
				cleared(); //and the space is cleared
				cout << "You got Queen's amulet! This item is important, don't lose it!" << endl; //bishops drop queen's amulet, which is needed to fight queen
				Player::bag->addItem(new QueensAmulet()); //amulet is added to bag
				Player::gainXP(35); //player gains 35xp
				if (randChance(2)) { //there is 1 in 2 chance of getting cloak which can increase player's speed
					cout << "You found Bishop's cloak! Do you want to place it in your bag ? (y / n)" << endl;
					char ans = readChar();
					if (tolower(ans) == 'y') {
						Player::bag->addItem(new BishopsCloak()); //place bishop's cloak in player's bag
					}
				}
				cout << "Challenge cleared!" << endl;
			}
		}
	}
}

void BishopSpace::description() //give space description
{
	cout << "This is BishopSpace! Bishop is loyal Queen's guard." << endl;
	cout << "He seems to be guarding something of a great value. Prepare for fight" << endl;
}

void BishopSpace::checkSurroundings(Bag * bag) //try checking surroundings for items
{
	if (!checked) { //if player didn't check this place
		if (randChance(3)) { //one in 3 chance of getting a potion
			cout << "You found potion! Do you want to place it in your bag? (y/n)" << endl;
			char ans = readChar();
			if (tolower(ans) == 'y') {
				bag->addItem(new HealingPotion()); //add potion to bag
			}
		}
		else { cout << "You found nothing..." << endl; }
		checked = true;
	}
	else { //otherwise, message is displayed
		cout << "You already checked this place." << endl;
	}
}

void BishopSpace::fireball() //bishop's fireball attack
{
	cout << "Bishop used Spell: Fireball" << endl;
	Player::healthBuff(-20); //fireball deals 20 damage to player
}

void BishopSpace::spearstab() //bishop's spear attack
{
	cout << "Bishop stabbed you with his spear" << endl;
	Player::healthBuff(-15); //stab deals 15 damage to player
}
