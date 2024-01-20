// -------------------------------------------------
// Copyright (c) 2024 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include "Keypad.h"

const int ROWS = 4; // Amount of rows on the keypad
const int COLS = 4; // Amount of columns on the keypad

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte PINS_ROW[ROWS] = {9, 8, 7, 6}; // Pins on Arduino corresponding to R1, R2, R3, R4
byte PINS_COL[COLS] = {5, 4, 3, 2}; // Pins on Arduino corresponding to C1, C2, C3, C4

Keypad MyKeypad = Keypad(makeKeymap(keys), PINS_ROW, PINS_COL, ROWS, COLS);

void setup()
{
  Serial.begin(115200);
  Serial.print("Starting...");
}

void loop()
{
  char key = MyKeypad.getKey(); // Read the key

  // Check if some key is pressed
  if (key) {
    Serial.print("Key Pressed: ");
    Serial.println(key);
  }
}
