/*
Lab 3 - Operator Overloading (IntArray)
Author:  Chris Hopp - 010809627
Version: 04.13.2018

*/

#ifndef _INTARRAY_H
#define _INTARRAY_H


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;

class IntArray {
private:
	string name;
	int upper;
	int lower;
	int offset;
	int intSize;
	int *intArray;

public:
	IntArray();
	IntArray(int elements);
	IntArray(int low, int high);
	IntArray(const IntArray& array1);
	~IntArray();
	int low() const;
	int high() const;
	int size() const;
	void setName(string name1);
	string getName();
	IntArray& operator=(const IntArray& array1);
	bool operator==(IntArray array1);
	bool operator!=(IntArray array1);
	int& operator[](int index);
	IntArray operator+(IntArray&);
	void operator+=(IntArray);
	friend ostream& operator <<(ostream& os, const IntArray& array1);
};
#endif

