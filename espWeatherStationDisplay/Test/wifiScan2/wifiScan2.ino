#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(100);

  // Scansione delle reti WiFi disponibili
  Serial.println("Scansione delle reti WiFi...");
  int n = WiFi.scanNetworks();
  if (n == 0) {
    Serial.println("Nessuna rete trovata");
  } else {
    Serial.print(n);
    Serial.println(" reti trovate:");
    for (int i = 0; i < n; ++i) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
      delay(10);
    }
  }

  // Chiedere all'utente di scegliere una rete
  Serial.println("Inserisci il numero della rete a cui vuoi connetterti:");
  while (!Serial.available()) {
    delay(100);
  }
  int networkIndex = Serial.parseInt() - 1;

  // Chiedere la password
  Serial.println("Inserisci la password:");
  while (!Serial.available()) {
    delay(100);
  }
  String password = Serial.readString();

  // Connettersi alla rete scelta
  Serial.print("Connessione a ");
  Serial.println(WiFi.SSID(networkIndex));
  WiFi.begin(WiFi.SSID(networkIndex).c_str(), password.c_str());

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connesso!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Il loop rimane vuoto
}
