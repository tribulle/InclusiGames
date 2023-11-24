#pragma once

#include "camera.h"
#include "OV7670.h"

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library

#include <WiFi.h>
#include <WiFiMulti.h>
#include <WiFiClient.h>
#include "BMP.h"

const int SIOD = 23; //SDA
const int SIOC = 22; //SCL

const int VSYNC = 25;
const int HREF = 26;

const int XCLK = 32;
const int PCLK = 33;
const char* ssid     = "Esp_32_Test";
const char* password = "12345678910";
const int D0 = 27;
const int D1 = 17;
const int D2 = 16;
const int D3 = 15;
const int D4 = 14;
const int D5 = 13;
const int D6 = 12;
const int D7 = 4;
const int D8 = 0;


OV7670 *camera;

WiFiMulti wifiMulti;
WiFiServer server(80);

unsigned char bmpHeader[BMP::headerSize];

void serve();