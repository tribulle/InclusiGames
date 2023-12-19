#include "mecanisms/stock_pusher/pusher_setup.h"
#include "mecanisms/stock_pusher/state_pusher.h"
//////////////////////////////
// Basic_state::MecanismF() peut être modifié à guise (pour correspondre à la partie vois loop() habituelle du main.cpp)
//////////////////////////////
// Variations State_chariot: All the possible state for the Chariot
void State_distrib::MecanismF(){
    value_sensor = digitalRead(SENSOR);
    delay(100);
}

void State_stocking::MecanismF(){
    value_sensor = digitalRead(SENSOR);
    delay(100);
}