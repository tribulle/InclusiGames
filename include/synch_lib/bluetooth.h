#ifndef BLUE_H
#define BLUE_H

#include <BluetoothSerial.h>
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

extern BluetoothSerial SerialBT;

#define SERVICE_UUID "00001101-0000-1000-8000-00805F9B34FB"
const bool THREAD_BLUETOOTH_NEEDED = false;

void BluetoothSetup();

#endif