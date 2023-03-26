#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>

const char* ssid = "EE-Hub-G3ge";
const char* password = "stock-led-HALF";

AsyncWebServer server(80);  // Async Webserver on port 80


void wifiBegin() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  while (WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(". ");
  }
  Serial.println("");
  Serial.print("Connected To ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void handle_client_requests() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(200, "text/plain", "Hi! I am ESP32.");
  });
}

void otaSetup(){
  handle_client_requests();  // Start Elegent OTA
  AsyncElegantOTA.begin(&server);
  //Initialise Server
  server.begin();
}


void setup() {
  Serial.begin(115200);
  wifiBegin();
  otaSetup();
}


void loop() {

}
