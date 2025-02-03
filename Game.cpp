#include <iostream>
#include <vector>
#include "Cards.hpp"
#include "Players.hpp"
#include "HandEvaluation.hpp"
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
    for (int n: {5, 3, 3, 3, 3}) {
        for (auto &player : players) {
            dealNCards(deck, player, n);
            assignAllCards(player);
        }
    }
    vector<vector<HandEvaluation>> playersHandsEvaluations;
    for (auto &player : players) {
        vector<HandEvaluation> handEvaluations;
        for (auto &hand : player.hands)
            handEvaluations.push_back(initHandEvaluation(hand));
        playersHandsEvaluations.push_back(handEvaluations);
        coutPlayerWithEvals(player, handEvaluations);
    }

}

void coutPlayerWithEvals(const Player &player, const vector<HandEvaluation> &handEvaluations) {
    cout << player.name << ":" << endl;
    for (int i=2; i>=0; i--) {
        cout << i+1 << ": " << player.hands[i];
        if (i==2) cout << "      ";
        cout << " " << rank_to_string[static_cast<int>(handEvaluations[i].rank)] << endl;
    }
    if (handEvaluations[2]>handEvaluations[1] or handEvaluations[1]>handEvaluations[0])
        cout << "Invalid board... It's a bust !" << endl;
    else {
        int score = 0;
        switch (handEvaluations[0].rank) {
            case 10: score += 25; break;
            case 9: score += 15; break;
            case 8: score += 10; break;
            case 7: score += 6; break;
            case 6: score += 4; break;
            case 5: score += 2; break;
            default: ;
        }
        switch (handEvaluations[1].rank) {
            case 10: score += 50; break;
            case 9: score += 30; break;
            case 8: score += 20; break;
            case 7: score += 12; break;
            case 6: score += 8; break;
            case 5: score += 4; break;
            case 4: score += 2; break;
            default: ;
        }
        switch (handEvaluations[2].rank) {
            case 4: score += max(0, static_cast<int>(handEvaluations[2].dominant_value)-3); break;
            case 2: score += 10+static_cast<int>(handEvaluations[2].dominant_value); break;
            default: ;
        }
        cout << "Valid board ! Here is your score: " << score << endl;
    }
}

