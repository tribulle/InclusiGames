#include <memory>
#include "mecanism.h"
#include <thread>

using namespace std;

// ThreadList manage to synchronize dynamically a list of mecanisms.
// We don't have to provide the full list of mecanisms, because each state of each mecanism provide the next mecanism to launch.
// We just have to provide the first Mecanism to launch.
// Typically some mecanism don't have a next_mecanism_ (by default = nullptr) so the ThreadList will stop.
class ThreadList{
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