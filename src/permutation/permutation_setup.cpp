#include "mecanisms/permutation/permutation_setup.h"
//////////////////////////////
// Définitions des variables de chariot_setup.h
// Chariot::Setup() peut être modifié à guise (pour correspondre à la partie vois setup() habituelle du main.cpp [sans la configuration Arduino])
//////////////////////////////
// NE PAS METTRE DE SERIAL.BEGIN()
//////

/*ESP_FlexyStepper stepper;
int previousDirection;
bool emergencySwitchTriggered;

void ICACHE_RAM_ATTR emergencySwitchHandler(){
  emergencySwitchTriggered = 1;
}*/

Stepper* myStepper;

void Permutation::Setup(){
  myStepper = new Stepper(stepsPerRevolution, STEPPER_IN1,STEPPER_IN2,STEPPER_IN3,STEPPER_IN4);
  myStepper->setSpeed(60);

  
	/*previousDirection = 1;
	emergencySwitchTriggered = 0;
  //set the pin for the emegrenxy witch to input with inernal pullup
  //the emergency switch is connected in a Active Low configuraiton in this example, meaning the switch connects the input to ground when closed
  pinMode(EMERGENCY_STOP_PIN, INPUT_PULLUP);
  //attach an interrupt to the IO pin of the switch and specify the handler function 
  attachInterrupt(digitalPinToInterrupt(EMERGENCY_STOP_PIN), emergencySwitchHandler, RISING);
  // connect and configure the stepper motor to its IO pins
  stepper.connectToPins(MOTOR_STEP_PIN, MOTOR_DIRECTION_PIN);

  // set the speed and acceleration rates for the stepper motor
  stepper.setSpeedInStepsPerSecond(SPEED_IN_STEPS_PER_SECOND);
  stepper.setAccelerationInStepsPerSecondPerSecond(ACCELERATION_IN_STEPS_PER_SECOND);
  stepper.setDecelerationInStepsPerSecondPerSecond(DECELERATION_IN_STEPS_PER_SECOND);*/
}