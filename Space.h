#pragma once
#ifndef SPACE_H
#define SPACE_H

#include "Counter.h"
#include "Bag.h"
#include "Player.h"
#include <iostream>
using namespace std;

class Space
{
protected:
	Space* top; //pointer to top space
	Space* bottom; //pointer to bottom space
	Space* left; //pointer to left space
	Space* right; //pointer to right space
	bool skipable; //true if you can leave room, false if you can't
	bool checked; //true if you used checkSurrounding(), false otherwise
	bool isCleared; //true if the space is cleared
public:
	Space();
	virtual ~Space(); //destructor has to be virtual
	void setSides(Space* t, Space* b, Space* l, Space* r); //links spaces
	bool checkPass(char f); //checks if you can go that way/ if there is a space or NULL
	Space* getNeigh(char f); //returns neighbour space
	bool escape(); //checks if you can leave room
	virtual void description() = 0; //description of space
	virtual void challenge() = 0; //space challenge - each space has its own challenge 
	virtual void checkSurroundings(Bag* bag) = 0; //checks surrounding for items or some hidden secrets
	void cleared(); //sets isCleared to true and increments counter of cleared spaces
	bool spaceCleared(); //returns true if space is cleared
	int readNumber(); //safe number reading
	char readChar(); //safe char reading
 	bool randChance(int rate); // 1/rate probability of returning true
};

#endif