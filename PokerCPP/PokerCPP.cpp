#include <iostream>
#include <string>
#include "Game.h"
using namespace std;

int main() {
    // Create a game session instance
    Game session;
    // Assume playing
    string s = "y";

    // do-loop because we want to play at least once
    do {
        cout << "* VIDEO DRAW POKER *\n";
        // Just what it says
        session.play();
        cout << "Play again? (Y/N): ";
        getline(cin, s); // Get input
    } while (tolower(s[0]) != 'n'); // Default choice is 'play again'

    return 0;
}
