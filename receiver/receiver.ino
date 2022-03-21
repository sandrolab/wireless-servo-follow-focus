#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t pipe = 0xE8E8F0F0E1LL; // Transmission ch.
RF24 radio (9, 10); // CE, CSN
int msg[1];

Servo myServo;

void setup()  {
  
  myServo.attach(6); 
  pinMode(6, OUTPUT); 
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening(); 
  
}

void loop()  {
  
  if (radio.available()){
    bool done = false;
      while (!done){
        done = radio.read (msg, 1);
        myServo.write (msg[0]);
      }
  }
  
  delay(1);
  
}
