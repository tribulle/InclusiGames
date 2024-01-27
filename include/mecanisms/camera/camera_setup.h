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

//#include <BluetoothSerial.h>

//extern BluetoothSerial SerialBT;

const int SIOD = 21; //SDA
const int SIOC = 22; //SCL

const int VSYNC = 11;
const int HREF = 10;

const int XCLK = 15;
const int PCLK = 25;
const int D0 = 26;
const int D1 = 12;
const int D2 = 13;
const int D3 = 33;
const int D4 = 32;
const int D5 = 14;
const int D6 = 27;
const int D7 = 2;

//char* const ssid     = "Esp_32_Test";
//char* const password = "12345678";

extern OV7670* camera; //global variable
extern char bmpHeader[BMP::headerSize];


#endif