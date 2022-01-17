/*
* GAME CLASS
* Incorporates the gameplay logic
* And the redrawing logic
* From an older version of main
*/

#pragma once
#include <vector>
#include "Deck.h"

class Game {
	// Deck and hand (of 5 cards)
	Deck* deck;
	Card hand[5];
	bool flags[5];
	std::vector<short> selectionVec;

public:
	// Redrawing cards
	bool draw();
	// The main play-game function
	void play();
};