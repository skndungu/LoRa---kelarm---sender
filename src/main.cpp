#include <Arduino.h>

#include <SPI.h>
#include <LoRa.h>

int counter = 0;

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6))
  {
    Serial.println("Starting LoRa failed!");
    while (1)
      ;
  }
}

void loop()
{
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("4");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;
}