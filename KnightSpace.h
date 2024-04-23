#pragma once
#ifndef KNIGHTSPACE_H
#define KNIGHTSPACE_H
#include "Space.h"
#include "HealingPotion.h"
#include "DarkKnightBlade.h"
#include "KnightsSpear.h"

class KnightSpace :
	public Space
{
private:
	int answer; //player's answer to questions
	int failedPersuade; //number of failed persuasions
	int persuaded; //number of successful persuasions
	int honorableAnswers; //number of honorable answers
public:
	KnightSpace();
	~KnightSpace();
	void challenge(); //try challenge
	void description(); //room description
	void checkSurroundings(Bag* bag); //check surroundings for items
};

#endif