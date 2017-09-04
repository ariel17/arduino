int retardo = 5;          // Tiempo de retardo en milisegundos (Velocidad del Motor)
int dato_rx;            // valor recibido en grados
int numero_pasos = 0;   // Valor en grados donde se encuentra el motor
String leeCadena;       // Almacena la cadena de datos recibida
int pote = 0;
int data2=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);     // inicializamos el puerto serie a 9600 baudios
pinMode(11, OUTPUT);    // Pin 11 conectar a IN4
pinMode(10, OUTPUT);    // Pin 10 conectar a IN3
pinMode(9, OUTPUT);     // Pin 9 conectar a IN2
pinMode(8, OUTPUT);     // Pin 8 conectar a IN1
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
    //retardo = map(Serial.parseInt(),0,10,15,200);
    retardo = Serial.parseInt();
    delay(100); 
   Serial.println(retardo);
  
  }
   paso_der(retardo);
}

 
          void paso_der(int retardo2){         // Pasos a la derecha
   digitalWrite(11, LOW); 
       digitalWrite(10, LOW);  
       digitalWrite(9, HIGH);  
       digitalWrite(8, HIGH);  
         delay(retardo2); 
       digitalWrite(11, LOW); 
       digitalWrite(10, HIGH);  
       digitalWrite(9, HIGH);  
       digitalWrite(8, LOW);  
         delay(retardo2); 
       digitalWrite(11, HIGH); 
       digitalWrite(10, HIGH);  
       digitalWrite(9, LOW);  
       digitalWrite(8, LOW);  
        delay(retardo2); 
       digitalWrite(11, HIGH); 
       digitalWrite(10, LOW);  
       digitalWrite(9, LOW);  
       digitalWrite(8, HIGH);  
        delay(retardo2);
          }

