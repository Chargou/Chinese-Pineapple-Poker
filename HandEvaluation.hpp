#pragma once
#include <iostream>
#include <vector>
#include "Cards.hpp"
#include "Players.hpp"
using namespace std;

/*
10. Royal flush //5 //Compare suit
A, K, Q, J, 10, all the same suit
9. Straight flush //5 //Compare highcard(kicker)
Five cards in a sequence, all in the same suit.
8. Four of a kind //4 //Compare dominant value
All four cards of the same rank.
7. Full house //5 //Compare dominant value
Three of a kind with a pair.
6. Flush //5 //Compare suit then highcard(kicker)
Any five cards of the same suit, but not in a sequence.
5. Straight //5 //Compare highcard(kicker)
Five cards in a sequence, but not of the same suit.
4. Three of a kind //3 //Compare dominant value
Three cards of the same rank.
3. Two pair //4 //Compare dominant value then secondary value then kicker
Two different pairs.
2. Pair //2 //Compare dominant value then kicker
Two cards of the same rank.
1. High Card //1 //Compare highcard(kicker)
When you haven't made any of the hands above, the highest card plays.
*/

struct HandEvaluation {
    int rank;
    Suit suit;
    Value dominant_value;
    Value secondary_value;
    Card kicker;
};

const array<string, 11> rank_to_string = {"?!?","High card", "Pair", "Two pair", "Three of a kind", "Straight", "Flush", "Full", "Four of a kind", "Straight flush", "Royal flush"};

HandEvaluation initHandEvaluation(const Hand& hand);

bool operator<(const HandEvaluation& lhs, const HandEvaluation& rhs);
bool operator>(const HandEvaluation& lhs, const HandEvaluation& rhs);

ostream& operator<<(ostream&, const HandEvaluation&);
