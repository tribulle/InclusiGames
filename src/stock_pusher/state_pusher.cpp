#include "mecanisms/stock_pusher/pusher_setup.h"
#include "mecanisms/stock_pusher/state_pusher.h"

#include "extender.h"
#include "Grove_Motor_Driver_TB6612FNG.h"
//////////////////////////////
// Basic_state::MecanismF() peut être modifié à guise (pour correspondre à la partie vois loop() habituelle du main.cpp)
//////////////////////////////
// Variations State_chariot: All the possible state for the Chariot
void State_distrib::MecanismF(){
    /*
    pcf8574_2.digitalWrite(vitesseA,HIGH); // Allume le moteur
    pcf8574_2.digitalWrite(vitesseB,HIGH); // Allume le moteur
    pcf8574_2.digitalWrite(directionA,HIGH); // Fait tourner le moteur dans une direction
    pcf8574_2.digitalWrite(directionB,LOW); // Fait tourner le moteur dans une direction
    while (pcf8574.digitalRead(SENSOR)==1)
    {
        Serial.println("Pas assez loin");
        delay(10);
    }
    delay(100);
    pcf8574_2.digitalWrite(vitesseA,LOW); // Eteint le moteur
    pcf8574_2.digitalWrite(vitesseB,LOW); // Eteint le moteur*/
    Serial.println("run at speed=-200");
    //motorDriver->dcMotorRun(MOTOR_CHA, -200);
    //motorDriver->dcMotorRun(MOTOR_CHB, 200);
    analogWrite(enAP, -200);
    analogWrite(enBP, -200);
    delay(5000);

    // stop 2 motors
    Serial.println("stop");
    //motorDriver->dcMotorStop(MOTOR_CHA);
    //motorDriver->dcMotorStop(MOTOR_CHB);
    analogWrite(enAP, 0);
    analogWrite(enBP, 0);
    
}

void State_stocking::MecanismF(){
    Serial.println("Hein??");
    /*
    pcf8574_2.digitalWrite(vitesseA,HIGH); // Allume le moteur
    pcf8574_2.digitalWrite(vitesseB,HIGH); // Allume le moteur
    pcf8574_2.digitalWrite(directionA,LOW); // Fait tourner le moteur dans une direction
    pcf8574_2.digitalWrite(directionB,HIGH); // Fait tourner le moteur dans une direction
    while (pcf8574.digitalRead(SENSOR)==0)
    {
        Serial.println("Pas assez loin");
        delay(10);
    }
    delay(100);
    pcf8574_2.digitalWrite(vitesseA,LOW); // Eteint le moteur
    pcf8574_2.digitalWrite(vitesseB,LOW); // Eteint le moteur
    */
}