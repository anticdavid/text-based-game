#pragma once
#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Space.h"
#include "EmptySpace.h"
#include "BishopSpace.h"
#include "RookSpace.h"
#include "PawnSpace.h"
#include "QueenSpace.h"
#include "KingSpace.h"
#include "KnightSpace.h"

class Game
{
private:
	int playerMap[3][5]; //map of player's position
	int curr_i, curr_j; //current position of player in matrix
	void openBag(); //opening players bag
	void challenge(); //starting current space's challenge
	int readNumber(); // safe number reading
	void leaveRoom(); //try to leave room
	void checkSurroundings(); //check current space's surroundings
	void checkStats(); //check player status
	void displayMap(); //print map on screen
	Space* currentSpace; //current space that player is in
	Space* sp11, *sp12, *sp13, *sp14, *sp15; //real map
	Space* sp21, *sp22, *sp23, *sp24, *sp25; // 
	Space* sp31, *sp32, *sp33, *sp34, *sp35; //
public:
	Game();
	~Game();
	void generateMap(); //generates map
	void startGame(); //starts game
};

#endif