#include "wifi_ui.h"
#include <WiFi.h>
#include <LovyanGFX.hpp>
#include "ui/ui.h" // UI generated with lvgl / squareline editor



void close_popup() {
  if (wifiCredentials.popup) {
    lv_obj_del_async(wifiCredentials.popup);
    wifiCredentials.popup = nullptr;
  }
  if (wifiCredentials.kb) {
    lv_obj_del_async(wifiCredentials.kb);
    wifiCredentials.kb = nullptr;
  }

  
}


void show_success_popup() {
    lv_obj_t *popup = lv_obj_create(lv_scr_act());
    lv_obj_set_size(popup, 200, 100);
    lv_obj_align(popup, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t *label = lv_label_create(popup);
    String TextStr;

    if (wifiCredentials.connected){
      TextStr = "Connessione riuscita";
    }else{
      TextStr = "Connessione fALLITA";
    }
    Serial.print(TextStr);
    
    lv_label_set_text_fmt(label, TextStr.c_str());
    lv_obj_center(label);

    // Timer per chiudere il popup dopo 3 secondi
    lv_timer_t *timer = lv_timer_create([](lv_timer_t *t) {
        lv_obj_del_async((lv_obj_t *)t->user_data);
    }, 3000, popup);

}

/*
void show_success_popup() {
    lv_obj_t *success_popup = lv_msgbox_create(NULL, "Connessione WiFi riuscita!", "  ", NULL, true);
    lv_obj_center(success_popup);

    // Timer per chiudere il popup dopo 2 secondi
    lv_timer_t *timer = lv_timer_create([](lv_timer_t * timer) {
        lv_obj_del_async((lv_obj_t *)timer->user_data);
    }, 2000, success_popup);
}
*/

void connect_to_wifi() {
  String password = lv_textarea_get_text(wifiCredentials.ta);

  wifiCredentials.password = password;
  // Stampa SSID e password sul monitor seriale
  Serial.print("SSID: ");
  Serial.println(wifiCredentials.ssid);
  Serial.print("Password: ");
  Serial.println(wifiCredentials.password);

  WiFi.begin(wifiCredentials.ssid, password.c_str());

  unsigned long startTime = millis(); // Registra il momento in cui hai avviato il ciclo
  unsigned long duration = 5000; // Durata desiderata in millisecondi (5 secondi)
  bool connect_to_wifi = true; // boolean value if connect or not connected

  while (WiFi.status() != WL_CONNECTED) {
    // Continua a controllare lo stato della connessione WiFi
    // fino a quando non è connesso o è trascorso il tempo desiderato
    if (millis() - startTime >= duration) {
      connect_to_wifi = false; // boolean value if connect or not connected
      break; // Esci dal ciclo dopo 5 secondi
    }
    delay(1000);
    Serial.print(".");
  }
  wifiCredentials.connected = connect_to_wifi;
  close_popup(); // Chiudi il popup e la tastiera

  Serial.print(connect_to_wifi); //debug print

  if (connect_to_wifi == 1){
    Serial.println("");
    Serial.println("Connesso!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }

  show_success_popup();


}

void password_popup() {
  lv_obj_t *popup = lv_obj_create(lv_scr_act());
  lv_obj_set_size(popup, 320, 155);
  lv_obj_align(popup, LV_ALIGN_CENTER, 0, -80); // questo era -50

  lv_obj_t *label = lv_label_create(popup);
  String TextStr = "Inserisci la password per:\n" + wifiCredentials.ssid;
  lv_label_set_text_fmt(label, TextStr.c_str());
  lv_obj_align(label, LV_ALIGN_TOP_MID, 0, -10);

  lv_obj_t *ta = lv_textarea_create(popup);
  lv_textarea_set_password_mode(ta, true);
  lv_obj_set_size(ta, 220, 40);
  lv_obj_align(ta, LV_ALIGN_CENTER, 0, -10);

  lv_obj_t *btn = lv_btn_create(popup);
  lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, 0, 0);
  lv_obj_t *btn_label = lv_label_create(btn);
  lv_label_set_text(btn_label, "Connetti");

  // Creazione della tastiera
  lv_obj_t *kb = lv_keyboard_create(lv_scr_act());
  lv_keyboard_set_textarea(kb, ta);

  // Popola la struttura con i dati necessari

  wifiCredentials.popup = popup;
  wifiCredentials.kb = kb;
  wifiCredentials.ta = ta;

  // Callback del pulsante "Connetti"
  lv_obj_add_event_cb(btn, [](lv_event_t *e) {
    connect_to_wifi();
  }, LV_EVENT_CLICKED, NULL);

  // Callback per il pulsante "Enter" sulla tastiera
  lv_obj_add_event_cb(kb, [](lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_READY) {
      connect_to_wifi();
    }
  }, LV_EVENT_READY, NULL);

}



void network_selected(lv_event_t *e) {
  lv_obj_t *btn = lv_event_get_target(e);
  lv_obj_t *label = lv_obj_get_child(btn, 0);
  const char* ssid = lv_label_get_text(label);

  // Stampa l'SSID sul monitor seriale
  wifiCredentials.ssid = String(ssid);


  close_popup(); // Chiudi il pannello di selezione della rete
  password_popup();
}

void create_wifi_popup() {
  lv_obj_t *popup = lv_obj_create(lv_scr_act());
  lv_obj_set_size(popup, 320, 200);
  lv_obj_align(popup, LV_ALIGN_CENTER, 0, 0);

  lv_obj_t *label = lv_label_create(popup);
  lv_label_set_text(label, "Seleziona una rete WiFi:");
  lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 10);

  lv_obj_t *list = lv_list_create(popup);
  lv_obj_set_size(list, 180, 120);
  lv_obj_align(list, LV_ALIGN_CENTER, 0, 20);

  // Scansione delle reti WiFi
  int n = WiFi.scanNetworks();
  if (n == 0) {
    lv_label_set_text(label, "Nessuna rete trovata");
  } else {
    for (int i = 0; i < n; ++i) {
      lv_obj_t *btn = lv_list_add_btn(list, NULL, WiFi.SSID(i).c_str());
      lv_obj_add_event_cb(btn, network_selected, LV_EVENT_CLICKED, NULL);
    }
  }

  wifiCredentials.popup = popup; // Assegna il popup corrente alla struttura
}
