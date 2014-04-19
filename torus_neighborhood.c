#include "neighborhood.h"
#include "plansza.h"

nbhood_t* set_up_nbhood() {
    nbhood_t *n = malloc(sizeof *n);
    n->max = 8;
    n->neighbors = malloc((size_t)n->max * sizeof *n->neighbors);
    return n;
}

/* funkcja wsadzajaca do struktury neighborhood_t kolejnych sasiadow (dla danej komorki)
 * (idziemy zgodnie z kierunkiem wskazowek zegara)
 **/
nbhood_t* get_nbhood(board_t* b, unsigned int x, unsigned int y) {
    nbhood_t *n = set_up_nbhood();

    // pierwszy sasiad (gora)
    n->neighbors[0] = get_cell(b, x == 0 ? b->rn-1 : x-1,   y);
    // prawy gorny
    n->neighbors[1] = get_cell(b, x == 0 ? b->rn-1 : x-1,   y == b->cn-1 ? 0 : y+1);
    // prawy
    n->neighbors[2] = get_cell(b, x,                        y == b->cn-1 ? 0 : y+1);
    // prawy dolny
    n->neighbors[3] = get_cell(b, x == b->rn-1 ? 0 : x+1,   y == b->cn-1 ? 0 : y+1);
    // dol
    n->neighbors[4] = get_cell(b, x == b->rn-1 ? 0 : x+1,   y);
    // lewy dolny
    n->neighbors[5] = get_cell(b, x == b->rn-1 ? 0 : x+1,   y == 0 ? b->cn-1 : y-1);
    // lewy
    n->neighbors[6] = get_cell(b, x,                        y == 0 ? b->cn-1 : y-1);
    // lewy gorny 
    n->neighbors[7] = get_cell(b, x == 0 ? b->rn-1 : x-1,   y == 0 ? b->cn-1 : y-1);

    return n;
}
