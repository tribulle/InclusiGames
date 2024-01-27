#include "mecanisms/camera/state_camera.h"
#include "mecanisms/camera/camera_setup.h"
#include "synch_lib/bluetooth.h"
//////////////////////////////
// Basic_state::MecanismF() peut être modifié à guise (pour correspondre à la partie vois loop() habituelle du main.cpp)
//////////////////////////////
// Variations State_chariot: All the possible state for the Chariot

int i=0;
int i1=0;
unsigned char cl;
unsigned char cm;
unsigned char rgb[3];
unsigned char arrcolor[3][80][60];
unsigned int timecnt;

void Basic_state_camera::MecanismF(){
      Serial.println("CAMERA: _start");
      String sendData = "";
      delay(10);
      timecnt = micros();

      camera->oneFrame();  
      for(int x = 0; x < camera->xres; x++){
        for(int y = 0; y < camera->yres; y++)
        {
          i = (y *camera->xres + x) << 1;
          cm=camera->frame[i];
          cl=camera->frame[i+1];
          rgb[0] = cl>>3;
          rgb[1]=((cl-((cl>>3)<<3)<<3)|cm>>5);
          rgb[2]=cm-((cm>>5)<<5);
          for(i1=0;i1<3;i1++){
            arrcolor[i1][x][y]=rgb[i1];
            //Serial.print(rgb[i1]);
            sendData += rgb[i1];
            if(i1<2){
            sendData += ",";// pour differencier different couleur
            //Serial.println(rgb[i1]);
          }
          }
          //Serial.print(";");
          sendData += ";";// pour differencier different pixel
        }
        //Serial.println("");
        sendData += "";
      }
      sendData += "_end";
      Serial.println(sendData);
      //timecnt = micros()-timecnt;  c'est pour voir le temps de transmission
      //Serial.printf("timecnt=%d\n",timecnt);
      delay(60);
      //serve();
      delay(10);
}
