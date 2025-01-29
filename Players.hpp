#pragma once
using namespace std;

struct Hand {
    int size;
    vector<Card> cards;
};

struct Player {
    string name;
    Hand third_hand;
    Hand second_hand;
    Hand first_hand;
    CardPile cards_to_assign;
};


