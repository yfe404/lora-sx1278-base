# lora-sx1278-base

## Wiring

To wire up the SX1278 module (LoRa module) to an ESP8266, you will need to connect the appropriate pins from the SX1278 module to the ESP8266 GPIO pins. Here is a typical wiring setup:

**SX1278 Module** | **ESP8266 GPIO**
--- | ---
VCC | 3.3V (or 5V if your module supports it)
GND | GND
MISO | GPIO12
MOSI | GPIO13
SCK | GPIO14
NSS/CS | GPIO15 (or any other GPIO pin, but update the code accordingly)
RST | GPIO16 (or any other GPIO pin, but update the code accordingly)
DIO0 | GPIO4 (or any other GPIO pin, but update the code accordingly)

Please note the following:

1. **VCC**: Connect to 3.3V on the ESP8266. Most ESP8266 boards operate at 3.3V, so make sure your SX1278 module can also work at this voltage. If your module requires 5V, you may need to use level shifters to interface with the ESP8266.

2. **NSS/CS**, **RST**, and **DIO0**: You can connect these pins to any available GPIO pins on the ESP8266, but make sure to specify the correct pins in your code. In the provided code examples, I've used GPIO15 for NSS/CS, GPIO16 for RST, and GPIO4 for DIO0. If you use different pins, update the pin definitions in the code accordingly.

3. **MISO**, **MOSI**, and **SCK**: These are the SPI communication pins and should be connected to the corresponding SPI pins on the ESP8266.

Once you've connected the pins correctly, you can upload the transmitter and receiver code to your ESP8266 modules, making sure to match the pin configurations you used in your wiring. This setup will allow the two ESP8266 modules to communicate with each other using the SX1278 module over LoRa.


