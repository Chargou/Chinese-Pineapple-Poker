#include <vector>
#include <map>
#include "Cards.hpp"
#include "Players.hpp"
#include "HandEvaluation.hpp"
using namespace std;

HandEvaluation initHandEvaluation(const Hand& hand) {
    HandEvaluation res{};
    vector<Card> sorted_hand;
    for (int i=51; i>=0; i--)
        for (auto card: hand.cards)
            if (DefaultDeck.cards[i] == card)
                sorted_hand.push_back(card);
    map<Value, int> valueAppearances;
    for (const auto& card: sorted_hand)
        valueAppearances[card.value]++;

    if (sorted_hand.size() == 5) {
        bool is_straight = true, is_flush = true;
        res.suit = sorted_hand[0].suit;
        for (const auto& card: sorted_hand) {
            if (card.suit != res.suit) {
                is_flush = false;
                break;
            }
        }
        for (int i=0; i<4; i++) {
            if (static_cast<int>(sorted_hand[i].value)-static_cast<int>(sorted_hand[i + 1].value) != 1) {
                is_straight = false;
                break;
            }
        }
        if (is_straight) {
            if (is_flush) {
                if (sorted_hand[0].value == Value::Ace) {
                    res.rank = 10;
                    return res;
                }
                res.rank = 9;
                res.kicker = sorted_hand[0];
                return res;
            }
            res.rank = 5;
            res.kicker = sorted_hand[0];
            return res;
        }
        if (is_flush) {
            res.rank = 6;
            res.kicker = sorted_hand[0];
            return res;
        }
        if (valueAppearances.size() == 2) {
            if (valueAppearances[sorted_hand[0].value] == 1) {
                res.rank = 8;
                res.dominant_value = sorted_hand[1].value;
                return res;
            }
            if (valueAppearances[sorted_hand[0].value] == 4) {
                res.rank = 8;
                res.dominant_value = sorted_hand[0].value;
                return res;
            }
            if (valueAppearances[sorted_hand[0].value] == 2) {
                res.rank = 7;
                res.dominant_value = sorted_hand[2].value;
                return res;
            }
            res.rank = 7;
            res.dominant_value = sorted_hand[0].value;
            return res;
        }
        if (valueAppearances.size() == 3) {
            bool two_pair = false;
            for (const auto& pair: valueAppearances) {
                if (pair.second == 3)
                    break;
                if (pair.second == 2) {
                    res.rank = 3;
                    if (two_pair) {
                        if (res.dominant_value > pair.first)
                            res.secondary_value = pair.first;
                        else {
                            res.secondary_value = res.dominant_value;
                            res.dominant_value = pair.first;
                        }
                    }
                    else {
                        two_pair = true;
                        res.dominant_value = pair.first;
                    }
                }
                else {
                    for (const auto& card: sorted_hand) {
                        if (card.value == pair.first) {
                            res.kicker = card;
                            break;
                        }
                    }
                }
            }
            if (two_pair) {
                return res;
            }
        }
    }
    for (const auto& pair: valueAppearances) {
        switch (pair.second) {
            case 3: res.rank=4;
                    res.dominant_value = pair.first;
                    return res;
            case 2: res.rank=2;
                    res.dominant_value = pair.first;
                    if (sorted_hand[0].value != pair.first) {
                        res.kicker = sorted_hand[0];
                        return res;
                    }
                    res.kicker = sorted_hand[2];
                    return res;
            default: break;
        }
    }
    res.rank = 1;
    res.kicker = sorted_hand[0];
    return res;
}

bool operator>(const HandEvaluation& lhs, const HandEvaluation& rhs) {
    if (lhs.rank > rhs.rank)
        return true;
    if (lhs.rank < rhs.rank)
        return false;
    switch (lhs.rank) {
        case 10: return lhs.suit > rhs.suit;
        case 9: case 5: case 1: return lhs.kicker > rhs.kicker;
        case 8: case 7: case 4: return lhs.dominant_value > rhs.dominant_value;
        case 6: if (lhs.suit == rhs.suit) return lhs.kicker > rhs.kicker;
                return lhs.suit > rhs.suit;
        case 3: if (lhs.dominant_value == rhs.dominant_value) {
                    if (lhs.secondary_value == rhs.secondary_value)
                        return lhs.kicker > rhs.kicker;
                    return lhs.secondary_value > rhs.secondary_value;
                }
                return lhs.dominant_value > rhs.dominant_value;
        case 2: if (lhs.dominant_value == rhs.dominant_value)
                    return lhs.kicker > rhs.kicker;
                return lhs.dominant_value > rhs.dominant_value;
        default: throw runtime_error("Comparing two hands with same rank, but outside of 1-10 range ???");
    }
}
bool operator<(const HandEvaluation& lhs, const HandEvaluation& rhs) {return rhs > lhs;}

ostream& operator<<(ostream& os, const HandEvaluation& he) {
    os << "{rank=" << he.rank << ", suit=" << he.suit << ", dominant_value=" << he.dominant_value << ", secondary_value=" << he.secondary_value << ", kicker=" << he.kicker << "}";
    return os;
}
/*
Bug:
3: TH JS KC        High card
2: 2D 4H 4C TD 6H  Pair
1: 6S 8S 9H 5C 6C  Pair
Invalid board... It's a bust !
???:
3: 4C 6S 7S        High card
{rank=1, suit=C, dominant_value=2, secondary_value=2, kicker=7S}
2: 8S TD QH 3S KS  High card
{rank=1, suit=S, dominant_value=2, secondary_value=2, kicker=KS}
1: 6D 9H 3C AS AD  Pair
{rank=2, suit=S, dominant_value=A, secondary_value=2, kicker=9H}
Invalid board... It's a bust !
 */