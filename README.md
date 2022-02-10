# GAM495-VideoDrawPoker
### Console-based video draw poker in modern C++

The program deals 5 random cards to the player and evaluates the hand based on the rules for some of the most common Poker hands. The program allows the player to redraw some cards before the hand is evaluated, should the player wish to have a chance at getting a better hand.

The card data is encoded as short ints and the rank and suit is evaluated using the remainder operator. A deck is therefore just an array of ints.

The redraw logic reads an input string from the player and parses it for single-digit ints. Repeats are ignored.

One of the major additions to the last iteration of this project was making the decks polymorphic, so that special decks (Pinochle in this repo as of writing this) can be added later without modifying parts of the core deck class.

The highlight of this project, however, is the hand evaluation. It uses an array of counts for ranks and suits (all initialised to 0). The reason this method is used is that it makes easy to spot hands such as straights, which - while sequential - do not necessarily depend on the order in which the cards are dealt (e.g. 4, 7, 6, 8, 5 is still a straight).

### Reflection

This program borrows parts inspired by my IT312 project, which was a dice game (Liar's Dice), except instead of rolling five dice, we deal five cards here. This changes the way a card's data is encoded, but the use of random numbers remains more or less identical, except that (for the standard deck) the values are restricted from 0 to 51, which are further divided into groups (suits) of 13.

The initial iteration simply dealt five cards. The evaluator class was added to it and the second build could evaluate some hands. Notably, the bicycle, little tiger, and big tiger hands were not part of this iteration. The most significant challenge for evaluating the hands was making the evaluation independent of the order in which cards were dealt. The use of arrays of counters greatly simplified this task.

The next iteration added the extra hands and the logic to allow redrawing cards. A significant challenge here was preventing redrawing the same card twice if the user entered the same number twice (e.g. 2, 3, 2). Similar to the use of arrays in evaluating hands, this was overcome by having an array of redraw flags.

The last iteration added the support for custom decks through polymorphism. The deck class was redesigned into an abstract class, and two subclasses were created for the standard and Pinochle decks. More decks can be added as needed. Also, the code from main was refactored into a separate game class with minimal modification.
