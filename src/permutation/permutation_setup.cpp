#include "mecanisms/permutation/permutation_setup.h"
//////////////////////////////
// Définitions des variables de chariot_setup.h
// Chariot::Setup() peut être modifié à guise (pour correspondre à la partie vois setup() habituelle du main.cpp [sans la configuration Arduino])
//////////////////////////////
// NE PAS METTRE DE SERIAL.BEGIN()
//////

Stepper myStepper(stepsPerRevolution, 8, 11, 9, 10);

void Permutation::Setup(){
	// set the speed at 60 rpm:
	myStepper.setSpeed(50);
}