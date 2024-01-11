#include <Arduino.h>
#include "main/main.h"

//////////////////////////////
// Ne pas toucher à part pour des tests (suivre la logique qui suit)
//////////////////////////////

Basic_state_camera* basic_state_camera = new Basic_state_camera(nullptr,nullptr);
CameraMecanism* camera_mecanism = new CameraMecanism(basic_state_camera, "Camera");

Disabled_person_position_push* disabled_person_position_push = new Disabled_person_position_push(nullptr,nullptr);
Disabled_person_position_reset* disabled_person_position_reset = new Disabled_person_position_reset(nullptr,nullptr);
Chariot* chariot = new Chariot(disabled_person_position_push, "Chariot");

Basic_state_permutation* basic_state_permutation = new Basic_state_permutation(nullptr,nullptr);
Permutation* permutation = new Permutation(basic_state_permutation, "Permutation");

State_distrib* state_distrib = new State_distrib(nullptr,nullptr);
State_stocking* state_stocking = new State_stocking(nullptr,nullptr);
Pusher* pusher = new Pusher(state_distrib, "Pusher");

ThreadList* threadlist;

Mecanism* disabled_person_position_push_next_mec[1] = {pusher};
Mecanism* state_distrib_next_mec[2] = {permutation, chariot};
Mecanism* basic_state_permutation_next_mec[1] = {camera_mecanism};
Mecanism* basic_state_camera_next_mec[1] = {pusher};

void setup() {
    Serial.begin(115200);
    Serial.println("DEBUT SETUP");
        Serial.println(    sizeof(disabled_person_position_push_next_mec)/sizeof(disabled_person_position_push_next_mec[0]));
    Serial.println(    sizeof(state_distrib_next_mec)/sizeof(state_distrib_next_mec[0]));
        Serial.println(    sizeof(basic_state_permutation_next_mec)/sizeof(basic_state_permutation_next_mec[0]));


    //Serial.println("TEST");
    //Serial.println(state_distrib->next_mecanism_==nullptr);
    Serial.println("SUITE DU SETUP");

    disabled_person_position_push->Change_next_mecanism_to(disabled_person_position_push_next_mec, 1);
    state_distrib->Change_next_mecanism_to(state_distrib_next_mec, 2);
    basic_state_permutation->Change_next_mecanism_to(basic_state_permutation_next_mec, 1);
    basic_state_camera->Change_next_mecanism_to(basic_state_camera_next_mec, 1);

    disabled_person_position_push->Change_next_state_to(disabled_person_position_reset);
    disabled_person_position_reset->Change_next_state_to(disabled_person_position_push);
    state_distrib->Change_next_state_to(state_stocking);
    state_stocking->Change_next_state_to(state_distrib);

        Serial.println(disabled_person_position_push->next_mecanism_==nullptr);
            Serial.println(disabled_person_position_reset->next_mecanism_==nullptr);
        Serial.println(disabled_person_position_push->next_state_==nullptr);
            Serial.println(disabled_person_position_reset->next_state_==nullptr);

    Serial.print("And the tableau: ");
    Serial.print(disabled_person_position_push_next_mec==nullptr);
    Serial.print(disabled_person_position_push_next_mec[0]==nullptr);
    Serial.println(disabled_person_position_push_next_mec[1]==nullptr);

    Serial.print(disabled_person_position_push->next_mecanism_==nullptr);
    Serial.print(disabled_person_position_push->next_mecanism_[0]==nullptr);
    Serial.println(disabled_person_position_push->next_mecanism_[1]==nullptr);

    Serial.println("REFRESH DATA");
            Serial.print("Integrity: ");
            Serial.println(chariot->next_mecanism_==chariot->ShowState()->next_mecanism_);

    chariot->RefreshStateData();
    permutation->RefreshStateData();
    pusher->RefreshStateData();
    camera_mecanism->RefreshStateData();

    Serial.println(chariot->ShowState()->next_mecanism_==nullptr);
    Serial.println(chariot->next_mecanism_==nullptr);
    Serial.println("SETUP()");
            Serial.print("Integrity: ");
            Serial.println(chariot->next_mecanism_==chariot->ShowState()->next_mecanism_);

            Serial.print(chariot->next_mecanism_==nullptr);
            Serial.print(chariot->next_mecanism_[0]==nullptr);
            Serial.println(chariot->next_mecanism_[1]==nullptr);

            Serial.print(chariot->ShowState()->next_mecanism_==nullptr);
            Serial.print(chariot->ShowState()->next_mecanism_[0]==nullptr);
            Serial.println(chariot->ShowState()->next_mecanism_[1]==nullptr);
    //camera_mecanism->Setup();
    chariot->Setup();
    //Serial.println(chariot->ShowState()->next_mecanism_==nullptr);
    //permutation->Setup();
    Serial.println("SETUP THREAD");
    threadlist = new ThreadList(chariot);
    Serial.println("FIN DU SETUP");
}

void loop() {
    Serial.println("CA START");
        Serial.print("And the tableau: ");

    Serial.println(sizeof(state_distrib_next_mec)/sizeof(state_distrib_next_mec[0]));
    Serial.println(state_distrib->nb_next_mecs_);
    Serial.println(pusher->nb_next_mecs_);

                Serial.println(    sizeof(chariot->next_mecanism_)/sizeof(chariot->next_mecanism_[0]));
    Serial.println(    sizeof(pusher->next_mecanism_)/sizeof(pusher->next_mecanism_[0]));
        Serial.println(    sizeof(permutation->next_mecanism_)/sizeof(permutation->next_mecanism_[0]));

                Serial.print("Integrity: ");
            Serial.println(pusher->next_mecanism_==pusher->ShowState()->next_mecanism_);
            Serial.println(state_distrib_next_mec[0]==pusher->next_mecanism_[0]);
            Serial.println(state_distrib_next_mec[1]==pusher->next_mecanism_[1]);
            Serial.println(state_distrib_next_mec[2]==pusher->next_mecanism_[2]);

            Serial.print(chariot->next_mecanism_==nullptr);
            //Serial.print(chariot->next_mecanism_[0]==nullptr);
            //Serial.println(chariot->next_mecanism_[1]==nullptr);

            Serial.print(chariot->ShowState()->next_mecanism_==nullptr);
            //Serial.print(chariot->ShowState()->next_mecanism_[0]==nullptr);
            //Serial.println(chariot->ShowState()->next_mecanism_[1]==nullptr);
    //threadlist->LaunchThread();
    chariot->LaunchMecanism();
    //permutation->LaunchMecanism();
    //camera_mecanism->LaunchMecanism();
    Serial.println("FIN DE LA LOOP");
}
