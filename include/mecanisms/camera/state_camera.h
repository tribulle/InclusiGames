#ifndef STATE_CAMERA_H
#define STATE_CAMERA_H

#include "base_class/state.h"

// Variations State: All the possible state
class Basic_state_camera: public State{
    public:
        int a;
        void MecanismF() override;

        Basic_state_camera(Mecanism** next_mecanism, State* next_state) : State(next_mecanism, next_state) {}
};

#endif