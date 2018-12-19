/*
Lab 3 - Operator Overloading (IntArray)
Author:  Chris Hopp - 010809627
Version: 04.13.2018

*/



#include <iostream>
#include <sstream>
#include "IntArray.h"

using namespace std;

extern ofstream csis;

IntArray::IntArray() {							//Constructor to create a default array of 10 elements
	lower = 0;
	upper = 9;
	offset = 0;
	intSize = upper + 1;
	intArray = new int[intSize];

}

IntArray::IntArray(int elements) {				//Constructor taking one argument for the number of elements.  Produces an error message if the number of elements is zero or negative
	lower = 0;
	upper = elements - 1;
	offset = 0;
	intSize = elements;

	if (upper < lower) {
		cout << "Error: Illegal array bounds.  Lower index greater than upper index.  Halt." << endl << endl;
		csis << "Error: Illegal array bounds.  Lower index greater than upper index.  Halt." << endl << endl;
	}

	intArray = new int[intSize];
}

IntArray::IntArray(int low, int high) {			//Constructor taking two arguments for the upper and lower indices.  Produces an error message if indices are out of range.
	if (high < low) {
		cout << "Error: Illegal array bounds.  Lower index greater than upper index.  Halt." << endl << endl;
		csis << "Error: Illegal array bounds.  Lower index greater than upper index.  Halt." << endl << endl;
	}

	lower = low;
	upper = high;
	intSize = abs ((upper - lower) + 1);
	offset = (0 - lower);						//Offset variable to use normal array indexing on the IntArray to allow for use of deconstructor

	intArray = new int[intSize];


}

IntArray::IntArray(const IntArray& array1) : lower(array1.low()), upper(array1.high()), intSize(array1.size()) {
	offset = array1.offset;											//Copy constructor. Takes one IntArray object as an argument and makes a copy.
	intArray = new int[intSize];

	for (int i = 0; i < intSize; i++) {
		intArray[lower + offset + i] = array1.intArray[array1.lower + array1.offset + i];
	}
}

 IntArray::~IntArray() {						//Destructor for IntArray objects.  Finally works.
	delete [] intArray;
} 

int IntArray::low() const {						//Returns lower index
	return lower;
}

int IntArray::high() const {					//Returns upper index
	return upper;
}

int IntArray::size() const {					//Returns size of the array
	return intSize;
}

void IntArray::setName(string name1) {			//Sets the name of the IntArray object
	name = name1;
}

string IntArray::getName() {					//Returns the name of the object
	return name;
}

IntArray& IntArray::operator=(const IntArray& array1) {			//Overloaded operator to set an invoking IntArray equal to another IntArray
	if (intSize != array1.intSize) {
		cout << "Error: Illegal operation.  Array lengths unequal.  Halt." << endl << endl;
		csis << "Error: Illegal operation.  Array lengths unequal.  Halt." << endl << endl;
		return *this; //return statement to prevent unreliable writing of memory if arrays are of different lengths.
	}
	else
		for (int i = 0; i < intSize; i++) {
			intArray[lower + i + offset] = array1.intArray[array1.lower + i + array1.offset];
		}

	
	return *this;

}

bool IntArray::operator==(IntArray array1) {				//Overloaded operator to compare two IntArray objects.  Returns true if elements are the same and arrays are the same length.
	if (intSize == array1.intSize) {
		for (int i = 0; i <intSize; i++) {
			if (intArray[lower + i + offset] != array1[array1.lower + i]) {
				return false;
			}
			return true;
		}
	}
	return false;
}

bool IntArray::operator!=(IntArray array1) {				//Overloaded operator to compare two IntArray objects.  Returns true if elements are not the same or lenght differs.
	if (intSize == array1.size()) {
		for (int i = 0; i < intSize; i++) {
			if (intArray[lower + i + offset] != array1[array1.lower + i]) {
				return true;
			}
			return false;
		}
	}
	return true;
}

int& IntArray::operator[](int index) {						//Overloaded operator to handle the IntArray as an array.  Returns value at desired location.
	if (index < lower || index > upper) {
		cout << "Error: Illegal operation. Index out of range.  Halt." << endl << endl;
		csis << "Error: Illegal operation. Index out of range.  Halt." << endl << endl;
		return intArray[lower+offset];
	}
	else 
	return intArray[index + offset];
}

IntArray IntArray::operator+(IntArray& array1) {			//Overloaded operator to add the contents of two IntArray objects and return them in a third IntArray.
	IntArray sum(lower, upper);

	if (intSize != array1.intSize) {
		cout << "Error: Illegal operation.  Array lengths unequal.  Halt." << endl << endl;
		csis << "Error: Illegal operation.  Array lengths unequal.  Halt." << endl << endl;
	}

	for (int i = 0; i < intSize; ++i) {
		sum[lower + i] = intArray[lower + i + offset] + array1[array1.lower + i];
	}
	return sum;

}

void IntArray::operator+=(IntArray array1) {				//Overloaded operator to add the contents of one IntArray to another.
	if (intSize != array1.intSize) {
		cout << "Error: Illegal operation.  Array lengths unequal.  Halt." << endl << endl;
		csis << "Error: Illegal operation.  Array lengths unequal.  Halt." << endl << endl;
	}
	else 
		for (int i = 0; i < intSize; ++i) {
			intArray[i] = (intArray[i] + array1[array1.lower + i]);
		}
	
}

ostream& operator << (ostream& os, const IntArray& array1) {		//Overloaded operator to output the contents of an IntArray object.
	if (array1.upper < array1.lower) {
		os << endl;		//Prevents outputting values on an illegal implementation
	}
	else

	for (int i = 0; i < array1.intSize; i++) {
		os << array1.name << "[" << (i - array1.offset) << "] = " << array1.intArray[i]  << endl;
	}
	return os;
}
