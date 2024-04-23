#pragma once
#ifndef BISHOPSPACE_H
#define BISHOPSPACE_H

#include "Space.h"
#include "BishopsCloak.h"
#include "HealingPotion.h"
#include "QueensAmulet.h"

class BishopSpace :
	public Space
{
private:
	int hp; //bishop's hp
	void fireball(); //
	void spearstab();//two types of attack bishop can do
public:
	BishopSpace();
	~BishopSpace();
	void challenge();
	void description();
	void checkSurroundings(Bag* bag);
};
#endif