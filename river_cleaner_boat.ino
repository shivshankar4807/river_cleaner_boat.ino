#define BLYNK_TEMPLATE_ID "TMPL3w-89v6Uj"
#define BLYNK_TEMPLATE_NAME "boat"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN" // Replace with your actual Blynk Auth Token

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// =================================================
// Wi-Fi Credentials
// =================================================
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YOUR_WIFI_SSID";     // Replace with your Wi-Fi Network Name
char pass[] = "YOUR_WIFI_PASSWORD"; // Replace with your Wi-Fi Password

// =================================================
// L298N #1: BOAT MOVEMENT
// =================================================
// Left Motor
#define ENA D0
#define IN1 D1
#define IN2 D2

// Right Motor
#define ENB D5
#define IN3 D3
#define IN4 D4

// =================================================
// L298N #2: CONVEYOR BELT (WASTE COLLECTION)
// =================================================
#define C_ENA D6
#define C_IN1 D7
#define C_IN2 D8

// =================================================
// CONTROL VARIABLES
// =================================================
bool forward = false;
bool backward = false;
bool left = false;
bool right = false;
bool conveyor = false;

// Function Declarations
void Forward();
void Backward();
void Left();
void Right();
void StopBoat();
void ConveyorON();
void ConveyorOFF();

void setup()
{
  Serial.begin(9600);

  // L298N #1 - Boat Movement Setup
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // L298N #2 - Conveyor Setup
  pinMode(C_ENA, OUTPUT);
  pinMode(C_IN1, OUTPUT);
  pinMode(C_IN2, OUTPUT);

  // Stop all motors initially
  StopBoat();
  ConveyorOFF();

  Serial.println();
  Serial.println("=================================");
  Serial.println("  RIVER CLEANER BOAT INITIALIZED ");
  Serial.println("=================================");
  Serial.println("Connecting to Wi-Fi...");

  Blynk.begin(auth, ssid, pass);

  Serial.println("Blynk Connected Successfully!");
}

// =================================================
// BLYNK VIRTUAL PIN HANDLERS
// =================================================

// V0 - FORWARD
BLYNK_WRITE(V0)
{
  forward = param.asInt();
  if (forward == 1) {
    Forward();
  } else {
    StopBoat();
  }
}

// V1 - BACKWARD
BLYNK_WRITE(V1)
{
  backward = param.asInt();
  if (backward == 1) {
    Backward();
  } else {
    StopBoat();
  }
}

// V2 - LEFT
BLYNK_WRITE(V2)
{
  left = param.asInt();
  if (left == 1) {
    Left();
  } else {
    StopBoat();
  }
}

// V3 - RIGHT
BLYNK_WRITE(V3)
{
  right = param.asInt();
  if (right == 1) {
    Right();
  } else {
    StopBoat();
  }
}

// V4 - CONVEYOR BELT TOGGLE
BLYNK_WRITE(V4)
{
  conveyor = param.asInt();
  if (conveyor == 1) {
    ConveyorON();
  } else {
    ConveyorOFF();
  }
}

// =================================================
// MOTOR CONTROL FUNCTIONS
// =================================================

void Forward()
{
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  // Left Motor Forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Right Motor Forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.println("State: FORWARD");
}

void Backward()
{
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  // Left Motor Backward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right Motor Backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.println("State: BACKWARD");
}

void Left()
{
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  // Differential Drive Turn
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.println("State: LEFT");
}

void Right()
{
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  // Differential Drive Turn
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.println("State: RIGHT");
}

void StopBoat()
{
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  Serial.println("State: STOP");
}

void ConveyorON()
{
  digitalWrite(C_ENA, HIGH);
  digitalWrite(C_IN1, HIGH);
  digitalWrite(C_IN2, LOW);

  Serial.println("State: CONVEYOR ON");
}

void ConveyorOFF()
{
  digitalWrite(C_ENA, LOW);
  digitalWrite(C_IN1, LOW);
  digitalWrite(C_IN2, LOW);

  Serial.println("State: CONVEYOR OFF");
}

void loop()
{
  Blynk.run();
}
