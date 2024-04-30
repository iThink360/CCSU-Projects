//
//  PartOne.c
//  Assignment 3
//
//  Created by Rumman Shahzad on 3/7/24.
//

// Write the program on Slide #11 in Lec 11. Change the code to work with a file you have in your current directory.

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, const char * argv[]) {
    
    struct stat infobuf; /* place to store info */
    
    if (stat("Screenshot.png", &infobuf) == -1 ) /* get info */
        perror("Screenshot.png");
    else
        printf("The size of Screenshot.png is %lld\n", infobuf.st_size);
    
    return 0;
}

