#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

#include <DabbleESP32.h>

// =====================================================
// PIN MOTOR & BUZZER
// =====================================================
const int motorkiriA1  = 17;
const int motorkiriA2  = 12;
const int motorkananB1 = 18;
const int motorkananB2 = 19;
const int buzzer        = 33;

// Nama Bluetooth
const char* nama_bluetooth = "PBS_sumo";


// =====================================================
// SETUP
// =====================================================
void setup()
{
  // Motor KIRI
  pinMode(motorkiriA1, OUTPUT);
  pinMode(motorkiriA2, OUTPUT);

  // Motor KANAN
  pinMode(motorkananB1, OUTPUT);
  pinMode(motorkananB2, OUTPUT);

  // Buzzer
  pinMode(buzzer, OUTPUT);

  // Pastikan semua OFF masa mula
  berhenti();
  digitalWrite(buzzer, LOW);

  // Serial Monitor
  Serial.begin(115200);
  delay(100);

  Serial.println("=================================");
  Serial.println(" Sistem Robot Mula");
  Serial.println(" Kawalan Menggunakan Dabble App");
  Serial.println("=================================");

  // Bluetooth Dabble
  Dabble.begin(nama_bluetooth);

  Serial.print("Bluetooth Name: ");
  Serial.println(nama_bluetooth);
}


// =====================================================
// LOOP
// =====================================================
void loop()
{
  // WAJIB untuk terima data daripada Dabble App
  Dabble.processInput();


  // ===================================================
  // FORWARD
  // ===================================================
  if (GamePad.isUpPressed())
  {
    depan();
    Serial.println("Motor Gerak ke DEPAN");
  }


  // ===================================================
  // BACKWARD
  // ===================================================
  else if (GamePad.isDownPressed())
  {
    undur();
    Serial.println("Motor Gerak ke UNDUR");
  }


  // ===================================================
  // LEFT
  // ===================================================
  else if (GamePad.isLeftPressed())
  {
    kiri();
    Serial.println("Motor Gerak ke KIRI");
  }


  // ===================================================
  // RIGHT
  // ===================================================
  else if (GamePad.isRightPressed())
  {
    kanan();
    Serial.println("Motor Gerak ke KANAN");
  }


  // ===================================================
  // STOP
  // ===================================================
  else
  {
    berhenti();
  }


  // ===================================================
  // BUZZER
  // Triangle button = buzzer ON
  // Lepas button = buzzer OFF
  // ===================================================
  if (GamePad.isTrianglePressed())
  {
    digitalWrite(buzzer, HIGH);
    Serial.println("Buzzer BUNYI");
  }
  else
  {
    digitalWrite(buzzer, LOW);
  }

  delay(20);
}


// =====================================================
// FUNCTION MOTOR DEPAN
// =====================================================
void depan()
{
  // Motor kiri
  digitalWrite(motorkiriA1, LOW);
  digitalWrite(motorkiriA2, HIGH);

  // Motor kanan
  digitalWrite(motorkananB1, HIGH);
  digitalWrite(motorkananB2, LOW);
}


// =====================================================
// FUNCTION MOTOR UNDUR
// =====================================================
void undur()
{
  // Motor kiri
  digitalWrite(motorkiriA1, HIGH);
  digitalWrite(motorkiriA2, LOW);

  // Motor kanan
  digitalWrite(motorkananB1, LOW);
  digitalWrite(motorkananB2, HIGH);
}


// =====================================================
// FUNCTION MOTOR KIRI
// =====================================================
void kiri()
{
  // Motor kiri undur
  digitalWrite(motorkiriA1, LOW);
  digitalWrite(motorkiriA2, HIGH);

  // Motor kanan undur / opposite direction
  digitalWrite(motorkananB1, LOW);
  digitalWrite(motorkananB2, HIGH);
}


// =====================================================
// FUNCTION MOTOR KANAN
// =====================================================
void kanan()
{
  // Motor kiri
  digitalWrite(motorkiriA1, HIGH);
  digitalWrite(motorkiriA2, LOW);

  // Motor kanan
  digitalWrite(motorkananB1, HIGH);
  digitalWrite(motorkananB2, LOW);
}


// =====================================================
// FUNCTION STOP
// =====================================================
void berhenti()
{
  digitalWrite(motorkiriA1, LOW);
  digitalWrite(motorkiriA2, LOW);

  digitalWrite(motorkananB1, LOW);
  digitalWrite(motorkananB2, LOW);
}