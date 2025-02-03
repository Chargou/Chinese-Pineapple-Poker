#include <iostream>
#include <vector>
#include <array>
#include "Cards.hpp"
#include "Players.hpp"
using namespace std;

Hand initHand(const int size) {
    return {size, {}};
}

ostream& operator<<(ostream& os, const Hand& hand) {
    for (auto card : hand.cards)
        os << card << " ";
    for (int i = hand.size-hand.cards.size(); i>0; i--)
        os << "-- ";
    return os;
}

void addCard(Hand& Hand, const Card card) {
    Hand.cards.push_back(card);
}

Player initPlayer() {
    Player player;
    cout << "What's the player's name ? "; cin >> player.name;
    player.hands = {{{5, {}}, {5, {}}, {3, {}}}};
    player.cards_to_assign = {{}};
    return player;
}

ostream& operator<<(ostream& os, const Player& player) {
    os << player.name << ":" << endl;
    for (int i=3; i>0; i--)
        cout << i << ": " << player.hands[i-1] << endl;
    if (not isEmpty(player.cards_to_assign))
        cout << "Cards left to assign: " << player.cards_to_assign;
    return os;
}

void assignCard(Player &player, const Card card) {
    int n;
    do {
        cout << "Which hand do you want to assign the card: " << card << " to? "; cin >> n;
    } while (n<1 or 3<n);
    Hand& target = player.hands[n-1];
    if (target.size == target.cards.size()) {
        cout << "That hand is already full..." << endl;
        return assignCard(player, card);
    }
    addCard(target, card);
}

void assignCard(Player& player) {
    assignCard(player, getLastCard(player.cards_to_assign));
}

void assignAllCards(Player& player) {
    while (not isEmpty(player.cards_to_assign)) {
        cout << player;
        assignCard(player);
    }
}

void dealNCards(CardPile& deck, Player& player, const int n) {
    for (int _=0; _<n; _++) player.cards_to_assign.cards.push_back(getLastCard(deck));
}

