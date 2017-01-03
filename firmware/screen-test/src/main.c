#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include "boxer.h"

#define WIDTH 96
#define HEIGHT 96

#define SHARPMEM_BIT_WRITECMD   (1)
#define SHARPMEM_BIT_VCOM       (1 << 1)
#define SHARPMEM_BIT_CLEAR      (1 << 2)

#define PIN_LED PD2

#define PIN_CS PC0
#define PIN_CLK PC1
#define PIN_DOUT PC2

#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))

#define forever for(;;)

uint8_t currentVcom = 0;

void clkLow() {
  cbi(PORTC, PIN_CLK);
}

void clkHigh() {
  sbi(PORTC, PIN_CLK);
}

void dataLow() {
  cbi(PORTC, PIN_DOUT);
}

void dataHigh() {
  sbi(PORTC, PIN_DOUT);
}

void select() {
  sbi(PORTC, PIN_CS);
}

void deselect() {
  cbi(PORTC, PIN_CS);
}

void send_byte(uint8_t data) {
  for (int i = 0; i < 8; i++) {
    clkLow();

    if (data & 1) {
      dataHigh();
    } else {
      dataLow();
    }

    clkHigh();
    data >>= 1;
  }

  clkLow();
}

void clear() {
  select();
  send_byte(currentVcom | SHARPMEM_BIT_CLEAR);
  currentVcom = currentVcom ? 0 : SHARPMEM_BIT_VCOM;
  send_byte(0);
  deselect();
}

/*
void refresh() {
  uint16_t i, totalbytes, currentline, oldline;  
  totalbytes = (WIDTH * HEIGHT) / 8;

  // Send the write command
  select();
  send_byte(SHARPMEM_BIT_WRITECMD | currentVcom);
  currentVcom = currentVcom ? 0 : SHARPMEM_BIT_VCOM;

  // Send the address for line 1
  oldline = currentline = 1;
  send_byte(currentline);

  // Send image buffer
  for (i=0; i<totalbytes; i++) {
    send_byte(0xAA);
    currentline = ((i+1)/(WIDTH/8)) + 1;
    if(currentline != oldline) {
      // Send end of line and address bytes
      send_byte(0x00);
      if (currentline <= HEIGHT) {
        send_byte(currentline);
      }
      oldline = currentline;
    }
  }

  // Send another trailing 8 bits for the last line
  send_byte(0x00);
  deselect();
}
*/

void drawBoxer() {
  select();
  send_byte(currentVcom | SHARPMEM_BIT_WRITECMD);
  currentVcom = currentVcom ? 0 : SHARPMEM_BIT_VCOM;

  send_byte(1);

  int i = 0;
  for (int row = 0; row < HEIGHT; row++) {
    for (int col = 0; col < WIDTH / 8; col++) {
      send_byte(pgm_read_byte_near(boxer + i++));
    }

    send_byte(0);
    send_byte(row);
  }

  send_byte(0);

  deselect();
}

int main() {
  DDRD |= 1 << PD2;

  sbi(PORTC, PIN_CS);
  cbi(PORTC, PIN_CLK);
  sbi(PORTC, PIN_DOUT);

  sbi(DDRC, PIN_CS);
  sbi(DDRC, PIN_CLK);
  sbi(DDRC, PIN_DOUT);

  clear();

  forever {
    PORTD |= 1 << PD2;
    drawBoxer();
    PORTD &= ~(1 << PD2);
    _delay_ms(500);
  }

  return 0;
}
