#include "sudoku.hpp"
#include <iostream>

using namespace std;

int    BOARD_HEIGHT           = 9;
int    BOARD_WIDTH            = BOARD_HEIGHT;
int    BOX_SIZE               = 3;
string BOX_SEPARATOR          = "\u2502";
string CORNER_DOWN_LEFT       = "\u2514";
string CORNER_DOWN_RIGHT      = "\u2518";
string CORNER_UP_LEFT         = "\u250c"; 
string CORNER_UP_RIGHT        = "\u2510";
string LINE                   = "\u2500";
string TWOWAY_LEFT_CONNECTOR  = "\u251c";
string TWOWAY_RIGHT_CONNECTOR = "\u2524"; 

Sudoku::Sudoku(board_t start_board) : board(start_board) {}

Sudoku::Sudoku(string import_string) {
    row_t row;
    for (int i=0; i < import_string.length(); ++i) {
        /*
         * For each char in the string, if you take away the ascii value of 0
         * You get the actual value of the char
         * e.g. 49(ASCII value of 1) - 48 (Ascii value of 0) -> 1
         */
        row.push_back(import_string[i] - '0');
        if (row.size() ==  BOARD_WIDTH) {
            board.push_back(row);
            row.clear();
        };
    }
}

Sudoku::Sudoku() {
    for (int i=0; i < BOARD_HEIGHT; ++i) {
        row_t row; 
        for (int j=0; j < BOARD_WIDTH; ++j) {
            row.push_back(0);
        }
        board.push_back(row);
    }
}

void Sudoku::print() {
    int sepDiff = board[0].size() / 3 + 1;
    int sepSize = board.size() + sepDiff;
    
    // Build the initial separator 
    for (int x=0; x < sepSize; ++x) {
        if (x == 0) cout << CORNER_UP_LEFT;
        else if (x == sepSize - 1) cout << CORNER_UP_RIGHT;
        else cout << LINE;
    }
    cout << endl;

    // Print out all the values
    for (int i=0; i < board.size(); ++i) {
        // First separator of the line
        cout << BOX_SEPARATOR;

        // Print actual values
        for (int j=0; j < board[i].size(); ++j) {
            cout << board[i][j];
            // If we're at the horizontal end of a box, then print a box separator
            if ((j + 1) % BOX_SIZE == 0) {
                cout << BOX_SEPARATOR;
            }
        }
        cout << endl;

        // If we're at the vertical end of a box, print a full line
        if ((i + 1) % BOX_SIZE == 0) {
            for (int x=0; x < sepSize; ++x) {
                // If we're not on the last (or first) line, connect this line to the others
                if (x == 0) {
                    if (i < board.size() - 1) cout << TWOWAY_LEFT_CONNECTOR;
                    else cout << CORNER_DOWN_LEFT;
                }
                else if (x == sepSize - 1) {
                    if (i < board.size() - 1) cout << TWOWAY_RIGHT_CONNECTOR;
                    else cout << CORNER_DOWN_RIGHT;
                }
                else {
                    cout << LINE;
                }

            }
            cout << endl;
        }

        // TODO Connect horizontal lines
    }
}

vector<int> Sudoku::getPossible(int y, int x) {
    vector<bool> possibles = {true, true, true, true, true, true, true, true, true};
    vector<int> possibles_actual;

    // Take the possibles from the rows and columns
    for (int i=0; i < board.size(); ++i) {
        for (int j=0; j < board[i].size(); ++j) {
            if (i == y || x == j) {
                int val = board[i][j];
                if (val != 0) possibles[val - 1] = false;
            }
        }
    }

    // Take the possibles from the box
    while (y % BOX_SIZE != 0) --y;
    while (x % BOX_SIZE != 0) --x;
    for (int i=y; i < y + 3; ++i) {
        for (int j=x; j < x + 3; ++j) {
            int val = board[i][j];
            if (val != 0) possibles[val - 1] = false;
        }
    }

    for (int x=0; x < possibles.size(); ++x) {
        if (possibles[x]) possibles_actual.push_back(x + 1);
    }
    return possibles_actual;
}

void Sudoku::advance() {    
    board_t newBoard;
    for (int i=0; i < board.size(); ++i) {
        row_t row;
        for (int j=0; j < board[i].size(); ++j) {
            vector<int> possible = getPossible(i, j);
            row.push_back(possible.size() == 1 && board[i][j] == 0 ? possible[0] : board[i][j]);
        }
        newBoard.push_back(row);
    }
    board = newBoard;
}

string Sudoku::exportString() {
    string output = "";
    for (auto i : board) {
        for (auto j : i) {
            output += j + '0';
        }
    }
    return output;
}

void Sudoku::solve() {
    string lastString = "";
    string newString  = "";
    while (true) {
        advance();
        newString = exportString();
        if (lastString == newString) {
            return;
        }
        else {
            lastString = newString;
        }
    }
}

