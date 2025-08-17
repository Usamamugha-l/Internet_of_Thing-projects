#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_NAME "Smart plant watering system"
#define BLYNK_TEMPLATE_ID "TMPL6OuRLnvSW"

#include<WifiClient.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = "ltHc-hkkUpHWf-X-hr7-oKic3r6hmNaX";
char ssid[] = "apna lagwa lo";
char pass[] = "123456789";

#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define sensor A0        
#define waterPump D5     
#define lightPin D3      

BlynkTimer timer;
bool manualOverride = false; 


BLYNK_WRITE(V2) {
  int state = param.asInt();
  if (state == 1) {
    digitalWrite(lightPin, HIGH);  
  } else {
    digitalWrite(lightPin, LOW);   
  }
}

BLYNK_WRITE(V1) {
  int relayState = param.asInt();
  if (relayState == 1) {
    manualOverride = true;         
    digitalWrite(waterPump, LOW);  
  } else {
    manualOverride = false;        
    digitalWrite(waterPump, HIGH); 
  }
}


void soilMoistureSensor() {
  if (manualOverride) {
    return;
  }

  int value = analogRead(sensor);
  value = map(value, 0, 1024, 0, 100); 
  value = (100 - value);              

  Blynk.virtualWrite(V0, value);      
  
  if (value < 30) {
    digitalWrite(waterPump, LOW);     
  } else {
    digitalWrite(waterPump, HIGH);    
  }
}


void sendSensor() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!"); 
    return;
  }

  Serial.print("Temperature: ");
  Serial.println(temperature); 
  Serial.print("Humidity: ");
  Serial.println(humidity);    

  Blynk.virtualWrite(V3, humidity);        
  Blynk.virtualWrite(V4, temperature);     
}

void setup() {
  Serial.begin(9600);  

  pinMode(waterPump, OUTPUT);
  pinMode(lightPin, OUTPUT);
  digitalWrite(waterPump, HIGH);  
  digitalWrite(lightPin, LOW);    

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  dht.begin();

  timer.setInterval(1000L, soilMoistureSensor); 
  timer.setInterval(5000L, sendSensor);         
}

void loop() {
  Blynk.run();  
  timer.run();  
}
