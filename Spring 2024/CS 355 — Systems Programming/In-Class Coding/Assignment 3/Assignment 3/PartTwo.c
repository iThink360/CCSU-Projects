//
//  PartTwo.c
//  Assignment 3
//
//  Created by Rumman Shahzad on 3/7/24.
//

// Write the program on slide #12 in Lec 11. Put enough comments in the main function.

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

void show_stat_info(char *, struct stat *);

int main(int argc, char * argv[]) {
    
    // Buffer for file info
    struct stat info;
    
    // There are arguments passed in
    if (argc > 1) {
        
        // If information of the file was successfully retrieved, then print it
        if (stat(argv[1], &info) != -1) {
            show_stat_info(argv[1], &info);
            return 0; // Process successful
        }
        else // Information not retrieved
            perror(argv[1]);
    }
    
    // No arguments passed in
    return 1;
}

// Displays some info from stat in a name=value format
void show_stat_info(char *fname, struct stat *buf) {
    printf("   mode: %o\n", buf->st_mode);        // type + mode
    printf("  links: %d\n", buf->st_nlink);       // # links
    printf("   user: %d\n", buf->st_uid);         // user id
    printf("  group: %d\n", buf->st_gid);         // group id
    printf("   size: %lld\n", buf->st_size);      // file size
    printf("modtime: %ld\n", buf->st_mtime);      // modified
    printf("   name: %s\n", fname);               // filename
}
