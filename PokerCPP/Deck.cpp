#include "Deck.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void Deck::shuffle() {
	currentCard = 0; // Start with the first (zeroth) card)
	// For each other card in reverse order
	for (short i = 51; i > 0; --i) {
		// Pick a random card in the unshuffled part
		short j = rand() % (i + 1);

		// Swap that card with the ith card
		short temp = cards[i];
		cards[i] = cards[j];
		cards[j] = temp;
		// Since i starts up top, the lower part (divided at i) is unshuffled
	}
}

Deck::Deck() { // ctor
	// Seed rand
	srand(time(nullptr));
	// Store ints 0 to 51 for the cards
	for (short i = 0; i < 52; ++i) {
		cards[i] = i;
	}
	// Shuffle on initialisation
	shuffle();
}

Card Deck::deal() { // Deal a card
	//
	if (currentCard > 51) {
		std::cout << "Reshuffling..." << std::endl;
		shuffle();
	}
	// deal a card based on the current ID number - the rank is (% 13) and the suit is (/ 13) or floor divided
	short r = cards[currentCard] % 13;
	short s = cards[currentCard++] / 13;
	return Card(r, s);
}
