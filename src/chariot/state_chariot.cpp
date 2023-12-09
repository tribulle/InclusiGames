#include "mecanisms/chariot/chariot_setup.h"
#include "mecanisms/chariot/state_chariot.h"
//////////////////////////////
// Basic_state::MecanismF() peut être modifié à guise (pour correspondre à la partie vois loop() habituelle du main.cpp)
//////////////////////////////
// Variations State_chariot: All the possible state for the Chariot
void Disabled_person_position::MecanismF(){

    Serial.println("CA ARRIVE LA");
    for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
        servo.write(posDegrees);
        Serial.println(posDegrees);
        delay(20);
    }

    for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
        servo.write(posDegrees);
        Serial.println(posDegrees);
        delay(20);
    }
}

void Valid_person_position::MecanismF(){

}

void Invalid_position::MecanismF(){

}