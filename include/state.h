#ifndef STATE_H
#define STATE_H

class Mecanism;

class State{
    public:
        virtual ~State() = default;
        Mecanism* next_mecanism_ = nullptr;

        virtual void Mecanism();
};

#endif