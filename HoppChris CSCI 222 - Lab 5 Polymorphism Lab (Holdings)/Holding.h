/*
Lab 5 - Polymorphism Lab (Library Holdings)
Author:  Chris Hopp - 010809627
Version: 05.18.2018

*/

#ifndef _HOLDING_H
#define _HOLDING_H
#include <iostream>
//#include <string>

using namespace std;

class Holding {

protected:

	char* title;
	char* artist;
	int callNumber;

public:

	Holding(const Holding&);
	Holding(char*, char*, int);
	Holding& operator = (const Holding&);
	virtual ~Holding();
	virtual void print();
};

#endif