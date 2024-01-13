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
            Serial.print("Integrity: ");
            Serial.println(mecanism_pointer->next_mecanism_==mecanism_pointer->ShowState()->next_mecanism_);
            Serial.print("THREAD: taille: ");
            Serial.println(sizeof(mecanism_pointer->next_mecanism_)/sizeof(mecanism_pointer->next_mecanism_[0]));
            Serial.print("THREAD: And the tableau: ");
            Serial.print(mecanism_pointer->next_mecanism_==nullptr);
            //Serial.print(mecanism_pointer->next_mecanism_[0]==nullptr);
            //Serial.print(mecanism_pointer->next_mecanism_[1]==nullptr);

            Serial.print(mecanism_pointer->ShowState()->next_mecanism_==nullptr);
            //Serial.print(mecanism_pointer->ShowState()->next_mecanism_[0]==nullptr);
            //Serial.println(mecanism_pointer->ShowState()->next_mecanism_[1]==nullptr);
            if (mecanism_pointer != nullptr){
                Mecanism** next_mecs= mecanism_pointer->next_mecanism_;
                int len_next_mecanism = mecanism_pointer->nb_next_mecs_;
                Serial.print("DEBUG next mecs null:");
                Serial.println(next_mecs==nullptr);

                Serial.println("THREAD: Lancement du mécanisme");
                thread t1(&Mecanism::LaunchMecanism, mecanism_pointer);

                t1.join();
                Serial.print("DEBUG post next mecs null:");
                Serial.println(next_mecs==nullptr);
                if(next_mecs != nullptr){
                    Serial.print("THREAD: taille: ");
                    Serial.print(sizeof(next_mecs));
                    Serial.print(sizeof(next_mecs[0]));
                    Serial.print(sizeof(next_mecs[1]));
                    Serial.println(sizeof(next_mecs[2]));
                    Serial.print("THREAD: nb de mecas: ");
                    Serial.println(len_next_mecanism);
                    for (int e=0; e<len_next_mecanism; e++){
                        Serial.print("THREAD: lancement nouveau mécanisme, tab: ");
                        Serial.print(next_mecs==nullptr);
                        Serial.print(" meca: ");
                        Serial.println(next_mecs[e]==nullptr);
                        LaunchMecanismInThread(next_mecs[e]);
                    }
                }else{
                    Serial.println("THREAD: Fini");
                }
            }else{
                Serial.println("Error");
            }
        }

};

#endif