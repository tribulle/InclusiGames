#ifndef STATE_PISTON_H
#define STATE_PISTON_H

#include "base_class/state.h"
#include "piston_setup.h"

// Variations State_chariot: All the possible state for the Chariot
class Basic_state_piston: public State{
    public:
        void MecanismF() override;
        Basic_state_piston(Mecanism** next_mecanism, State* next_state) : State(next_mecanism, next_state) {}
};

#endif