
#include "Player.h"
#include <limits>
#include <math.h>
#include <iostream>
using namespace std;

int Player::xp = 10; //initializing variables
int Player::hp = 100; //player can have max 100hp
int Player::atk = 5; //base atk
int Player::def = 5; //base def
Bag* Player::bag = new Bag(); //player's bag
int Player::speed = 1; //player's speed -> number of attacks in same turn
bool Player::alive = true; //true if player alive
Player::Player()
{
}

Player::~Player()
{
	delete bag; //clearing memory
}

void Player::equipCloak()
{
	speed = 2; //cloak raises speed to 2
}

void Player::equipWeapon(int bonus)
{
	atk = 5 + bonus; //base atk + weapon bonus
}

int Player::attack()
{
	return atk + xp / 10; //attack calculated using base attack and xp; 
}

int Player::lightningbolt()
{
	return (int)floor(xp / 3); //lightningbolt is completely calculated using xp;
}

void Player::gainXP(int _xp)
{
	xp += _xp;  //raising xp
	cout << "+" << _xp << "XP gained" << endl;
}

void Player::healthBuff(int buff, char dkb)
{
	if (dkb == 'y' || buff>0) {
		hp += buff; //damage from Dark Knight's Blade is not reduced by defense
					//same goes for bonus from healing potion
		if (hp > 100) hp = 100; //normalizing health if it goes over 100
	}
	else {
		int damage = (buff + def); //damage is calculated using output damage from enemy and player's defense
		if (damage >= 0) { //if damage gets equal to or bigger than 0
			damage = -2; //normalize it
		}
		hp += damage; //calculate new hp
		cout << "You lost " << abs(damage) << "HP." << endl;
	}
}

void Player::showStatus() //print player's stats
{
	cout << "HP: " << hp << endl;
	cout << "XP: " << xp << endl;
	cout << "Attack: " << atk << endl;
	cout << "Defense: " << def << endl;
	cout << "Speed: " << speed << endl;
}

