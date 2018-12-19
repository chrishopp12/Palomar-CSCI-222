/*
Lab 5 - Polymorphism Lab (Library Holdings)
Author:  Chris Hopp - 010809627
Version: 05.18.2018

*/

#include "recording.h"

#include <fstream>

extern ofstream csis;

Recording::Recording(const Recording& recording1) : Holding(recording1) {				//Recording derived copy constructor 

	int formatLength;
	for (int i = 0; recording1.format[i] != '\0'; i++) { formatLength = i; }

	format = new char[formatLength + 1];

	for (int i = 0; i < formatLength; i++) {
		format[i] = recording1.artist[i];
	}
	format[formatLength] = '\0';
}

Recording::Recording(char* recordingTitle, char* recordingArtist, char recordingFormat, int recordingNumber) : Holding(recordingTitle, recordingArtist, recordingNumber) {
																					//4 arg derived constructor
	if (recordingFormat == 'M' || recordingFormat == 'm') {							//sets format based on operator input
		format = new char[4];

		format = strcpy(format, "MP3");

	}

	else if (recordingFormat == 'W' || recordingFormat == 'w') {
		format = new char[4];

		format = strcpy(format, "WAV");

	}
	
	else if (recordingFormat == 'A' || recordingFormat == 'a') {
		format = new char[5];

		format = strcpy(format, "AIFF");

	}

	else {
		cout << "Error: Unrecognized format" << endl;
		csis << "Error: Unrecognized format" << endl;
	}
}

Recording& Recording::operator = (const Recording& recording1){						//Assignment operator for Recording objects (Rule of Three)
	Holding::operator = (recording1);

	int formatLength;
	for (int i = 0; recording1.format[i] != '\0'; i++) { formatLength = i; }

	format = new char[formatLength + 1];

	for (int i = 0; i < formatLength; i++) {
		format[i] = recording1.artist[i];
	}
	format[formatLength] = '\0';

	return *this;
}

void Recording::print() {																								//Recording specific print function
	cout << "RECORDING: \"" << title << "\" " << artist << " (" << format << ") " << callNumber << endl;
	csis << "RECORDING: \"" << title << "\" " << artist << " (" << format << ") " << callNumber << endl;

}

Recording::~Recording() {					//Recording destructor
	delete[] format;
}