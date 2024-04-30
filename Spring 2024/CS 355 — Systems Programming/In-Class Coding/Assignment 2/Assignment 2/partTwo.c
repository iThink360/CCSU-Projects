//
//  partTwo.c
//  Assignment 2
//
//  Created by Rumman Shahzad on 2/15/24.
//

/* Suppose we stored 10 strings in an array. Write a program in C to print the elements of the array in reverse order. You are not allowed to use string.h. */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    // Setup array of strings
    char strings[10][50] = {"This", "is", "an", "example", "of", "an", "array", "of", "ten", "strings!"};
    
    // Print strings in reverse order
    for (int i = 9; i >= 0; i--) {
        printf("%s\n", strings[i]);
    }
    
    return 0;
}
