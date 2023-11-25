#ifndef MECANISM_H
#define MECANISM_H

#include <Arduino.h>
#include <memory>
#include "context.h"

using namespace std;

// Definition of Mecanism (It's like an interface to use the membres of the current State) Inherits Context
class Mecanism: public Context{
    public:
        Mecanism* next_mecanism_ = nullptr; //What is the next mecanism (from state_)

        void TransitionTo(State* newState) override { // Function to change dynamiccaly the current State (and so the membres of this current Mecanism)
            this->state_ = newState;
            if (this->state_ != nullptr) this->next_mecanism_ = this->state_->next_mecanism_;
        }

        void LaunchMecanism(){  // Launch the mecanism (from state_)
            state_->MecanismF();
        }

        virtual void Setup() = 0;
        
        Mecanism(State* state){ // constructor
            TransitionTo(state);
        }
};

#endif