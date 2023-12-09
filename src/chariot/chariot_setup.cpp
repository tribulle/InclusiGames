#include "mecanisms/chariot/chariot_setup.h"
//////////////////////////////
// Définitions des variables de chariot_setup.h
// Chariot::Setup() peut être modifié à guise (pour correspondre à la partie vois setup() habituelle du main.cpp [sans la configuration Arduino])
//////////////////////////////
// NE PAS METTRE DE SERIAL.BEGIN()
//////

Servo servo;

void Chariot::Setup(){
    servo.setPeriodHertz(50);
    servo.attach(14, 500, 2400);
}