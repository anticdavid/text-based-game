#pragma once
#ifndef COUNTER_H
#define COUNTER_H
class Counter
{
public:
	//simple class for counting number of spaces cleared
	Counter();
	~Counter();
	static int counter; //variable for storing number of cleared spaces
};

#endif