#include "mecanisms/stockage/stockage_setup.h"
#include "mecanisms/stockage/state_stockage.h"
#include "mecanisms/stock_pusher/pusher_setup.h"

#include "Grove_Motor_Driver_TB6612FNG.h"
//////////////////////////////
// Basic_state::MecanismF() peut être modifié à guise (pour correspondre à la partie vois loop() habituelle du main.cpp)
//////////////////////////////
// Variations State_chariot: All the possible state for the Chariot

void Draw_state_stockage::MecanismF(){
  
  int pos = this->card_position;// pos est un valeur qu'on recoit de Bluetooth
  Serial.print("DRAW: Card pos:");
  Serial.println(pos);

  // Stepper run 10 rounds at MICRO_STEPPING mode, this takes about 5 seconds
  // At MICRO_STEPPING mode, one step = 1.8 degree, so it takes 200 step to go a round
  // At this mode, stepper runs very smoothly 
  Serial.print("stepper de stockge reset");
  motor.stepperRun(MICRO_STEPPING, this->currentPos + 5, rpm);//rpm est la vitesse de motor stepper 
  delay(200); 

  Serial.print("stepper de stockge move to card_pose");
  motor.stepperRun(MICRO_STEPPING, - (pos*Step_between_pos+Step_draw)*Step_calibrer_stockage, rpm);//rpm est la vitesse de motor stepper 
  delay(200); 
  
}

void Play_state_stockage::MecanismF(){
  int pos = this->card_position;
  Serial.print("PLAY: Card pos:");
  Serial.println(pos);
  // Stepper run 10 rounds at MICRO_STEPPING mode, this takes about 5 seconds
  // At MICRO_STEPPING mode, one step = 1.8 degree, so it takes 200 step to go a round
  // At this mode, stepper runs very smoothly 
  Serial.print("stepper de stockge reset");
  motor.stepperRun(MICRO_STEPPING, this->currentPos + 5, rpm);//rpm est la vitesse de motor stepper 
  delay(200); 

  Serial.print("stepper de stockge move to card_pose");
  motor.stepperRun(MICRO_STEPPING, - (pos*Step_between_pos+Step_play)*Step_calibrer_stockage, rpm);//rpm est la vitesse de motor stepper 
  delay(200); 
}