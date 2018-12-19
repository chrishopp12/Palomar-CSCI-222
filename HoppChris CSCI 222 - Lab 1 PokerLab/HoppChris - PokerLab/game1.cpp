/*
*  game1.cpp
*  Chris Hopp - 010809627
*  v. 03.02.2018
*  
*/

#include "game1.h"
#include "card.h"
#include "deck.h"
#include "stdlib.h"
#include "time.h"

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <fstream>

using namespace std;
ofstream csis;

void Game::deal() {
	srand((unsigned)time(NULL));										

	double totalFlush=0;
	double totalPair=0;

	cout << fixed << setprecision(2);				//Displays Header
	csis << fixed << setprecision(2);
	cout << setw(14) << "Trial Number" << setw(24) << "Number of Hands Dealt" << setw(24) << "Number of pairs" << setw(24) << "Number of flushes" << setw(24) << "Percent pairs" << setw(24) << "Percent Flushes" << endl;
	csis << setw(14) << "Trial Number" << setw(24) << "Number of Hands Dealt" << setw(24) << "Number of pairs" << setw(24) << "Number of flushes" << setw(24) << "Percent pairs" << setw(24) << "Percent Flushes" << endl;

	for (int j = 0; j < trials; j++) {
		handNumber = 0;													
		flushes = 0;													
		pairs = 0;													
		for (int k = 0; k < totalHands; k++) {
			deck.shuffle(100);											

			for (int i = 0; i < 5; i++) {							//Builds a hand of 5 cards	
				hand[i] = deck.getCard();
			}

			if (isFlush()) {										//Increases the counter if the hand is a flush
				flushes++;
				totalFlush++;
			}
			if (isPair()) {											//Increases the counter if the hand is a pair
				pairs++;
				totalPair++;
			}

			returnCards();

			handNumber++;
		}

		flushPercent = (double(flushes) / double(handNumber)) * 100;		//Calculates percentages of flushes and pairs
		pairPercent = (double(pairs) / double(handNumber)) * 100;		


		// Prints information
		cout << setw(14) << (j + 1) << setw(24) << handNumber << setw(24) << pairs << setw(24) << flushes << setw(24) << pairPercent << setw(24) << flushPercent << endl;
		csis << setw(14) << (j + 1) << setw(24) << handNumber << setw(24) << pairs << setw(24) << flushes << setw(24) << pairPercent << setw(24) << flushPercent << endl;

	
	}
	
	// Prints total percentage information
	cout << "Total flush percentage: " << setw(14) << totalFlush / (totalHands * trials) * 100 <<endl;
	cout <<"Total pair percentage: " << setw(14) << totalPair/ (totalHands * trials) * 100 << endl;


	csis << "Total flush percentage: " << setw(14) << totalFlush / (totalHands * trials) * 100 << endl;
	csis << "Total pair percentage: " << setw(14) << totalPair / (totalHands * trials) * 100 << endl;
}

bool Game::isPair() {		//Determines if the hand is a pair by comparing each card								

	for (int i = 0; i < 5; i++) {								
		for (int j = i + 1; j < 5; j++) {						
			if (hand[i].getValue() == hand[j].getValue()) {
				return true;
			}
		}
	}
	return false;
}

bool Game::isFlush() {		//Determines if the hand is a flush by comparing the cards to the first card
												
	for (int i = 1; i < 5; i++) {								
		if (hand[i].getSuit() != hand[0].getSuit()) {			
			
			return false;
		}
	}
	return true;
}

void Game::returnCards() {			//Returns cards to the deck
	for (int i = 0; i < 5; i++) {								
		deck.addCard(hand[i]);
	}

}

int main() {						//Runs the program
	csis.open("csis1.txt");										
	Game game;													
	game.deal();												
	csis.close();												
}