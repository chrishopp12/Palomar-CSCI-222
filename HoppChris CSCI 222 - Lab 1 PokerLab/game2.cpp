/*
*  game1.cpp
*  Chris Hopp - 010809627
*  v. 03.02.2018
*
*/

#include "game2.h"
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "stdlib.h"
#include "time.h"

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <fstream>



using namespace std;
ofstream csis;

void Game2::deal() {
	srand((unsigned)time(NULL));										

	double totalFlush = 0;
	double totalPair = 0;

	cout << fixed << setprecision(2);				//Displays Header
	csis << fixed << setprecision(2);
	cout << setw(14) << "Trial Number" << setw(24) << "Number of Hands Dealt" << setw(24) << "Number of pairs" << setw(24) << "Number of flushes" << setw(24) << "Percent pairs" << setw(24) << "Percent Flushes" << endl;
	csis << setw(14) << "Trial Number" << setw(24) << "Number of Hands Dealt" << setw(24) << "Number of pairs" << setw(24) << "Number of flushes" << setw(24) << "Percent pairs" << setw(24) << "Percent Flushes" << endl;


	for (int j = 0; j < trials; j++) {
		handNumber = 0;														
		hand.flushes = 0;													
		hand.pairs = 0;													
		for (int k = 0; k < totalHands; k++) {
			deck.shuffle(100);												

			for (int i = 0; i < 5; i++) {									//Builds a 5 card hand
				hand.hand[i] = deck.getCard();
			}

			if (hand.isFlush()) {									//Increases the counter if the hand is a flush
				hand.flushes++;
				totalFlush++;
			}

			if (hand.isPair()) {									//Increases the counter if the hand is a pair
				hand.pairs++;
				totalPair++;
			}
			returnCards();

			handNumber++;

		}


		//Calculates percentages of flushes and pairs
		flushPercent = (double(hand.flushes) / double(handNumber)) * 100;
		pairPercent = (double(hand.pairs) / double(handNumber)) * 100;


		// Prints information
		cout << setw(14) << (j + 1) << setw(24) << handNumber << setw(24) << hand.pairs << setw(24) << hand.flushes << setw(24) << pairPercent << setw(24) << flushPercent << endl;
		csis << setw(14) << (j + 1) << setw(24) << handNumber << setw(24) << hand.pairs << setw(24) << hand.flushes << setw(24) << pairPercent << setw(24) << flushPercent << endl;


	}

	// Prints total percentage information
	cout << "Total flush percentage: " << setw(14) << totalFlush / (totalHands * trials) * 100 << endl;
	cout << "Total pair percentage: " << setw(14) << totalPair / (totalHands * trials) * 100 << endl;


	csis << "Total flush percentage: " << setw(14) << totalFlush / (totalHands * trials) * 100 << endl;
	csis << "Total pair percentage: " << setw(14) << totalPair / (totalHands * trials) * 100 << endl;
	
}

void Game2::returnCards() {				//Returns cards to the deck
	for (int i = 0; i < 5; i++) {
		deck.addCard(hand.hand[i]);
	}

}

int main() {							//Runs the program
	csis.open("csis2.txt");
	Game2 game;															
	game.deal();													

	csis.close();
}