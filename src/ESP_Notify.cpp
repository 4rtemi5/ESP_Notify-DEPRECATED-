#include "ESP_Notify.h"

#include "ESP8266HTTPClient.h"

ESP_Notify::ESP_Notify(){}

ESP_Notify::~ESP_Notify(){}

HTTPClient http;
HTTPClient httpTOPIK;
String SERVER_ID = "AAAAt9OorV0:APA91bGz0lvkMFkebhz7LZMcdwIU8S6KidEWiDP21U98G0LCBu1EQE1C-0B9zy0cv4Z5crLSf_uvzH2vq6XZx0RPWmOdzG3LIbqB-o3IcI5LGKMxtjNHn5kOswZKUChPMkWMXyqH37Sz";

void ESP_Notify::sendNotification(String deviceId, String title, String message)
{

  String data = "{";
  data = data + "\"data\": {";
  data = data + "\"body\" : \"" + message + "\",";
  data = data + "\"title\" : \"" + title + "\"";
  data = data + "},";
  data = data + "\"registration_ids\": [\"" + deviceId + "\"]";
  data = data + "}";

  http.begin("http://fcm.googleapis.com/fcm/send");
  http.addHeader("Authorization", "key=" + SERVER_ID);
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Host", "fcm.googleapis.com");
  http.addHeader("Content-Length", String(message.length()));
  http.POST(data);
  http.writeToStream(&Serial);
  http.end();
  Serial.println();
}

void ESP_Notify::sendNotificationToTopic( String topic, String title, String message) {

  String data ="{";
  data = data + "\"to\": \"/topics/" + topic + "\",";
  data = data + "\"data\": {";
  data = data + "\"body\" : \"" + message +"\",";
  data = data + "\"title\" : \"" + title + "\"";
  data = data + "} }";

  String key = "key=" + SERVER_ID;

  httpTOPIK.begin("http://fcm.googleapis.com/fcm/send");
  httpTOPIK.addHeader("Authorization", key);
  httpTOPIK.addHeader("Content-Type", "application/json");
  httpTOPIK.addHeader("Host", "fcm.googleapis.com");
  httpTOPIK.addHeader("Content-Length", String(message.length()));
  httpTOPIK.POST(data);
  httpTOPIK.writeToStream(&Serial);
  httpTOPIK.end();
  Serial.println();

}