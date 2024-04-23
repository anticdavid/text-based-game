#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>

class Item
{
public:
	Item();
	virtual ~Item(); //destructor has to be virtual 
	virtual std::string name() = 0; //name of a item
	virtual void use() = 0; //try to use item
	virtual void desc() = 0; //get item description
};

#endif