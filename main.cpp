#include "sudoku.hpp"
#include <iostream>

using namespace std;

int main() {
    string board = "000105000140000670080002400063070010900000003010090520007200080026000035000409000";
    Sudoku game = board;
    game.print();
    game.solve();
    game.print();
    cout << game.exportString() << endl;
    return 0;
}

