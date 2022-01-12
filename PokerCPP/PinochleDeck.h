#pragma once
#include "Deck.h"
class PinochleDeck : public Deck {
	short cards[48]; // Array of cards
	short currentCard; // A certain highlighted card (see functions)
	void shuffle(); // What it says
public:
	PinochleDeck(); // Default ctor. All we need
	Card deal(); // Deals a card
};

