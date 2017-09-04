#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8); // Configura el puerto serial para el SIM900. Para el Arduino MEGA utilizar pines 10 y 11

int respuesta;
char aux_str[50];

//Contenido del sms que enviamos. \x1A corresponde al caracter de finalizacion
char sms[] = "Mensaje enviado desde el Arduino de Prometec! \x1A \r\n";

void setup()
{
  SIM900.begin(19200); //Configura velocidad del puerto serie para el SIM900
  Serial.begin(19200); //Configura velocidad del puerto serie del Arduino
  delay(1000);
  Serial.println("Iniciando...");
  power_on();
  iniciar();
}

void loop()
{
  if (Serial.available())
    switch (Serial.read())
    {
      case 'l':
        llamar();
        break;
      case 's':
        mensaje_sms();
        break;
    }
  if (SIM900.available()) {
    Serial.write(SIM900.read());
  }
}


int enviarAT(char* ATcommand, char* resp_correcta, unsigned int tiempo)
{

  int x = 0;
  bool correcto = 0;
  char respuesta[100];
  unsigned long anterior;

  memset(respuesta, '\0', 100); // Inicializa el string
  delay(100);
  while ( SIM900.available() > 0) SIM900.read(); // Limpia el buffer de entrada
  SIM900.println(ATcommand); // Envia el comando AT
  x = 0;
  anterior = millis();
  // Espera una respuesta
  do {
    // si hay datos el buffer de entrada del UART lee y comprueba la respuesta
    if (SIM900.available() != 0)
    {
      //Comprueba que no haya desbordamiento en la capacidad del buffer
      if (x < 99) {
        respuesta[x] = SIM900.read();
        x++;
      }
      else Serial.println("Desbordamiento!");
      // Comprueba si la respuesta del modulo es la 1
      if (strstr(respuesta, resp_correcta) != NULL)
      {
        correcto = 1;
      }
    }
  }
  // Espera hasta tener una respuesta
  while ((correcto == 0) && ((millis() - anterior) < tiempo));
  Serial.println(respuesta);

  return correcto;
}

void power_on()
{
  int respuesta = 0;

  // Comprueba que el modulo SIM900 esta arrancado
  if (enviarAT("AT", "OK", 2000) == 0) //comprueba la conexion a la red
  {
    Serial.println("Encendiendo el GPRS...");

    pinMode(9, OUTPUT);
    digitalWrite(9, HIGH);
    delay(1000);
    digitalWrite(9, LOW);
    delay(1000);

    // Espera la respuesta del modulo SIM900
    while (respuesta == 0) {
      // Envia un comando AT cada 2 segundos y espera la respuesta
      respuesta = enviarAT("AT", "OK", 2000);
      SIM900.println(respuesta);
    }
  }
}

void power_off()
{
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  delay(1000);
}

void reiniciar()
{
  Serial.println("Reiniciando...");
  power_off();
  delay (5000);
  power_on();
}

void iniciar()
{
  enviarAT("AT+CPIN=\"1867\"", "OK", 1000);
  Serial.println("Conectando a la red...");
  delay (5000);

  //espera hasta estar conectado a la red movil
  while ( enviarAT("AT+CREG?", "+CREG: 0,1", 1000) == 0 )
  {
  }
  Serial.println("Conectado a la red.");
  enviarAT("AT+CLIP=1\r", "OK", 1000); // Activamos la identificacion de llamadas
  enviarAT("AT+CMGF=1\r", "OK", 1000); //Configura el modo texto para enviar o recibir mensajes
  enviarAT("AT+CNMI=2,2,0,0,0\r", "OK", 1000); //Configuramos el modulo para que nos muestre los SMS recibidos por comunicacion serie
  Serial.println("Preparado.");
}

void mensaje_sms()
{
  if (enviarAT("AT+CREG?", "+CREG: 0,1", 1000) == 1) //comprueba la conexion a la red
  {
    Serial.println("Enviando SMS...");
    enviarAT("AT+CMGF=1\r", "OK", 1000); //Comando AT para mandar un SMS
    sprintf(aux_str, "AT+CMGS=\"XXXXXXXXX\"", strlen(sms)); //Numero al que vamos a enviar el mensaje
    //Texto del mensaje
    if (enviarAT(aux_str, ">", 10000) == 1)
    {
      enviarAT(sms, "OK", 10000);
    }
    Serial.println("SMS enviado");
  }
  else
  {
    reiniciar();
    iniciar();
  }
}
void llamar()
{
  if (enviarAT("AT+CREG?", "+CREG: 0,1", 1000) == 1) //Comprueba la conexion a la red
  {
    Serial.println("Realizando llamada...");
    enviarAT("ATDXXXXXXXXX;", "OK", 1000);
    delay(20000); // Espera 20 segundos mientras realiza la llamada
    enviarAT("ATH", "OK", 1000); // Cuelga la llamada
    Serial.println("Llamada finalizada");
  }
  else
  {
    reiniciar();
    iniciar();
  }
}
