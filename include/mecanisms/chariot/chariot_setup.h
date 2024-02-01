#ifndef CHARIOT_SETUP_H
#define CHARIOT_SETUP_H
//////////////////////////////
// Déclarations des variables nécessaires au Setup du chariot (Mécanisme de distribution des cartes)
// Tu peux rajouter des variables (leurs déclarations uniquement) [sauf pour les types de bases] Ne pas supprimer les autre variables
//////////////////////////////
#include "chariot.h"
#include <ESP32Servo.h>
#include<extender.h>
const int potpin = A0;
const int val = 90;

const int enA = P5;
const int in1 = P0;
const int in2 = P1;

//const int in3= P2;
//const int in4=P3;
const int enB=P6;

// ICI Le port de ena,in1,in2 sont des port d'extenteur2 et se vois 


extern Servo servo;

#endif