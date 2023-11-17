#include <iostream>
#include "mecanism.h"
#include "state_chariot.h"

using namespace std;

// This is a singleton (So you can't instantiate 2 Chariots. It's to prevent error)
// We access to the chariot with:    Chariot* chariot = Chariot::getInstance();

class Chariot : public Mecanism {
public:
    // This is how you can access the single instance
    static Chariot* getInstance();

protected:
    State* state_;        // current state of the chariot
    int position_number_; // Position of the chariot

private:
    static Chariot* inst_;   // The one, single instance
    Chariot() {} // private constructor
    Chariot(const Chariot&); // private to avoid an involuntary copy
    Chariot& operator=(const Chariot&); // same with involuntary assignment

    void IncreasePosition(int increase_step){  // Function to manage the position of the chariot (Is it facing a valid or a disabled player ?)
        position_number_ += increase_step;
    }
    void DecreasePosition(int decrease_step){ // Same
        position_number_ -= decrease_step;
    }

    void PositionUpdate();
    void StateUpdate();
    
};

// Define the static Singleton pointer
Chariot* Chariot::inst_ = nullptr;

Chariot* Chariot::getInstance() {
    if (inst_ == nullptr) {
        inst_ = new Chariot();
    }
    return(inst_);
}