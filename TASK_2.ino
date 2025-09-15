#define temp_sensor A0
#define fan_pin 13   

void setup() {
  pinMode(fan_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensor_value = analogRead(temp_sensor);
  int temp = map(sensor_value, 0, 1023, 0, 50);

  String fan_mode = "";

  if (temp < 25) {
    digitalWrite(fan_pin, LOW);   
    fan_mode = "FAN OFF";
  } 
  else if (temp < 30) {
    digitalWrite(fan_pin, HIGH);
    delay(100);                   // short ON
    digitalWrite(fan_pin, LOW);
    delay(100);                   // short OFF 
    fan_mode = "50% SPEED";
  } 
  else {
    digitalWrite(fan_pin, HIGH);  
    fan_mode = "100% SPEED";
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C | Fan: ");
  Serial.println(fan_mode);
  delay(500);
}
