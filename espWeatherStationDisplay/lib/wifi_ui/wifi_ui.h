#ifndef WIFI_UI_H
#define WIFI_UI_H

#include <lvgl.h>
#include "Arduino.h"

// Struttura per conservare le credenziali WiFi


struct WifiCredentials {
  String ssid;
  String password;
  bool connected;
  lv_obj_t *popup;
  lv_obj_t *kb;
  lv_obj_t *ta;
};

extern WifiCredentials wifiCredentials;

void connect_to_wifi(void); 
void close_popup(void);
void password_popup(void);
void show_success_popup(void);
//void not_show_success_popup(void);
void network_selected(lv_event_t *e);
void create_wifi_popup(void);

#endif // WIFI_UI_H
