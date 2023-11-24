#ifndef STATE_CAMERA_H
#define STATE_CAMERA_H

#include "../../base_class/state.h"
#include "camera_setup.h"

// Variations State_chariot: All the possible state for the Chariot
class Basic_state: public State{
    public:
        void Mecanism() override {
            camera->oneFrame();  
            delay(100);
            serve();
        }
};

#endif