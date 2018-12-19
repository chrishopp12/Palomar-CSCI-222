/*
*  game1.cpp
*  Chris Hopp - 010809627
*  v. 03.02.2018
*
*/

#ifndef _GAME2_H
#define _GAME2_H

#include "card.h"
#include "deck.h"
#include "hand.h"

class Game2 {
private:
	Hand hand;							//Declarations
	Deck deck;

	int handNumber = 0;					// Variables
	int trials = 10;
	int totalHands = 10000;
	double pairPercent;					
	double flushPercent;				

	void returnCards();					//Private Functions

public:
	void deal();						//Public Functions
};

#endif
