#include <Arduino.h>
#include "main/main.h"
#include<Wire.h>

//////////////////////////////
// DECLARATION DES ETATS (STATE) DE CHAQUE MECANISME avec (nullptr,nullptr)
//////////////////////////////

Basic_state_camera* camera_state = new Basic_state_camera(nullptr,nullptr); // CAMERA

Chariot_state_push* chariot_state_push = new Chariot_state_push(nullptr,nullptr); // CHARIOT: DISTRIBUTION
Chariot_state_reset* chariot_state_reset = new Chariot_state_reset(nullptr,nullptr); // CHARIOT: RESET

Basic_state_permutation* permutation_state = new Basic_state_permutation(nullptr,nullptr); // MECANISM DE PERMUTATION (RETOURNER LA CARTE)

State_distrib* pusher_state_placement_helping = new State_distrib(nullptr,nullptr); // PUSHER: FAIRE AVANCER LA CARTE SOUS LA CAMERA
State_stocking* pusher_state_card_stocking = new State_stocking(nullptr,nullptr);// PUSHER: FAIRE AVANCER LA CARTE DANS LE STOCKAGE

Draw_state_stockage* stockage_state_draw = new Draw_state_stockage(nullptr,nullptr); // PUSHER: FAIRE AVANCER LA CARTE SOUS LA CAMERA
Play_state_stockage* stockage_state_play = new Play_state_stockage(nullptr,nullptr);// PUSHER: FAIRE AVANCER LA CARTE DANS LE STOCKAGE

Basic_state_piston* piston_state = new Basic_state_piston(nullptr,nullptr);// PUSHER: FAIRE AVANCER LA CARTE DANS LE STOCKAGE

//////////////////////////////
// DECLARATION DES MECANISMES (MECANISM)
//////////////////////////////

CameraMecanism* camera_mecanism = new CameraMecanism(nullptr, "Camera"); // Paramètres: (State: Etat initial au lancement des mécanismes, Nom: nom du mécanisme pour le débuggage)
Chariot* chariot_mecanism = new Chariot(nullptr, "Chariot");
Permutation* permutation_mecanism = new Permutation(nullptr, "Permutation");
Pusher* pusher_mecanism = new Pusher(nullptr, "Pusher");
Stockage* stockage_mecanism = new Stockage(nullptr, "Stockage");
Piston* piston_mecanism = new Piston(nullptr, "Piston");

//////////////////////////////
// DECLARATION DES TABLEAUX DES PROCHAIN MECANISMES (mettre nullptr ou enlever la ligne si aucun mécanisme ne suit)
//////////////////////////////

Mecanism* chariot_state_push_NEXTMEC[1] = {pusher_mecanism}; // 1 tableau par état (state)
Mecanism* pusher_state_placement_helping_NEXTMEC[2] = {chariot_mecanism, permutation_mecanism};
Mecanism* permutation_state_NEXTMEC[1] = {pusher_mecanism};
Mecanism* camera_state_NEXTMEC[1] = {pusher_mecanism};

//////////////////////////////
// DECLARATION DES THREADS
//////////////////////////////

ThreadList* threadlist_Draw;
ThreadList* threadlist_Play;

