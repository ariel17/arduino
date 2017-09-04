#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x12};
IPAddress ip(192,168,2,212);
EthernetServer server(80);

String HTTP_req;          // Para guardar la peticion del cliente
boolean LED2_status = 0;

void setup()
{   Ethernet.begin(mac, ip);  
    server.begin();           
    Serial.begin(9600);       
    pinMode(2, OUTPUT);       
}
void loop()
{  EthernetClient client = server.available();  // Comprobamos si hay peticiones
   if (client)                                  // En caso afirmativo
      {  boolean currentLineIsBlank = true;
         while (client.connected()) 
           { if (client.available())           // Hay algo pendiente de leer
               { char c = client.read(); // Leemos los caracteres de uno en uno
                 HTTP_req += c;          // Los añadimos al String
                 if (c == '\n' && currentLineIsBlank)
                    { client.println("HTTP/1.1 200 OK");
                      client.println("Content-Type: text/html");
                      client.println("Connection: close");
                      client.println();
                      client.println("<!DOCTYPE html>");          // Envia la pagina Web
                      client.println("<html>");
                      client.println("<head>");
                      client.println("<title>Control de LEDs en Arduino</title>");
                      client.println("</head>");
                      client.println("<body>");
                      client.println("<h1>LED</h1>");
                      client.println("<p>Haz click para conmutar el LED.</p>");
                      client.println("<form method=\'get\'>");
                      ProcessCheckbox(client);
                      client.println("</form>");
                      client.println("</body>");
                      client.println("</html>");
                      Serial.print(HTTP_req);
                      HTTP_req = "";    // Una vez procesador, limpiar el string
                      break;
                    }
                 if (c == '\n')
                      currentLineIsBlank = true;
                 else if (c != '\r')
                      currentLineIsBlank = false;
              } // if (client.available
           }   // WHile
        delay(10);      // dar tiempo
        client.stop(); // Cerra conexion
   }  // If client
}

void ProcessCheckbox(EthernetClient cl)
  {  if (HTTP_req.indexOf("LED2=2") > -1)    // LED2 pinchado?
          LED2_status = !LED2_status ;         // Si pichado invertimos el valor

     digitalWrite(2, LED2_status);
     if (LED2_status)
             cl.println("<input type=\'checkbox\' name=\'LED2\'value=\'2\' \\ onclick=\'submit();\' checked>LED2");
     else
             cl.println("<input type=\'checkbox\' name=\'LED2\' value=\'2\' \\  onclick=\'submit();\'>LED2");
   }
