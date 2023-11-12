#ifndef MECANISM_H
#define MECANISM_H

#include <memory>
#include "context.h"

using namespace std;

class Mecanism: public Context{
    protected:
        bool finished_;
    public:
        Mecanism* next_mecanism_ = nullptr;

        void TransitionTo(State* newState){ 
            this->state_ = newState;
            this->next_mecanism_ = this->state_->next_mecanism_;
        }

        void LaunchMecanism(){
            state_->Mecanism();
        }
};

#endif