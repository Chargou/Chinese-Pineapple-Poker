#include <iostream>
#include <vector>
#include "Cards.hpp"
using namespace std;



bool operator<(const Suit c1, const Suit c2) { return int(c1) < int(c2); }
bool operator>(const Suit c1, const Suit c2) { return int(c1) > int(c2); }
bool operator==(const Suit c1, const Suit c2) { return int(c1) == int(c2); }

bool operator<(const Value v1, const Value v2) { return int(v1) < int(v2); }
bool operator>(const Value v1, const Value v2) { return int(v1) > int(v2); }
bool operator==(const Value v1, const Value v2) { return int(v1) == int(v2); }

bool operator>(const Card& c1, const Card& c2) {
    if (c1.value>c2.value) return true;
    else if (c1.value<c2.value) return false;
        else {
            if (c1.suit>c2.suit) return true;
            else if (c1.suit<c2.suit) return false;
                else throw logic_error("The two cards have the same value and suit ???");
        }
}
bool operator==(const Card& c1, const Card& c2) { return c1.value==c2.value and c1.suit==c2.suit; }
bool operator!=(const Card& c1, const Card& c2) { return not (c1==c2); }
bool operator<(const Card& c1, const Card& c2) { return c2>c1; }

const char *card_suits_in_order = "CDHS";
ostream& operator<<(ostream& os, const Suit& suit) {
    os << card_suits_in_order[int(suit)];
    return os;
}
const char *card_values_in_order = "23456789TJQKA";
ostream& operator<<(ostream& os, const Value& value) {
    os << card_values_in_order[int(value)];
    return os;
}
ostream& operator<<(ostream& os, const Card& card) {
    os << card.value << card.suit;
    return os;
}

ostream& operator<<(ostream& os, const CardPile& card_pile) {
    os << "(";
    for (int i=0; i<card_pile.cards.size()-1; i++)
        os << card_pile.cards[i] << ", ";
    os << card_pile.cards.back() << ")";
    return os;
}

CardPile initDeck() {return DefaultDeck;}

void shuffleDeck(CardPile& card_pile) {
    srand(time(NULL));
    for (int _ = 0; _<1000; _++) {
        const int i1 = rand() % card_pile.cards.size();
        const int i2 = rand() % card_pile.cards.size();
        const Card c1 = card_pile.cards[i1];
        card_pile.cards[i1] = card_pile.cards[i2];
        card_pile.cards[i2] = c1;
    }
}

Card getLastCard(CardPile& card_pile) {
    const Card card = card_pile.cards.back();
    card_pile.cards.pop_back();
    return card;
}

