/*
Lab 4 - Inheritance Lab (String Class)
Author:  Chris Hopp - 010809627
Version: 05.04.2018

*/

#ifndef _STRING_H
#define _STRING_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;

class String {
protected:
	int length;
	char* buf;
public:
	String();
	String(const char*);
	String(char);
	String(int);
	String(const String&);
	String(char, int);

	~String();

	String& operator = (const String&);
	String& operator = (const char*);

	friend String operator + (const String&, const String&);
	friend String operator + (const String&, const char*);
	friend String operator + (const char*, const String&);
	friend String operator + (const String&, char);
	friend String operator + (char, const String&);

	String& operator += (const String&);

	String operator + () const;

	friend int operator == (const String&, const String&);
	friend int operator != (const String&, const String&);
	friend int operator < (const String&, const String&);
	friend int operator <= (const String&, const String&);
	friend int operator > (const String&, const String&);
	friend int operator >= (const String&, const String&);

	char& operator [] (int);

	friend char* operator + (const String&, int);
	friend char* operator + (int, const String&);

	String& operator ++();
	String& operator --();
	String operator ++(int);
	String operator --(int);

	int getLength();

	String substr(int, int);

	void print();

	friend ostream& operator<<(ostream&, const String&);
	
};

#endif
