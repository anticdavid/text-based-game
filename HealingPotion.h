#pragma once
#ifndef HEALINGPOTION_H
#define HEALINGPOTION_H

#include "Item.h"
#include "Player.h"
using namespace std;
class HealingPotion :
	public Item
{
public:
	HealingPotion();
	~HealingPotion();
	string name();//return item's name
	void use();//try using item
	void desc(); //return item's description
};

#endif