#ifndef SWAP_SETUP_H
#define SWAP_SETUP_H
//////////////////////////////
// Déclarations des variables nécessaires au Setup du chariot (Mécanisme de distribution des cartes)
// Tu peux rajouter des variables (leurs déclarations uniquement) [sauf pour les types de bases] Ne pas supprimer les autre variables
//////////////////////////////
#include "permutation.h"
// Include the Arduino Stepper Library
//#include <ESP_FlexyStepper.h>
#include <Stepper.h>
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
#define STEPPER_IN1 14
#define STEPPER_IN2 32
#define STEPPER_IN3 15
#define STEPPER_IN4 33

// initialize the stepper library on pins 8 through 11:
extern Stepper* myStepper;

/*// IO pin assignments
const int MOTOR_STEP_PIN = 33;
const int MOTOR_DIRECTION_PIN = 25;
const int EMERGENCY_STOP_PIN = 13; //define the IO PIN the emergency stop switch is connected to

// Speed settings
const int DISTANCE_TO_TRAVEL_IN_STEPS = 500;
const int SPEED_IN_STEPS_PER_SECOND = 800;
const int ACCELERATION_IN_STEPS_PER_SECOND = 500;
const int DECELERATION_IN_STEPS_PER_SECOND = 500;

// create the stepper motor object
extern ESP_FlexyStepper stepper;
extern int previousDirection;
extern bool emergencySwitchTriggered;*/

#endif