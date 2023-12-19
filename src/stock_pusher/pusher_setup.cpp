#include "mecanisms/stock_pusher/pusher_setup.h"
//////////////////////////////
// Définitions des variables de chariot_setup.h
// Chariot::Setup() peut être modifié à guise (pour correspondre à la partie vois setup() habituelle du main.cpp [sans la configuration Arduino])
//////////////////////////////
// NE PAS METTRE DE SERIAL.BEGIN()
//////

bool value_sensor;
void Pusher::Setup(){
    pinMode(LASER, OUTPUT);
    pinMode(SENSOR, INPUT);
    digitalWrite(LASER,HIGH);
}