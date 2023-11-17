#ifndef STATE_H
#define STATE_H

class Mecanism;

// Definition of State (Cross-referenced with Mecanism (Context)) It's from the State Pattern (Design patterns for OOP)
class State{
    public:
        virtual ~State() = default;
        Mecanism* mecanism_ = nullptr;        //What is the Mecanism which stores this state
        Mecanism* next_mecanism_ = nullptr;   //What should be the next mecanism (for this current state)

        virtual void Mecanism();             //What should do the mecanism (for this current state)
};

#endif