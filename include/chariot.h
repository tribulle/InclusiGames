#include <iostream>
#include "mecanism.h"

using namespace std;

class Chariot : public Mecanism {
private:
    int position_number_; // Position of the chariot
    
    void IncreasePosition(int increase_step){  // Function to manage the position of the chariot (Is it facing a valid or a disabled player ?)
        position_number_ += increase_step;
    }
    void DecreasePosition(int decrease_step){ // Same
        position_number_ -= decrease_step;
    }

    void PositionUpdate();
    void StateUpdate();
    
};