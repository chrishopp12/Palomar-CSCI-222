/*
Lab 4 - Inheritance Lab (String Class)
Author:  Chris Hopp - 010809627
Version: 05.04.2018

*/

#include <iostream>
#include <sstream>
#include "String.h"


using namespace std;

extern ofstream csis;

String::String() {							//Constructor for an empty String object
	length = 0;
	buf = new char[length + 1];

	buf[0] = '\0';
}						

String::String(const char* string) {		//Constructor for a String object from a string of characters
	length = (int(strlen(string)));

	buf = new char[length + 1];
	for (int i = 0; i < length; i++) {
		buf[i] = string[i];
	}

	buf[length] = '\0';
}

String::String(char char1) {				//Constructor for a String object from a single character
	length = 1;
	buf = new char[length + 1];
	buf[0] = char1;
	buf[length] = '\0';
}

String::String(int num) {					//Constructor for a String object from an integer
	if (num <= 0) {								//Error Checking for a zero or negative integer - Constructs an empty String object
		length = 0;
		buf = new char[length + 1];
		buf[0] = '\0';

		cout << "Error: Negative or Zero integer." << endl << endl;
		csis << "Error: Negative or Zero integer." << endl << endl;

	}

	else {										//Creates a String Object the with space allocated for an integer number of characters with the first element set to NULL
		buf = new char[num];
		length = num;
		buf[0] = '\0';
	}

}


String::String(const String& string1){			//Copy constructor for String objects
	length = string1.length;
	buf = new char[length + 1];					

	for (int i = 0; i < length; i++) {
		buf[i] = string1.buf[i];
	}

	buf[length] = '\0';
}

String::String(char char1, int num) {			//Constructor for a String object of a number of repeating characters
	if (num <= 0) {									//Error checking if a String is called to be constructed of zero or negative number of characters - Constructs and empty String object
		length = 0;
		buf = new char[length +1];
		buf[0] = '\0';

		cout << "Error: Illegal operation. Negative or Zero integer.  Halt." << endl << endl;
		csis << "Error: Illegal operation. Nagative or Zero integer.  Halt." << endl << endl;

	}

	else {
		buf = new char[num + 1];
		length = num;

		for (int i = 0; i < num; ++i) {
			buf[i] = char1;
		}

		buf[length] = '\0';
	}
}

String::~String() {								//Destructor for String object .... again causing me to lose sleep
	
		delete[] buf;
		length = 0;
	
}

String& String::operator = (const String& string1) {					//Assignment operator for String objects
	if (length != string1.length) {										//Checks if initial String lengths are equal. Resizes receiving String length accordingly.
		length = string1.length;
		buf = new char[length + 1];
	}

	for (int i = 0; i < length; i++) {
		buf[i] = string1.buf[i];
	}

	buf[length] = '\0';

		return *this;
}

String& String::operator = (const char* string) {					//Assignment operators for String objects from a string of characters

	length = int(strlen(string));
	buf = new char[length + 1];
	for (int i = 0; i < length; i++) {
		buf[i] = string[i];
	}
	
	buf[length] = '\0';

	return *this;
}

String operator + (const String& string1, const String& string2) {		//Overloaded addition operator to concatenate two String objects
	int totalLength = string1.length + string2.length;
	String sum;

	sum.buf = new char[totalLength + 1];
	sum.length = totalLength;

	for (int i = 0; i < string1.length; ++i) {
		sum.buf[i] = string1.buf[i];
	}

	for (int i = string1.length; i < totalLength; i++){
		sum.buf[i] = string2.buf[i - string1.length];

	}
	sum.buf[totalLength] = '\0';

	return sum;
}

String operator + (const String& string1, const char* string2) {		//Overloaded addition operator to concatenate a String object and a string of characters
	int totalLength = string1.length + strlen(string2);
	String sum;

	sum.buf = new char[totalLength + 1];
	sum.length = totalLength;

	for (int i = 0; i < string1.length; ++i) {
		sum.buf[i] = string1.buf[i];
	}

	for (int i = string1.length; i < totalLength; i++) {
		sum.buf[i] = string2[i - string1.length];

	}
	sum.buf[totalLength] = '\0';

	return sum;
}

