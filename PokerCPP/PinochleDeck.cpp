#include "PinochleDeck.h"

void PinochleDeck::shuffle() {
	currentCard = 0;
	for (short i = 47; i > 0; --i) {
		// Pick a random card in the unshuffled part
		short j = rand() % (i + 1);

		// Swap that card with the ith card
		short temp = cards[i];
		cards[i] = cards[j];
		cards[j] = temp;
		// Since i starts up top, the lower part (divided at i) is unshuffled
	}
}

PinochleDeck::PinochleDeck() {
	// Seed rand
	srand(time(nullptr));
	// Store ints 0 to 46 for the cards
	for (short i = 0; i < 47; ++i) {
		cards[i] = i;
	}
	// Shuffle on initialisation
	shuffle();
}

Card PinochleDeck::deal() {
	// If at the top
	if (currentCard > 47) {
		std::cout << "Reshuffling..." << std::endl;
		shuffle();
	}
	// deal a card based on the current ID number
	short r = (cards[currentCard] % 6) + 7; // 9 to A
	short s = (cards[currentCard++] % 24) / 6; // 0 to 3
	return Card(r, s);
}
