#ifndef MECANISM_H
#define MECANISM_H

#include <memory>
#include "context.h"

using namespace std;

class Mecanism: public Context{
    public:
        bool finished_;
        Mecanism* next_mecanism_ = nullptr;

        void TransitionTo(State* newState){ 
            this->state_ = newState;
            this->next_mecanism_ = this->state_->next_mecanism_;
        }

        void LaunchMecanism(){
            this->finished_ == false;
            state_->Mecanism();
        }
};

#endif