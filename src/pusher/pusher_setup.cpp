#include "mecanisms/stock_pusher/pusher_setup.h"
#include "extender.h"
#include <Wire.h>
#include "Grove_Motor_Driver_TB6612FNG.h"
//////////////////////////////
// Définitions des variables de chariot_setup.h
// Chariot::Setup() peut être modifié à guise (pour correspondre à la partie vois setup() habituelle du main.cpp [sans la configuration Arduino])
//////////////////////////////
// NE PAS METTRE DE SERIAL.BEGIN()
//////

MotorDriver motor;

bool value_sensor;
void Pusher::Setup(){
     motor.init();
    // LASER RECEPTEUR 1
    /*
    pcf8574.pinMode(LASER, OUTPUT);
    pcf8574.pinMode(SENSOR, INPUT);
    pcf8574.digitalWrite(LASER,HIGH);

    // LASER RECEPTEUR 2
    pcf8574.pinMode(LASER2, OUTPUT);
    pcf8574.pinMode(SENSOR2, INPUT);
    pcf8574.digitalWrite(LASER2,HIGH);
    */
    
    // Test fait avec L298N
    //pinMode(enAP, OUTPUT);
    //pinMode(enBP, OUTPUT);
    //pinMode(In1, OUTPUT);
    //pinMode(In2, OUTPUT);
    //pinMode(In3, OUTPUT);
    //pinMode(In4, OUTPUT);

    //Wire.begin();
    //motorDriver->init();
    //pcf8574_2.pinMode(vitesseA,OUTPUT); 
    //pcf8574_2.pinMode(vitesseB,OUTPUT);
    //pcf8574_2.pinMode(directionA,OUTPUT);
    //pcf8574_2.pinMode(directionB,OUTPUT);ça sera à quoi???
}