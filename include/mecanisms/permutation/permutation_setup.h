#ifndef SWAP_SETUP_H
#define SWAP_SETUP_H
//////////////////////////////
// Déclarations des variables nécessaires au Setup
// Tu peux rajouter des variables (leurs déclarations uniquement) [sauf pour les types de bases] Ne pas supprimer les autre variables
//////////////////////////////
#include "permutation.h"
#include <Stepper.h>
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
#define STEPPER_IN1 14
#define STEPPER_IN2 32
#define STEPPER_IN3 15
#define STEPPER_IN4 33

// initialize the stepper library on pins 8 through 11:
extern Stepper* myStepper;

#endif