#include <ESP8266WiFi.h>

// Datos para conectarse a la red.
const char* ssid = "eant";
const char* password = "eantpass";

// Crear la instancia de servidor.
// especificar el puerto.
WiFiServer server(80);

void setup() {
Serial.begin(115200);
delay(10);

// preparar el led
pinMode(LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN, LOW);
  
// Conectar al WiFi.
Serial.println();
Serial.print("Conectando a ");
Serial.println(ssid);
  
WiFi.begin(ssid, password);
  
while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
Serial.println("");
Serial.println("WiFi conectado");
  
// Inicializar el servidor.
server.begin();
Serial.println("Servidor inicializado en:");
Serial.println(WiFi.localIP());
}

void loop() {
// Verificar si hay cliente conectado.
WiFiClient client = server.available();
if (!client) {
    return;
    }
  
// Esperar pedido del cliente.

Serial.println("Nuevo Cliente");
  
while(!client.available()){
    delay(1);
  }
  
// Leer la primera línea del pedido.
String req = client.readStringUntil('\r');
Serial.println(req);
client.flush();
  
// Coincidir el pedido.
int val;
if (req.indexOf("/led/0") != -1) val = 0;
  
else if (req.indexOf("/led/1") != -1) val = 1;

else {
    Serial.println("pedido no valido");
    client.stop();
    return;
     }

// Prender o apagar el led de acuerdo al pedido.
 digitalWrite(LED_BUILTIN, val);
 client.flush();

// Preparo la respuesta.
String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nEl led esta ahora: ";
s += (val)?"apagado":"prendido";
s += "</html>\n";

  // Send the response to the client
  client.print(s);
  delay(1);
  Serial.println("Cliente desconectado");
}

