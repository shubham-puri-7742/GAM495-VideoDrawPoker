#pragma once
#include "Deck.h"

class NormalDeck : public Deck {
	short cards[52]; // Array of cards
	short currentCard; // A certain highlighted card (see functions)
	void shuffle(); // What it says
public:
	NormalDeck(); // Default ctor. All we need
	Card deal(); // Deals a card
};