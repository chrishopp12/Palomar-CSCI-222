/*
*  game1.cpp
*  Chris Hopp - 010809627
*  v. 03.02.2018
*
*/

#ifndef _HAND_H
#define _HAND_H

#include "card.h"
#include "deck.h"

class Hand {
	friend class Game2;
private:
	Card hand[5];						//Declarations

	int pairs;							//Variables						
	int flushes;						

public:
	bool isFlush();						//Public functions
	bool isPair();
};

#endif
