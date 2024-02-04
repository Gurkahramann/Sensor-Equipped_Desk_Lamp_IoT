#define BLYNK_TEMPLATE_ID "TMPL6MMChzWct" 
#define BLYNK_TEMPLATE_NAME "IoT" 
#define BLYNK_AUTH_TOKEN "Ty8M1xf5YoBG5gcXohAP85fc5so1LIvM" 
#include <cvzone.h> 
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h> 
SerialData serialData(1, 1);  
int valsRec[1];  
char auth[] = "Ty8M1xf5YoBG5gcXohAP85fc5so1LIvM"; 
char ssid[] = "E10 2.4GHz"; 
char pass[] = "TMtKgrEvcU3X"; 
void setup() { 
pinMode(D1, OUTPUT); 
serialData.begin(); 
Serial.begin(9600);  
pinMode(D0, OUTPUT); 
Blynk.begin(auth, ssid, pass, "blynk.cloud", 80); 
} 
void loop() { 
serialData.Get(valsRec); 
int d1State = valsRec[0]; 
digitalWrite(D1, d1State); 
Blynk.virtualWrite(V0, d1State); 
delay(10); 

Blynk.run(); 
} 
BLYNK_WRITE(V0) {  
int pinValue = param.asInt(); 
digitalWrite(D0, pinValue); 
}