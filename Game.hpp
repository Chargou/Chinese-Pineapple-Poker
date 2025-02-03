#pragma once
#include <iostream>
#include <vector>
#include "Cards.hpp"
#include "Players.hpp"
#include "HandEvaluation.hpp"
using namespace std;

void playGame();

void coutPlayerWithEvals(const Player&, const vector<HandEvaluation>&);

