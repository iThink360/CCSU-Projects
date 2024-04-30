//
//  main.c
//  Homework 7
//
//  Created by Rumman Shahzad on 3/26/24.
//

#include <stdio.h>

#define DEVICENAME "/dev/random" // device name
#define len 10 // constant buffer length

int main(int argc, const char * argv[]) {
    
    // Variables for total bytes read and buffer data
    size_t total = 0;
    char data[len];
    
    // Open the device file in read-only mode
    FILE * f = fopen(DEVICENAME, "r");
    
    // If the file was not opened successfully, print an error
    if (NULL == f)
        fprintf(stderr, "Failed to open '%s'.\n", DEVICENAME);
    else {
        
        // From file to buffer, read len elements of data (based on buffer length) with each element 1 byte long, capturing total number of bytes read
        total = fread(data, 1, sizeof(data), f);
        
        // If no bytes were read, print an error and exit
        if (total == 0){
            fprintf(stderr, "Error reading from '%s'.\n", DEVICENAME);
            fclose(f);
        }
        
        // Print the buffer data read from the file and close the file
        for (int i = 0; i < len; i++)
            printf(" %d \n", data[i]);
        fclose(f);
    }
    
    // Summary statement of how many bytes were read from which file. Note that %zu should be %d, but my IDE generated a warning that total is technically an unsigned long.
    printf("Read %zu bytes from '%s'.\n", total, DEVICENAME);
    return 0;
}

// More information... /dev/random is a file in Unix that stores random numbers/data based on system noise, including device drivers and other random behaviors. /dev/random is considered a source of high quality random numbers. An example of application for /dev/random would be in cryptography.

// Numbers I obtained from the recentmost execution: 94, 13, -58, 53, -63, -41, -78, -118, -95, 34.
