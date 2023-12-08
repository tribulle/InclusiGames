#include "mecanisms/permutation/permutation_setup.h"
#include "mecanisms/permutation/state_permutation.h"
//////////////////////////////
// Basic_state::MecanismF() peut être modifié à guise (pour correspondre à la partie vois loop() habituelle du main.cpp)
//////////////////////////////
// Variations State_chariot: All the possible state for the Chariot
void Basic_state_permutation::MecanismF(){
    // step one revolution in one direction:
    myStepper.step(890);//25
    delay(1000);
    myStepper.step(-890);//25
    delay(1000);
}
