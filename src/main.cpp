#include <Arduino.h>
#include "main/main.h"


//////////////////////////////
// DECLARATION DES ETATS (STATE) DE CHAQUE MECANISME avec (nullptr,nullptr)
//////////////////////////////

Basic_state_camera* camera_basic_state = new Basic_state_camera(nullptr,nullptr); // CAMERA

Chariot_state_push* chariot_state_push = new Chariot_state_push(nullptr,nullptr); // CHARIOT: DISTRIBUTION
Chariot_state_reset* chariot_state_reset = new Chariot_state_reset(nullptr,nullptr); // CHARIOT: RESET

Basic_state_permutation* basic_state_permutation = new Basic_state_permutation(nullptr,nullptr); // MECANISM DE PERMUTATION (RETOURNER LA CARTE)

State_distrib* state_distrib = new State_distrib(nullptr,nullptr); // PUSHER: FAIRE AVANCER LA CARTE SOUS LA CAMERA
State_stocking* state_stocking = new State_stocking(nullptr,nullptr);// PUSHER: FAIRE AVANCER LA CARTE DANS LE STOCKAGE

//////////////////////////////
// DECLARATION DES MECANISMES (MECANISM)
//////////////////////////////

CameraMecanism* camera_mecanism = new CameraMecanism(camera_basic_state, "Camera"); // Paramètres: (State: Etat initial au lancement des mécanismes, Nom: nom du mécanisme pour le débuggage)
Chariot* chariot = new Chariot(chariot_state_push, "Chariot");
Permutation* permutation = new Permutation(basic_state_permutation, "Permutation");
Pusher* pusher = new Pusher(state_distrib, "Pusher");

//////////////////////////////
// DECLARATION DES TABLEAUX DES PROCHAIN MECANISMES (mettre nullptr ou enlever la ligne si aucun mécanisme ne suit)
//////////////////////////////

Mecanism* chariot_state_push_next_mec[1] = {pusher}; // 1 tableau par état (state)
Mecanism* state_distrib_next_mec[2] = {chariot, permutation};
Mecanism* basic_state_permutation_next_mec[1] = {camera_mecanism};
Mecanism* basic_state_camera_next_mec[1] = {pusher};

//////////////////////////////
// DECLARATION DES THREADS
//////////////////////////////

ThreadList* threadlist;

void setup() {

    Serial.println("SETUP: START");

    Serial.begin(115200);

////////////////////////////////////////////////////////////////////////
    Serial.println("SETUP: CHANGE NEXT_MECANISM"); // CHANGE NEXT_MECANISM (mettre nullptr ou enlever la ligne si aucun mécanisme ne suit)

    chariot_state_push->Change_next_mecanism_to(chariot_state_push_next_mec, 1); // Paramètres: (Tableau: next_mecanisms, Nombre: Longueur du tableau next_mecanism)
    state_distrib->Change_next_mecanism_to(state_distrib_next_mec, 2);
    basic_state_permutation->Change_next_mecanism_to(basic_state_permutation_next_mec, 1);
    camera_basic_state->Change_next_mecanism_to(basic_state_camera_next_mec, 1);

////////////////////////////////////////////////////////////////////////
    Serial.println("SETUP: CHANGE NEXT_STATE"); // CHANGE NEXT_STATE (mettre nullptr ou enlever la ligne si l'état ne change pas)

    chariot_state_push->Change_next_state_to(chariot_state_reset); // Paramètres: (State: prochain état)
    chariot_state_reset->Change_next_state_to(chariot_state_push);

    state_distrib->Change_next_state_to(state_stocking);

    state_stocking->Change_next_state_to(state_distrib);

////////////////////////////////////////////////////////////////////////
    Serial.println("SETUP: REFRESH MECANISM DATA"); // REFRESH MECANISM'S DATA (Rajouter cette ligne obligatoirement pour chaque nouveau mécanisme)

    chariot->RefreshStateData();
    permutation->RefreshStateData();
    pusher->RefreshStateData();
    camera_mecanism->RefreshStateData();

////////////////////////////////////////////////////////////////////////
    Serial.println("SETUP: LANCEMENT MECANISM->SETUP()"); // Obligatoire pour pouvoir utiliser un mécanisme (mettre en commentaire les mécanismes non brancher pour éviter tous problèmes possible)

    //camera_mecanism->Setup();
    //chariot->Setup();
    //permutation->Setup();
    pusher->Setup();

////////////////////////////////////////////////////////////////////////
    Serial.println("SETUP: THREAD SETUP"); // 1 Thread permet de lancer une séquence de mécanismes (on peut lancer un mécanisme sans passer par un thread)

    threadlist = new ThreadList();


    Serial.println("SETUP: END");
}

void loop() {
    Serial.println("LOOP: START");

////////////////////////////////////////////////////////////////////////
    Serial.println("LOOP: MECANISM LAUNCH");
    //threadlist->LaunchThread(chariot);

    chariot->LaunchMecanism();
    //permutation->LaunchMecanism();
    //camera_mecanism->LaunchMecanism();
    //pusher->LaunchMecanism();

    Serial.println("LOOP: END");
}
