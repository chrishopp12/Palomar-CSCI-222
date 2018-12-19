/* 
Constructor Lab (Bar Codes)

Chris Hopp - 010809627

3.16.2018


*/



#include <fstream>
#include <iostream>
#include <string>

#include "ZipCode.h"

using namespace std;

ZipCode::ZipCode(int inputZipCode) {					// Constructor to create zip code objects from an integer zip code input
	zipCode = inputZipCode;
	barCode = "";
	zipToBar(inputZipCode);
}

ZipCode::ZipCode(string inputBarCode) {					// Constructor to create zip code objects from a string bar code input
	barCode = inputBarCode;
	zipCode = 0;
	barToZip(inputBarCode);
}

string ZipCode::zipToBar(int zipCode) {					// Converts integer zip codes to string bar codes
	barCode = "1";										// Add last "1" digit for bar code

	while (zipCode > 0) {								// Zip code will be reduced as while loop parses each digit from the end
		int digit = zipCode % 10;						// Takes value of end digit of the zip code integer

		if (digit == 0) {								// Each statement adds the appropriate string bar code segment to the bar code string based on the corresponding digit
			barCode = "11000" + barCode;
		}

		else if (digit == 1) {
			barCode = "00011" + barCode;
		}

		else if (digit == 2) {
			barCode = "00101" + barCode;
		}

		else if (digit == 3) {
			barCode = "00110" + barCode;
		}

		else if (digit == 4) {
			barCode = "01001" + barCode;
		}

		else if (digit == 5) {
			barCode = "01010" + barCode;
		}

		else if (digit == 6) {
			barCode = "01100" + barCode;
		}

		else if (digit == 7) {
			barCode = "10001" + barCode;
		}

		else if (digit == 8) {
			barCode = "10010" + barCode;
		}

		else if (digit == 9) {
			barCode = "10100" + barCode;
		}

		else {
			cout << "Error: Improper zipcode format" << endl;
		}
				
		zipCode /= 10;									// Reduces zip code to eliminate the last digit already parsed
	}
	barCode = "1" + barCode;							// Add first "1" digit for bar code string
	return barCode;
}

int ZipCode::barToZip(string barCode) {
									
	string code = barCode;
	code.erase(code.begin());							// Eliminates first "1" digit for bar code string
	code.erase(code.begin() + 25);						// Eliminates last "1" digit for bar code string


	while (code.length() > 0) {							//While loop parses as long as the string contains data
		string zipDigit = code.substr(0, 5);			//Obtains first 5-digit segment of bar code to be converted

														// Each statement adds the appropriate integer digit corresponding to the 5-digit string segment by multiplying by
		if (zipDigit == "11000") {						//	10 to place the previous value at one place to the left and adding the appropriate integer value
			zipCode = zipCode * 10;				
		}
		
		else if (zipDigit == "00011") {
			zipCode = zipCode * 10 + 1;					
		}

		else if (zipDigit == "00101") {
			zipCode = zipCode * 10 + 2;					
		}

		else if (zipDigit == "00101") {
			zipCode = zipCode * 10 + 3;					
		}

		else if (zipDigit == "01001") {
			zipCode = zipCode * 10 + 4;					
		}

		else if (zipDigit == "01010") {
			zipCode = zipCode * 10 + 5;					
		}

		else if (zipDigit == "01100") {
			zipCode = zipCode * 10 + 6;					
		}

		else if (zipDigit == "10001") {
			zipCode = zipCode * 10 + 7;					
		}

		else if (zipDigit == "10010") {
			zipCode = zipCode * 10 + 8;					
		}

		else if (zipDigit == "10100") {
			zipCode = zipCode * 10 + 9;					
		}
		else {
			cout << "Error: Improper barcode format" << endl;
		}

		code = code.substr(5);							//Eliminates string segment that has been parsed		
	}
		
	return zipCode;										//Returns integer zip code value
}

int ZipCode::getZipCode() {								// Getter to return the integer zip code
	return zipCode;
}

string ZipCode::getBarCode() {							// Getter to return the string bar code
	return barCode;
}

