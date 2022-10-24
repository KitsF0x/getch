#ifndef GETCH_H_INCLUDED
#define GETCH_H_INCLUDED

#include <stdio.h>
#include <windows.h>

char getch() {
  char getch_input = 0;
  // Break loop when key was pressed.
  while (getch_input == 0) {
    for (char i = 97; i < 122; i++) {
      // Check for a-z keys press.
      if (GetAsyncKeyState(toupper(i))) {
        // Break loop when key was released.
        while (1) {
          if (!GetAsyncKeyState(toupper(i))) {
            // Assign pressed key to getch_input variable.
            getch_input = i;
            // If shift was pressed make char uppercase(e.g. a -> A).
            if (GetAsyncKeyState(VK_SHIFT)) {
              getch_input -= 32;
            }
            break;
          }
        }
      }
    }
  }
  // Return pressed char.
  return getch_input;
}

#endif