#include "Card.h"

std::ostream& operator<<(std::ostream& os, const Card& card) {
	//							INDICES:   0     1     2     3     4     5     6     7     8     9    10    11    12
	static const std::string ranks[] = { " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K", " A" }; // The extra space is to align the 10
	//							INDICES:   0     1     2     3
	static const std::string suits[] = { "\3", "\4", "\5", "\6" }; // (Alt-codes for suit symbols - Hearts, Diamonds, Clubs, Spades)
	os << ranks[card.rank] + ' ' + suits[card.suit] + '.'; // e.g. " A ♠." (w/o quotes)
	return os;
}