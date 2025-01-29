#include <iostream>
#include "Game.hpp"
#include "Players.hpp"
#include "Cards.hpp"
using namespace std;

void playGame() {
    int player_count;
    cout << "Welcome to Pineapple Chinese Poker !" << endl;
    cout << "How many players today ?" << endl; cin >> player_count;
    array<Player, player_count> players;
    for (auto& player: players)
        player = initPlayer();
}