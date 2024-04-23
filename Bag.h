#pragma once
#ifndef BAG_H
#define BAG_H
#include "Item.h"
#include <vector>
#include <iostream>

class Bag
{
private:
	int capacity; //capacity of a bag
	std::vector<Item*> storage; //vector storing items
	void listItems(); //function that lists items stored in vector
	int readNumber(); //function for inputing numbers without errors
	char readChar(); //function for inputing chars without errors
	void dropItem(); //removes item from vector
	void itemDesc(); //gives description of item
	void useItem(); //item is being used, and if it's potion, it's removed from vector 
public:
	Bag();
	Bag(int capacity); 
	~Bag();
	bool placeItem(); //used for placing queen's amulet on pedestal
	bool addItem(Item* item); //tries to add item in vector, and returns true if
	//successfull, false otherwise
	void takeAction(); //interface for all bag functions
};

#endif