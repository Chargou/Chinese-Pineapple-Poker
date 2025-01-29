#include <iostream>
#include <vector>
#include "Cards.hpp"
#include "Players.hpp"
using namespace std;

Hand initHand(const int size) {
    return {size, {}};
}

void addCard(Hand& Hand, const Card card) {
    Hand.cards.push_back(card);
}



