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

