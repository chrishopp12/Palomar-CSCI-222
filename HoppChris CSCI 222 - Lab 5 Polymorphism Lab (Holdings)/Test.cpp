/*
Lab 5 - Polymorphism Lab (Library Holdings)
Author:  Chris Hopp - 010809627
Version: 05.18.2018

*/

#include "Holding.h"
#include "Test.h"

#include <fstream>

using namespace std;

ofstream csis;

int main() {
	csis.open("csis.txt");

	Holding** cart = new Holding*[numberOfHoldings];							//Creates an array of pointers to Holding Objects

	cout << "Enter holdings to be stored in a list: " << endl << endl;					//Prompts user to enter holding information
	csis << "Enter holdings to be stored in a list: " << endl << endl;

	for (int i = 0; i < numberOfHoldings; i++) {
		cart[i] = interface();
	}

	cout << endl << endl << "Here are the holdings: " << endl << endl;
	csis << endl << endl << "Here are the holdings: " << endl << endl;

	for (int i = 0; i < numberOfHoldings; i++) {								//Prints each item using proper print function
		cart[i]->print();
	}

}


Holding * interface() {															//Operator interface to enter book or recording objects
	Holding* item = nullptr;
	
	char holdingTitle[MAX];
	char holdingArtist[MAX];
	int holdingNumber;
	char input;

	cout << "Enter B for book, R for recording: " ;
	csis << "Enter B for book, R for recording: " ;
	cin >> input; cin.ignore();



	if (input == 'B' || input == 'b') {											//Creates a "Book" object on user prompt
		
		csis << " B" << endl;
		
		cout << "Enter book title: ";
		cin.getline(holdingTitle, MAX);
		csis << "Enter book title: " << holdingTitle << endl;

		cout << "Enter book author: ";
		cin.getline(holdingArtist, MAX);
		csis << "Enter book author: " << holdingArtist << endl;

		cout << "Enter call number: ";
		cin >> holdingNumber;
		csis << "Enter call number: " << holdingNumber << endl;

		item = new Book(holdingTitle, holdingArtist, holdingNumber);

		return item;
	}


	else if (input == 'R' || input == 'r') {									//Creates a "Recording" object on user prompt

		char recordingFormat;

		csis << " R" << endl;

		cout << "Enter recording title: ";
		cin.getline(holdingTitle, MAX);
		csis << "Enter recording title: " << holdingTitle << endl;

		cout << "Enter performer: ";
		cin.getline(holdingArtist, MAX);
		csis << "Enter performer: " << holdingArtist << endl;

		cout << "Enter format: (M)P3, (W)AV, (A)IFF: ";
		cin >> recordingFormat;
		csis << "Enter format: (M)P3, (W)AV, (A)IFF: " << recordingFormat << endl;

		cout << "Enter call number: ";
		cin >> holdingNumber;
		csis << "Enter call number: " << holdingNumber << endl;

		item = new Recording(holdingTitle, holdingArtist, recordingFormat, holdingNumber);

		return item;
	}

	else {
		cout << "Error: invalid selection" << endl;
		csis << "Error: invalid selection" << endl;
	}

	return item;															//Returns "Holding" item as default (null)
}