#ifndef MECANISM_H
#define MECANISM_H

#include <Arduino.h>
#include <memory>
#include "context.h"
#include "singleton.h"
#include "mecanism_setup.h"

using namespace std;

// Definition of Mecanism (It's like an interface to use the membres of the current State) Inherits Context
class Mecanism: public Context, public Singleton{
    protected:
        MecanismPin** all_pins_; // All the pins information
        int pin_number_;
    public:
        Mecanism* next_mecanism_ = nullptr; //What is the next mecanism (from state_)

        void TransitionTo(State* newState) override { // Function to change dynamiccaly the current State (and so the membres of this current Mecanism)
            this->state_ = newState;
            this->next_mecanism_ = this->state_->next_mecanism_;
        }

        void LaunchMecanism(){  // Launch the mecanism (from state_)
            state_->Mecanism();
        }

        // Lauch pinMode for each pin of the Mecanism
        void InitializePin(){
            InitializeSetup(this->all_pins_);
            for (int i = 0; i < this->pin_number_; i++){
                pinMode(all_pins_[i]->pin_, all_pins_[i]->pin_mode_);
            }
        }

        virtual void InitializeSetup(MecanismPin** all_pins);
};

#endif