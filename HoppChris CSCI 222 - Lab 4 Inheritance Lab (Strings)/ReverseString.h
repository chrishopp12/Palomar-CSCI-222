/*
Lab 4 - Inheritance Lab (String Class)
Author:  Chris Hopp - 010809627
Version: 05.04.2018

*/

#ifndef _REVERSESTRING_H
#define _REVERSESTRING_H

#include <iostream>
#include "String.h"

using namespace std;

class ReverseString : public String {
private:
	char* reverse;

public:
	ReverseString();
	ReverseString(const ReverseString&);
	ReverseString(const char*);

	ReverseString& operator = (const ReverseString&);
	ReverseString operator~();

};

#endif
