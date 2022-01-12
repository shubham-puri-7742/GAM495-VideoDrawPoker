/*
* DECK CLASS
* Abstract base class for a deck
*/

#pragma once
#include "Card.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Deck {
public:
	virtual Card deal() = 0; // Deals a card
};