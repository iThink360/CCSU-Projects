//
//  MyProg.c
//  Homework 3
//
//  Created by Rumman Shahzad on 2/11/24.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    // User input
    char input[50] = "";
    printf("Please input a string: ");
    char *inputPtr = fgets(input, sizeof(input), stdin);
    
    // Loop through the string and print each word in a pyramid pattern, as per directions
    for (int x = 0; *(inputPtr + x) != '\0'; x++) {
        
        // If *(inputPtr + x) is an alphabetic character, then work from there. Else, skip it
        if ((*(inputPtr + x) >= 'a' && *(inputPtr + x) <= 'z') || (*(inputPtr + x) >= 'A' && *(inputPtr + x) <= 'Z')) {
            
            // Store the current position temporarily
            int y = x;
            
            // Move y back to the beginning of the word
            while ((*(inputPtr + y) >= 'a' && *(inputPtr + y) <= 'z') || (*(inputPtr + y) >= 'A' && *(inputPtr + y) <= 'Z'))
                y--;
            
            y++; // Advance forward one character (decremented one too many)
            
            // Capitalize the first letter of the word if needed
            printf("%c", (*(inputPtr + y) >= 'a' && *(inputPtr + y) <= 'z') ? *(inputPtr + y) - 32 : *(inputPtr + y));
            y++;
            
            // Print the remaining characters of the word
            while (y <= x) {
                printf("%c", *(inputPtr + y));
                y++;
            }
            printf("\n");
        }
    }
    
    return 0;
}
