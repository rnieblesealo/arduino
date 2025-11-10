int switchState = 0;

void setup() {
  pinMode(2, INPUT); // Check voltage on pin, will be voltage if switch works

  // These are output pins
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  switchState = digitalRead(2);

  // Keep first LED on
  // When button pressed, flash the other 2 LEDS before turning the first one back on again
  // Pretty easy!
  
  if (switchState == LOW) {
    digitalWrite(3, HIGH); 
    digitalWrite(4, LOW);  
    digitalWrite(5, LOW);  
  }

  else {
    digitalWrite(3, LOW);  
    digitalWrite(4, LOW);  
    digitalWrite(5, HIGH); 

    delay(250);

    digitalWrite(4, HIGH); 
    digitalWrite(5, LOW);  

    delay(250);
  }
}
