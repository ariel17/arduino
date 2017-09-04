# WiFi connection

## Progress

**2016-12-24**
  Seems to be a lot harder than I thought. There are errors on sketch
  uploading:

  ```bash
  warning: espcomm_sync failed
  error: espcomm_open failed
  error: espcomm_open failed
  ```

  and I'm not sure if I'm uploading the sketch into the Arduino microcontroller
  or into the ESP controller... anyway, I need to enforce my knowledge about
  it. Closing this text, the WiFi connection led was flashing, so I don't know
  what it could mean :P.


## Sketches

* [WiFi simulation ESP8266](https://circuits.io/circuits/3586219-wifi-simulation-esp8266)

## Resources

* [Arduino y WiFi ESP8266](http://www.prometec.net/arduino-wifi/)
* [Send AT commands to esp8266 from Arduino Uno via a SoftwareSerial port](http://arduino.stackexchange.com/questions/18575/send-at-commands-to-esp8266-from-arduino-uno-via-a-softwareserial-port)
* [How to Reduce Voltage with Resistors](http://www.learningaboutelectronics.com/Articles/How-to-reduce-voltage-with-resistors.php)
* [wifiwebserver](http://www.arduinesp.com/wifiwebserver)

## Components & libraries

* [ESP8266 datasheet](http://download.arduino.org/products/UNOWIFI/0A-ESP8266-Datasheet-EN-v4.3.pdf)
* [ESP8266 - AT Command Reference](https://room-15.github.io/blog/2015/03/26/esp8266-at-command-reference/#AT+CWLIF)
* [ESP8266 core for Arduino](https://github.com/esp8266/Arduino)
