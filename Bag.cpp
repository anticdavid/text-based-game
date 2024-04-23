
#include "Bag.h"
#include <cstdlib>
#include <limits>
Bag::Bag()
{
	this->capacity = 10; //if not specified, capacity is set to 10
}

Bag::Bag(int capacity) //constructor with capacity
{
	this->capacity = capacity;
}


Bag::~Bag()
{
	for (int i = 0; i < storage.size(); i++) {
		delete storage[i]; //clearing vector of pointers
	}
	storage.clear();
}

bool Bag::placeItem() //placing queen's amulet on pedestal (remove it from vector)
{
	for (int i = 0; i < storage.size(); i++) {
		if (storage[i]->name() == "Queen's amulet") { //if there's queen's amulet
			storage.erase(storage.begin() + i); //remove it from the vector
			return true; //and stop searching, also notify that you have found amulet
		}
	}
	return false; //notify that there is no amulet in vector
}

bool Bag::addItem(Item * item) //add Item pointer in vector 
{
	if (this->capacity == storage.size()) { //if bag is full
		std::cout << "Bag is full. Want to drop some item from bag? (y/n)" << std::endl; //ask player if he wants to drop some item
		char ans = readChar();
		if (tolower(ans) == 'y') { //if he wants 
			dropItem(); //call function dropItem()
		}
		else {
			return false; //if he doesn't want, return false to notify that the item was not added
		}
	}
	storage.push_back(item); //add item in vector
	return true;//notify that item was added in vector
}

void Bag::takeAction() //take action - give user choice what he wants to do with items in bag
{
	int input = 0;
	while (input != 5) { //while player doesn't say "Do nothing"
		std::cout << "________________________________________________" << std::endl;
		std::cout << "What do you want to do? " << std::endl; //ask him what he wants to do
		std::cout << "______________________________" << std::endl;
		std::cout << "(1) Use item from bag " << std::endl;
		std::cout << "(2) Drop item from bag " << std::endl;
		std::cout << "(3) List items" << std::endl;
		std::cout << "(4) Item description" << std::endl;
		std::cout << "(5) Do nothing" << std::endl;
		std::cout << "________________________________________________" << std::endl;
		input = readNumber(); //read his answer
		switch (input) { //depending on answer, do what he wanted
		case 1:
			useItem();
			break;
		case 2:
			dropItem();
			break;
		case 3:
			listItems();
			break;
		case 4:
			itemDesc();
			break;
		case 5:
			break;
		default:
			std::cout << "Wrong input... Try again" << std::endl;
		}
	}
}

void Bag::listItems() //function lists all items in bag
{
	if (storage.size() == 0) { std::cout << "Bag is empty" << std::endl; } //if there are no items
	else { //otherwise, list all items
		for (int i = 0; i < storage.size(); i++) {
			std::cout << "(" << i + 1 << ") " << storage[i]->name() << std::endl;
		}
	}
}

int Bag::readNumber() //safe reading integer
{
	int number;
	std::cin >> number;
	while (std::cin.fail()) {
		std::cout << "Wrong input! Please insert integer..." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> number;
	}
	return number;
}

char Bag::readChar() //safe reading char
{
	char character;
	std::cin >> character;
	while (std::cin.fail()) {
		std::cout << "Wrong input! Please insert character..." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> character;
	}
	return character;
}

void Bag::dropItem() //drop item from bag
{
	listItems(); //show player all items
	std::cout << "Insert number of item you want dropped: ";
	int n = readNumber() - 1;
	if (n >= 0 && n < storage.size()) {
		if (!(storage[n]->name() == "Queen's amulet")) { //if the item is queen's amulet, it cannot be droped
			storage.erase(storage.begin() + n); //removing item from bag
		}
		else {
			std::cout << "Cannot drop that item!" << std::endl;
		}

	}
	else { std::cout << "There is no item with that number..." << std::endl; }
}

void Bag::itemDesc()//item description
{
	listItems(); //list items in bag
	std::cout << "Insert number of item you want described: ";
	int n = readNumber() - 1;
	if (n >= 0 && n < storage.size()) { //depending on input, display item description
		std::cout << "________________________________________________" << std::endl;
		storage[n]->desc();
	}
	else { std::cout << "There is no item with that number..." << std::endl; }
}

void Bag::useItem() //using item
{
	listItems(); //list items in bag
	std::cout << "Insert number of item you want used: ";
	int n = readNumber() - 1;
	if (n >= 0 && n < storage.size()) {
		storage[n]->use(); //use item player wanted to use
		if (storage[n]->name() == "Healing potion") { //if used item is healing potion
			storage.erase(storage.begin() + n); //it is removed from bag
		}
	}
	else { std::cout << "There is no item with that number..." << std::endl; }
}
