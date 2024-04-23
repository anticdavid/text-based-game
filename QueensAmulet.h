#pragma once
#ifndef QUEENSAMULET_H
#define QUEENSAMULET_H
#include "Item.h"
#include "Player.h"
using namespace std;

class QueensAmulet :
	public Item
{
public:
	QueensAmulet();
	~QueensAmulet();
	string name(); //return item's name
	void use(); //try using item
	void desc(); //print item's description
};

#endif