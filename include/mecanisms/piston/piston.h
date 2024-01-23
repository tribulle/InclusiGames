#ifndef PISTON_H
#define PISTON_H
//////////////////////////////
// Ne Pas Toucher ce fichier
//////////////////////////////
#include <iostream>
#include "base_class/mecanism.h"

class Piston : public Mecanism {
    public:
        void Setup() override;
        Piston(State* state, char* name): Mecanism(state, name){}
    
};

#endif