/*
*  game1.cpp
*  Chris Hopp - 010809627
*  v. 03.02.2018
*
*/

#ifndef _GAME1_H
#define _GAME1_H

#include "card.h"
#include "deck.h"

class Game {
private:
	Card hand[5];						//Declarations
	Deck deck;						

	int pairs;							//Variables
	int flushes;						
	int handNumber = 0;					
	int trials = 10;					
	int totalHands = 10000;				
	double pairPercent;					
	double flushPercent;				

	bool isFlush();						//Private Functions
	bool isPair();					
	void returnCards();

public:
	void deal();						//Public Function
};
#endif