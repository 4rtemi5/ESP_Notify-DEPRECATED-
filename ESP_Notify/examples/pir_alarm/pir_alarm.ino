
#include <ESP8266WiFi.h>
#include <ESP_Notify.h>

// define your values here
//############################################################
#define WIFI_SSID     "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

#define DEVICE_ID "YOUR_DEVICE_ID"
//############################################################

ESP_Notify notifier;
int LED = 2;
int PIR = D2;
int interval = 5000;
int previous_millis = millis();
boolean state = LOW;
boolean newState = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(PIR, INPUT);
  
  //calling the connectToWifi() function
  connectToWifi();
}

void loop() {
  if(WiFi.status() != WL_CONNECTED){
    connectToWifi();        //reconnect in case of connection loss
  }
  update();
}


void connectToWifi(){
  // funtion to connect to WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("\n\nconnecting");
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED, !digitalRead(LED));   // blink internal LED
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nconnected: ");
  Serial.println(WiFi.localIP());
  digitalWrite(LED, HIGH);
}

void update(){
  newState = digitalRead(PIR);
  if (newState != state) {
    if(newState){
      // sending Notification
      Serial.println("Movement started!");
      notifier.sendNotification(DEVICE_ID, "Alarm!", "Movement in the room!");
      digitalWrite(LED, LOW);
    }else{
      // sending Notification
      Serial.println("Movement stopped!");
      notifier.sendNotification(DEVICE_ID, "Alarm!", "Movement hast stopped!");
    digitalWrite(LED, HIGH);
    }
    state = newState;
  }
}

