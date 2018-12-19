/*
Lab 5 - Polymorphism Lab (Library Holdings)
Author:  Chris Hopp - 010809627
Version: 05.18.2018

*/

#ifndef _RECORDING_H
#define _RECORDING_H

#include "Holding.h"

class Recording : public Holding {
private:
	char* format;

public:
	Recording(const Recording&);
	Recording(char*, char*, char, int);
	Recording& operator = (const Recording& recording1);

	virtual ~Recording();
	virtual void print();
};

#endif
