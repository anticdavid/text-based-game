
#include "EmptySpace.h"


EmptySpace::EmptySpace()
{
	this->skipable = true; //empty space is skipable
	this->checked = false;
}

EmptySpace::~EmptySpace()
{
}

void EmptySpace::description() //space description
{
	cout << "This is castle's entrance. ";
	if (!checked) {
		cout << "Check your surroundings!";
	}
	cout << endl;
}

void EmptySpace::challenge() //try challenge
{
	cout << "There is no one here to challenge..." << endl; //there is no challenge
}

void EmptySpace::checkSurroundings(Bag * bag)//check surroundings for items
{
	if (!checked) { //if the room's not checked
		cout << "You found potion. It's being placed in your bag..." << endl;
		bag->addItem(new HealingPotion()); //there is a potion here
		checked = true; //room is now checked
	}
	else {
		cout << "You already checked this place." << endl;
	}
}