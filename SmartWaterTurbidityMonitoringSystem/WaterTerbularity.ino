#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 16);

int sensorPin = A0; 

void setup() { 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 
  Serial.begin(9600);
  lcd.init();                     
  lcd.backlight();
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  int turbidity = map(sensorValue, 0, 750, 100, 0);
  delay(100);
  lcd.setCursor(0, 0);
  lcd.print("Turbidity:");
  lcd.print("   ");
  lcd.setCursor(10, 0);
  lcd.print(turbidity);
  
  delay(100);
  if (turbidity < 20) {
    lcd.setCursor(0, 1);
    digitalWrite(7, HIGH); 
    digitalWrite(8, LOW); 
    digitalWrite(9, HIGH); 
    lcd.print(" its CLEAR ");
    Serial.print(" its CLEAR ");
  } else if (turbidity >= 20 && turbidity < 50) {
    lcd.setCursor(0, 1);
    digitalWrite(7, HIGH); 
    digitalWrite(8, HIGH); 
    digitalWrite(9, LOW); 
    lcd.print(" its CLOUDY ");
    Serial.print(" its CLOUDY ");
  } else if (turbidity >= 50) {
    lcd.setCursor(0, 1);
    digitalWrite(7, LOW); 
    digitalWrite(8, HIGH); 
    digitalWrite(9, HIGH);  
    lcd.print(" its DIRTY ");
    Serial.print(" its DIRTY ");
  }
}
