
#include "DarkKnightBlade.h"


DarkKnightBlade::DarkKnightBlade()
{
}

DarkKnightBlade::~DarkKnightBlade()
{
}

string DarkKnightBlade::name() //return item's name
{
	return "Dark Knight's blade";
}

void DarkKnightBlade::use() //try using item
{
	cout << "Dark Knight's Blade equipped" << endl;
	Player::equipWeapon(45); //equips weapon on player
	cout << "Dark energy from blade harms you. -20HP" << endl;
	Player::healthBuff(-20, 'y'); //this is imagined to be a cursed artifact, so it damages health when equiped
}

void DarkKnightBlade::desc() //item's description
{
	cout << "Dark Knight's Blade. It radiates dark energy." << endl;
	cout << "Stronger than Knight's Spear, but decreases 20hp when equipped" << endl;
}
