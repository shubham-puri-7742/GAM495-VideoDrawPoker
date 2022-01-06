/*
* CARD CLASS
* Stores data for a single card as an ordered pair (rank, suit)
*/

#pragma once
#include <string>

class Card {
public:
	Card() {} // Default ctor. We don't really use it all that much
	Card(short r, short s) : rank(r), suit(s) {} // The real deal
	short rank, suit; // Rank and suit are short ints
	std::string display(); // Consider overloading <<
};

