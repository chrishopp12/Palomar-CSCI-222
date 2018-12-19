/*
Lab 4 - Inheritance Lab (String Class)
Author:  Chris Hopp - 010809627
Version: 05.04.2018

*/

#ifndef _CASESTRING_H
#define _CASESTRING_H

#include <iostream>
#include "String.h"

using namespace std;

class CaseString : public String {
protected:
	char* upper;
	char* lower;

public:
	CaseString ();
	CaseString (const CaseString&);
	CaseString (const char*);

	CaseString& operator = (const CaseString&);

	~CaseString();

	void print();
};

#endif