String operator + (const char* string1, const String& string2) {		//Overloaded addition operator to concatenate a String object and a string of characters
	int totalLength = strlen(string1) + string2.length;
	String sum;

	sum.buf = new char[totalLength + 1];
	sum.length = totalLength;

	for (int i = 0; i < int(strlen(string1)); ++i) {
		sum.buf[i] = string1[i];
	}

	for (int i = strlen(string1); i < totalLength; i++) {
		sum.buf[i] = string2.buf[i - strlen(string1)];

	}
	sum.buf[totalLength] = '\0';

	return sum;
}

String operator + (const String& string1, char char1) {					//Overloaded addition operator to concatenate a String object and a single character
	int totalLength = string1.length + 1;
	String sum;

	sum.buf = new char[totalLength + 1];
	sum.length = totalLength;

	for (int i = 0; i < string1.length; ++i) {
		sum.buf[i] = string1.buf[i];
	}

	sum.buf[totalLength - 1] = char1;									//Character is placed at the end of the String object
	sum.buf[totalLength] = '\0';

	return sum;
}

String operator + (char char1, const String& string1) {					//Overloaded addition operator to concatenate a String object and a single character
	int totalLength = string1.length + 1;
	String sum;

	sum.buf = new char[totalLength + 1];
	sum.length = totalLength;

	for (int i = 1; i < totalLength; ++i) {
		sum.buf[i] = string1.buf[i-1];
	}

	sum.buf[0] = char1;													//Character is placed at the beginning of the String object
	sum.buf[totalLength] = '\0';

	return sum;
}

String& String::operator += (const String& string2) {					//Addition operator to concatenate a String object to an existing String object
	int totalLength = length + string2.length;					
	char* sum = new char[totalLength + 1];

	for (int i = 0; i < length; ++i) {
		sum[i] = buf[i];
	}
	
	for (int i = length; i < totalLength; ++i) {
		sum[i] = string2.buf[i - length];
	}

	length = totalLength;												//Resizing to prevent overflow
	buf = new char[length + 1];

	for (int i = 0; i < length; ++i) {
		buf[i] = sum[i];
	}

	buf[length] =  '\0';

	return *this;

}

String String::operator+() const{									//Unary operator that returns a String object in uppercase
	String upperCase;
	upperCase.buf = new char[length + 1];
	upperCase.length = length;

	for (int i = 0; i < length; ++i) {
		upperCase [i] = buf[i];
	}

	for (int i = 0; i < length; ++i) {
		upperCase[i] = toupper(upperCase[i]);
	}

	upperCase[length] = '\0';

	return upperCase;

}

int operator == (const String& string1, const String& string2) {	//Compares two String objects for equality.  Returns 1 if the same length and all elements are equal.  Returns 0 otherwise.
	if (string1.length != string2.length) {
		return 0;
	}

	else {
		for (int i = 0; i < string1.length; ++i) {
			if (string1.buf[i] != string2.buf[i]) {
				return 0;
			}

		}
	}


	return 1;
}

int operator != (const String& string1, const String& string2) {	//Compares two String objects for inequality.  Returns 1 if unequal length or elements are not equal.  Returns 0 if equal.
	if (string1.length != string2.length) {
		return 1;
	}

	else {
		for (int i = 0; i < string1.length; ++i) {
			if (string1.buf[i] != string2.buf[i]) {
				return 1;
			}

		}
	}


	return 0;
}

int operator < (const String& left, const String& right) {		//Compares two String objects for equality.  Returns 1 if left is shorter.  Returns 0 if longer or any left element is greater.
	if (left == right) {										//Uses equality operator to check for total equality.  Returns 0 if equal.
		return 0;
	}
	
	else if (left.length > right.length) {						//If left is longer than right, returns 0.
		return 0;
	}

	else {														//Compares elements. If any single element is greater, returns 0.
		for (int i = 0; i < left.length; ++i) {
			if (left.buf[i] > right.buf[i]) {
				return 0;
			}

		}
	}

	return 1;
}

int operator <= (const String& left, const String& right) {		//Compares two String objects for equality.  Returns 1 if equal or left is shorter.  Returns 0 if longer or any left element is greater.
	if (left == right) {												//Uses equality operator to check for total equality.  Returns 1 if equal.
		return 1;
	}

	else if (left.length > right.length) {								//If left is longer than right, returns 0.
		return 0;
	}

	else {
		for (int i = 0; i < left.length; ++i) {							//Compares elements. If any single left element is greater, returns 0.
			if (left.buf[i] > right.buf[i]) {
				return 0;
			}

		}
	}


	return 1;
}

