//
//  partOne.c
//  Assignment 2
//
//  Created by Rumman Shahzad on 2/15/24.
//

/* Write a program in C to count the number of vowels and constants in a string using a pointer. Use scanf() to get the user input. */

#include <stdio.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    
    // User input
    char input[100] = "";
    printf("Please enter a string without spaces: ");
    scanf("%s", input);
    
    char *ptr = input;
    
    // Count number of vowels and consonants
    int vowels = 0;
    int consonants = 0;
    
    for (int i = 0; *(ptr + i) != '\0'; i++) {
        
        // Lowercase current character
        char current = tolower(*(ptr+i));
        
        if (current == 'a' || current == 'e' || current == 'i' || current == 'o' || current == 'u') // is current a vowel?
            vowels++;
        else if (current >= 'a' && current <= 'z') // is current a consonant?
            consonants++;
        
        // If nothing was incremented, then the character was a number or a special character.
        
    }
    
    // Print output
    printf("Number of Vowels: %d\n", vowels);
    printf("Number of Consonants: %d\n", consonants);
    
    return 0;
}
