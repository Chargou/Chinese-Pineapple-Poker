#include <iostream>
#include <vector>
#include "Cards.hpp"
#include "Players.hpp"
using namespace std;

int main() {
    CardPile Deck = initDeck();
    shuffleDeck(Deck);
    cout << Deck << endl;
    cout << getLastCard(Deck) << endl;
    cout << Deck << endl;
    return 0;
}