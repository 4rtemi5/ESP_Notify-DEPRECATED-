
#include <ESP8266WiFi.h>
#include <ESP_Notify.h>

// input your values here
//############################################################
#define WIFI_SSID     "YOUR_WiFi_SSID"
#define WIFI_PASSWORD "YOUR_WiFi_PASSWORD"

#define DEVICE_ID "YOUR_DEVICE_ID"
//############################################################

// define a notifier
ESP_Notify notifier;

void setup() {
  Serial.begin(115200);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("\n\nconnecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nconnected: ");
  Serial.println(WiFi.localIP());

  // Send notification
  notifier.sendNotification(DEVICE_ID, "Hello World!", "Stuff, Stuff!");
}

void loop() {
  //empty loop
}