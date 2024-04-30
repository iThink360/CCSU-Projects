// This program runs until 'q' is pressed, then it terminates. There is no output because echo mode is disabled when raw mode is enabled.

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

// Global structure to store original terminal attributes
struct termios orig_termios;

// Function to disable raw mode by restoring original terminal attributes
void disableRawMode() {
    tcsetattr(0, TCSAFLUSH, &orig_termios);
}

// Function to enable raw mode by modifying terminal attributes
void enableRawMode() {
    
    // Get original terminal attributes
    tcgetattr(0, &orig_termios);
    
    // Create a copy of original attributes
    struct termios raw = orig_termios;
    
    // Modify attributes to enable raw mode:
    // Turn off echoing of input characters (ECHO flag)
    // Turn off canonical mode, where input is line-buffered (ICANON flag)
    raw.c_lflag &= ~(ECHO | ICANON);
    
    // Apply modified attributes to terminal
    tcsetattr(0, TCSAFLUSH, &raw);
}

// Main function
int main(int argc, const char * argv[]) {
    
    enableRawMode(); // Enable raw mode
    
    char c; // Variable to store input character
    while (read(0, &c, 1) == 1 && c != 'q'); // Read input character by character until 'q' is pressed
    
    disableRawMode(); // Disable raw mode before exiting
    
    return 0;
}
