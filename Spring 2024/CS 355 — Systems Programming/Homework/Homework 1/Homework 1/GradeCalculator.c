//
//  GradeCalculator.c
//  Homework 1
//
//  Created by Rumman Shahzad on 2/1/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    
    // User input
    char input[5] = "";
    printf("Please enter a numeric grade: ");
    scanf("%s", input);
    
    unsigned int length = (unsigned int) strlen(input);
    
    // Check if the input is an integer and falls within bounds, exit if not
    
    // A standalone negative sign is invalid input
    if (length == 1 && input[0] == '-') {
        printf("Your input could not be interpreted as an integer value.\n");
        exit(1);
    }
    
    // Any nonnumerical characters are invalid input
    for (int i = 0; i < length; i++) {
        
        if (!isdigit(input[i])) { // Nonnumerical character detected
            
            // If the first character is a negative sign, skip it
            if (i == 0 && input[i] == '-')
                continue;
            
            printf("Your input could not be interpreted as an integer value.\n");
            exit(1);
        }
    }
    
    // Any number greater than 100 or less than 0 is invalid
    int grade = atoi(input);
    if (grade < 0 || grade > 100) {
        printf("You entered an invalid value.\n");
        exit(1);
    }
    
    // Input validated. Now obtain the final letter grade and print it
    char finalGrade;
    if (grade <= 100 && grade >= 90) // [90, 100]
        finalGrade = 'A';
    else if (grade >= 80 && grade <= 89) // [80, 90)
        finalGrade = 'B';
    else if (grade >= 70 && grade <= 79) // [70, 80)
        finalGrade = 'C';
    else if (grade >= 60 && grade <= 69) // [60, 70)
        finalGrade = 'D';
    else // [0, 60)
        finalGrade = 'F';
    
    printf("Your grade is a %c.\n", finalGrade);
    return 0;
}
