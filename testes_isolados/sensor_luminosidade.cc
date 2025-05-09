const int ldrPin = A0;
const int ledVermelho = 12;
const int ledVerde = 13;

void setup() {
  Serial.begin(9600);
  
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  int luminosity = map(ldrValue, 1010, 0, 100, 0);

  Serial.print("Luminosidade: ");
  Serial.print(luminosity);
  Serial.println("%");

  if (luminosity < 75) {
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, LOW);
  } else {
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, HIGH);
  }

  delay(500);
}
