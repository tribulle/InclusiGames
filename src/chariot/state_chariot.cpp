#include "mecanisms/chariot/chariot_setup.h"
#include "mecanisms/chariot/state_chariot.h"
//////////////////////////////
// Basic_state::MecanismF() peut être modifié à guise (pour correspondre à la partie vois loop() habituelle du main.cpp)
//////////////////////////////
// Variations State_chariot: All the possible state for the Chariot
void Chariot_state_push::MecanismF(){

    //pcf8574_2.digitalWrite(enA, HIGH);// pcf8574 no analogWrite du coups pour la vitesse c'est pas facile à changer....
   
    pcf8574_2.digitalWrite(enA,HIGH);
    pcf8574_2.digitalWrite(enB,HIGH);
    pcf8574_2.digitalWrite(in1, LOW);
    pcf8574_2.digitalWrite(in2, HIGH);//demarrer un motor
    pcf8574_2.digitalWrite(in4, LOW);
    pcf8574_2.digitalWrite(in3, HIGH);//demarrer la deuxieme motor
    for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
        servo.write(posDegrees);
        //Serial.println(posDegrees);
        delay(4);
    }
    delay(5000);
}

void Chariot_state_reset::MecanismF(){

    for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
        servo.write(posDegrees);
        pcf8574_2.digitalWrite(in1, LOW);
        pcf8574_2.digitalWrite(in2, LOW);
        pcf8574_2.digitalWrite(in4, LOW);
        pcf8574_2.digitalWrite(in3, LOW);//arreter le motor
        //Serial.println(posDegrees);
        delay(4);
    }
}
