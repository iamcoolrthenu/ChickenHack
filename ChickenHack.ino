#define motor 2
#define touch_sensor 3
bool motorState = false; // false means motor is off, true means motor is on
bool lastSensorState = LOW; // Track the last state of the sensor
//No functionality for the taser has been added to the code.
void setup() {
  pinMode(motor, OUTPUT);
  pinMode(touch_sensor, INPUT_PULLUP); // Assuming active-low sensor. Use INPUT if active-high.
  digitalWrite(motor, LOW); // Ensure the motor is off initially
  Serial.begin(9600);
}

void loop() {
  bool currentSensorState = digitalRead(touch_sensor);

  if (lastSensorState == HIGH && currentSensorState == LOW) {
    motorState = !motorState; // Toggle the state
    //digitalWrite(motor, motorState ? HIGH : LOW); // Apply the new state
    Serial.println(motor_status()); // Print the new state
  }

  lastSensorState = currentSensorState; // Update the last sensor state
  Serial.println(currentSensorState);
  delay(50); 
}

const char* motor_status() {
  return motorState ? "The motor is on." : "The motor is off.";
}


