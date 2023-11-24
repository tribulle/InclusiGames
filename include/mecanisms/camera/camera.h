#include <iostream>
#include "../../base_class/mecanism.h"

using namespace std;

class Camera : public Mecanism {
    public:
        void Setup() override;
};