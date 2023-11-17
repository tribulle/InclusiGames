#ifndef CONTEXT_H
#define CONTEXT_H

#include <memory>
#include "state.h"

using namespace std;

// Definition of Context (Cross-referenced with State) It's from the State Pattern (Design patterns for OOP)
class Context{
    protected:
        State* state_;   // What is the current State of the Context ?
    public:
        virtual void TransitionTo(State* newState){        // Function to change dynamiccaly the current State
            this->state_ = newState;
        }

        Context(){  // Constructor
            TransitionTo(nullptr);
        }
};

#endif