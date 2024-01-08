#include <Arduino.h>
#include "main/main.h"

//////////////////////////////
// Ne pas toucher à part pour des tests (suivre la logique qui suit)
//////////////////////////////

Basic_state_camera* basic_state_camera = new Basic_state_camera(nullptr,nullptr);
CameraMecanism* camera_mecanism;

Disabled_person_position_push* disabled_person_position_push = new Disabled_person_position_push(nullptr,nullptr);
Disabled_person_position_reset* disabled_person_position_reset = new Disabled_person_position_reset(nullptr,nullptr);
Chariot* chariot;

Basic_state_permutation* basic_state_permutation = new Basic_state_permutation(nullptr,nullptr);
Permutation* permutation;

State_distrib* state_distrib = new State_distrib(nullptr,nullptr);
Pusher* pusher;

ThreadList* threadlist;

void setup() {
    Serial.begin(115200);
    Serial.println("DEBUT SETUP");

    camera_mecanism = new CameraMecanism(basic_state_camera);
    chariot = new Chariot(disabled_person_position_push);
    permutation = new Permutation(basic_state_permutation);
    pusher = new Pusher(state_distrib);

    threadlist = new ThreadList(chariot);

    //Serial.println("TEST");
    //Serial.println(state_distrib->next_mecanism_==nullptr);
    Serial.println("SUITE DU SETUP");

    Mecanism* disabled_person_position_push_next_mec[1] = {chariot};
    Mecanism* disabled_person_position_reset_next_mec[1] = {chariot};
    disabled_person_position_push->Change_next_mecanism_to(disabled_person_position_push_next_mec);
    disabled_person_position_reset->Change_next_mecanism_to(disabled_person_position_reset_next_mec);
    disabled_person_position_push->Change_next_state_to(disabled_person_position_reset);
    disabled_person_position_reset->Change_next_state_to(disabled_person_position_push);

        Serial.println(disabled_person_position_push->next_mecanism_==nullptr);
            Serial.println(disabled_person_position_reset->next_mecanism_==nullptr);
        Serial.println(disabled_person_position_push->next_state_==nullptr);
            Serial.println(disabled_person_position_reset->next_state_==nullptr);

    Serial.print("And the tableau: ");
    Serial.print(disabled_person_position_reset_next_mec==nullptr);
    Serial.print(disabled_person_position_reset_next_mec[0]==nullptr);
    Serial.println(disabled_person_position_reset_next_mec[1]==nullptr);

    Mecanism* state_distrib_next_mec[2] = {permutation,chariot};
    state_distrib->Change_next_mecanism_to(state_distrib_next_mec);

    Serial.println("REFRESH DATA");

    chariot->RefreshStateData();
    permutation->RefreshStateData();
    pusher->RefreshStateData();

    Serial.println(chariot->ShowState()->next_mecanism_==nullptr);
    Serial.println(chariot->next_mecanism_==nullptr);
    Serial.println("SETUP()");
    //camera_mecanism->Setup();
    //chariot->Setup();
    //Serial.println(chariot->ShowState()->next_mecanism_==nullptr);
    //permutation->Setup();
    Serial.println("FIN DU SETUP");
}

void loop() {
    //Serial.println("CA START");
    threadlist->LaunchThread();
    //chariot->LaunchMecanism();
    //permutation->LaunchMecanism();
    //camera_mecanism->LaunchMecanism();
}
