#pragma once
#ifndef EMPTYSPACE_H
#define EMPTYSPACE_H
#include "Space.h"
#include "HealingPotion.h"
class EmptySpace :
	public Space
{
public:
	EmptySpace();
	~EmptySpace();
	void description(); //get space description
	void challenge(); //try challenge
	void checkSurroundings(Bag* bag); //check surroundings for item
};

#endif