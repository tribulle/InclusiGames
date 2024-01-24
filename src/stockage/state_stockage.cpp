#include "mecanisms/stockage/stockage_setup.h"
#include "mecanisms/stockage/state_stockage.h"
//////////////////////////////
// Basic_state::MecanismF() peut être modifié à guise (pour correspondre à la partie vois loop() habituelle du main.cpp)
//////////////////////////////
// Variations State_chariot: All the possible state for the Chariot

void Draw_state_stockage::MecanismF(){
  int pos = this->card_position;
  Serial.print("DRAW: Card pos:");
  Serial.println(pos);
}

void Play_state_stockage::MecanismF(){
  int pos = this->card_position;
  Serial.print("PLAY: Card pos:");
  Serial.println(pos);
}