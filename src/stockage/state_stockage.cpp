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
  Serial.print("stepper de stockge on");
  motor.stepperRun(MICRO_STEPPING, -200*10, rpm);//rpm est la vitesse de motor stepper 
  delay(6000); 
  
  switch (pos)
  {
    case 0:
   Serial.println(" no carte vont enregistrer");  
     break;
  case 1:
        // Stepper run 10 rounds at MICRO_STEPPING mode, this takes about 5 seconds
        // At MICRO_STEPPING mode, one step = 1.8 degree, so it takes 200 step to go a round
        // At this mode, stepper runs very smoothly 
        Serial.print("stepper de stockge  postion 0");
        motor.stepperRun(MICRO_STEPPING, -200*10, rpm);//rpm est la vitesse de motor stepper 
        delay(6000); 
     break;
  
  default:
        Serial.print("no carte à stocker");
    break;
  }

  
}

void Play_state_stockage::MecanismF(){
  int pos = this->card_position;
  Serial.print("PLAY: Card pos:");
  Serial.println(pos);
}