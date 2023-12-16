#include <Arduino.h>
#include "synch_lib/thread.h"

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

ThreadList* threadlist = new ThreadList(chariot);

void setup() {
    Serial.begin(115200);
    Serial.println("CA SETUP");
    //disabled_person_position->Change_next_mecanism_to(chariot);

    //camera_mecanism->Setup();
    //chariot->Setup();
    permutation->Setup();
}

void loop() {
    Serial.println("CA START");
    //threadlist->LaunchThread();
    //chariot->LaunchMecanism();
    permutation->LaunchMecanism();
}
