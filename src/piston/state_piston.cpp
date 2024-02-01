#include "mecanisms/piston/piston_setup.h"
#include "mecanisms/piston/state_piston.h"
//////////////////////////////
// Basic_state::MecanismF() peut être modifié à guise (pour correspondre à la partie vois loop() habituelle du main.cpp)
//////////////////////////////
// Variations State_chariot: All the possible state for the Chariot

void Basic_state_piston::MecanismF(){
    
    pcf8574_2.digitalWrite(in4, HIGH);
    pcf8574_2.digitalWrite(in3, LOW);//demarrer l'actionnneur lineaire
    delay(temps_actionneur); 

    pcf8574_2.digitalWrite(in4, LOW);
    pcf8574_2.digitalWrite(in3, HIGH);//initialisation
    delay(temps_actionneur);// 

    pcf8574_2.digitalWrite(in4, LOW);
    pcf8574_2.digitalWrite(in3, LOW);//arrete l'actionnneur
}
