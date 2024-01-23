#ifndef STATE_STOCK_H
#define STATE_STOCK_H

#include "base_class/state.h"
#include "stockage_setup.h"

// Variations State_chariot: All the possible state for the Chariot
class Draw_state_stockage: public State{
    public:
        int card_position = 0;
        void MecanismF() override;
        Draw_state_stockage(Mecanism** next_mecanism, State* next_state) : State(next_mecanism, next_state) {}
};

class Play_state_stockage: public State{
    public:
        int card_position = 0;
        void MecanismF() override;
        Play_state_stockage(Mecanism** next_mecanism, State* next_state) : State(next_mecanism, next_state) {}
};

#endif