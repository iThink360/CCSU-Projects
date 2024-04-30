//
//  partOne.c
//  Assignment 1
//
//  Created by Rumman Shahzad on 1/30/24.
//

// Write a C program to input a character from user and check whether given character is alphabet, digit or special character using if else.

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    // Capture user input
    char myChar;
    printf("Input a character: ");
    scanf("%c", &myChar);
    
    // Using ASCII codes, print an output
    if ((myChar >= '0') && (myChar <= '9'))
        printf("The character you inputted is a digit.\n");
    else if (((myChar >= 'a') && (myChar <= 'z')) || ((myChar >= 'A') && (myChar <= 'Z')))
        printf("The character you inputted is from the English alphabet.\n");
    else
        printf("The character you inputted is a special character.\n");

    return 0;
}

