#ifndef STATE_H
#define STATE_H
//////////////////////////////
// Ne Pas Toucher ce fichier
//////////////////////////////
#include <Arduino.h>
class Mecanism;

// Definition of State (Cross-referenced with Mecanism (Context)) It's from the State Pattern (Design patterns for OOP)
class State{
    public:
        Mecanism** next_mecanism_;   //What should be the next mecanism (for this current state)
        State* next_state_;
        int nb_next_mecs_;

        virtual void MecanismF() = 0;        //What should do the mecanism (for this current state)

        State(Mecanism** next_mecanism, State* next_state){
            this->next_mecanism_ = next_mecanism;
            this->next_state_ = next_state;
            this->nb_next_mecs_ = 0;
        }

        void Change_next_mecanism_to(Mecanism** next_mecanism, int size){
            //Serial.println("DEBUG CHANGE MEC");
            //Serial.println(this->next_mecanism_==nullptr);
            //Serial.println(next_mecanism==nullptr);
            this->next_mecanism_ = next_mecanism;
            this->nb_next_mecs_ = size;
            if(next_mecanism == nullptr){
                this->nb_next_mecs_ = 0;
                Serial.println("Change_next_mecanism_to ATTENTION : next_mecanism_ == Nullptr");
            }
        }

        void Change_next_state_to(State* next_state){
            this->next_state_ = next_state;
        }
};

#endif