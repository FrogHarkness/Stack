
#include <assert.h>
#include <stdio.h>
#include "connect.h"
#include "cs136-trace.h"

const char NONE = '_';
const char RED = 'R';
const char YELLOW = 'Y';

// The number of pieces that have to be in a straight line (horizontal of
//   vertical) in order to win the game.
static const int WINLENGTH = 4;

// The width / number of columns of the Connect Four board.
static const int WIDTH = 7;

// The height / number of rows of the Connect Four board.
static const int HEIGHT = 6;

// get_char(board, c, r) returns the player who's piece is in column c and
//   row r.
// requires: c must be between 0 (inclusive) and WIDTH (exclusive)
//           r must be between 0 (inclusive) and HIGHT (exclusive)

static char get_char(const char *board, int c, int r) {
    int index = r * 7 + c;
    return board[index];
}


// See connect.h for documentation.
struct connect connect_init() {
    struct connect my_game;
    
    for (int i = 0; i < WIDTH * HEIGHT; ++i) {
        my_game.board[i] = NONE;
    }

    my_game.current_player = RED;
    return my_game;
}

// See connect.h for documentation.
bool connect_drop_piece(struct connect *cf, int col){
 
    for (int row = 5; row >= 0; row--) {
        if (get_char(cf->board, col, row) == NONE) {
            //index of (row, col) 
            int index = row * 7 + col;
            cf->board[index] = cf->current_player;
            return true;
        }else{
            return false;
        }
    }
}
// See connect.h for documentation.
char connect_has_won(const struct connect *cf) {
    assert(cf);

    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 7; ++col) {
            char curr = get_char(cf->board, col, row);
            
            if (curr != NONE) {
                //horizontally
                if (col <= WINLENGTH - 1 && 
                    curr == get_char(cf->board, col + 1, row) && 
                    curr == get_char(cf->board, col + 2, row) && 
                    curr == get_char(cf->board, col + 3, row)) 
                {
                    return curr;
                }
                
                //vertically
                if (row <= 2 && 
                    curr == get_char(cf->board, col, row + 1) && 
                    curr == get_char(cf->board, col, row + 2) && 
                    curr == get_char(cf->board, col, row + 3)) 
                {
                    return curr;
                }
                
                if (row <= 2 && col <= 3 && 
                    curr == get_char(cf->board, col + 1, row + 1) && 
                    curr == get_char(cf->board, col + 2, row + 2) && 
                    curr == get_char(cf->board, col + 3, row + 3)) 
                {
                    return curr;
                }

                if (row >= 3 && col <= 3 && 
                    curr == get_char(cf->board, col + 1, row - 1) && 
                    curr == get_char(cf->board, col + 2, row - 2) && 
                    curr == get_char(cf->board, col + 3, row - 3)) 
                {
                    return curr;
                }
            }
        }
    }
    return NONE;
}


// See connect.h for documentation.
bool connect_has_finished(const struct connect *cf){
    for (int i = 0; i < 42; i++) {
        if (cf->board[i] == NONE) {
            return false;
        }
    }
    return true;
}

// See connect.h for documentation.
void connect_print(struct connect *cf) {
    assert(cf);
    for (int r = 0; r < HEIGHT; ++r) {
        printf("|");
        for (int c = 0; c < WIDTH; ++c) {
            printf(" %c |", get_char(cf->board, c, r));
        }
        printf("\n");
    }
    printf("%c", cf->current_player);
    for (int w = 0; w < 4 * WIDTH - 1; ++w) {
        printf("-");
    }
    printf("%c\n\n", cf->current_player);
}
//it can produce output, but totally wrong.
