#include <Arduino.h>

#include "mecanisms/camera/camera.h"
#include "mecanisms/camera/state_camera.h"

Basic_state* basic_state_camera = new Basic_state(nullptr);
CameraMecanism* camera_mecanism = new CameraMecanism(basic_state_camera);

void setup() {
    camera_mecanism->Setup();
}

void loop() {
    camera_mecanism->LaunchMecanism();
}
