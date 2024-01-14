#ifndef CAMERASETUP_H
#define CAMERASETUP_H
//////////////////////////////
// Déclarations des variables nécessaires au Setup de la caméra
// Tu peux rajouter des variables (leurs déclarations uniquement) [sauf pour les types de bases] Ne pas supprimer les autre variables
//////////////////////////////

#include "camera.h"
#include "OV7670.h"

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library

#include <WiFi.h>
#include <WiFiMulti.h>
#include <WiFiClient.h>
#include "BMP.h"

#include <BluetoothSerial.h>

extern BluetoothSerial SerialBT;

const int SIOD = 23; //SDA
const int SIOC = 22; //SCL

const int VSYNC = 25;
const int HREF = 26;

const int XCLK = 32;
const int PCLK = 33;
const int D0 = 27;
const int D1 = 17;
const int D2 = 16;
const int D3 = 15;
const int D4 = 14;
const int D5 = 13;
const int D6 = 12;
const int D7 = 4;

char* const ssid     = "Esp_32_Test";
char* const password = "12345678";

extern OV7670* camera; //global variable
extern char bmpHeader[BMP::headerSize];


#endif