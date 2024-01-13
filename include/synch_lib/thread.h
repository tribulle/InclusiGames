#ifndef THREAD_H
#define THREAD_H
//////////////////////////////
// Ne Pas Toucher ce fichier
//////////////////////////////
#include <memory>
#include "base_class/mecanism.h"
#include <thread>

using namespace std;

// ThreadList manage to synchronize dynamically a list of mecanisms.
// We don't have to provide the full list of mecanisms, because each state of each mecanism provide the next mecanism to launch.
// We just have to provide the first Mecanism to launch.
// Typically some mecanism don't have a next_mecanism_ (by default = nullptr) so the ThreadList will stop.
class ThreadList{
    public:
        int mec_nb_x;

        void LaunchThread(Mecanism* first_mecanism){
            mec_nb_x=0;
            LaunchMecanismInThread(first_mecanism);
        }

        void LaunchMecanismInThread(Mecanism* mecanism_pointer){

            mec_nb_x += 1;
            Serial.println("");
            Serial.println("");
            Serial.print("THREAD: start n°: ");
            Serial.println(mec_nb_x);

            if (mecanism_pointer != nullptr){

                Mecanism** next_mecs= mecanism_pointer->next_mecanism_;
                int len_next_mecanism = mecanism_pointer->nb_next_mecs_;

                thread t1(&Mecanism::LaunchMecanism, mecanism_pointer);
                t1.join();

                Serial.print("THREAD: nb de mecanismes suivant: ");
                Serial.println(len_next_mecanism);

                if(next_mecs != nullptr && len_next_mecanism != 0){
                    for (int e=0; e<len_next_mecanism; e++){
                        if(next_mecs[e] != nullptr) LaunchMecanismInThread(next_mecs[e]);
                        else Serial.println("THREAD: FATAL ERROR next_mecs[e] == Nullptr");
                    }
                }else{
                    Serial.println("THREAD: Fini");
                }

            }else{
                Serial.println("Error: mecanism_pointer == nullptr ");
            }
        }

};

#endif