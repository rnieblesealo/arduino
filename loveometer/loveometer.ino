const int sensorPin = A0;
const float baseTemp  = 22.78; // Room temp from my thermostat, probably inaccurate but f**k it we ball! 

enum LED_INDICES {
  READ_LOW = 2,
  READ_MID = 3,
  READ_HI  = 4
};

void setup(){
  // Open up connection between board and computer with speed of 9600 bits per second
  Serial.begin(9600);
  
  // Set LED pins as outputs and set their voltage to low, clearing them
  int lowestPin = 2;
  int highestPin = 4;

  for (int i = lowestPin; i <= highestPin; ++i){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop(){
  // Get analog temp reading and print it; this is 0-1023 value that maps to a voltage
  int sensorVal = analogRead(sensorPin);

  // Calculate voltage
  // Max voltage is 5; you can get the rest of the math from this!
  float voltage = (sensorVal / 1024.0) * 5.0;

  // Calculate temp in celsius; 10mv = 1 degree celsius of temp. change
  float temp = (voltage - 0.5) * 100;

  // Update LEDs so that they reflect reading
  if (temp < baseTemp){
    digitalWrite(LED_INDICES::READ_LOW, LOW);
    digitalWrite(LED_INDICES::READ_MID, LOW);
    digitalWrite(LED_INDICES::READ_HI, LOW);
  } else if (temp >= baseTemp + 2 && temp < baseTemp + 4) {
    digitalWrite(LED_INDICES::READ_LOW, HIGH);
    digitalWrite(LED_INDICES::READ_MID, LOW);
    digitalWrite(LED_INDICES::READ_HI, LOW);
  } else if (temp >= baseTemp + 4 && temp < baseTemp + 6) {
    digitalWrite(LED_INDICES::READ_LOW, HIGH);
    digitalWrite(LED_INDICES::READ_MID, HIGH);
    digitalWrite(LED_INDICES::READ_HI, LOW);
  } else if (temp >= baseTemp + 6 && temp < baseTemp + 8) {
    digitalWrite(LED_INDICES::READ_LOW, HIGH);
    digitalWrite(LED_INDICES::READ_MID, HIGH);
    digitalWrite(LED_INDICES::READ_HI, HIGH);
  }

  // Display info to serial port
  Serial.print("SENSOR ");
  Serial.print(sensorVal);
  Serial.print(" | ");
  Serial.print("VOLTAGE ");
  Serial.print(voltage);
  Serial.print(" | ");
  Serial.print("TEMP ");
  Serial.print(temp);
  Serial.print("\n");

  delay(1000); // Update reading every second 
}
