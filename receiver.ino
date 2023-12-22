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

  // Set receive mode
  rf95.setModeRx();

  Serial.println("LoRa receiver initialized successfully.");
}

void loop() {
  if (rf95.available()) {
    // Message received
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);

    if (rf95.recv(buf, &len)) {
      Serial.print("Received: ");
      Serial.println((char*)buf);
    } else {
      Serial.println("Receive failed");
    }
  }
}