int operator > (const String& left, const String& right) {			//Compares two String objects for equality.  Returns 1 if left is longer.  Returns 0 if shorter or any left element is less.	
	if (left == right) {												//Uses equality operator to check for total equality.  Returns 0 if equal.
		return 0;
	}

	else if (left.length < right.length) {								//If left is shorter than right, returns 0.
		return 0;
	}

	else {
		for (int i = 0; i < left.length; ++i) {							//Compares elements. If any single left element is less, returns 0.
			if (left.buf[i] < right.buf[i]) {
				return 0;
			}

		}
	}

	return 1;
}

int operator >= (const String& string1, const String& string2) {	//Compares two String objects for equality.  Returns 1 if left is longer.  Returns 0 if shorter or any left element is less.
	if (string1 == string2) {											//Uses equality operator to check for total equality.  Returns 1 if equal.
		return 1;
	}

	else if (string1.length < string2.length) {							//If left is shorter than right, returns 0.
		return 0;
	}

	else {
		for (int i = 0; i < string1.length; ++i) {						//Compares elements. If any single left element is less, returns 0.
			if (string1.buf[i] < string2.buf[i]) {
				return 0;
			}

		}
	}


	return 1;
}


char& String::operator[](int index) {					//Overloaded bracket operator allows the character elements to be accessed in array notation
	char error = '\0';

	if (index < 0 || index > length) {																//Error checking if index is out of range
		cout << "Error: Illegal operation. Index out of range.  Halt." << endl << endl;		
		csis << "Error: Illegal operation. Index out of range.  Halt." << endl << endl;
		return error;
	}
	else
		return buf[index];

}

char* operator+ (const String& string1, int index) {			//Overloaded + operator to allow elements to be accessed with pointer notation ie. *(string + index)
	return &string1.buf[index];
}

char* operator+(int index, const String& string1) {				//Overloaded + operator to allow elements to be accessed with pointer notation ie. *(index + string)
	return &string1.buf[index];
}

String& String::operator++() {									//Prefix increment operator adds 1 to each individual element and returns the resulting String
	for (int i = 0; i < length; i++) {
		buf[i] = (buf[i] + 1);
	}

	return *this;
}

String& String::operator--() {									//Prefix decrement operator subtracts 1 to each individual element and returns the resulting String
	for (int i = 0; i < length; i++) {
		buf[i] = (buf[i] - 1);
	}

	return *this;
}

String String::operator++(int num) {							//Postfix increment operator adds 1 to each individual element and returns the original String
	String original;
	original.length = length;
	original.buf = new char[length + 1];

	for (int i = 0; i < length; i++) {
		original.buf [i] = buf[i];
	}
	for (int i = 0; i < length; i++) {
		buf[i] = (buf[i] + 1);
	}

	original.buf[length] = '\0';
	return original;
}

String String::operator--(int num) {							//Postfix decrement operator subtracts 1 to each individual element and returns the original String
	String original;
	original.length = length;
	original.buf = new char[length + 1];

	for (int i = 0; i < length; i++) {
		original.buf[i] = buf[i];
	}
	for (int i = 0; i < length; i++) {
		buf[i] = (buf[i] - 1);
	}

	original.buf[length] = '\0';
	return original;
}

int String::getLength(){										//Returns length of String object
	return length;
}

String String::substr(int index, int stringLength) {			//Creates a substring given a starting index and a desired length
	String substring;
	substring.length = stringLength;
	substring.buf = new char[length + 1];

	for (int i = 0; i < length; i++) {
		substring.buf[i] = buf[i + index];
	}

	substring.buf[stringLength] = '\0';

	return substring;
}

void String::print() {															//Print function to display the string and length
	cout << "\"" << buf << "\"" << " " << "Length is " << length << endl;
	csis << "\"" << buf << "\"" << " " << "Length is " << length << endl;
}

ostream& operator<<(ostream&os, const String& string1) {						//Overloaded output operator to output the string
	for (int i = 0; i < string1.length; i++) {
		os << string1.buf[i];
	}
	return os;
}