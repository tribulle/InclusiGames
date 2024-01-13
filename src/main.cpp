#include <Arduino.h>
#include "main/main.h"


//////////////////////////////
// DECLARATION DES ETATS (STATE) DE CHAQUE MECANISME avec (nullptr,nullptr)
//////////////////////////////

Basic_state_camera* camera_state = new Basic_state_camera(nullptr,nullptr); // CAMERA

Chariot_state_push* chariot_state_push = new Chariot_state_push(nullptr,nullptr); // CHARIOT: DISTRIBUTION
Chariot_state_reset* chariot_state_reset = new Chariot_state_reset(nullptr,nullptr); // CHARIOT: RESET

Basic_state_permutation* permutation_state = new Basic_state_permutation(nullptr,nullptr); // MECANISM DE PERMUTATION (RETOURNER LA CARTE)

State_distrib* pusher_state_placement_helping = new State_distrib(nullptr,nullptr); // PUSHER: FAIRE AVANCER LA CARTE SOUS LA CAMERA
State_stocking* pusher_state_card_stocking = new State_stocking(nullptr,nullptr);// PUSHER: FAIRE AVANCER LA CARTE DANS LE STOCKAGE

//////////////////////////////
// DECLARATION DES MECANISMES (MECANISM)
//////////////////////////////

CameraMecanism* camera_mecanism = new CameraMecanism(nullptr, "Camera"); // Paramètres: (State: Etat initial au lancement des mécanismes, Nom: nom du mécanisme pour le débuggage)
Chariot* chariot_mecanism = new Chariot(nullptr, "Chariot");
Permutation* permutation_mecanism = new Permutation(nullptr, "Permutation");
Pusher* pusher_mecanism = new Pusher(nullptr, "Pusher");

//////////////////////////////
// DECLARATION DES TABLEAUX DES PROCHAIN MECANISMES (mettre nullptr ou enlever la ligne si aucun mécanisme ne suit)
//////////////////////////////

Mecanism* chariot_state_push_NEXTMEC[1] = {pusher_mecanism}; // 1 tableau par état (state)
Mecanism* pusher_state_placement_helping_NEXTMEC[2] = {chariot_mecanism, permutation_mecanism};
Mecanism* permutation_state_NEXTMEC[1] = {camera_mecanism};
Mecanism* camera_state_NEXTMEC[1] = {pusher_mecanism};

//////////////////////////////
// DECLARATION DES THREADS
//////////////////////////////

ThreadList* threadlist;

void setup() {

    Serial.println("SETUP: START");

    Serial.begin(115200);

////////////////////////////////////////////////////////////////////////
    Serial.println("SETUP: CHANGE NEXT_MECANISM"); // CHANGE NEXT_MECANISM (mettre nullptr ou enlever la ligne si aucun mécanisme ne suit)

    chariot_state_push->Change_next_mecanism_to(chariot_state_push_NEXTMEC, 1); // Paramètres: (Tableau: next_mecanisms, Nombre: Longueur du tableau next_mecanism)
    pusher_state_placement_helping->Change_next_mecanism_to(pusher_state_placement_helping_NEXTMEC, 2);
    permutation_state->Change_next_mecanism_to(permutation_state_NEXTMEC, 1);
    camera_state->Change_next_mecanism_to(camera_state_NEXTMEC, 1);

////////////////////////////////////////////////////////////////////////
    Serial.println("SETUP: CHANGE NEXT_STATE"); // CHANGE NEXT_STATE (mettre nullptr ou enlever la ligne si l'état ne change pas)

    chariot_state_push->Change_next_state_to(chariot_state_reset); // Paramètres: (State: prochain état)
    chariot_state_reset->Change_next_state_to(chariot_state_push);

    pusher_state_placement_helping->Change_next_state_to(pusher_state_card_stocking);
    pusher_state_card_stocking->Change_next_state_to(pusher_state_placement_helping);

////////////////////////////////////////////////////////////////////////
    Serial.println("SETUP: LANCEMENT MECANISM->DATA_STATE_REFRESH() ET MECANISM->SETUP()"); // Obligatoire pour pouvoir utiliser un mécanisme (mettre en commentaire les mécanismes non brancher pour éviter tous problèmes possible)

    //camera_mecanism->Setup();
    //chariot_mecanism->Setup();
    //permutation_mecanism->Setup();
    pusher_mecanism->Setup();

////////////////////////////////////////////////////////////////////////
    Serial.println("SETUP: THREAD SETUP"); // 1 Thread permet de lancer une séquence de mécanismes (on peut lancer un mécanisme sans passer par un thread)

    threadlist = new ThreadList();

////////////////////////////////////////////////////////////////////////
    Serial.println("SETUP: INITIALIZE MECANISM'S INITIAL STATE"); // Juste pour choisir l'état "d'origine" du mécanisme 

    camera_mecanism->TransitionTo(camera_state);
    chariot_mecanism->TransitionTo(chariot_state_push);
    permutation_mecanism->TransitionTo(permutation_state);
    pusher_mecanism->TransitionTo(pusher_state_placement_helping);

    Serial.println("SETUP: END");
}

void loop() {
    Serial.println("LOOP: START");

////////////////////////////////////////////////////////////////////////
    Serial.println("LOOP: MECANISM LAUNCH");
    //threadlist->LaunchThread(chariot_mecanism);

    chariot_mecanism->LaunchMecanism();
    //permutation_mecanism->LaunchMecanism();
    //camera_mecanism->LaunchMecanism();
    //pusher_mecanism->LaunchMecanism();

    Serial.println("LOOP: END");
}
