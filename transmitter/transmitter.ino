#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t pipe = 0xE8E8F0F0E1LL; // Transmission ch.
RF24 radio (9, 10); // CE, CSN
int msg[1];

void setup()  {
  
  radio.begin ();
  radio.openWritingPipe (pipe);
  
}

void loop()  {
  
  msg[0] =  map (analogRead (0), 0, 1023, 0, 180); // Read
  radio.write (msg, 1); // Write
  delay (1);
  
}
