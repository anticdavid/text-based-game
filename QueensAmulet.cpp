
#include "QueensAmulet.h"


QueensAmulet::QueensAmulet()
{
}


QueensAmulet::~QueensAmulet()
{
}

string QueensAmulet::name() //return item's name
{
	return "Queen's amulet";
}

void QueensAmulet::use() //try using item
{
	cout << "Nothing happens..." << endl; //queen's amulet is only used to wake up queen
}

void QueensAmulet::desc() //item's description
{
	cout << "Queen's amulet. Legend says the Queen gave three amulets to her loyal bishops." << endl;
	cout << "Now asleep she waits for a challenger to bring her all amulets" << endl;
}
