#include "BluetoothSerial.h"

const int motorkiriA1 = 17 ; 
const int motorkiriA2 = 12 ; 
const int motorkananB1 = 18 ; 
const int motorkananB2 = 19 ; 
const int buzzer = 33 ;  

const char* nama_bluetooth = "sumoKKSJ01";
BluetoothSerial my_bluetooth;

void setup() {

//-- Motor KIRI
  pinMode(motorkiriA1, OUTPUT);
  pinMode(motorkiriA2, OUTPUT);
//-- Motor Kanan  F
  pinMode(motorkananB1, OUTPUT);
  pinMode(motorkananB2, OUTPUT);
//--  buzzer
  pinMode(buzzer, OUTPUT);

//-- istihar fungsi komunikasi Serial.
  Serial.begin(115200);
  delay(100);
  Serial.println(" Sistem Robot Mula");

  //-- istihar fungsi komunikasi Bluetooth.
my_bluetooth.begin(nama_bluetooth);
}

void loop() {

 // if(Serial.available()> 0){
 //   char dat = Serial.read();
  //  Serial.println(dat);
  
  if(my_bluetooth.available()> 0){
    char dat = my_bluetooth.read();
   
    
    if (dat=='B'){
      digitalWrite(motorkiriA1,HIGH);
      digitalWrite(motorkiriA2,LOW);
      digitalWrite(motorkananB1,LOW);
      digitalWrite(motorkananB2,HIGH);
      Serial.println(" Motor Gerak ke UNDUR");
      
    }
    
    else if (dat=='F'){
      digitalWrite(motorkiriA1,LOW);
      digitalWrite(motorkiriA2,HIGH);
      digitalWrite(motorkananB1,HIGH);
      digitalWrite(motorkananB2,LOW);
      Serial.println(" Motor Gerak ke DEPAN ");
    }
    else if (dat=='S'){
      digitalWrite(motorkiriA1,LOW);
      digitalWrite(motorkiriA2,LOW);
      digitalWrite(motorkananB1,LOW);
      digitalWrite(motorkananB2,LOW);
      Serial.println(" Motor HENTI");
    }

    else if (dat=='L'){
      digitalWrite(motorkiriA1,LOW);
      digitalWrite(motorkiriA2,HIGH);
      digitalWrite(motorkananB1,LOW);
      digitalWrite(motorkananB2,HIGH);
      Serial.println(" Motor Gerak ke KIRI");
    }

    else if (dat=='R'){
      digitalWrite(motorkiriA1,HIGH);
      digitalWrite(motorkiriA2,LOW);
      digitalWrite(motorkananB1,HIGH);
      digitalWrite(motorkananB2,LOW);
      Serial.println(" Motor Gerak ke KANAN");
    }

    else if (dat=='H'){
      digitalWrite(buzzer,HIGH);
      Serial.println(" buzzer bunyi");
    }

     else if (dat=='h'){
      digitalWrite(buzzer,LOW);
      Serial.println(" buzzer senyap");
    }
  }
}