const int sensorPin = A0;
const float baseTemp  = 22.78; // Room temp from my thermostat, probably inaccurate but f**k it we ball! 

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
  // NOTE: Max voltage is 5; you can get the rest of the math from this!
  float voltage = (sensorVal / 1024.0) * 5.0;

  // Calculate temp in celsius; see datasheets for math (arduino.cc/datasheets)
  float temp = (voltage - 0.5) * 100;

  // Display info!
  Serial.print("SENSOR ");
  Serial.print(sensorVal);
  Serial.print(" | ");
  Serial.print("VOLTAGE ");
  Serial.print(voltage);
  Serial.print(" | ");
  Serial.print("TEMP ");
  Serial.print(temp);
  Serial.print("\n");

  delay(1000); // 1-second delay for readability
}
