#include "plansza.h"
#include "state.h"

#include <string.h>

/* funkcja mallocujaca pamiec na zmienna typu board_t */
board_t*    make_board(int rn, int cn) {
    board_t *new_board = malloc(sizeof *new_board);
    if(new_board == NULL)
        return NULL;
    if((new_board->state = malloc((size_t)rn * (size_t)cn * sizeof *new_board->state)) == NULL) {
        free(new_board);
        return NULL;
    }
    new_board->rn = rn;
    new_board->cn = cn;
    memset(new_board->state, 0, (size_t)(rn * (size_t)cn * sizeof *new_board->state));
    return new_board;
}

void        free_board(board_t* b) {
    free(b->state);
    free(b);
}

void        set_cell(board_t* b, int x, int y, state_t state) {
    if(x >= 0 && x <= b->rn && y >= 0 && y <= b->cn)
        b->state[x * b->cn + y] = state;
}

state_t     get_cell(board_t* b, int x, int y) {
    if(x >= 0 && x <= b->rn && y >= 0 && y <= b->cn)
        return b->state[x * b->cn + y];
    else
        return 0;                                // co ma sie dziac z obszarem poza brzegami?
}
