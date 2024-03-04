void movBWD(){
  digitalWrite(motorkiriA1,HIGH);
  digitalWrite(motorkiriA2,LOW);
  digitalWrite(motorkananB1,LOW);
  digitalWrite(motorkananB2,HIGH);
  Serial.println(" Motor UNDUR");
}
    
void movFWD(){
  digitalWrite(motorkiriA1,LOW);
  digitalWrite(motorkiriA2,HIGH);
  digitalWrite(motorkananB1,HIGH);
  digitalWrite(motorkananB2,LOW);
  Serial.println(" Motor DEPAN ");
}
    
void moveSTOP(){
  digitalWrite(motorkiriA1,LOW);
  digitalWrite(motorkiriA2,LOW);
  digitalWrite(motorkananB1,LOW);
  digitalWrite(motorkananB2,LOW);
  Serial.println(" Motor HENTI");
}

void moveLEFT(){
  digitalWrite(motorkiriA1,LOW);
  digitalWrite(motorkiriA2,HIGH);
  digitalWrite(motorkananB1,LOW);
  digitalWrite(motorkananB2,HIGH);
  Serial.println(" Motor ke KIRI");
}

void moveRIGHT(){
  digitalWrite(motorkiriA1,HIGH);
  digitalWrite(motorkiriA2,LOW);
  digitalWrite(motorkananB1,HIGH);
  digitalWrite(motorkananB2,LOW);
  Serial.println(" Motor ke KANAN");
}