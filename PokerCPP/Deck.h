/*
* DECK CLASS
* Stores a standard deck of 52 cards with associated shuffling and dealing logic
* Consider making it a minimal (abstract) class from which subclasses Standard, Pinochle (etc.) inherit
*/

#pragma once
#include "Card.h"

class Deck {
	short cards[52]; // Array of cards
	short currentCard; // A certain highlighted card (see functions)
	void shuffle(); // What it says
public:
	Deck(); // Default ctor. All we need
	Card deal(); // Deals a card
};

