#ifndef STATE_SWAP_H
#define STATE_SWAP_H

#include "base_class/state.h"
#include "permutation_setup.h"

// Variations State_chariot: All the possible state for the Chariot
class Basic_state_permutation: public State{
    public:
        void MecanismF() override;
        Basic_state_permutation(Mecanism** next_mecanism) : State(next_mecanism) {}
};

#endif