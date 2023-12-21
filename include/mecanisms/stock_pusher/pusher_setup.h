#ifndef PUSHER_SETUP_H
#define PUSHER_SETUP_H
//////////////////////////////
// Déclarations des variables nécessaires au Setup du chariot (Mécanisme de distribution des cartes)
// Tu peux rajouter des variables (leurs déclarations uniquement) [sauf pour les types de bases] Ne pas supprimer les autre variables
//////////////////////////////
#include "pusher.h"

#define LASER 2
#define SENSOR 3

const int vitesseA = 3;
const int vitesseB = 11;
const int directionA = 12;
const int directionB = 13;

extern bool value_sensor;
#endif