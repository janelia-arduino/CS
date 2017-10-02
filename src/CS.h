// ----------------------------------------------------------------------------
// CS.h
//
// Chip select
//
// Author: Steve Sawtelle
// ----------------------------------------------------------------------------

#ifndef CS_H_
#define CS_H_
#include <Arduino.h>

#define NO_CS 8
#define MCP_CS 7
#define MUX_CS 0
#define CS_EN_PIN   47  // pin 47 low to enable CS
#define CS_ADR0_PIN 22
#define CS_ADR1_PIN 23
#define CS_ADR2_PIN 28

#define ID_SENSE_RANGE  36  // +/- volts to be in ID_SENSE range
#define ID_SENSE_IN A8


class CSClass
{
 public:
  void begin(int,int,int,int);
  void SPIselect(uint8_t chip);

 private:

  int en_pin;
  int adr0_pin;
  int adr1_pin;
  int adr2_pin;

};

extern CSClass CS;

#endif // CS
