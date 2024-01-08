#ifndef MECANISM_H
#define MECANISM_H
//////////////////////////////
// Ne Pas Toucher ce fichier
//////////////////////////////
#include <Arduino.h>
#include <memory>
#include "context.h"

using namespace std;

// Definition of Mecanism (It's like an interface to use the membres of the current State) Inherits Context
class Mecanism: public Context{
    public:
        Mecanism** next_mecanism_ = nullptr; //What is the next mecanism (from state_)

        void TransitionTo(State* newState) override { // Function to change dynamiccaly the current State (and so the membres of this current Mecanism)
            //Serial.println("Statechanging ");
            if (newState == nullptr) return;

            this->state_ = newState;
            RefreshStateData();
        }

        void LaunchMecanism(){  // Launch the mecanism (from state_)
            this->state_->MecanismF();
            Serial.print("MEC: Changement d'état, next state null: ");
            Serial.println(this->state_->next_state_==nullptr);
            TransitionTo(this->state_->next_state_);
            delay(100);
        }

        virtual void Setup() = 0;
        
        Mecanism(State* state){ // constructor
            TransitionTo(state);
        }

        State* ShowState(){
            return this->state_;
        }

        void RefreshStateData(){
            if (this->state_ != nullptr){
                this->next_mecanism_ = this->state_->next_mecanism_;
                //Serial.print("next_mec changing: ");
                //Serial.println(this->next_mecanism_ == nullptr);
            }
            else{
                this->next_mecanism_ = nullptr;
            }
        }
};

#endif