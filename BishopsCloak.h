#pragma once
#ifndef BISHOPSCLOAK_H
#define BISHOPSCLOAK_H

#include "Item.h"
#include "Player.h"
using namespace std;

class BishopsCloak :
	public Item
{
public:
	BishopsCloak();
	~BishopsCloak();
	string name();
	void use();
	void desc();
};

#endif
