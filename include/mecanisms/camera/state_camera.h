#ifndef STATE_CAMERA_H
#define STATE_CAMERA_H

#include "base_class/state.h"

// Variations State_chariot: All the possible state for the Chariot
class Basic_state: public State{
    public:
        int a;
        void MecanismF() override;
};

#endif