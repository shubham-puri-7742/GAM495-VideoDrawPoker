/*
* EVALUATOR CLASS
* Evaluates poker hands
* (Consider adding more hands)
*/

#pragma once
#include <string>
#include "Card.h"

class Eval {
	// We initialise arrays of ints as counters for each rank and suit. This makes it easy to spot patterns regardless of the order in which the cards are dealt
	short rankCounts[13];
	short suitCounts[4];
	// Checks if anything repeats n times
	bool repeats(short n);
	// Booleans for the named hands. Straight uses a helper function
	bool bigTiger();
	bool littleTiger();
	bool straight();
	bool checkStraight(short n);
	bool bicycle();
	bool flush();
	bool twoPair();

public:
	Eval(Card* cards); // We only need a parameterised ctor on an array of cards (a hand). Although not explicit, we assume a hand has 5 cards (see function logic, particularly straight)
	std::string rankHands(); // Output hand and payout. Sorry but you'll have to make do with virtual bu¢k$ here
};