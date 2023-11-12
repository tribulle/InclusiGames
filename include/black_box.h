#include <iostream>
#include "context.h"

using namespace std;

class Black_box : public Context {
public:
    // This is how clients can access the single instance
    static Black_box* getInstance();

protected:

private:
    static Black_box* inst_;   // The one, single instance
    Black_box() {} // private constructor
    Black_box(const Black_box&); // private to avoid an involuntary copy
    Black_box& operator=(const Black_box&); // same with involuntary assignment
};

// Define the static Singleton pointer
Black_box* Black_box::inst_ = NULL;

Black_box* Black_box::getInstance() {
    if (inst_ == NULL) {
        inst_ = new Black_box();
    }
    return(inst_);
}