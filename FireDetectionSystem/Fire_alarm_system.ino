
const int buzzerPin = 3; 
const int fireSensorPin = 4;
const int greenLED = 5; 
const int redLED = 2;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(fireSensorPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  
  int fireValue = digitalRead(fireSensorPin);
  Serial.println(fireValue);

  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);

  if (fireValue == 0 || sensorValue > 500) {
    
    analogWrite(buzzerPin, 500); 
    digitalWrite(redLED, HIGH);    
    digitalWrite(greenLED, LOW); 
    delay(1000);                 
  } else {
    analogWrite(buzzerPin, 0);   
    digitalWrite(redLED, LOW);  
    digitalWrite(greenLED, HIGH); 
  }
  delay(1000);
}