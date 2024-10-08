/**
 * First program for programming the Elegoo UNO R3
 * Author: Luna Klatzer
 * Date: 10.09.2024
 */
#include <LED-Display-Project.h>
#include <LedControl.h>

#define MATRIX_DELAY 500
#define DATA_IN_PIN 12
#define CLK_PIN 10
#define LOAD_CS_PIN 11

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn
 pin 10 is connected to the CLK
 pin 11 is connected to LOAD (CS)
 We have only a single MAX72XX.
 */
static LedControl lc = LedControl(DATA_IN_PIN, CLK_PIN, LOAD_CS_PIN, 1);

/**
 * Setup function for the microcontroller.
 *
 * This sets up the microcontroller and then runs the main loop.
 */
void setup()
{
  SETUP_BEGIN;

  // Set the LED pin as an output
  pinMode(LED_PIN, OUTPUT);

  // The MAX72XX is in power-saving mode on startup, we have to do a wakeup call
  lc.shutdown(0, false);
  // Set the brightness to a medium values
  lc.setIntensity(0, 8);
  // and clear the display
  lc.clearDisplay(0);

  SETUP_END;
}

/**
 * Main loop for the microcontroller.
 *
 * This is where the main functionality of the microcontroller is implemented.
 */
void loop()
{
  blink_onboard_led();
  writeArduinoOnMatrix();
  rows();
  columns();
  single();
}

/**
 * This method will display the characters for the
 * word "Arduino" one after the other on the matrix.
 * (you need at least 5x7 leds to see the whole chars)
 */
void writeArduinoOnMatrix()
{
  // here is the data for the characters
  byte a[5] = {B01111110, B10001000, B10001000, B10001000, B01111110};
  byte r[5] = {B00111110, B00010000, B00100000, B00100000, B00010000};
  byte d[5] = {B00011100, B00100010, B00100010, B00010010, B11111110};
  byte u[5] = {B00111100, B00000010, B00000010, B00000100, B00111110};
  byte i[5] = {B00000000, B00100010, B10111110, B00000010, B00000000};
  byte n[5] = {B00111110, B00010000, B00100000, B00100000, B00011110};
  byte o[5] = {B00011100, B00100010, B00100010, B00100010, B00011100};

  // now display them one by one with a small delay
  lc.setRow(0, 0, a[0]);
  lc.setRow(0, 1, a[1]);
  lc.setRow(0, 2, a[2]);
  lc.setRow(0, 3, a[3]);
  lc.setRow(0, 4, a[4]);
  delay(MATRIX_DELAY);
  lc.setRow(0, 0, r[0]);
  lc.setRow(0, 1, r[1]);
  lc.setRow(0, 2, r[2]);
  lc.setRow(0, 3, r[3]);
  lc.setRow(0, 4, r[4]);
  delay(MATRIX_DELAY);
  lc.setRow(0, 0, d[0]);
  lc.setRow(0, 1, d[1]);
  lc.setRow(0, 2, d[2]);
  lc.setRow(0, 3, d[3]);
  lc.setRow(0, 4, d[4]);
  delay(MATRIX_DELAY);
  lc.setRow(0, 0, u[0]);
  lc.setRow(0, 1, u[1]);
  lc.setRow(0, 2, u[2]);
  lc.setRow(0, 3, u[3]);
  lc.setRow(0, 4, u[4]);
  delay(MATRIX_DELAY);
  lc.setRow(0, 0, i[0]);
  lc.setRow(0, 1, i[1]);
  lc.setRow(0, 2, i[2]);
  lc.setRow(0, 3, i[3]);
  lc.setRow(0, 4, i[4]);
  delay(MATRIX_DELAY);
  lc.setRow(0, 0, n[0]);
  lc.setRow(0, 1, n[1]);
  lc.setRow(0, 2, n[2]);
  lc.setRow(0, 3, n[3]);
  lc.setRow(0, 4, n[4]);
  delay(MATRIX_DELAY);
  lc.setRow(0, 0, o[0]);
  lc.setRow(0, 1, o[1]);
  lc.setRow(0, 2, o[2]);
  lc.setRow(0, 3, o[3]);
  lc.setRow(0, 4, o[4]);
  delay(MATRIX_DELAY);
  lc.setRow(0, 0, 0);
  lc.setRow(0, 1, 0);
  lc.setRow(0, 2, 0);
  lc.setRow(0, 3, 0);
  lc.setRow(0, 4, 0);
  delay(MATRIX_DELAY);
}

/**
 * This function lights up a some Leds in a row.
 * The pattern will be repeated on every row.
 * The pattern will blink along with the row-number.
 * row number 4 (index==3) will blink 4 times etc.
 */
void rows()
{
  for (int row = 0; row < 8; row++)
  {
    delay(MATRIX_DELAY);
    lc.setRow(0, row, B10100000);
    delay(MATRIX_DELAY);
    lc.setRow(0, row, (byte)0);
    for (int i = 0; i < row; i++)
    {
      delay(MATRIX_DELAY);
      lc.setRow(0, row, B10100000);
      delay(MATRIX_DELAY);
      lc.setRow(0, row, (byte)0);
    }
  }
}

/**
 * This function lights up a some Leds in a column.
 * The pattern will be repeated on every column.
 * The pattern will blink along with the column-number.
 * column number 4 (index==3) will blink 4 times etc.
 */
void columns()
{
  for (int col = 0; col < 8; col++)
  {
    delay(MATRIX_DELAY);
    lc.setColumn(0, col, B10100000);
    delay(MATRIX_DELAY);
    lc.setColumn(0, col, (byte)0);
    for (int i = 0; i < col; i++)
    {
      delay(MATRIX_DELAY);
      lc.setColumn(0, col, B10100000);
      delay(MATRIX_DELAY);
      lc.setColumn(0, col, (byte)0);
    }
  }
}

/*
 This function will light up every Led on the matrix.
 The led will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void single()
{
  for (int row = 0; row < 8; row++)
  {
    for (int col = 0; col < 8; col++)
    {
      delay(MATRIX_DELAY);
      lc.setLed(0, row, col, true);
      delay(MATRIX_DELAY);
      for (int i = 0; i < col; i++)
      {
        lc.setLed(0, row, col, false);
        delay(MATRIX_DELAY);
        lc.setLed(0, row, col, true);
        delay(MATRIX_DELAY);
      }
    }
  }
}
