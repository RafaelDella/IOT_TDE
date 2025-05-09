#include "DHT.h"

// --- CONFIGURAÇÃO DO SENSOR DHT22 ---
#define DHTPIN 13
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// --- CONFIGURAÇÃO DO SENSOR LDR ---
#define LDR_PIN 25

void setup() {
  Serial.begin(115200);

  // Inicializa sensores
  dht.begin();
  analogReadResolution(12); // ESP32: leitura de 0 a 4095

  Serial.println("Sensores DHT22 e LDR iniciados.");
}

void loop() {
  // --- LEITURA DA TEMPERATURA ---
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("Falha ao ler do sensor DHT!");
  } else {
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");

    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.println(" %");
  }

  // --- LEITURA DA LUMINOSIDADE ---
  int valorAnalogico = analogRead(LDR_PIN);
  float luminosidade = (valorAnalogico / 4095.0) * 100.0;

  Serial.print("Luminosidade: ");
  Serial.print(luminosidade, 1);
  Serial.println(" %");

  Serial.println("-------------------------");
  delay(2000);
}
