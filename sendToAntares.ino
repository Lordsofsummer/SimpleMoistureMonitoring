#include <AntaresESP32HTTP.h>
#include "DHTesp.h"

#define ACCESSKEY "<access id for antares>"       
#define WIFISSID "<WIFISSID>"         
#define PASSWORD "<YOURWIFIPASSWORD>"     

#define applicationName "testsmartdevice"   // Ganti dengan application name Antares yang telah dibuat
#define deviceName "temperaturesensor"     // Ganti dengan device Antares yang telah dibuat

// Sensor pin declaration
#define PIN_DHT 14
#define PIN_LDR A0
#define PIN_MOISTURE A3

// object library initialization
DHTesp dht;
AntaresESP32HTTP antares(ACCESSKEY);

int moisture = 0;
int ldr = 0;
int temp =0;
int hum = 0;

void setup()
{

  Serial.begin(9600);

  pinMode(PIN_LDR, INPUT);
  
  pinMode(PIN_MOISTURE, INPUT);
  
  dht.setup(PIN_DHT, DHTesp::DHT11);

  // for debugging in Antares Platform
  antares.setDebug(true);
  // for connecting to Antares Platform via wifi
  antares.wifiConnection(WIFISSID,PASSWORD);
}
 
void loop() {
  // LDR
  ldr = analogRead(PIN_LDR);
  // moisture
  moisture = analogRead(PIN_MOISTURE);
  // DHT
  TempAndHumidity data = dht.getTempAndHumidity();
  // extract temperature data
  temp = data.temperature;
  // extract humidity data
  hum = data.humidity;

  // display data ke serial monitor
  Serial.println("===================");
  Serial.print("LDR: ");
  Serial.println(ldr);
  Serial.print("Temperature: ");
  Serial.println(temp);
  Serial.print("Humidity: ");
  Serial.println(hum);
  Serial.print("Moisture: ");
  Serial.println(moisture);
  Serial.println("===================");
  
  // include data ke json
  antares.add("LDR", ldr);
  antares.add("Temperature", temp);
  antares.add("Humidity", hum);
  antares.add("Moisture", moisture);

  //Send data to Antares
  antares.send(applicationName, deviceName);
  delay(20000);
}
