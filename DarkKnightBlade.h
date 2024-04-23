#pragma once
#ifndef DARKKNIGHTBLADE_H
#define DARKKNIGHTBLADE_H
#include "Item.h"
#include "Player.h"
using namespace std;

class DarkKnightBlade :
	public Item
{
public:
	DarkKnightBlade();
	~DarkKnightBlade();
	string name(); //return item's name
	void use(); // try using item
	void desc(); //item's description
};

#endif