#include <ESP8266WiFi.h>
#include <espnow.h>

// Define strip name and LED pin for Green Light
const char* STRIP_NAME = "Strip 3";  // Name to match incoming message
#define RELAY_GREEN_PIN 14           // D5
#define RELAY_RED_PIN 5              // D1
#define RELAY_WHITE_GREEN_PIN 12     // D6
#define RELAY_WHITE_RED_PIN 4        // D2

// Enable or disable verbose output
bool verbose = false;

// Structure to hold the incoming message
struct struct_message {
  uint8_t msgType;
  uint8_t macAddr[6];
  unsigned int Right_Score;
  unsigned int Left_Score;
  unsigned int Seconds_Remaining;
  unsigned int Minutes_Remaining;
  bool Green_Light;
  bool Red_Light;
  bool White_Green_Light;
  bool White_Red_Light;
  bool Yellow_Green_Light;
  bool Yellow_Red_Light;
  bool Yellow_Card_Green;
  bool Yellow_Card_Red;
  bool Red_Card_Green;
  bool Red_Card_Red;
  bool Priority_Left;
  bool Priority_Right;
  char customMessage[32];
};

struct_message incomingMessage;

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_GREEN_PIN, OUTPUT);
  pinMode(RELAY_RED_PIN, OUTPUT);
  pinMode(RELAY_WHITE_GREEN_PIN, OUTPUT);
  pinMode(RELAY_WHITE_RED_PIN, OUTPUT);

  // Start all relays off (HIGH for active-low)
  digitalWrite(RELAY_GREEN_PIN, HIGH);
  digitalWrite(RELAY_RED_PIN, HIGH);
  digitalWrite(RELAY_WHITE_GREEN_PIN, HIGH);
  digitalWrite(RELAY_WHITE_RED_PIN, HIGH);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if (esp_now_init() != 0) {
    if (verbose) Serial.println("ESP-NOW initialization failed");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);

  if (verbose) Serial.println("ESP-NOW Initialized. Waiting for messages...");
}

void loop() {
  delay(1);  // Potentially allows for better prioritization of the wifi tasks
}

void OnDataRecv(uint8_t* mac, uint8_t* incomingData, uint8_t len) {
  memcpy(&incomingMessage, incomingData, sizeof(incomingMessage));

  if (String(incomingMessage.customMessage) == STRIP_NAME) {
    if (verbose) {
      Serial.print("Message from ");
      Serial.println(STRIP_NAME);
      Serial.print("Red: ");
      Serial.println(incomingMessage.Red_Light ? "ON" : "OFF");
      Serial.print("Green: ");
      Serial.println(incomingMessage.Green_Light ? "ON" : "OFF");
      Serial.print("White Red: ");
      Serial.println(incomingMessage.White_Red_Light ? "ON" : "OFF");
      Serial.print("White Green: ");
      Serial.println(incomingMessage.White_Green_Light ? "ON" : "OFF");
    }

    digitalWrite(RELAY_GREEN_PIN, incomingMessage.Green_Light ? LOW : HIGH);
    digitalWrite(RELAY_RED_PIN, incomingMessage.Red_Light ? LOW : HIGH);
    digitalWrite(RELAY_WHITE_GREEN_PIN, incomingMessage.White_Green_Light ? LOW : HIGH);
    digitalWrite(RELAY_WHITE_RED_PIN, incomingMessage.White_Red_Light ? LOW : HIGH);

    if (verbose) Serial.println();
  }
}
