#include "mecanisms/stock_pusher/pusher_setup.h"
#include "mecanisms/stock_pusher/state_pusher.h"
//////////////////////////////
// Basic_state::MecanismF() peut être modifié à guise (pour correspondre à la partie vois loop() habituelle du main.cpp)
//////////////////////////////
// Variations State_chariot: All the possible state for the Chariot
void State_distrib::MecanismF(){
    value_sensor = digitalRead(SENSOR);
        // Moteur A
    digitalWrite(vitesseA,HIGH); // Allume le moteur
    digitalWrite(vitesseB,HIGH); // Allume le moteur
    digitalWrite(directionA,HIGH); // Fait tourner le moteur dans une direction
    digitalWrite(directionB,LOW); // Fait tourner le moteur dans une direction
    while (digitalRead(SENSOR)==1)
    {
        Serial.println("Pas assez loin");
        delay(10);
    }
    delay(100);
    digitalWrite(vitesseA,LOW); // Eteint le moteur
    digitalWrite(vitesseB,LOW); // Eteint le moteur
    
}

void State_stocking::MecanismF(){
    digitalWrite(vitesseA,HIGH); // Allume le moteur
    digitalWrite(vitesseB,HIGH); // Allume le moteur
    digitalWrite(directionA,LOW); // Fait tourner le moteur dans une direction
    digitalWrite(directionB,HIGH); // Fait tourner le moteur dans une direction
    while (digitalRead(SENSOR)==0)
    {
        Serial.println("Pas assez loin");
        delay(10);
    }
    delay(100);
    digitalWrite(vitesseA,LOW); // Eteint le moteur
    digitalWrite(vitesseB,LOW); // Eteint le moteur
}