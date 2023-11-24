#ifndef STATE_CHARIOT_H
#define STATE_CHARIOT_H

#include "../../base_class/state.h"
#include "chariot_setup.h"

// Variations State_chariot: All the possible state for the Chariot
class Valid_person_position: public State{
    public:
        void Mecanism() override {}
};

class Disabled_person_position: public State{
    public:
        void Mecanism() override {}
};

class Invalid_position: public State{
    public:
        void Mecanism() override {}
};

#endif