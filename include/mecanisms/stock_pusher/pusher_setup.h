#ifndef PUSHER_SETUP_H
#define PUSHER_SETUP_H
//////////////////////////////
// Déclarations des variables nécessaires au Setup du chariot (Mécanisme de distribution des cartes)
// Tu peux rajouter des variables (leurs déclarations uniquement) [sauf pour les types de bases] Ne pas supprimer les autre variables
//////////////////////////////
#include "pusher.h"
#include "extender.h"
#include "Grove_Motor_Driver_TB6612FNG.h"

const int LASER = P0;
const int SENSOR = 34;

//const int enAP = 12; test
//const int enBP = 14;

//const int In1 = 27;
//const int In2 = 33;
//const int In3 = 15;
//const int In4 = 32; test

extern bool value_sensor;

extern MotorDriver motor;
#endif