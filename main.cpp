#include "sudoku.hpp"
#include <iostream>

using namespace std;

int main() {
    string board;
    getline(cin, board);
    Sudoku game = board;
    game.print();
    game.solve();
    game.print();
    cout << game.exportString() << endl;
    return 0;
}

