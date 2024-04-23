#pragma once
#ifndef KNIGHTSSPEAR_H
#define KNIGHTSSPEAR_H
#include "Item.h"
#include "Player.h"
using namespace std;
class KnightsSpear :
	public Item
{
public:
	KnightsSpear();
	~KnightsSpear();
	string name(); //return item's name
	void use(); //try using item
	void desc(); //print item's description
};

#endif
