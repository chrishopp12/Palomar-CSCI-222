/*
Lab 4 - Inheritance Lab (String Class)
Author:  Chris Hopp - 010809627
Version: 05.04.2018

*/

#include "CaseString.h"
#include <iostream>
#include <fstream>

using namespace std;

extern ofstream csis;

CaseString::CaseString() : String(){}		//Constructor for an empty caseString object which is simply an empty String object

CaseString::CaseString(const CaseString& string1) : String(string1) {		//Copy constructor for caseString objects.  Creates an upper and lowercase copy of a String object.
	upper = new char[length + 1];
	lower = new char[length + 1];

	for (int i = 0; i < length; ++i) {
		upper[i] = toupper(buf[i]);
	}

	for (int i = 0; i < length; ++i) {
		lower[i] = tolower(buf[i]);
	}

	upper[length] = '\0';
	lower[length] = '\0';
}

CaseString::CaseString(const char* string1) : String(string1) {			//Constructor for a caseString object from a string of characters
	upper = new char[length + 1];
	lower = new char[length + 1];

	for (int i = 0; i < length; ++i) {
		upper[i] = toupper(string1[i]);
	}

	for (int i = 0; i < length; ++i) {
		lower[i] = tolower(string1[i]);
	}

	upper[length] = '\0';
	lower[length] = '\0';

}

CaseString& CaseString::operator = (const CaseString& caseString) {		//Assignment operator assigning one caseString object to another
	length = caseString.length;
	buf = new char[length + 1];
	upper = new char[length + 1];
	lower = new char[length + 1];

	for (int i = 0; i < length; ++i) {
		buf[i] = caseString.buf[i];
	}

	for (int i = 0; i < length; ++i) {
		upper[i] = caseString.upper[i];
	}

	for (int i = 0; i < length; ++i) {
		lower[i] = caseString.lower[i];
	}

	buf[length] = '\0';
	upper[length] = '\0';
	lower[length] = '\0';

	return *this;
}

void CaseString::print() {							//CaseString print fucntion that also displays the upper and lowercase strings.
	cout << "\"" << buf << "\"" << " " << " Length is: " << length << " Upper is: " << "\"" << upper << "\"" << " " << " Lower is: " << "\"" << lower << "\"" << " " << endl;
	csis << "\"" << buf << "\"" << " " << " Length is: " << length << " Upper is: " << "\"" << upper << "\"" << " " << " Lower is: " << "\"" << lower << "\"" << " " << endl;
}

CaseString::~CaseString() {							//Destructor for caseString objects.  Deletes both the upper and lower Strings.
	delete[] upper;
	delete[] lower;
}