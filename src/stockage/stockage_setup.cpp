#include "mecanisms/stockage/stockage_setup.h"
#include "extender.h"
//////////////////////////////
// Définitions des variables de chariot_setup.h
// Chariot::Setup() peut être modifié à guise (pour correspondre à la partie vois setup() habituelle du main.cpp [sans la configuration Arduino])
//////////////////////////////
// NE PAS METTRE DE SERIAL.BEGIN()
//////
Stepper* myStepper_2;
void Stockage::Setup(){
//Setup de cette mecanismes est deja fait dans pusher state( meme motor driver)
myStepper_2 = new Stepper(stepsPerRevolution_2, P4,P5,P6,P7);
myStepper_2->setSpeed(60);

}