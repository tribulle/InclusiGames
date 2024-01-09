#ifndef CAMERA_H
#define CAMERA_H
//////////////////////////////
// Ne Pas Toucher ce fichier
//////////////////////////////
#include <iostream>
#include "base_class/mecanism.h"

class CameraMecanism : public Mecanism {
    public:
        void Setup() override;
        CameraMecanism(State* state, char* name): Mecanism(state, name){}
};

#endif