char data; 
int data2;
void setup() {

Serial.begin(9600);
}

void loop() {

if(Serial.available())
  {
  data = Serial.read(); 
  delay(100);
  Serial.println(data);
  }

/*  
   {
   data2 = Serial.parseInt();
   delay(100); 
   Serial.println(data2);
   }
*/  
}
