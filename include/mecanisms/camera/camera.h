#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include "base_class/mecanism.h"

class CameraMecanism : public Mecanism {
    public:
        void Setup() override;
        CameraMecanism(State* state): Mecanism(state){}
};

#endif