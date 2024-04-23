#pragma once
#ifndef PAWNSPACE_H
#define PAWNSPACE_H
#include "Space.h"
#include "HealingPotion.h"
class PawnSpace :
	public Space
{
private:
	int a, b, sol; //a and b are numbers generated, sol is player's input
public:
	PawnSpace();
	~PawnSpace();
	void challenge(); //try challenge
	void description(); //print space's description
	void checkSurroundings(Bag* bag); //check surroundings for items
};

#endif