#include "letters.h"

int LEDpins[] = { 9, 10, 11, 12, 13, 14, 15, 16 };

int current_col = 0;
int number_cols = 8;

int invert = 0;

int number_rows = 8;

int delay_col = 1;

void setup() {
  int r;

  for (r = 0; r < number_rows; r++) {
    pinMode(LEDpins[ r ], OUTPUT);
    digitalWrite(LEDpins[ r ], OUTPUT);
  }

}

void loop() {
  show(H, 0);
  show(E, 0);
  show(L, 0);
  show(L, 0);
  show(O, 0);
        
  show(SPACE, 0);
  show(SPACE, 0);
  show(SPACE, 0);
  show(SPACE, 0);

}

void show(byte letter[], int invert) {
  int c, r, real_col;
  
  for (c = 0; c < number_cols; c++) {
  
    real_col = invert ? (number_cols - 1) - c : c;

    for (r = 0; r < number_rows; r++) {
      digitalWrite(LEDpins[ r ], bitRead(letter[ r ], real_col));
    }
    
    delay(delay_col);
  }
  
}

