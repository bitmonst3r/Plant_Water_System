const int moistureAO = 0;

int AO = 0; // Pin connected to A0 on the controller
int tmp = 0; // Value of the analog pin
int buzzPin = 11; // Pin connected to the piezo buzzer
int LED = 13; // Pin connected to the LED
int relayPin = 7; //pin connected to relay
void setup () {
  Serial.begin(9600); // Send Arduino reading to IDE
  Serial.println("Soil moisture sensor");
  pinMode(moistureAO, INPUT);
  pinMode(relayPin, OUTPUT);
  
}
void loop () {
  tmp = analogRead( moistureAO );
  if ( tmp != AO ) {
    AO = tmp;
    Serial.print("Resistance = "); // Show the resistance value of the sensor
    Serial.println(AO);
  }
  delay (1000);
  if (analogRead(A0) > 500){ // If the reading is higher than 900,
    digitalWrite(relayPin,HIGH); //rely will activate and pump will start working
    delay(1000); // Wait for 1 second
    digitalWrite(buzzPin, LOW);
    digitalWrite(LED, HIGH);
    digitalWrite(relayPin,HIGH);
    delay(1000);
  
  }
  else {
    digitalWrite(relayPin,LOW);
  }
}
