#pragma once
#ifndef QUEENSPACE_H
#define QUEENSPACE_H
#include "Space.h"
#include "HealingPotion.h"
#include "Player.h"
using namespace std;
class QueenSpace :
	public Space
{
private:
	int hp; //queen's health
	int pedestals; //number of amulets placed on pedestals
	bool awake; //true if queen's awake
	int def; //queen's defense
	void fireball(); //three types of attack that queen can do
	void firestorm();//
	void guarded();//
public:
	QueenSpace();
	~QueenSpace();
	void description(); //room description
	void challenge(); //try challenge
	void checkSurroundings(Bag* bag); //check surroundings for items
};

#endif