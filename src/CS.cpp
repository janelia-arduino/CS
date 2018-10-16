// ----------------------------------------------------------------------------
// CS.h
//
// Provides chip select via a 3-8 decoder
//
// Author: Steve Sawtelle
// ----------------------------------------------------------------------------
#include "CS.h"

//---------- constructor ----------------------------------------------------

CSClass CS;


//---------- public ----------------------------------------------------


// ----------------------------------------------------------------------------
//
// ----------------------------------------------------------------------------
void CSClass::begin(int cs_en_pin, int cs_adr0_pin, int cs_adr1_pin, int cs_adr2_pin)
{
  en_pin = cs_en_pin;
  adr0_pin = cs_adr0_pin;
  adr1_pin = cs_adr1_pin;
  adr2_pin = cs_adr2_pin;

  // disable chip selects and set them as ouputs
  SPIselect(8);
  pinMode(en_pin, OUTPUT);
  pinMode(adr0_pin, OUTPUT);
  pinMode(adr1_pin, OUTPUT);
  pinMode(adr2_pin, OUTPUT);
}


void CSClass::SPIselect(uint8_t chip)
{

  // Serial.print("---");
  // Serial.println(chip, HEX);

  //   delayMicroseconds(100);
  digitalWrite(en_pin, HIGH); // disable all CS while changing

  if( chip < 8)
  {
    digitalWrite(adr0_pin, chip & 0x01);
    digitalWrite(adr1_pin, (chip & 0x02) >> 1);
    digitalWrite(adr2_pin, (chip & 0x04) >> 2);

    digitalWrite(en_pin, LOW);  // enable selected output
  }
}
