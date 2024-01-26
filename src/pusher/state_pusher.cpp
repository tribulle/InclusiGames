#include "mecanisms/stock_pusher/pusher_setup.h"
#include "mecanisms/stock_pusher/state_pusher.h"

#include "extender.h"
#include "Grove_Motor_Driver_TB6612FNG.h"
//////////////////////////////
// Basic_state::MecanismF() peut être modifié à guise (pour correspondre à la partie vois loop() habituelle du main.cpp)
//////////////////////////////
// Variations State_chariot: All the possible state for the Chariot
void State_distrib::MecanismF(){
    /*
    pcf8574_2.digitalWrite(vitesseA,HIGH); // Allume le moteur
    pcf8574_2.digitalWrite(vitesseB,HIGH); // Allume le moteur
    pcf8574_2.digitalWrite(directionA,HIGH); // Fait tourner le moteur dans une direction
    pcf8574_2.digitalWrite(directionB,LOW); // Fait tourner le moteur dans une direction
    while (pcf8574.digitalRead(SENSOR)==1)
    {
        Serial.println("Pas assez loin");
        delay(10);
    }
    delay(100);
    pcf8574_2.digitalWrite(vitesseA,LOW); // Eteint le moteur
    pcf8574_2.digitalWrite(vitesseB,LOW); // Eteint le moteur( test with l298n)*/
    // drive 2 DC motors at speed=200, anticlockwise
    
    //////////DEMARRER 2 motors
    Serial.println("run at speed=-255");
    motor.dcMotorRun(MOTOR_CHA, -255);
    motor.dcMotorRun(MOTOR_CHB, -255);
    delay(3000);// le temps doit etre fixe en faisant des essaies
    
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
    motor.dcMotorRun(MOTOR_CHA, -255);
    motor.dcMotorRun(MOTOR_CHB, -255);
    delay(3000);// le temps doit etre fixe en faisant des essaies
    
    //////////////STOP 2 motors
    Serial.println("stop");
    // brake
    Serial.println("brake");
    motor.dcMotorBrake(MOTOR_CHA);
    motor.dcMotorBrake(MOTOR_CHB);
    delay(1000);
    
  switch (pos)/// pour initialiser la postion de stepper qui est pour changer la position stock(y a 8 postion possible)
  {
  case 0:
   Serial.println(" pas besoin de initialiser");  
   break;
  case 1:
        // Stepper run 10 rounds at MICRO_STEPPING mode, this takes about 5 seconds
        // At MICRO_STEPPING mode, one step = 1.8 degree, so it takes 200 step to go a round
        // At this mode, stepper runs very smoothly 
        Serial.print("stepper de stockge  postion 0");
        motor.stepperRun(MICRO_STEPPING, 200*10, rpm);//rpm est la vitesse de motor stepper 
        delay(6000); 
   break;
  
  default:
  break;
    
    }
}