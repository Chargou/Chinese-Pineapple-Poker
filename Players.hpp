#pragma once
#include <iostream>
#include <vector>
#include <array>
#include "Cards.hpp"
using namespace std;

struct Hand {
    int size;
    vector<Card> cards;
};

ostream& operator<<(ostream&, const Hand&);

struct Player {
    string name;
    array<Hand, 3> hands;
    CardPile cards_to_assign;
};

ostream& operator<<(ostream&, const Player&);

Hand initHand(int size);

void addCard(Hand&, Card);

Player initPlayer();

void assignCard(Player&, Card);
void assignCard(Player&);
void assignAllCards(Player&);

void dealNCards(CardPile&, Player&, int);

