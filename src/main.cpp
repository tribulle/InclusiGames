#include <Arduino.h>

#include "mecanisms/camera/camera.h"
#include "mecanisms/camera/state_camera.h"

#include "mecanisms/chariot/chariot.h"
#include "mecanisms/chariot/state_chariot.h"

#include "mecanisms/permutation/permutation.h"
#include "mecanisms/permutation/state_permutation.h"
//////////////////////////////
// Ne pas toucher à part pour des tests (suivre la logique qui suit)
//////////////////////////////

Basic_state_camera* basic_state_camera = new Basic_state_camera(nullptr);
CameraMecanism* camera_mecanism = new CameraMecanism(basic_state_camera);

Disabled_person_position* disabled_person_position = new Disabled_person_position(nullptr);
Chariot* chariot = new Chariot(disabled_person_position);

Basic_state_permutation* basic_state_permutation = new Basic_state_permutation(nullptr);
Permutation* permutation = new Permutation(basic_state_permutation);

void setup() {
    Serial.begin(921600);
    camera_mecanism->Setup();
    chariot->Setup();
    permutation->Setup();
}

void loop() {
    camera_mecanism->LaunchMecanism();
}
