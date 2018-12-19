/*
*  deck.h
*  Poker
*
*  Created by Richard Stegman on 5/28/12.
*  Copyright 2012. All rights reserved.
*
*/

#ifndef _DECK_H
#define _DECK_H

#include "card.h"

const int DECKSIZE = 52;

class Deck {
private:
	Card inDeck[DECKSIZE];            // These are private data members and
	int nextCard;                     // can be used only by member functions.
public:
	Deck();                           // Initialization. Called automatically
									  // when a Deck variable is declared.
	void shuffle(int);                // Exchange random pairs of cards.
	Card getCard();                   // Returns top card from the deck.
	void addCard(Card);               // Put named card in the deck.
	int totalCards();                 // Returns number of cards left in deck.
};

#endif