void setup() {
    Serial.begin(115200);
   
   pinMode(4,OUTPUT);
   analogWrite(4,80);// PIN 4 Servo motor (actuellement pas utilisé)

   pcf8574.pinMode(P4, OUTPUT);
   pcf8574.pinMode(P5, OUTPUT);
   pcf8574.pinMode(P6, OUTPUT);
   pcf8574.pinMode(P7, OUTPUT);// POUR STEPPER avec L298N

   pcf8574.pinMode(P1, OUTPUT);
   pcf8574.pinMode(P2, OUTPUT);
   pcf8574.pinMode(P3, OUTPUT);// c'est pour led
   
   pcf8574.digitalWrite(P1, HIGH);
   pcf8574.digitalWrite(P2, HIGH);
    pcf8574.digitalWrite(P3, HIGH);
   //pcf8574_2.pinMode(enA,OUTPUT);
   //pcf8574_2.pinMode(enB, OUTPUT); pas besoin car l'extender est digital pas analog io

   pcf8574_2.pinMode(in1, OUTPUT);
   pcf8574_2.pinMode(in2, OUTPUT);
   pcf8574_2.pinMode(in3, OUTPUT);
   pcf8574_2.pinMode(in4, OUTPUT);// pour les deuxs motor DC Chariot

   pcf8574_2.digitalWrite(in4, LOW);
   pcf8574_2.digitalWrite(in3, LOW);
   
    Serial.println("SETUP: START");
   
    Serial.print("Init pcf8574...");
	if (pcf8574.begin()){
		Serial.println("OK");
	}else{
		Serial.println("KO");
	}
    Serial.print("Init pcf8574_2...");
	if (pcf8574_2.begin()){
		Serial.println("OK");
	}else{
		Serial.println("KO");
	}// initialisation
    


////////////////////////////////////////////////////////////////////////
    Serial.println("SETUP: CHANGE NEXT_MECANISM"); // CHANGE NEXT_MECANISM (mettre nullptr ou enlever la ligne si aucun mécanisme ne suit)

    chariot_state_push->Change_next_mecanism_to(chariot_state_push_NEXTMEC, 1); // Paramètres: (Tableau: next_mecanisms, Nombre: Longueur du tableau next_mecanism)
    pusher_state_placement_helping->Change_next_mecanism_to(pusher_state_placement_helping_NEXTMEC, 2);
    permutation_state->Change_next_mecanism_to(permutation_state_NEXTMEC, 1);
    camera_state->Change_next_mecanism_to(camera_state_NEXTMEC, 1);
    

////////////////////////////////////////////////////////////////////////
    Serial.println("SETUP: CHANGE NEXT_STATE"); // CHANGE NEXT_STATE (mettre nullptr ou enlever la ligne si l'état ne change pas)

    chariot_state_push->Change_next_state_to(chariot_state_push); // Paramètres: (State: prochain état) [Actuellement, reste dans le même état]
    chariot_state_reset->Change_next_state_to(chariot_state_reset);

    pusher_state_placement_helping->Change_next_state_to(pusher_state_placement_helping);
    pusher_state_card_stocking->Change_next_state_to(pusher_state_placement_helping);

////////////////////////////////////////////////////////////////////////
    Serial.println("SETUP: LANCEMENT MECANISM->DATA_STATE_REFRESH() ET MECANISM->SETUP()"); // Obligatoire pour pouvoir utiliser un mécanisme (mettre en commentaire les mécanismes non brancher pour éviter tous problèmes possible)

    camera_mecanism->Setup();
    //chariot_mecanism->Setup();
    //permutation_mecanism->Setup();
    //pusher_mecanism->Setup();
    //stockage_mecanism->Setup();
    //piston_mecanism->Setup();

////////////////////////////////////////////////////////////////////////
    Serial.println("SETUP: THREAD SETUP"); // 1 Thread permet de lancer une séquence de mécanismes (on peut lancer un mécanisme sans passer par un thread)

    threadlist_Draw = new ThreadList();
    threadlist_Play = new ThreadList();

////////////////////////////////////////////////////////////////////////
    Serial.println("SETUP: BLUETOOTH");

    BluetoothSetup();

////////////////////////////////////////////////////////////////////////
    Serial.println("SETUP: INITIALIZE MECANISM'S INITIAL STATE"); // Juste pour choisir l'état "d'origine" du mécanisme 

    camera_mecanism->TransitionTo(camera_state);
    chariot_mecanism->TransitionTo(chariot_state_push);
    permutation_mecanism->TransitionTo(permutation_state);
    pusher_mecanism->TransitionTo(pusher_state_placement_helping);
    stockage_mecanism->TransitionTo(stockage_state_draw);
    piston_mecanism->TransitionTo(piston_state);

    Serial.println("SETUP: END");
}

void loop() {
   
    Serial.println("LOOP: START");

    if(THREAD_BLUETOOTH_NEEDED){ // Déclaré dans synch_lib bluetooth.h
        Serial.println("LOOP: Bluetooth: Waiting");
        while(!SerialBT.connected()){}
        Serial.println("LOOP: Bluetooth: Connected");
        while(!SerialBT.available()){}
        Serial.println("LOOP: Bluetooth: Données reçues");

        String data = SerialBT.readString(); //Récupération des infos envoyées par l'application
        Serial.println(data);

        int data_length = data.length();
        int place = 0 ;
        if(data[0] == 'p'){ // Action bouton pioche

            Serial.println(data[2]);
            place = data[2]-48; // position dans le stockage libre pour accueillir la carte
            Serial.print("LOOP: Bluetooth: Piocher: Place:");
            Serial.println(place);
            stockage_state_draw->card_position = place;
            stockage_mecanism->TransitionTo(stockage_state_draw);
            ////////////////////////////////////
            //Séquence de mécansime pour la pioche de carte
            camera_mecanism->LaunchMecanism();
            ////////////////////////////////////
            //Récupère l'information de la position du stockage (pour pouvoir reset après)
            stockage_state_draw->currentPos = (place*Step_between_pos+Step_draw)*Step_calibrer_stockage;
            stockage_state_play->currentPos = (place*Step_between_pos+Step_draw)*Step_calibrer_stockage;

        }else if(data[0] == 'j'){ // Action bouton jouer un carte

            Serial.println(data[2]);
            place = data[2]-48; // position dans le stockage de la carte qui doit être expuslée
            Serial.print("LOOP: Bluetooth: Jouer: Place:");
            Serial.println(place);
            stockage_state_play->card_position = place;
            stockage_mecanism->TransitionTo(stockage_state_play);
            ////////////////////////////////////
            //Séquence de mécansime pour la pioche de carte

            ////////////////////////////////////
            //Récupère l'information de la position du stockage (pour pouvoir reset après)
            stockage_state_draw->currentPos = (place*Step_between_pos+Step_play)*Step_calibrer_stockage;
            stockage_state_play->currentPos = (place*Step_between_pos+Step_play)*Step_calibrer_stockage;

        }else{
            Serial.println("LOOP: Bluetooth: Données reçues INCORRECTES");
        }

    }else{
////////////////////////////////////////////////////////////////////////
    Serial.println("LOOP SANS BLUETOOTH: MECANISM LAUNCH");

    }

    Serial.println("LOOP: END");
}
