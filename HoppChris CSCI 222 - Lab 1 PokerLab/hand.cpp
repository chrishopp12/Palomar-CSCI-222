/*
*  game1.cpp
*  Chris Hopp - 010809627
*  v. 03.02.2018
*
*/

#include "hand.h"
#include "card.h"
#include "deck.h"

using namespace std;

bool Hand::isPair() {									//Determines if the hand is a pair by comparing each card							

		for (int i = 0; i < 5; i++) {
			for (int j = i + 1; j < 5; j++) {
				if (hand[i].getValue() == hand[j].getValue()) {
					return true;
				}
			}
		}
		return false;
	}

bool Hand::isFlush() {									//Determines if the hand is a flush by comparing the cards to the first card

	for (int i = 1; i < 5; i++) {
		if (hand[i].getSuit() != hand[0].getSuit()) {

			return false;
		}
	}
	return true;
}

