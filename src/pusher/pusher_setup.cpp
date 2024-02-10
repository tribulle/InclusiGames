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
// pour la connection de steppeur faut connecter 1,3 et 2,4
MotorDriver motor;

bool value_sensor;
void Pusher::Setup(){
     motor.init();


    // LASER RECEPTEUR 1
    
    pcf8574.pinMode(LASER, OUTPUT);
    pinMode(SENSOR, INPUT);
    pcf8574.digitalWrite(LASER,HIGH);


    
    
    

    //Wire.begin();
    //motorDriver->init();
    //pcf8574_2.pinMode(vitesseA,OUTPUT); 
    //pcf8574_2.pinMode(vitesseB,OUTPUT);
    //pcf8574_2.pinMode(directionA,OUTPUT);
    //pcf8574_2.pinMode(directionB,OUTPUT);cette partie peut supprimer
}