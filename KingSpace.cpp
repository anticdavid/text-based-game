
#include "KingSpace.h"
#include <cstdlib>

KingSpace::KingSpace()
{
	hp = 300; //king's hp
	def = 15; //king's defense
	atk = 15; //king's attack
	this->skipable = true;
	this->isCleared = false;
	this->checked = false;
}

void KingSpace::description()
{
	cout << "This is KingSpace. You successfully cleared all other spaces." << endl;
	cout << "King slowly stands up from his throne, ready to avenge his fallen subjects." << endl;
}

void KingSpace::challenge()
{
	if (Counter::counter == 14) { //unless all other spaces are cleared, you cannot fight king
		description();
		cout << "King is angry! Prepare for battle..." << endl;
		while (Player::hp > 0 && hp > 0) { //while both you and king are alive
			for (int i = 0; i < Player::speed; i++) { //you get your first attack, you can attack twice if your speed = 2
				cout << "________________________________________________" << endl;
				cout << "What do you want to do? " << endl;
				cout << "______________________________" << endl;
				cout << "(1) Attack with weapon" << endl;
				cout << "(2) Use lightning bolt" << endl;
				cout << "(3) Check bag" << endl;
				cout << "________________________________________________" << endl;
				int ans = readNumber();
				while (ans != 1 && ans != 2 && ans != 3) { //repeat until the input is correct
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
					hp -= Player::attack() - def; //use standard attack, decrease king's hp
					cout << "King lost " << Player::attack() - def << " HP" << endl;
				}
				else if (ans == 2) {
					hp -= Player::lightningbolt() - def;// use lightning bolt, decrease king's hp
					cout << "King lost " << Player::lightningbolt() - def << " HP" << endl;
				}
				else {
					Player::bag->takeAction(); //open bag
				}
			}
			if (hp > 0) { //if king is alive
				int t = rand() % 100;
				if (t < 85) { //85% chance of swordslash
					swordslash();
				}
				else if (t < 90) { //5% chance of guarded
					guarded();
				}
				else if (t < 95) { //5% chance of fury
					fury();
				}
				else {
					swordstab(); //5% chance of swordstab
				}
			}
		}
		if (Player::hp <= 0) { //if player's health reach 0 or go bellow
			cout << "You lost" << endl;
			Player::alive = false; //player dies
		}
		else {
			cout << "You won" << endl;
			cleared();
		}
	}
	else {
		cout << "You are still too weak to fight the king" << endl; //message to display if there are less than 14 spaces cleared
	}
}

void KingSpace::checkSurroundings(Bag * bag)
{
	if (!checked) { //if this space is not explored
		cout << "You found potion! Do you want to place it in your bag? (y/n)" << endl; //there's always healing potion here
		char ans = readChar();
		if (tolower(ans) == 'y') {
			bag->addItem(new HealingPotion()); //placing potion in the bag
		}
		checked = true;
	}
	else {
		cout << "You already checked this place." << endl;
	}
}

KingSpace::~KingSpace()
{
}

void KingSpace::swordslash()
{
	cout << "King used sword slash." << endl;
	Player::healthBuff(-35 - atk); //swordslash deals atk + 35 damage
}

void KingSpace::swordstab()
{
	cout << "King stabbed you with his sword." << endl;
	Player::healthBuff(-60 - atk); //swordstab deals atk + 60 damage
}

void KingSpace::guarded()
{
	cout << "King used Enchantment: Guarded" << endl;
	def = 30; //guarded raises king's defense up to 30
}

void KingSpace::fury()
{
	cout << "King used Enchantment: Fury" << endl;
	atk = 15; //fury raises king's attack up to 15
}
