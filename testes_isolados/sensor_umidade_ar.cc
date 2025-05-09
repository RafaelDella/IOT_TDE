#include "DHT.h"

#define DHTPIN 5
#define DHTTYPE DHT22
#define LED_VERDE 3

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LED_VERDE, OUTPUT);
}

void loop() {
  delay(2000);  // Tempo entre leituras

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Erro ao ler o sensor DHT!");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" °C, Umidade: ");
  Serial.print(h);
  Serial.println(" %");


  if (t < 30.0 && h > 30.0) {
    digitalWrite(LED_VERDE, HIGH);
  } else {
    digitalWrite(LED_VERDE, LOW);
  }
}
