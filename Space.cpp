
#include "Space.h"
#include <cstdlib>
#include <limits>

Space::Space()
{
}


Space::~Space()
{
	delete top; //delete all pointers
	delete bottom;
	delete left;
	delete right;
}

void Space::setSides(Space * t, Space * b, Space * l, Space * r) //set all four sides of space
{
	this->top = t; //set all pointers to other spaces or NULL
	this->bottom = b;
	this->right = r;
	this->left = l;
}

bool Space::checkPass(char f) //check if player can go in that direction
{
	if (f == 't') {
		return top != NULL; //if the top is not NULL, there is space there
	}
	else if (f == 'b') {
		return bottom != NULL;//if the bottom is not NULL, there is space there
	}
	else if (f == 'l') {
		return left != NULL;//if the left is not NULL, there is space there
	}
	else {
		return right != NULL;//if the right is not NULL, there is space there
	}
}

Space * Space::getNeigh(char f) //returns space that is on specified side
{
	if (f == 't') {
		return top; //return space that is assigned to top pointer
	}
	else if (f == 'b') {
		return bottom; //return space that is assigned to bottom pointer
	}
	else if (f == 'l') {
		return left; //return space that is assigned to left pointer
	}
	else {
		return right; //return space that is assigned to right pointer
	}
}

bool Space::escape() //check if player can leave space
{
	return (skipable || isCleared); //room can be left if it's either cleared or skipable
}

void Space::cleared() //set space on cleared, and raise number of cleared spaces
{
	Counter::counter++; //increase number of cleared space
	isCleared = true;
}

bool Space::spaceCleared() //checks if space is cleared
{
	return this->isCleared;
}

int Space::readNumber()//reading number without errors
{ 
	int number;
	cin >> number;
	while (cin.fail()) {
		cout << "Wrong input! Please insert integer..." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> number;
	}
	return number;
}


char Space::readChar()
{ //reading character without errors
	char character;
	cin >> character;
	while (cin.fail()) {
		cout << "Wrong input! Please insert character..." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> character;
	}
	return character;
}


bool Space::randChance(int rate) //random 1 in rate chance
{
	return ((rand() % 100) % rate == 0);
}