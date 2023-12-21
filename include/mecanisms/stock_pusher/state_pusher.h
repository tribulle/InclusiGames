#ifndef STATE_PUSHER_H
#define STATE_PUSHER_H

#include "base_class/state.h"
#include "pusher_setup.h"

// Variations State_chariot: All the possible state for the Chariot
class State_distrib: public State{
    public:
        void MecanismF() override;
        State_distrib(Mecanism** next_mecanism, State* next_state) : State(next_mecanism, next_state) {}
};

class State_stocking: public State{
    public:
        void MecanismF() override;
        State_stocking(Mecanism** next_mecanism, State* next_state) : State(next_mecanism, next_state) {}
};


#endif