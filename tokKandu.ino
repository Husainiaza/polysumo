#include "BluetoothSerial.h"

#define lampu       4

const char* nama_bluetooth = "Tok Kandu";

const int motorkiriA1 = 17 ; 
const int motorkiriA2 = 12 ; 
const int motorkananB1 = 18 ; 
const int motorkananB2 = 19 ; 
const int buzzer = 25 ;  

BluetoothSerial my_bluetooth;

// Variables
  int i=0;
  int j=0;
  int state;
  int vSpeed=200;

void setup() {

//-- Motor KIRI
  pinMode(motorkiriA1, OUTPUT);
  pinMode(motorkiriA2, OUTPUT);
//-- Motor Kanan  F
  pinMode(motorkananB1, OUTPUT);
  pinMode(motorkananB2, OUTPUT);
//--  buzzer
  pinMode(buzzer, OUTPUT);

//-- istihar fungsi komunikasi Bluetooth.
my_bluetooth.begin(nama_bluetooth);

//-- istihar fungsi komunikasi Serial.
  Serial.begin(115200);
  delay(100);
  Serial.println(" Sistem Robot Mula");
}

void loop() {

  if(my_bluetooth.available()> 0){
    char dat = my_bluetooth.read();
    Serial.println(dat);
    
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

    else if (dat=='R'){
      digitalWrite(motorkiriA1,LOW);
      digitalWrite(motorkiriA2,HIGH);
      digitalWrite(motorkananB1,LOW);
      digitalWrite(motorkananB2,HIGH);
      Serial.println(" Motor Gerak ke KIRI");
    }

    else if (dat=='L'){
      digitalWrite(motorkiriA1,HIGH);
      digitalWrite(motorkiriA2,LOW);
      digitalWrite(motorkananB1,HIGH);
      digitalWrite(motorkananB2,LOW);
      Serial.println(" Motor Gerak ke KANAN");
    }
  

  else if (dat == 'W') {
      if (i==0){  
         digitalWrite(lampu, HIGH); 
         i=1;
      }
      else if (i==1){
         digitalWrite(lampu, LOW); 
         i=0;
      }
      state='n';
    }

    //If state is equal with letter 'V', play (or stop) horn sound
     else if (dat == 'V'){
      Serial.println(j);
      if (j==0){  
         digitalWrite(buzzer, HIGH);//Speaker on 
          Serial.println(" HON BERBUNYI");
         j=1;
      }
      else if (j==1){
         digitalWrite(buzzer, LOW);
         Serial.println(" HON STOP");
         j=0;
      }
      dat='n';  
    }
  }
}
