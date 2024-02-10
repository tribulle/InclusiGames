#include "mecanisms/stock_pusher/pusher_setup.h"
#include "mecanisms/stock_pusher/state_pusher.h"

#include "extender.h"
#include "Grove_Motor_Driver_TB6612FNG.h"
//////////////////////////////
// Basic_state::MecanismF() peut être modifié à guise (pour correspondre à la partie vois loop() habituelle du main.cpp)
//////////////////////////////
// Variations State_chariot: All the possible state for the Chariot
void State_distrib::MecanismF(){
    
    //////////DEMARRER 2 motors
    Serial.println("run at speed=-255");
    motor.dcMotorRun(MOTOR_CHA, -50);
    motor.dcMotorRun(MOTOR_CHB, -50);
    delay(1000);// le temps doit etre fixe en faisant des essaies
    
    //////////////STOP 2 motors
    Serial.println("stop");
    // brake
    Serial.println("brake");
    motor.dcMotorBrake(MOTOR_CHA);
    motor.dcMotorBrake(MOTOR_CHB);
    delay(1000);
    



    // Stepper run 10 rounds at MICRO_STEPPING mode, this takes about 5 seconds
    // At MICRO_STEPPING mode, one step = 1.8 degree, so it takes 200 step to go a round
    // At this mode, stepper runs very smoothly
    
    //Serial.print("OSKOURRR");
    //motor.stepperRun(MICRO_STEPPING, -200*10, rpm);
    //delay(6000);
       
}

void State_stocking::MecanismF(){
    int pos = this->card_position;
    Serial.print(" push to stock at the postion: "); 
    Serial.println(pos);
    //////////DEMARRER 2 motors
    Serial.println("run at speed=-255");
    motor.dcMotorRun(MOTOR_CHA, 40);// faut faire attention au tension correspondre
    motor.dcMotorRun(MOTOR_CHB, 40);
    delay(1000);// le temps doit etre fixe en faisant des essaies
    
    //////////////STOP 2 motors
    Serial.println("stop");
    // brake
    Serial.println("brake");
    motor.dcMotorBrake(MOTOR_CHA);
    motor.dcMotorBrake(MOTOR_CHB);
    delay(1000);
}