#ifndef STATE_CAMERA_H
#define STATE_CAMERA_H
//////////////////////////////
// Ne Pas Toucher ce fichier
//////////////////////////////
#include "base_class/state.h"

// Variations State_chariot: All the possible state for the Chariot
class Basic_state_camera: public State{
    public:
        int a;
        void MecanismF() override;

        Basic_state_camera(Mecanism* next_mecanism) : State(next_mecanism) {}
};

#endif