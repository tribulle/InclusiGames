#include <memory>
#include "mecanism.h"
#include <thread>

using namespace std;

class Thread{
    public:
        Mecanism* first_mecanism_ = nullptr;
        Mecanism* current_mecanism_ = nullptr;

        void LaunchThread(){
            LaunchMecanismInThread(first_mecanism_);
        }

        void LaunchMecanismInThread(Mecanism* mecanism_pointer){
            if (mecanism_pointer != nullptr){
                current_mecanism_ = mecanism_pointer;
                thread t1(&Mecanism::LaunchMecanism, mecanism_pointer);

                t1.join();
                LaunchMecanismInThread(mecanism_pointer->next_mecanism_);
            }
        }

};