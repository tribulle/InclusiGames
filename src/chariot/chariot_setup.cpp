#include "mecanisms/chariot/chariot_setup.h"
#include "extender.h"
//////////////////////////////
// Définitions des variables de chariot_setup.h
// Chariot::Setup() peut être modifié à guise (pour correspondre à la partie vois setup() habituelle du main.cpp [sans la configuration Arduino])
//////////////////////////////
// NE PAS METTRE DE SERIAL.BEGIN()
//////

Servo servo;

void Chariot::Setup(){
    //pcf8574_2.pinMode(enA, OUTPUT);
    //pcf8574_2.pinMode(in1, OUTPUT);
    //pcf8574_2.pinMode(in2, OUTPUT);
    //pcf8574_2.pinMode(enB, OUTPUT);
    //pcf8574_2.pinMode(in3, OUTPUT);
    //pcf8574_2.pinMode(in4, OUTPUT);// fait dans le main.cpp
    
  

  
    //servo.setPeriodHertz(50);
    //servo.attach(21, 500, 2400);
    Serial.println("****************************************SETUP-ED*******************************");
}