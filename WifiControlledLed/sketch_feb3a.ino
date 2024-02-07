#define BLYNK_TEMPLATE_ID "TMPL3L-nmKBXf"
#define BLYNK_TEMPLATE_NAME "LED"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "2m9tpFIEOIw_7gF4TePXxNijWzSbPXao"; // Enter your Blynk auth token
char ssid[] = "POCO X2"; // Enter your WiFi name
char pass[] = "12345678"; // Enter your WiFi password

#define light1 5
#define light2 4
#define wifiLed 16

BLYNK_WRITE(V0) {
  bool value1 = param.asInt();
  if (value1 == 1) {
    digitalWrite(light1, LOW);
  } else {
    digitalWrite(light1, HIGH);
  }
}

BLYNK_WRITE(V1) {
  bool value2 = param.asInt();
  if (value2 == 1) {
    digitalWrite(light2, LOW);
  } else {
    digitalWrite(light2, HIGH);
  }
}

void setup() {
  Serial.begin(9600);
  delay(100);

  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(wifiLed, OUTPUT);

  digitalWrite(light1, HIGH);
  digitalWrite(light2, HIGH);
  digitalWrite(wifiLed, HIGH);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
}
