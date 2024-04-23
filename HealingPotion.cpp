
#include "HealingPotion.h"


HealingPotion::HealingPotion()
{
}


HealingPotion::~HealingPotion()
{
}

string HealingPotion::name() //returns item's name
{
	return "Healing potion";
}

void HealingPotion::use() //try using item
{
	Player::healthBuff(20); //healing potion increases 20hp to player's health
	cout << "+20hp" << endl;
}

void HealingPotion::desc() // describe item
{
	cout << "Healing potion. Restores 20hp when used" << endl;
}
