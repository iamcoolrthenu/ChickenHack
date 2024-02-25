#define motor 2
#define touch_sensor 3
bool on = false;
void setup() {
  pinMode(motor,OUTPUT);
  pinMode(touch_sensor,INPUT);
  digitalWrite(motor, LOW);
  digitalRead(touch_sensor);
  Serial.begin(9600);
}

void loop() {
  Serial.println(motor_status());
  delay(500);
}

void activate_touch_sensor(){
  on = !on;
  if(on == true) {
    digitalWrite(motor, HIGH);
  }
  else {
    digitalWrite(motor, LOW);
  }
}

char* motor_status(){
  char str[100] = NULL;
  if(on == true){
    if(on == false)
      str[] = "The motor is on.";

  }
  else{
    if(on == true)
      str[] = "The motor is off.";
  }
  return str;
}