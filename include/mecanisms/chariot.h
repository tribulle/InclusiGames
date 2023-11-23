#include <iostream>
#include "../base_class/mecanism.h"

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

    void InitializeSetup(MecanismPin** all_pins);
    void PositionUpdate();
    void StateUpdate();
    
};

void Chariot::InitializeSetup(MecanismPin** all_pins){
    all_pins[0] = new MecanismPin(9, OUTPUT);
    all_pins[1] = new MecanismPin(8, OUTPUT);
    all_pins[2] = new MecanismPin(7, OUTPUT);
}