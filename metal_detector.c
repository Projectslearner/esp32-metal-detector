/*
    Project name: ESP32 Metal Detector
    Modified Date: 24-06-2024
    Code by: Projectslearner
    Website: https://projectslearner.com/learn/esp32-metal-detector
*/

const int metalDetectorPin = 34; // GPIO pin connected to the metal detector coil
const int thresholdValue = 500; // Adjust this threshold based on sensor calibration
bool isMetalDetected = false; // Variable to store metal detection status

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(metalDetectorPin, INPUT); // Set metal detector pin as input
}

void loop() {
  // Read analog value from metal detector coil
  int metalValue = analogRead(metalDetectorPin);

  // Print raw value to Serial Monitor
  Serial.print("Metal Value: ");
  Serial.println(metalValue);

  // Check if metal is detected based on threshold
  if (metalValue > thresholdValue) {
    if (!isMetalDetected) {
      Serial.println("Metal detected!");
      isMetalDetected = true;
    }
  } else {
    if (isMetalDetected) {
      Serial.println("No metal detected.");
      isMetalDetected = false;
    }
  }

  delay(500); // Add a small delay before the next reading
}
