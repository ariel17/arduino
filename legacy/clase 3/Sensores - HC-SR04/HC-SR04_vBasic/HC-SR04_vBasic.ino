/*
 * Sensor HC-SR04
  Ultrasonic sensor Pins:
      VCC: +5VDC
      Trig : Trigger (INPUT) - Pin11
      Echo: Echo (OUTPUT) - Pin 12
      GND: GND
 */
 
int trigPin = 12;    //Trig
int echoPin = 11;    //Echo
int buzzer = 6;
long duracion, cm;
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer,OUTPUT);
}
 
void loop()
{


  // El sensor es inicializado mediante un pulso (HIGH) de 10 microsegundos o más
  // Seteamos un pulso en baja (LOW) para asegurarnos un pulso en alto limpio
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Lee la señal proveniente del sensor: un pulso HIGH cuya duración es el tiempo en microsegundos de haber 
  //mandado la señal desde el transmisor y su llegada al receptor
  duracion = pulseIn(echoPin, HIGH);
 
  // convierte el tiempo en distancia
  //cm = (duracion/2) / 29.1;
  cm = duracion * 0.01715;
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  int senal=(cm*10);
tone (buzzer, 2000, senal);



  
  delay(250);
}
