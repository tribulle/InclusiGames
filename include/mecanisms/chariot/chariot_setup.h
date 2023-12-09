#ifndef CHARIOT_SETUP_H
#define CHARIOT_SETUP_H
//////////////////////////////
// Déclarations des variables nécessaires au Setup du chariot (Mécanisme de distribution des cartes)
// Tu peux rajouter des variables (leurs déclarations uniquement) [sauf pour les types de bases] Ne pas supprimer les autre variables
//////////////////////////////
#include "chariot.h"
#include <ESP32Servo.h>

const int potpin = A0;
const int val = 90;

extern Servo servo;

#endif