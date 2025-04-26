
#include <Servo.h>
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

// Function prototypes from gemini.ino
void connectWiFi();
String callGeminiAPI(String prompt);

Servo myServo;  // Create servo object
bool fanActive = false;
unsigned long previousMillis = 0;
const long interval = 60; // Time between servo movements (ms)
int servoPos = 0;
int servoDirection = 1; // 1 for increasing, -1 for decreasing

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;  // Wait for serial port

  myServo.attach(9);  // Attach servo to pin 9
  myServo.write(0);   // Start at 0 degrees

  Serial.println("Gemini API + Servo Example");
  connectWiFi();  // Connect to WiFi

  // Call Gemini API
  Serial.println("\n--- Calling Gemini API ---");
  int humidity = 60; // Sensor 'data'
  int temperature = 15;
  String sHumidity = String(humidity);
  String sTemperature = String(temperature);
  String prompt = "Is "+sHumidity+"% humidity and " +sTemperature + " degree  unusual for sheffield in this time of day? say 'it is,yes' if so";
  Serial.print("Prompt: ");
  Serial.println(prompt);

  String result = callGeminiAPI(prompt);
  Serial.println("\n--- Gemini Response ---");
  Serial.println(result);

  // Set fan state based on response
  if (result.indexOf("yes") >= 0 ) {
    fanActive = true;
    Serial.println("Fan activated!");
  } else {
    fanActive = false;
    myServo.write(0);
    Serial.println("Fan remains off.");
  }

  // LED Matrix setup
  matrix.begin();
  updateDisplay(humidity,temperature);
  delay(2000);
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Continuous fan movement if active
  if (fanActive && (currentMillis - previousMillis >= interval)) {
    previousMillis = currentMillis;
    
    servoPos += servoDirection * 1000; // Adjust speed by changing this value
    
    // Reverse direction at limits
    if (servoPos >= 180) {
      servoPos = 180;
      servoDirection = -1;
    } else if (servoPos <= 0) {
      servoPos = 0;
      servoDirection = 1;
    }
    
    myServo.write(servoPos);
  }

  // Update display periodically
  static unsigned long lastDisplayUpdate = 0;
  if (currentMillis - lastDisplayUpdate >= 1000) {
    lastDisplayUpdate = currentMillis;
    int humidity = 60; // Replace with actual sensor reading
    int temperature = 15;
    updateDisplay(humidity, temperature);
  }
}

void updateDisplay(int humidity, int temperature) {
  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(50);
  
  // Show fan status
  const char* statusText = fanActive ? "FAN ON " : "FAN OFF";
  matrix.textFont(Font_4x6);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(statusText);
  matrix.endText();

  // Show humidity value scrolling
  String humidityText = "    H:" + String(humidity) + "% " + " T: " + String(temperature) +"C   ";
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(humidityText.c_str());
  matrix.endText(SCROLL_LEFT);

  matrix.endDraw();
}
