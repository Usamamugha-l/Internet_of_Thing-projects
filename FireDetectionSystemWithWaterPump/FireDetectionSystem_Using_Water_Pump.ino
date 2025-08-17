const int buzzerPin = 3; 
const int fireSensorPin = 4;
const int greenLED = 5; 
const int redLED = 2;
#define waterPump 6 

void setup() {
  Serial.begin(9600);

  pinMode(buzzerPin, OUTPUT);
  pinMode(fireSensorPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(waterPump, OUTPUT); 

  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, HIGH);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(waterPump, LOW); 
}

void loop() {
  int fireValue = digitalRead(fireSensorPin);
  Serial.println(fireValue);

  if (fireValue == 0) { 
    analogWrite(buzzerPin, 500); 
    digitalWrite(redLED, LOW);  
    digitalWrite(greenLED, HIGH);
    digitalWrite(waterPump, LOW);
    delay(1000);                 
  } else { 
    analogWrite(buzzerPin, 0);
    digitalWrite(redLED, HIGH); 
    digitalWrite(greenLED, LOW); 
    digitalWrite(waterPump, HIGH); 
  }
  delay(1000);
}
