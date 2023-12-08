#include "mecanisms/chariot/chariot_setup.h"
#include "mecanisms/chariot/state_chariot.h"
//////////////////////////////
// Basic_state::MecanismF() peut être modifié à guise (pour correspondre à la partie vois loop() habituelle du main.cpp)
//////////////////////////////
// Variations State_chariot: All the possible state for the Chariot
void Disabled_person_position::MecanismF(){
    analogWrite(enA, 255); // Send PWM signal to L298N Enable pin
    delay(1000);
}

void Valid_person_position::MecanismF(){
    analogWrite(enA, 255); // Send PWM signal to L298N Enable pin
    delay(1000);
}

void Invalid_position::MecanismF(){
    analogWrite(enA, 255); // Send PWM signal to L298N Enable pin
    delay(1000);
}