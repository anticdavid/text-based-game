#pragma once
#ifndef ROOKSPACE_H
#define ROOKSPACE_H
#include "Space.h"
class RookSpace :
	public Space
{
private:
	int a, b, sol, counter; //a and b are range, sol is solution for question, counter is counting wrong answers
public:
	RookSpace();
	~RookSpace();
	void challenge(); //try space challenge
	void description(); //print space description
	void checkSurroundings(Bag* bag); //check surroundings for item
};

#endif