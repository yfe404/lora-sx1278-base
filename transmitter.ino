#include <SPI.h>
#include <RH_RF95.h>

#define RFM95_CS 15    // Define the Chip Select (CS) pin
#define RFM95_RST 16   // Define the Reset (RST) pin
#define RFM95_INT 4    // Define the Interrupt (INT) pin

RH_RF95 rf95(RFM95_CS, RFM95_INT);

void setup() {
  Serial.begin(115200);

  // Initialize the LoRa module
  if (!rf95.init()) {
    Serial.println("LoRa initialization failed.");
    while (1);
  }

  // Setup the frequency (in Hz)
  rf95.setFrequency(915.0); // Change this to your desired frequency

  // Set transmit power (range from 5 to 23 dBm)
  rf95.setTxPower(23);

  Serial.println("LoRa transmitter initialized successfully.");
}

void loop() {
  // Message to send
  const char* message = "Hello, LoRa World!";
  
  // Send the message
  rf95.send((uint8_t*)message, strlen(message));
  rf95.waitPacketSent();

  Serial.println("Message sent.");
  
  // Wait for a while before sending the next message
  delay(5000);
}
