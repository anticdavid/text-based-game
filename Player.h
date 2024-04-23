#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Bag.h"

class Player
{
public:
	Player();
	~Player();
	static int xp; // Experience
	static int hp;// Health
	static int atk;// Base attack
	static int def;// Defense
	static int speed;// Number of attacks possible in one turn (opening bag counts like one attack) 
	static bool alive; //true if player is alive
	static Bag* bag; //player's bag
	static void equipCloak(); //raises speed to 2
	static void equipWeapon(int bonus); //gives bonus to player for equiped weapon
	static int attack(); //calculate attack using base attack and experience
	static int lightningbolt(); //calculate attack using experience
	static void gainXP(int _xp); //raise player's xp
	static void healthBuff(int buff, char dkb = 'n'); //changes health
	static void showStatus(); //prints xp, hp, atk, def and speed
};

#endif