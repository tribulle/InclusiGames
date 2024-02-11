#include "synch_lib/bluetooth.h"


BluetoothSerial SerialBT;

void BluetoothSetup(){

    SerialBT.begin("Inclusigame_bluetooth"); // le nom de bluetooth: "ESP32_bluetooth"
    Serial.printf("BT initial ok and ready to pair. \r\n");
}