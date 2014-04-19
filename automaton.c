#include "automaton.h"
#include "rules.h"

board_t*    prepare_backstage_board(board_t* init_b) {
    board_t *backstage_board = make_board(init_b->rn, init_b->cn);
    return backstage_board;
}

void        prepare_next_states(board_t* b, board_t* backb) {
    int i, j;
    for(i = 0; i < b->rn; i++) {
        for(j = 0; j < b->cn; j++) {
            set_cell(backb, i, j, get_next_state(get_cell(b, i, j), get_nbhood(b, i, j)));
        }
    }
}

void        swap_boards(board_t** b, board_t** backb) {
    board_t *temp = *b;
    *b = *backb;
    *backb = temp;
}
