#include "mecanisms/chariot/chariot_setup.h"
//////////////////////////////
// Définitions des variables de chariot_setup.h
// Chariot::Setup() peut être modifié à guise (pour correspondre à la partie vois setup() habituelle du main.cpp [sans la configuration Arduino])
//////////////////////////////
// NE PAS METTRE DE SERIAL.BEGIN()
//////
void Chariot::Setup(){
    pinMode(ena,OUTPUT);
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
}