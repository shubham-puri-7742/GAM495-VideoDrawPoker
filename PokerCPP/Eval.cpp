#include "Eval.h"

// Checks if something repeats n times
bool Eval::repeats(short n) {
	// For each of the rank counters
	for (short i = 0; i < 13; ++i)
		// If something repeats exactly n times
		if (rankCounts[i] == n)
			return true;
	// (implicitly 'else')
	return false;
}

// STRAIGHT: If 5 consecutive cards are dealt (e.g. 4, 5, 6, 7, 8 - but in any order)
bool Eval::straight() {
	// For the first 8 counters (because the last 'straight' can have counters equal to 1 for indices 8 to 12, inclusive)
	for (short i = 0; i <= 8; ++i)
		// When the first counter reading 1 is found
		if (rankCounts[i] == 1)
			// return the result of this helper (which checks contiguity)
			return checkStraight(i);
	return false;
}

// Helper function for finding straights. Detects contiguity
bool Eval::checkStraight(short n) {
	// Check the next 4 cards
	for (short i = n + 1; i < n + 5; ++i)
		// If any of their counters is not 1, there is no way this is a straight
		if (rankCounts[i] != 1)
			return false;
	return true;
}

// FLUSH: 5 of the same suit
bool Eval::flush() {
	// For each suit counter
	for (short i = 0; i < 4; ++i)
		// If there are 5 cards of a suit
		if (suitCounts[i] == 5)
			return true;
	return false;
}

// TWO-PAIR: Needs no explanation.
bool Eval::twoPair() {
	short n = 0; // counter for pairs
	// For each card counter
	for (short i = 0; i < 13; ++i)
		// If there are two cards of a rank (a pair)
		if (rankCounts[i] == 2)
			++n; // We have + 1 pair
	// The loop basically counts pairs
	return n == 2; // This checks if that count is 2 (for a hand of 5 cards, you can only have 0, 1, or 2 pairs)
}

Eval::Eval(Card* cards) { // Ctor
	// Initialise each card counter to 0
	for (short i = 0; i < 13; ++i) {
		rankCounts[i] = 0;
	}
	// Initialise each suit counter to 0
	for (short i = 0; i < 4; ++i) {
		suitCounts[i] = 0;
	}

	// Since we initialise on a hand, we iterate over its elements
	for (short i = 0; i < 5; ++i) {
		// Get the rank and suit of the current card
		short r = cards[i].rank;
		short s = cards[i].suit;
		// And increment the corresponding count
		++rankCounts[r];
		++suitCounts[s];
	}
}

// Gets the final result to display
std::string Eval::rankHands() {
	std::string s;
	// STRAIGHT (and) FLUSH
	if (straight() && flush()) {
		// ROYAL FLUSH: A straight flush from 10 to A (we only need to check if a straight flush has the last two cards. Two, because aces can be low as well - LOW ACES NOT IMPLEMENTED YET)
		if (rankCounts[12] && rankCounts[11]) {
			s = "You have a ROYAL FLUSH! PAYOUT = 800";
		}
		// A simple straight flush
		else {
			s = "You have a STRAIGHT FLUSH! PAYOUT = 50";
		}
	}
	// FOUR OF A KIND: self-explanatory
	else if (repeats(4)) {
		s = "You have FOUR OF A KIND! PAYOUT = 25";
	}
	// FULL HOUSE: Three of a kind + Pair
	else if (repeats(3) && repeats(2)) {
		s = "You have a FULL HOUSE! PAYOUT = 9";
	}
	// FLUSH: 5 of the same suit
	else if (flush()) {
		s = "You have a FLUSH! PAYOUT = 6";
	}
	// STRAIGHT: 5 in a row (irrespective of the order)
	else if (straight()) {
		s = "You have a STRAIGHT! PAYOUT = 4";
	}
	// THREE OF A KIND: self-explanatory
	else if (repeats(3)) {
		s = "You have THREE OF A KIND! PAYOUT = 3";
	}
	// TWO-PAIR: self-explanatory
	else if (twoPair()) {
		s = "You have a TWO-PAIR! PAYOUT = 2";
	}
	// PAIR: self-explanatory. This is where you break even
	else if (repeats(2)) {
		s = "You have a pair. PAYOUT = 1";
	}
	// NOTHING. You lose everything
	else {
		s = "You have no pair. PAYOUT = 0";
	}
	return s;
}
