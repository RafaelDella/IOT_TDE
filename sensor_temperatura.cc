#include <Wire.h>
#include <Adafruit_ADS1X15.h>

#define LED_VERDE 26
#define LED_VERMELHO 25
#define ADS1115_ADDR 0x48

Adafruit_ADS1115 ads;

void setup() {
    Serial.begin(115200);

    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_VERMELHO, OUTPUT);

    if (!ads.begin()) {
        Serial.println("Falha ao inicializar o ADS1115!");
        while (1);
    }

    Serial.println("ESP32 com ADS1115 e LM35 Inicializado!");
}

void loop() {
   int16_t leituraLM35 = ads.readADC_SingleEnded(1);

    float tensao = leituraLM35 * (4.096 / 32767.0);
    float temperatura = tensao * 100.0;

    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");

    if (temperatura > 20) {
        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_VERMELHO, HIGH);
    } else {
        digitalWrite(LED_VERDE, HIGH);
        digitalWrite(LED_VERMELHO, LOW);
    }

    delay(1000);
}