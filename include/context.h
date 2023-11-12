#ifndef CONTEXT_H
#define CONTEXT_H

#include <memory>
#include "state.h"

using namespace std;

class Context{
    protected:
        State* state_;
    public:
        virtual void TransitionTo(State* newState){ 
            this->state_ = newState;
        }

        Context(){
            TransitionTo(nullptr);
        }
};

#endif