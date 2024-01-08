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
        Mecanism* first_mecanism_;
        Mecanism* current_mecanism_;

        void LaunchThread(){
            LaunchMecanismInThread(first_mecanism_);
        }

        void LaunchMecanismInThread(Mecanism* mecanism_pointer){
            Serial.println("THREAD: start");
            Serial.print("THREAD: And the tableau: ");
            Serial.print(mecanism_pointer->next_mecanism_==nullptr);
            Serial.print(mecanism_pointer->next_mecanism_[0]==nullptr);
            Serial.println(mecanism_pointer->next_mecanism_[1]==nullptr);
            if (mecanism_pointer != nullptr){
                current_mecanism_ = mecanism_pointer;
                Mecanism** next_mecs= mecanism_pointer->next_mecanism_;
                Serial.print("DEBUG next mecs null:");
                Serial.println(next_mecs==nullptr);

                Serial.println("THREAD: Lancement du mécanisme");
                thread t1(&Mecanism::LaunchMecanism, mecanism_pointer);

                t1.join();
                Serial.print("DEBUG post next mecs null:");
                Serial.println(next_mecs==nullptr);
                if(next_mecs != nullptr){
                    int len_next_mecanism = sizeof(next_mecs)/sizeof(next_mecs[0]); //length calculation
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

        ThreadList(Mecanism* first_mecanism){
            this->first_mecanism_ = first_mecanism;
        }

};

#endif