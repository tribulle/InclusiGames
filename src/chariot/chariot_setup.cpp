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
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    servo.setPeriodHertz(50);
    servo.attach(21, 500, 2400);
}