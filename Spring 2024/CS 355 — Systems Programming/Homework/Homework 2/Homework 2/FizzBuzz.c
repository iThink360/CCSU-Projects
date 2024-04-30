//
//  main.c
//  Homework 2
//
//  Created by Rumman Shahzad on 2/6/24.
//

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void fizzbuzz(int);

// Main function
int main(int argc, const char * argv[]) {
    
    // User input
    int input;
    printf("Please enter an integer: ");
    scanf("%d", &input);
    
    // Negative inputs are invalid
    if (input < 0) {
        printf("Your input must be a positive integer.\n");
        exit(1);
    }
    
    // Print outputs using a loop and invoking fizzbuzz() function
    for (int i = 0; i <= input; i++)
        fizzbuzz(i);
    
    return 0;
}

// Convert an integer to an output: multiples of 3 output Fizz; multiples of 5 output Buzz; multiples of both 3 and 5 output FizzBuzz; otherwise output remains unchanged.
void fizzbuzz(int x) {
    
    if (x % 3 == 0 && x % 5 == 0)
        printf("FizzBuzz\n");
    else if (x % 3 == 0)
        printf("Fizz\n");
    else if (x % 5 == 0)
        printf("Buzz\n");
    else
        printf("%d\n", x);
}
