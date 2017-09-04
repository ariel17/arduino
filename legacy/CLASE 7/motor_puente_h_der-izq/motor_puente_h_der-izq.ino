//Código para utilizar motor con puente H
int LeftPin=8; //Pines de salida del Arduino
int RightPin=7;
int input=0;
 
void setup(){
    //Serial.begin(9600);
    pinMode(LeftPin, OUTPUT);
    pinMode(RightPin, OUTPUT);
}
 
void loop(){
    

    for (int i=0;i<300;i++){
      //gira para un lado
      digitalWrite(LeftPin, HIGH);
      digitalWrite(RightPin, LOW);
      i=i++;
    }

    delay(4000);
   for (int i=300;i>0;i--){
    digitalWrite(LeftPin, LOW);
    digitalWrite(RightPin, HIGH);
    i=i--;
   }
    
   
}
