/*
Lab 4 - Inheritance Lab (String Class)
Author:  Chris Hopp - 010809627
Version: 05.04.2018

*/

#include "ReverseString.h"
#include <iostream>
#include <fstream>

using namespace std;

extern ofstream csis;

ReverseString::ReverseString() : String() {}				//Creates an empty ReverseString object, which is the same as an empty string object.

ReverseString::ReverseString(const ReverseString& reverseString) : String(reverseString) {}		//ReverseString copy constructor.  Again, works the same as String object.

ReverseString::ReverseString(const char* reverseString) : String(reverseString) {}				//ReverseString constructor from a string of characters.

ReverseString &ReverseString::operator = (const ReverseString& reverseString) {		//Assignment operator to assign one ReverseString to another
	length = strlen(reverseString.buf);
	buf = new char[length + 1];

	for (int i = 0; i < length; ++i) {
		buf[i] = reverseString.buf[i];
	}

	buf[length] = '\0';
	return *this;
}

ReverseString ReverseString::operator ~ () {				//Overloaded ~ operator that serves to reverse the order of a ReverseString object
	ReverseString reverse;
	reverse.length = length;
	reverse.buf = new char[length + 1];
	
	for (int i = 0; i < length; ++i) {
		reverse.buf[i] = buf[length - i - 1];
	}

	reverse[length] = '\0';

	return reverse;
}