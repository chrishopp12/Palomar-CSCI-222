/*
*  deck.cpp
*  Poker
*
*  Created by Richard Stegman 5/28/12.
*  Copyright 2010. All rights reserved.
*
*/

#include <stdlib.h>
#include "deck.h"

Deck::Deck() {
	int i;
	Card::Suit curSuit;
	Card::Value curValue;

	nextCard = 0;
	for (i = 0, curSuit = Card::Diamonds, curValue = Card::Ace; i < DECKSIZE; i++) {
		inDeck[i] = Card(curSuit, curValue);
		curValue = nextValue(curValue);
		if (curValue == Card::Ace)
			curSuit = nextSuit(curSuit);
	}
}

void Deck::shuffle(int swaps) {
	Card temp;

	for (int i = 0; i < swaps; i++) {
		int i1 = rand() % DECKSIZE;
		int i2 = rand() % DECKSIZE;
		temp = inDeck[i1];
		inDeck[i1] = inDeck[i2];
		inDeck[i2] = temp;
	}
}

Card Deck::getCard() {
	return(nextCard < DECKSIZE) ? inDeck[nextCard++] : Card(Card::Clubs, Card::NullCard);
}

void Deck::addCard(Card newCard) {
	if (nextCard > 0)
		inDeck[--nextCard] = newCard;
}

int Deck::totalCards() {
	return DECKSIZE - nextCard;
}

