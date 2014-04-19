#ifndef _NEIGHBORHOOD_H_
#define _NEIGHBORHOOD_H_

#include "plansza.h"

/* oficjalne skroty:
 * *****************
 * neighborhood =   nbhood
 *
 * uzywane wszedzie oprocz nazw plikow
 */

typedef struct {
    int max;
    state_t* neighbors;
} nbhood_t;

nbhood_t* set_up_nbhood();

nbhood_t* get_nbhood(board_t* b, unsigned int x, unsigned int y);

#endif
