#ifndef STOCK_H
#define STOCK_H
//////////////////////////////
// Ne Pas Toucher ce fichier
//////////////////////////////
#include <iostream>
#include "base_class/mecanism.h"

class Stockage : public Mecanism {
    public:
        void Setup() override;
        Stockage(State* state, char* name): Mecanism(state, name){}
    
};

#endif