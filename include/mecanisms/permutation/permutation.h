#ifndef SWAP_H
#define SWAP_H
//////////////////////////////
// Ne Pas Toucher ce fichier
//////////////////////////////
#include <iostream>
#include "base_class/mecanism.h"

class Permutation : public Mecanism {
    public:
        void Setup() override;
        Permutation(State* state): Mecanism(state){}
    
};

#endif