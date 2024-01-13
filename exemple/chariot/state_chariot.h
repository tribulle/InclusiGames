#ifndef STATE_CHARIOT_H
#define STATE_CHARIOT_H

#include "base_class/state.h"
#include "chariot_setup.h"

// Variations State_chariot: All the possible state for the Chariot
class Valid_person_position: public State{
    public:
        void MecanismF() override;
        Valid_person_position(Mecanism** next_mecanism, State* next_state) : State(next_mecanism, next_state) {}
};

class Disabled_person_position_push: public State{
    public:
        void MecanismF() override;
        Disabled_person_position_push(Mecanism** next_mecanism, State* next_state) : State(next_mecanism, next_state) {}
};

class Disabled_person_position_reset: public State{
    public:
        void MecanismF() override;
        Disabled_person_position_reset(Mecanism** next_mecanism, State* next_state) : State(next_mecanism, next_state) {}
};

class Invalid_position: public State{
    public:
        void MecanismF() override;
        Invalid_position(Mecanism** next_mecanism, State* next_state) : State(next_mecanism, next_state) {}
};

#endif