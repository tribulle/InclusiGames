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
        char* name_;
        int nb_next_mecs_;

        void TransitionTo(State* newState) override { // Function to change dynamiccaly the current State (and so the membres of this current Mecanism)
            //Serial.println("Statechanging ");
            if (newState == nullptr) return;

            this->state_ = newState;
            RefreshStateData();
        }

        void LaunchMecanism(){  // Launch the mecanism (from state_)
            this->state_->MecanismF();
            Serial.print("MEC: ");
            Serial.println(this->name_);
            Serial.print("MEC: Changement d'état, next state null: ");
            Serial.println(this->state_->next_state_==nullptr);
            TransitionTo(this->state_->next_state_);
            delay(3000);
        }

        virtual void Setup() = 0;
        
        Mecanism(State* state, char* name){ // constructor
            this->state_ = state;
            this->name_ = name;
        }

        State* ShowState(){
            return this->state_;
        }

        void RefreshStateData(){
            if (this->state_ != nullptr){
                this->next_mecanism_ = this->state_->next_mecanism_;
                this->nb_next_mecs_ = this->state_->nb_next_mecs_;
                Serial.print("RefreshStateData:next_mec changing: ");
                Serial.print(this->next_mecanism_ == nullptr);
                Serial.println(this->nb_next_mecs_);
            }
            else{
                this->next_mecanism_ = nullptr;
            }
        }
};

#endif