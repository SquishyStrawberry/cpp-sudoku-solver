#ifndef _SUDOKU_HPP_
#define _SUDOKU_HPP_
#include <vector>
#include <string>

using namespace std;

extern int    BOARD_HEIGHT;
extern int    BOARD_WIDTH;
extern int    BOX_SIZE;
extern string BOX_SEPARATOR;
extern string CORNER_DOWN_LEFT;
extern string CORNER_DOWN_RIGHT;
extern string CORNER_UP_LEFT;
extern string CORNER_UP_RIGHT;
extern string LINE;
extern string TWOWAY_LEFT_CONNECTOR;
extern string TWOWAY_RIGHT_CONNECTOR;
 

typedef vector<int> row_t;
typedef vector<row_t> board_t;

class Sudoku {
    public:
    board_t board;
    Sudoku();
    Sudoku(board_t);
    void print();
};

#endif // _SUDOKU_HPP_
