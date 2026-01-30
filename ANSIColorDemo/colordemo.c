// Soren Nilssen

#include <stdio.h> // We use this for printF
#include <unistd.h> // We use this for uSleep

int color = 0; // Variable that stores the current color

void rainbowcolors() {
    color++; // Increment the current color
    switch (color) {
      default: // Should only happen when we actually want to overflow, but can't be too safe
        color = 0; // Reset the color to 0
        printf("\033[0m"); // Reset to terminal default
        break;
      case 0:
        printf("\033[30m"); // Black
        break;
      case 1:
        printf("\033[31m"); // Red
        break;
      case 2:
        printf("\033[32m"); // Green
        break;
      case 3:
        printf("\033[33m"); // Yellow
        break;
      case 4:
        printf("\033[34m"); // Blue
        break;
      case 5:
        printf("\033[35m"); // Magenta
        break;
      case 6:
        printf("\033[36m"); // Cyan
        break;
      case 7:
        printf("\033[37m"); // White
        break;
    }
}

char *message = "ANSI Color Demo! "; // The Message we want to display
int messageLength = 17; // The length of said message
// Because there are 8 colors, defining a message with a length that is a multiple of 8 will result in the colors being static

int main() {
    printf("\033[?25l"); // Hide cursor
    printf("\033[2J"); // Erase entire terminal
    for (int loops=0; loops<400; loops++) {
        printf("\033[H"); // Move the cursor to the home position
        for (int i=0;i<messageLength;i++){
            rainbowcolors(); // Update the terminal's color
            printf("%c", message[i]); // Prints the message
        }
        usleep(10000); // Small delay to make the text more visible
        printf("\033[0K"); // Remove all characters to the right of the cursor, as sometimes desync will cause extra characters to appear
    }

    printf("\033[?25h"); // Show Cursor
    printf("\033[2J"); // Erase entire terminal
    printf("\033[H"); // Reset the cursor's position
    printf("\033[0m"); // Reset the colors

    return 0; // Exit
}
