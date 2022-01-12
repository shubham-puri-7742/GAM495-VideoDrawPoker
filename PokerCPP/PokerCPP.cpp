#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Card.h"
#include "NormalDeck.h"
#include "PinochleDeck.h"
#include "Eval.h"
using namespace std;

// Deck and hand (of 5 cards)
Deck* deck;
Card hand[5];
bool flags[5];
vector<short> selectionVec;

// Redrawing cards
bool draw() {
    // Get the input as a string of indices to redraw
    string input;
    // Clear the selection vector
    selectionVec.clear();
    // Get the input
    cout << "Input the #s of cards to redraw: ";
    getline(cin, input);
    // If nothing is entered, we are not redrawing
    if (input.size() == 0)
        return false;
    // We get below this point if we are redrawing

    // Redraw flags. To prevent repeat redraws
    bool redrawFlags[5];
    // Assume redrawing everything
    for (short i = 0; i < 5; ++i)
        redrawFlags[i] = true;

    // For each element of the input
    for (short i = 0; i < input.size(); ++i) {
        // Get the input minus '0' (this gets the number of the card to redraw)
        short n = input[i] - '0';
        // If it is in a valid range (1-5, inclusive) AND not already redrawn
        if (n >= 1 && n <= 5 && redrawFlags[n - 1]) {
            // Push back the index (number - 1) and disallow the redraw flag for it
            selectionVec.push_back(n - 1);
            redrawFlags[n - 1] = false;
        }
    }

    // For each element of the selection
    for (short i = 0; i < selectionVec.size(); ++i) {
        // Get the element of the vector
        short j = selectionVec[i];
        /*
        * DEBUG
        cout << "Redrawing " << j + 1 << endl;
        */
        // Deal a new card for the specified slot
        hand[j] = deck->deal();
        // And flag it as redrawn
        flags[j] = true;
    }

    return true; // Because we redrew some cards
}

// The main play-game function
void play() {
    // Set all the redraw flags to false (default to no redraws)
    for (short i = 0; i < 5; ++i) {
        flags[i] = false;
    }

    cout << "Pick your deck:\n1) Standard\n2) Pinochle\n";
    string deckChoice;
    getline(cin, deckChoice);

    switch (stoi(deckChoice)) {
    case 2:
        deck = new PinochleDeck;
        break;
    default:
        cout << "Invalid selection. Defaulting to a standard deck...\n";
	case 1:
		deck = new NormalDeck;
		break;
    }

    // Deal 5 cards and display each card dealt
    for (short i = 0; i < 5; ++i) {
        hand[i] = deck->deal();
        cout << i + 1 << ". " << hand[i] << '\n'; // Possible refactoring: Overload << for the Card class
    }

    // Blank line at the end
    cout << endl;

	// If redrawing
	if (draw()) {
		// For each of the cards in the hand
		for (short i = 0; i < 5; ++i) {
			// Display the card
			cout << i + 1 << ". " << hand[i];
			// If redrawn
			if (flags[i]) {
				// Add a star
				cout << "*";
			}
			cout << endl; // Formatting
		}
		cout << endl; // More formatting
	}

    // Evaluate the hand dealt
    Eval handEval(hand); // Initialise the evaluator on the hand
    cout << handEval.rankHands() << endl; // Display the results
}

int main() {
    // Assume playing
    string s = "y";
    // do-loop because we want to play at least once
    do {
        // Just what it says
        play();
        cout << "Play again? (Y/N): ";
        getline(cin, s); // Get input
    } while (tolower(s[0]) != 'n'); // Default choice is 'play again'

    return 0;
}
