#ifndef PUSHER_H
#define PUSHER_H
//////////////////////////////
// Ne Pas Toucher ce fichier
//////////////////////////////
#include <iostream>
#include "base_class/mecanism.h"

class Pusher : public Mecanism {

    public:
        void Setup() override;
        Pusher(State* state): Mecanism(state){}
    
};

#endif