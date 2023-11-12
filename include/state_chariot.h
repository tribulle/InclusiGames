#ifndef STATE_CHARIOT_H
#define STATE_CHARIOT_H

#include "state.h"

// Variations State_chariot
class Valid_person_position: public State{
    public:
        void Mecanism() {}
};

class Disabled_person_position: public State{
    public:
        void Mecanism() {}
};

class Invalid_position: public State{
    public:
        void Mecanism() {}
};

#endif