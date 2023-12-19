#ifndef STATE_H
#define STATE_H
//////////////////////////////
// Ne Pas Toucher ce fichier
//////////////////////////////

class Mecanism;

// Definition of State (Cross-referenced with Mecanism (Context)) It's from the State Pattern (Design patterns for OOP)
class State{
    public:
        Mecanism** next_mecanism_;   //What should be the next mecanism (for this current state)

        virtual void MecanismF() = 0;        //What should do the mecanism (for this current state)

        State(Mecanism** next_mecanism){
            this->next_mecanism_ = next_mecanism;
        }

        void Change_next_mecanism_to(Mecanism** next_mecanism){
            this->next_mecanism_ = next_mecanism;
        }
};

#endif