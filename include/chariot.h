#include <iostream>
#include "mecanism.h"
#include "state_chariot.h"

using namespace std;

class Chariot : public Mecanism {
public:
    // This is how clients can access the single instance
    static Chariot* getInstance();

protected:
    State* state_;
    int position_number_;

private:
    static Chariot* inst_;   // The one, single instance
    Chariot() {} // private constructor
    Chariot(const Chariot&); // private to avoid an involuntary copy
    Chariot& operator=(const Chariot&); // same with involuntary assignment

    void Increase_position(int increase_step){
        position_number_ += increase_step;
    }
    void Decrease_position(int decrease_step){
        position_number_ -= decrease_step;
    }

    void Position_update();
    void State_update();
    
};

// Define the static Singleton pointer
Chariot* Chariot::inst_ = nullptr;

Chariot* Chariot::getInstance() {
    if (inst_ == nullptr) {
        inst_ = new Chariot();
    }
    return(inst_);
}