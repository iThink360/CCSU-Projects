//
//  partThree.c
//  Assignment 1
//
//  Created by Rumman Shahzad on 1/30/24.
//

// Write a C program to check whether a triangle is valid or not if angles are given using if else. A triangle is said to be a valid triangle if and only if sum of its angles is 180°.

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    // Assume integer inputs.
    
    int angleOne, angleTwo, angleThree;
    
    printf("Input the first angle of the triangle: ");
    scanf("%d", &angleOne);
    
    printf("Input the second angle of the triangle: ");
    scanf("%d", &angleTwo);
    
    printf("Input the third angle of the triangle: ");
    scanf("%d", &angleThree);
    
    // Final computation and output
    int sum = angleOne + angleTwo + angleThree;
    printf(((sum == 180) ? "\nThis triangle is valid.\n" : "\nThis triangle is invalid.\n"));
    
    return 0;
}

