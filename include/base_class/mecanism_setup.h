struct MecanismPin{
    public:
        int pin_;
        int pin_mode_;

        MecanismPin(int pin, int pin_mode){
            this->pin_ = pin;
            this->pin_mode_ = pin_mode;
        }
};