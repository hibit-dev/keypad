// -------------------------------------------------
// Copyright (c) 2023 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include "Keypad.h"

const int COLS = 3; // Amount of columns on the keypad
const int ROWS = 4; // Amount of rows on the keypad

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte PINS_ROW[ROWS] = {9, 8, 7, 6}; // Pins on Arduino corresponding to R1, R2, R3, R4
byte PINS_COL[COLS] = {5, 4, 3}; // Pins on Arduino corresponding to C1, C2, C3

Keypad MyKeypad = Keypad(makeKeymap(keys), PINS_ROW, PINS_COL, ROWS, COLS);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  char key = MyKeypad.getKey(); // Read the key

  // Check if some key is pressed
  if (key) {
    Serial.print("Key Pressed : ");
    Serial.println(key);
  }
}
