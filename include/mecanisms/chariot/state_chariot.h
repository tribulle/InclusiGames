#ifndef STATE_CHARIOT_H
#define STATE_CHARIOT_H

#include "base_class/state.h"
#include "chariot_setup.h"

// Variations State_chariot: All the possible state for the Chariot

class Chariot_state_push: public State{
    public:
        void MecanismF() override;
        Chariot_state_push(Mecanism** next_mecanism, State* next_state) : State(next_mecanism, next_state) {}
};

class Chariot_state_reset: public State{
    public:
        void MecanismF() override;
        Chariot_state_reset(Mecanism** next_mecanism, State* next_state) : State(next_mecanism, next_state) {}
};

#endif