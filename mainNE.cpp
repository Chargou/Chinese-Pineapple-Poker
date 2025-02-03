#include <iostream>
#include "GameNE.hpp"
using namespace std;

int main() {
    bool playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (0/1) "; cin >> playAgain;
    } while (playAgain);
    return EXIT_SUCCESS;
}
