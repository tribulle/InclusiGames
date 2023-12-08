#ifndef SWAP_SETUP_H
#define SWAP_SETUP_H
//////////////////////////////
// Déclarations des variables nécessaires au Setup du chariot (Mécanisme de distribution des cartes)
// Tu peux rajouter des variables (leurs déclarations uniquement) [sauf pour les types de bases] Ne pas supprimer les autre variables
//////////////////////////////
#include "permutation.h"
// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 200;
//int i =0;

// Create Instance of Stepper library
extern Stepper myStepper;//8,11,9,10

#endif