#include <iostream>
#include "Game.hpp"
using namespace std;

int main() {
    bool playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (0/1) "; cin >> playAgain;
    } while (playAgain);
    return EXIT_SUCCESS;
}

/* testing before making game.cpp:
CardPile Deck = initDeck();
    shuffleDeck(Deck);
    auto p = initPlayer();
    dealNCards(Deck, p, 5);
    assignAllCards(p);
    dealNCards(Deck, p, 4);
    assignAllCards(p);
    dealNCards(Deck, p, 4);
    assignAllCards(p);
    cout << p;
*/