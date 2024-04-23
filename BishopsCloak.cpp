
#include "BishopsCloak.h"


BishopsCloak::BishopsCloak()
{
}

BishopsCloak::~BishopsCloak()
{
}

string BishopsCloak::name() //return item's name
{
	return "Bishop's cloak";
}

void BishopsCloak::use() //try using item
{
	cout << "Bishop's Cloak equipped" << endl;
	Player::equipCloak(); //bishop's cloak raises player's speed up to 2
}

void BishopsCloak::desc() //give item's description
{
	cout << "Bishop's Cloak. It's very light." << endl;
	cout << "Allows you to attack twice during the same turn" << endl;
}
