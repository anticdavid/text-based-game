#pragma once
#ifndef KINGSPACE_H
#define KINGSPACE_H
#include "Space.h"
#include "HealingPotion.h"
class KingSpace :
	public Space
{
private:
	int hp; //king's hp
	int atk; //king's attack
	int def; //king's defense
	void swordslash(); //four types of attacks : first type
	void swordstab(); // second type
	void guarded();// third type
	void fury();//fourth type
public:
	KingSpace();
	~KingSpace();
	void description(); //space description
	void challenge(); //try challenge
	void checkSurroundings(Bag* bag); //check surroundings for item
};

#endif