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

MotorDriver* motorDriver;

bool value_sensor;
void Pusher::Setup(){
    // LASER RECEPTEUR 1
    pcf8574.pinMode(LASER, OUTPUT);
    pcf8574.pinMode(SENSOR, INPUT);
    pcf8574.digitalWrite(LASER,HIGH);

    // LASER RECEPTEUR 2
    pcf8574.pinMode(LASER2, OUTPUT);
    pcf8574.pinMode(SENSOR2, INPUT);
    pcf8574.digitalWrite(LASER2,HIGH);
    
    Wire.begin();
    motorDriver->init();
    //pcf8574_2.pinMode(vitesseA,OUTPUT);
    //pcf8574_2.pinMode(vitesseB,OUTPUT);
    //pcf8574_2.pinMode(directionA,OUTPUT);
    //pcf8574_2.pinMode(directionB,OUTPUT);
}