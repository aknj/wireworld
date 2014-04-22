#ifndef _RULES_H_
#define _RULES_H_

#include "state.h"
#include "neighborhood.h"

state_t get_next_state(state_t current_state, nbhood_t* neighbors);

#endif
