#include "rules.h"

int get_number_of_eheads(nbhood_t* nbh) {
    int i;
    int sum = 0;
    for(i = 0; i < nbh->max; i++)
        if(nbh->neighbors[i] == EHEAD)
            sum++;
    return sum;
}

state_t get_next_state(state_t current_state, nbhood_t* neighbors) {
    int eheads = get_number_of_eheads(neighbors);

    if(current_state == EMPTY) {
        return EMPTY;
    }
    else if(current_state == EHEAD) {
        return ETAIL;
    }
    else if(current_state == ETAIL) {
        return CONDR;
    }
    else if(current_state == CONDR) {
        if(eheads == 1 || eheads == 2)
            return EHEAD;
        else
            return CONDR;
    }
    else
        return EMPTY;    // cos innego by sie tu przydalo
}
