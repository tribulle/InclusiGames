#include <iostream>

using namespace std;

// This is a singleton (So you can't instantiate 2 Chariots. It's to prevent error)
// We access to the chariot with:    Chariot* chariot = Chariot::getInstance();

class Singleton{
public:
    // This is how you can access the single instance
    static Singleton* getInstance();

private:
    static Singleton* inst_;   // The one, single instance
    Singleton() {} // private constructor
    Singleton(const Singleton&); // private to avoid an involuntary copy
    Singleton& operator=(const Singleton&); // same with involuntary assignment
};

// Define the static Singleton pointer
Singleton* Singleton::inst_ = nullptr;

Singleton* Singleton::getInstance() {
    if (inst_ == nullptr) {
        inst_ = new Singleton();
    }
    return(inst_);
}