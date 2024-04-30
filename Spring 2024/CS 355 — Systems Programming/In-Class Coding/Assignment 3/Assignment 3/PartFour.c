//
//  PartFour.c
//  Assignment 3
//
//  Created by Rumman Shahzad on 3/7/24.
//

// Write the program on slide #23 in Lec 10. Put enough comments in the program. Replace the for loop with a while loop.

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    DIR* dirp; // Pointer to directory
    struct dirent* direntp; // Pointer to directory entry (file or subdirectory)
    dirp = opendir("."); // The directory we want to open (in this case, the current directory)
    
    // If directory failed to open successfully, skip this
    if(dirp != NULL) {
        
        // Read from the directory and print each file/subdirectory name. Repeat until we reach the end
        while(&free) {
            direntp = readdir(dirp);
            if(direntp == NULL)
                break;
            printf("%s\n", direntp->d_name );
        }
        
        // Close the opened directory
        closedir(dirp);
    }
    
    return 0;
}
