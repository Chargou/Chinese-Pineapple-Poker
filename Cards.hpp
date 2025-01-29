#pragma once
#include <iostream>
#include <vector>
using namespace std;

enum class Suit {Clubs, Diamonds, Hearts, Spades};
enum class Value {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

struct Card {
    Value value;
    Suit suit;
};

struct CardPile {
    vector<Card> cards;
};

bool operator<(Suit, Suit);
bool operator>(Suit, Suit);
bool operator==(Suit, Suit);

bool operator<(Value, Value);
bool operator>(Value, Value);
bool operator==(Value, Value);

bool operator>(const Card&, const Card&);
bool operator==(const Card&, const Card&);
bool operator!=(const Card&, const Card&);
bool operator<(const Card&, const Card&);

ostream& operator<<(ostream&, const Suit&);
ostream& operator<<(ostream&, const Value&);
ostream& operator<<(ostream&, const Card&);
ostream& operator<<(ostream&, const CardPile&);

/**
 * Default deck containing all (52) cards
 */
const CardPile DefaultDeck = {
    {
        {Value::Two, Suit::Clubs}, {Value::Two, Suit::Diamonds}, {Value::Two, Suit::Hearts}, {Value::Two, Suit::Spades},
        {Value::Three, Suit::Clubs}, {Value::Three, Suit::Diamonds}, {Value::Three, Suit::Hearts}, {Value::Three, Suit::Spades},
        {Value::Four, Suit::Clubs}, {Value::Four, Suit::Diamonds}, {Value::Four, Suit::Hearts}, {Value::Four, Suit::Spades},
        {Value::Five, Suit::Clubs}, {Value::Five, Suit::Diamonds}, {Value::Five, Suit::Hearts}, {Value::Five, Suit::Spades},
        {Value::Six, Suit::Clubs}, {Value::Six, Suit::Diamonds}, {Value::Six, Suit::Hearts}, {Value::Six, Suit::Spades},
        {Value::Seven, Suit::Clubs}, {Value::Seven, Suit::Diamonds}, {Value::Seven, Suit::Hearts}, {Value::Seven, Suit::Spades},
        {Value::Eight, Suit::Clubs}, {Value::Eight, Suit::Diamonds}, {Value::Eight, Suit::Hearts}, {Value::Eight, Suit::Spades},
        {Value::Nine, Suit::Clubs}, {Value::Nine, Suit::Diamonds}, {Value::Nine, Suit::Hearts}, {Value::Nine, Suit::Spades},
        {Value::Ten, Suit::Clubs}, {Value::Ten, Suit::Diamonds}, {Value::Ten, Suit::Hearts}, {Value::Ten, Suit::Spades},
        {Value::Jack, Suit::Clubs}, {Value::Jack, Suit::Diamonds}, {Value::Jack, Suit::Hearts}, {Value::Jack, Suit::Spades},
        {Value::Queen, Suit::Clubs}, {Value::Queen, Suit::Diamonds}, {Value::Queen, Suit::Hearts}, {Value::Queen, Suit::Spades},
        {Value::King, Suit::Clubs}, {Value::King, Suit::Diamonds}, {Value::King, Suit::Hearts}, {Value::King, Suit::Spades},
        {Value::Ace, Suit::Clubs}, {Value::Ace, Suit::Diamonds}, {Value::Ace, Suit::Hearts}, {Value::Ace, Suit::Spades},
    }
};

CardPile initDeck();

void shuffleDeck(CardPile&);

Card getLastCard(CardPile&);

bool isEmpty(const CardPile&);

