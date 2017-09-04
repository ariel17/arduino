void setup() {
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
 digitalWrite(8, HIGH);
 digitalWrite(11, LOW);
 Serial.begin(9600);
}

void loop() {
  
  int valorPot = analogRead(A0);
  int x = map(valorPot , 0, 1023, 15, 150);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(x);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(x);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(x);
  digitalWrite(10, LOW);
  digitalWrite(11,HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(x);
  
  analogWrite(6, x);
  
  Serial.println(x);
  
  // wait for a second
}
