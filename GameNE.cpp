#include <iostream>
#include <vector>
#include "Cards.hpp"
#include "Players.hpp"
#include "Game.hpp"
using namespace std;

void playGame() {
    int player_count;
    cout << "Welcome to Pineapple Chinese Poker !" << endl;
    cout << "How many players today ?" << endl; cin >> player_count;
    vector<Player> players;
    for (int i = 0; i < player_count; i++)
        players.push_back(initPlayer());

    auto deck = initDeck();
    shuffleDeck(deck);
    for (int n: {5, 4, 4}) {
        for (auto &player : players) {
            dealNCards(deck, player, n);
            assignAllCards(player);
        }
    }
    cout << endl;
    cout << "Final state of the game:" << endl;
    for (auto &player : players) {
        cout << player << endl;
    }
}
