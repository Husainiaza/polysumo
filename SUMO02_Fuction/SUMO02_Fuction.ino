const int motorkiriA1 = 17 ; 
const int motorkiriA2 = 12 ; 
const int motorkananB1 = 18 ; 
const int motorkananB2 = 19 ; 
const int buzzer = 25 ;  

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
}

void loop() {

  if(Serial.available()> 0){
    char dat = Serial.read();
    Serial.println(dat);
    
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
}