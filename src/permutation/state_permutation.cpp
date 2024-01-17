#include "mecanisms/permutation/permutation_setup.h"
#include "mecanisms/permutation/state_permutation.h"
//////////////////////////////
// Basic_state::MecanismF() peut être modifié à guise (pour correspondre à la partie vois loop() habituelle du main.cpp)
//////////////////////////////
// Variations State_chariot: All the possible state for the Chariot

void Basic_state_permutation::MecanismF(){
  Serial.println("Rotating Clockwise...");
  myStepper->step(890);
  delay(500);
  Serial.println("Rotating Anti-Clockwise...");
  myStepper->step(-890);
  delay(500);


  /*if(stepper.getDirectionOfMotion() == 0){
    delay(4000);
    previousDirection *= -1;
    stepper.setTargetPositionRelativeInSteps(DISTANCE_TO_TRAVEL_IN_STEPS * previousDirection);
  }
  if(emergencySwitchTriggered){
    //clear the target position (if it the stepper is moving at all) and stop moving
    stepper.emergencyStop();
    //clear the flag that has been set in the ISR 
    emergencySwitchTriggered = 0;
  }
  //call the function to update the position of the stepper in a non blocking way
  //for smooth movements this requires that the loop function in general has no blocking call to other functions and can be processes in a rather short time
  //if you need to perform long running operations in the loop, this approach will not work for you and you should start a vtask instead that calls the processMovment function
  stepper.processMovement();*/
}
