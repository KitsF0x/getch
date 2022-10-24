#ifndef GETCH_H_INCLUDED
#define GETCH_H_INCLUDED

#include <stdio.h>
#include <windows.h>

char getch() {
  char getch_input = 0;
  while (getch_input == 0) {
    for (char i = 97; i < 122; i++) {
      if (GetAsyncKeyState(toupper(i))) {
        while (1) {
          if (!GetAsyncKeyState(toupper(i))) {
            getch_input = i;
            // Uppercase
            if (GetAsyncKeyState(VK_SHIFT)) {
              getch_input -= 32;
            }
            break;
          }
        }
      }
    }
  }
  return getch_input;
}

#endif