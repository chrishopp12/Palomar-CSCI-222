/*
Constructor Lab (Bar Codes)

Chris Hopp - 010809627

3.16.2018

*/

#include <iostream>

#ifndef _ZIPCODE_H
#define _ZIPCODE_H

using namespace std;

class ZipCode {
private:
	int zipCode;						// Variable for the zip code value as an integer
	string barCode;						// Variable for the bar code as a string

	string zipToBar(int zipCode);		// Converts integer zip codes to string bar codes
	int barToZip(string barCode);		// Converts string bar codes to integer zip codes

public:
	ZipCode(int zipCode);				// Overloaded constructor for zip code objects input as integers
	ZipCode(string barCode);			// Overloaded constructor for zip code objects input as a bar code string

	int getZipCode();					// Returns zip code as an integer
	string getBarCode();				// Returns bar code as a string
};

#endif

