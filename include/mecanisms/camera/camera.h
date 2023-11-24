#include <iostream>
#include "../../base_class/mecanism.h"

class Camera : public Mecanism {
    public:
        void Setup() override;
        Camera(State* state): Mecanism(state){}
};