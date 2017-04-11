
#ifndef ESP_Notify_h
#define ESP_Notify_h

#include "ESP8266WiFi.h"

class ESP_Notify
{
  public:
    ESP_Notify();
    ~ESP_Notify();
    void sendNotification(String deviceId, String title, String message);
    void sendNotificationToTopic(String topic, String title, String message);
};

#endif

