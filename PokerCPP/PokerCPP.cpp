#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Eval.h"
using namespace std;

// Deck and hand (of 5 cards)
Deck deck;
Card hand[5];

// The main play-game function
void play() {
    // Deal 5 cards and display each card dealt
    for (short i = 0; i < 5; ++i) {
        hand[i] = deck.deal();
        cout << i + 1 << ". " << hand[i].display() << '\n'; // Possible refactoring: Overload << for the Card class
    }

    // Blank line at the end
    cout << endl;

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
