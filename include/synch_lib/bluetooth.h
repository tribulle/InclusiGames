#ifndef BLUE_H
#define BLUE_H

#include <BluetoothSerial.h>

extern BluetoothSerial SerialBT;
char* const ssid     = "Esp_32_Test";
char* const password = "12345678";

#define SERVICE_UUID "00001101-0000-1000-8000-00805F9B34FB"
const bool THREAD_BLUETOOTH_NEEDED = false;

void BluetoothSetup();

#endif