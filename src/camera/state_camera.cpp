#include "mecanisms/camera/state_camera.h"
#include "mecanisms/camera/camera_setup.h"
//////////////////////////////
// Basic_state::MecanismF() peut être modifié à guise (pour correspondre à la partie vois loop() habituelle du main.cpp)
//////////////////////////////
// Variations State_chariot: All the possible state for the Chariot
void Basic_state::MecanismF(){
    camera->oneFrame();  
    delay(100);
    serve();
}
