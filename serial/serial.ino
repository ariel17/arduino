const int BAUDS = 9600;
const int LED_PIN = 13;

void setup() {
  Serial.begin(BAUDS);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {

  if (Serial.available() > 0) {
    int inByte = Serial.read();
    Serial.print("Received byte: ");
    Serial.println(inByte);

    if (inByte == 48) {
      digitalWrite(LED_PIN, LOW);
      Serial.println("Light off.");
    } else if (inByte == 49) {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("Light on.");
    }
  }
}
