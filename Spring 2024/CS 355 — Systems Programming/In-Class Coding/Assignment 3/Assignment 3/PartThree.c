//
//  PartThree.c
//  Assignment 3
//
//  Created by Rumman Shahzad on 3/7/24.
//

// Write the program on slide #19 in Lec 10. Put enough comments in the program. Change the code to work with the parent of your current directory.

#include <stdio.h>
#include <stdio.h>
#include <dirent.h>

int main(int argc, const char * argv[]) {
    
    DIR *folder; // To work with a directory
    struct dirent *entry; // To work with each file in the directory
    
    int files = 0; // To keep track of number of files
    folder = opendir(".."); // Open parent directory
    
    // If the directory was not successfully opened, exit
    if (folder == NULL) {
        perror("Unable to read directory");
        return 1;
    }
    
    // Print all file information in the parent directory
    while((entry = readdir(folder))) {
        files++;
        printf("File %3d: %s\n", files, entry->d_name);
    }
    
    closedir(folder);
    return 0;
}
