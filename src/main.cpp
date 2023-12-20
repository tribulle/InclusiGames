#include <Arduino.h>
#include "synch_lib/thread.h"

#include "mecanisms/camera/camera.h"
#include "mecanisms/camera/state_camera.h"

#include "mecanisms/chariot/chariot.h"
#include "mecanisms/chariot/state_chariot.h"

#include "mecanisms/permutation/permutation.h"
#include "mecanisms/permutation/state_permutation.h"

#include "mecanisms/stock_pusher/pusher.h"
#include "mecanisms/stock_pusher/state_pusher.h"
//////////////////////////////
// Ne pas toucher à part pour des tests (suivre la logique qui suit)
//////////////////////////////

Basic_state_camera* basic_state_camera = new Basic_state_camera(nullptr);
CameraMecanism* camera_mecanism = new CameraMecanism(basic_state_camera);

Disabled_person_position_push* disabled_person_position_push = new Disabled_person_position_push(nullptr);
Chariot* chariot = new Chariot(disabled_person_position_push);

Basic_state_permutation* basic_state_permutation = new Basic_state_permutation(nullptr);
Permutation* permutation = new Permutation(basic_state_permutation);

State_distrib* state_distrib = new State_distrib(nullptr);
Pusher* pusher = new Pusher(state_distrib);

ThreadList* threadlist = new ThreadList(chariot);

void setup() {
    Serial.begin(115200);
    Serial.println("CA SETUP");

    Mecanism* disabled_person_position_push_next_mec[2] = {pusher,chariot};
    disabled_person_position_push->Change_next_mecanism_to(disabled_person_position_push_next_mec);

    Mecanism* state_distrib_next_mec[1] = {permutation};
    state_distrib->Change_next_mecanism_to(state_distrib_next_mec);

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
