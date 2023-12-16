#ifndef STATE_CHARIOT_H
#define STATE_CHARIOT_H

#include "base_class/state.h"
#include "pusher_setup.h"

// Variations State_chariot: All the possible state for the Chariot
class Basic_state_pusher: public State{
    public:
        void MecanismF() override;
        Basic_state_pusher(Mecanism* next_mecanism) : State(next_mecanism) {}
};


#endif