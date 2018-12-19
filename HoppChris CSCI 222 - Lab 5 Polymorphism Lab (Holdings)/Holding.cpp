/*
Lab 5 - Polymorphism Lab (Library Holdings)
Author:  Chris Hopp - 010809627
Version: 05.18.2018

*/

#include "holding.h"


using namespace std;

Holding::Holding(const Holding& holding1) {					//Holding copy constructor

	callNumber = holding1.callNumber;
	int titleLength;
	int artistLength;


	for (int i = 0; holding1.title[i] != '\0'; ++i) { titleLength = i + 1; }

	title = new char[titleLength + 1];
	
	for (int i = 0; i <= titleLength; i++) {
		title[i] = holding1.title[i];
	}
	title[titleLength] = '\0';

	for (int i = 0; holding1.artist[i] != '\0'; ++i) { artistLength = i + 1; }


	artist = new char[artistLength + 1];

	for (int i = 0; i <= artistLength; i++) {
		artist[i] = holding1.artist[i];
	}
	artist[artistLength] = '\0';

}

Holding::Holding(char* name, char* author, int num) {					//3 arg base constructor

	callNumber = num;

	int titleLength;
	int artistLength;

	for (int i = 0; name[i] != '\0'; ++i) { titleLength = i+1; }
	
	title = new char[titleLength];

	for (int i = 0; i <= titleLength; i++) {
		title[i] = name[i];
	}
	title[titleLength] = '\0';


	for (int i = 0; author[i] != '\0'; ++i) { artistLength = i+1; }

	artist = new char[artistLength];

	for (int i = 0; i <= artistLength; i++) {
		artist[i] = author[i];
	}
	artist[artistLength] = '\0';

}


Holding& Holding::operator = (const Holding& holding1) {					//Assignment operator for Holding objects (Rule of Three)
	callNumber = holding1.callNumber;
	int titleLength;
	int artistLength;

	for (int i = 0; holding1.title[i] != '\0'; ++i) { titleLength = i + 1; }

	title = new char[titleLength + 1];

	for (int i = 0; i <= titleLength; i++) {
		title[i] = holding1.title[i];
	}
	title[titleLength] = '\0';


	for (int i = 0; holding1.artist[i] != '\0'; ++i) { artistLength = i + 1; }

	artist = new char[artistLength + 1];

	for (int i = 0; i <= artistLength; i++) {
		artist[i] = holding1.artist[i];
	}
	artist[artistLength] = '\0';

	return *this;
}

Holding::~Holding() {				//Holding destructor
	delete[] title;
	delete[] artist;
	callNumber = 0;
}

void Holding::print() {};			//Virtual print