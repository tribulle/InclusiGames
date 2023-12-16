#ifndef CHARIOT_H
#define CHARIOT_H
//////////////////////////////
// Ne Pas Toucher ce fichier
//////////////////////////////
#include <iostream>
#include "base_class/mecanism.h"

class Chariot : public Mecanism {
    private:
        //int position_number_; // Position of the chariot

    public:
       /* void IncreasePosition(int increase_step){  // Function to manage the position of the chariot (Is it facing a valid or a disabled player ?)
            position_number_ += increase_step;
        }
        void DecreasePosition(int decrease_step){ // Same
            position_number_ -= decrease_step;
        }*/

        void Setup() override;
        Chariot(State* state): Mecanism(state){}
        //void PositionUpdate();
        //void StateUpdate();
    
};

#endif