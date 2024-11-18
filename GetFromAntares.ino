#include <AntaresESP32HTTP.h>

#define ACCESSKEY "<antares access key>"
#define WIFISSID "<your wifi SSID>"         
#define PASSWORD "<your wifi password>"     

#define applicationName "testsmartdevice"   // Ganti dengan application name Antares yang telah dibuat
#define deviceName "temperaturesensor"     // Ganti dengan device Antares yang telah dibuat

// LED
#define LED_Grow_Light 12 // ADC Value
#define LED_Fan 13 // Suhu
#define LED_Drip_Irrigation 36 // Moisture

// Batas LED Menyala
int LDRthreshold = 2400; 
int Tempthreshold = 20;
int Moistthreshold = 2800; 

AntaresESP32HTTP antares(ACCESSKEY);      

void setup() {
  Serial.begin(9600);     
  
  pinMode(LED_Grow_Light, OUTPUT);
  pinMode(LED_Fan, OUTPUT);
  pinMode(LED_Drip_Irrigation, OUTPUT);

  antares.setDebug(true);   //for debugging in Antares Platform
  antares.wifiConnection(WIFISSID,PASSWORD);  // Connecting to Antares Platform
}

void loop() {
  // Get latest data
  antares.get(applicationName, deviceName);

  // Mendapatkan data individu
  int LDR = antares.getInt("LDR");
  int temperature = antares.getInt("temperature");
  int humidity = antares.getInt("humidity");
  int moist = antares.getInt("Moisture");

  // Print data ke serial monitor
  Serial.println("ADC Value: " + String(LDR));
  Serial.println("temperature: " + String(temperature));
  Serial.println("humidity: " + String(humidity));
  Serial.println("Moisture: " + String(moist));
  Serial.println("Tempthreshold: " + String(Tempthreshold));
  delay(10000); 

  // LED Grow Light
  if(LDR > LDRthreshold){
    digitalWrite(LED_Grow_Light, HIGH);
    Serial.println("Lamp is activated");
  }
  else {
    digitalWrite(LED_Grow_Light, LOW);
    Serial.println("Lamp is deactivated");
  }

  // LED Fan
  if(temperature > Tempthreshold){
    digitalWrite(LED_Fan, HIGH);
    Serial.println("Fan is activated");
  }
  else {
    digitalWrite(LED_Fan, LOW);
    Serial.println("Fan is deactivated");
  }
  
  // LED Drip Irrigation
  if(moist > Moistthreshold){
    digitalWrite(LED_Drip_Irrigation, LOW);
    Serial.println("Drip irigation is activated");
  }
  else {
    digitalWrite(LED_Drip_Irrigation, HIGH);
    Serial.println("Drip irigation is deactivated");
  }
}
