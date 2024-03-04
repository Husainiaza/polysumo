void movBWD(){
  analogWrite(motorkiriA1,vSpeed);
  analogWrite(motorkiriA2,LOW);
  analogWrite(motorkananB1,LOW);
  analogWrite(motorkananB2,vSpeed);
  Serial.println(" Motor UNDUR");
}
    
void movFWD(){
  analogWrite(motorkiriA1,LOW);
  analogWrite(motorkiriA2,vSpeed);
  analogWrite(motorkananB1,vSpeed);
  analogWrite(motorkananB2,LOW);
  Serial.println(" Motor DEPAN ");
}
    
void moveSTOP(){
  analogWrite(motorkiriA1,LOW);
  analogWrite(motorkiriA2,LOW);
  analogWrite(motorkananB1,LOW);
  analogWrite(motorkananB2,LOW);
  Serial.println(" Motor HENTI");
}

void moveLEFT(){
  analogWrite(motorkiriA1,LOW);
  analogWrite(motorkiriA2,vSpeed);
  analogWrite(motorkananB1,LOW);
  analogWrite(motorkananB2,vSpeed);
  Serial.println(" Motor ke KIRI");
}

void moveRIGHT(){
  analogWrite(motorkiriA1,vSpeed);
  analogWrite(motorkiriA2,LOW);
  analogWrite(motorkananB1,vSpeed);
  analogWrite(motorkananB2,LOW);
  Serial.println(" Motor ke KANAN");
}