//
//  main.c
//  Homework 8
//
//  Created by Rumman Shahzad on 4/26/24.
//

/* This program tests colors with the curses library in C by changing the terminal window/text color as each character is inputted. The program also invokes a finish function upon an interrupt signal (Ctrl+C) being received. This program runs in non-canonical mode. The program output is a bunch of characters in different colors (you can input as many as you like and the program will echo each one to the terminal) until an interrupt signal is sent. */

#include <stdlib.h>
#include <curses.h>
#include <signal.h>

// Function prototype for interrupted signals
static void finish(int sig);

int main(int argc, const char * argv[]) {
    
    int num = 0;
    
    /* Initialize non-curses data structures here */
    
    (void) signal(SIGINT, finish); // When an interrupt signal is received, call finish(), which ultimately terminates the program.
    
    (void) initscr(); // initialize curses library
    keypad(stdscr, TRUE); // enable keyboard mapping
    (void) nonl(); // tell curses not to do NL->CR/NL on output
    (void) cbreak(); // take input chars one at a time, no wait for \n
    (void) echo(); // echo input - in color
    
    // Query the terminal capability for colors
    if (has_colors()) {
        
        // Ready to define colors our program will use
        start_color();
        
        // Create color pairs in the form (num, text, background). This is simple color assignment, often all we need.
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK);
        init_pair(5, COLOR_CYAN, COLOR_BLACK);
        init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(7, COLOR_WHITE, COLOR_BLACK);
    }
    
    // Cycle through color pairs per character inputted on screen.
    for (;;) {
        
        int c = getch(); // Get current character inputted
        attrset(COLOR_PAIR(num % 8)); // Set color pair with mod operation
        num++;
        
        /* process command keystroke */
    }
    
    finish(0); // Interrupt signal received. Ignore warning for code never being executed.
}

// Invoked when an interrupt signal is sent.
static void finish(int sig) {
    
    endwin(); // Turns off curses
    
    // do non-curses wrap-up here
    
    exit(0); // Process successful
}
