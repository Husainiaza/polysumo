#include "BluetoothSerial.h"

const int motorkiriA1 = 17 ; 
const int motorkiriA2 = 12 ; 
const int motorkananB1 = 18 ; 
const int motorkananB2 = 19 ; 
const int buzzer = 25 ;  
const int lights = 15 ;  

//Useful Variables
  int i=0;
  int j=0;
  int dat;
  int vSpeed=200;

BluetoothSerial my_bluetooth;
const char* nama_bluetooth = "aza";

void setup() {

//-- Motor KIRI
  pinMode(motorkiriA1, OUTPUT);
  pinMode(motorkiriA2, OUTPUT);
//-- Motor Kanan  F
  pinMode(motorkananB1, OUTPUT);
  pinMode(motorkananB2, OUTPUT);
//--  buzzer
  pinMode(buzzer, OUTPUT);
  pinMode(lights, OUTPUT); 

//-- istihar fungsi komunikasi Serial.
  Serial.begin(115200);
  delay(100);
  Serial.println(" Sistem Robot Mula");
  my_bluetooth.begin(nama_bluetooth);
}

void loop() {

 /*if(Serial.available()> 0){
    dat = Serial.read();
    Serial.println(dat);} */

  if(my_bluetooth.available() > 0){
    dat = my_bluetooth.read();
    Serial.println(dat);
  }
//----------speed-------------------
    if (dat == '0'){
      vSpeed=0;
      Serial.println(dat);}
    else if (dat == '1'){
      vSpeed=100;
      Serial.println(dat);}
    else if (dat == '2'){
      vSpeed=180;
      Serial.println(dat);}
    else if (dat == '3'){
      vSpeed=200;
      Serial.println(dat);}
    else if (dat == '4'){
      vSpeed=255;
      Serial.println(dat);}
 	  
    
    if (dat=='B'){
      movBWD();    
    }
    
    else if (dat=='F'){
      movFWD();
    }
    
    else if (dat=='S'){
     moveSTOP();
    }

    else if (dat=='L'){
      moveLEFT();
    }

    else if (dat=='R'){
     moveRIGHT();
    }
  
}