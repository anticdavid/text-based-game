
#include "KnightsSpear.h"


KnightsSpear::KnightsSpear()
{
}


KnightsSpear::~KnightsSpear()
{
}

string KnightsSpear::name() //returns item's name
{
	return "Knight's spear";
}

void KnightsSpear::use()//try using knights spear (equip)
{
	cout << "Knight's Spear equipped" << endl;
	Player::equipWeapon(35); //knight's spear raises base attack of player by 35
}

void KnightsSpear::desc() //items description
{
	cout << "Knight's Spear. It deals additional 35 damage." << endl;
}
