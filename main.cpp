#include "sudoku.hpp"
#include <iostream>

using namespace std;

int main() {
    Sudoku game = (board_t){
        {0, 0, 0, 1, 0, 5, 0, 0, 0},
        {1, 4, 0, 0, 0, 0, 6, 7, 0},
        {0, 8, 0, 0, 0, 2, 4, 0, 0},
        {0, 6, 3, 0, 7, 0, 0, 1, 0},
        {9, 0, 0, 0, 0, 0, 0, 0, 3},
        {0, 1, 0, 0, 9, 0, 5, 2, 0},
        {0, 0, 7, 2, 0, 0, 0, 8, 0},
        {0, 2, 6, 0, 0, 0, 0, 3, 5},
        {0, 0, 0, 4, 0, 9, 0, 0, 0}
    };
    string lastString = "";
    while (true) {
        game.print();
        game.advance();
        if (lastString == game.exportString()) {
            cout << game.exportString() << endl;
            return 0;
        }
        else {
            lastString = game.exportString();
        }
    }
}

